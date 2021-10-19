/*
 * (C) Copyright 2019 Fuzhou Rockchip Electronics Co., Ltd
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#include <common.h>
#include <asm/gpio.h>
#include <dm/device.h>
#include <power/fuel_gauge.h>
#include <power/pmic.h>
#include <linux/usb/phy-rockchip-inno-usb2.h>

DECLARE_GLOBAL_DATA_PTR;

#define BQ25700_ID				0x25700
#define BQ25703_ID				0x25703

#define COMPAT_BQ25700				"ti,bq25700"
#define COMPAT_BQ25703				"ti,bq25703"

#define BQ25700_I2C_SPEED			100000
#define BQ25700_CHARGE_CURRENT_1500MA		0x5C0
#define BQ25700_SDP_INPUT_CURRENT_500MA		0xA00
#define BQ25700_DCP_INPUT_CURRENT_1500MA	0x1E00
#define BQ25700_DCP_INPUT_CURRENT_2000MA	0x2800
#define BQ25700_DCP_INPUT_CURRENT_3000MA	0x3C00

#define WATCHDOG_ENSABLE			(0x03 << 13)

#define BQ25700_CHARGEOPTION0_REG		0x12
#define BQ25700_CHARGECURREN_REG		0x14
#define BQ25700_CHARGERSTAUS_REG		0x20
#define BQ25700_INPUTVOLTAGE_REG		0x3D
#define BQ25700_INPUTCURREN_REG			0x3F

#define BQ25703_CHARGEOPTION0_REG		0x00
#define BQ25703_CHARGECURREN_REG		0x02
#define BQ25703_CHARGERSTAUS_REG		0x20
#define BQ25703_INPUTVOLTAGE_REG		0x0A
#define BQ25703_INPUTCURREN_REG			0x0E

enum bq25700_table_ids {
	/* range tables */
	TBL_ICHG,
	TBL_CHGMAX,
	TBL_INPUTVOL,
	TBL_INPUTCUR,
	TBL_SYSVMIN,
	TBL_OTGVOL,
	TBL_OTGCUR,
	TBL_EXTCON,
};

struct bq25700 {
	struct udevice *dev;
	struct gpio_desc typec0_enable_gpio;
	struct gpio_desc typec1_enable_gpio;
	u32 ichg;
	u32 chip_id;
};

struct bq25700_range {
	u32 min;
	u32 max;
	u32 step;
};

static int bq25700_read(struct bq25700 *charger, uint reg)
{
	u16 val;
	int ret;

	ret = dm_i2c_read(charger->dev, reg, (u8 *)&val, 2);
	if (ret) {
		debug("write error to device: %p register: %#x!",
		      charger->dev, reg);
		return ret;
	}

	return val;
}

static int bq25700_write(struct bq25700 *charger, uint reg, u16 val)
{
	int ret;

	ret = dm_i2c_write(charger->dev, reg, (u8 *)&val, 2);
	if (ret) {
		debug("write error to device: %p register: %#x!",
		      charger->dev, reg);
		return ret;
	}

	return 0;
}

#if defined(CONFIG_POWER_FUSB302)
static const union {
	struct bq25700_range  rt;
} bq25700_tables[] = {
	/* range tables */
	[TBL_ICHG] = { .rt = {0, 8128000, 64000} },
	/* uV */
	[TBL_CHGMAX] = { .rt = {0, 19200000, 16000} },
	/* uV  max charge voltage*/
	[TBL_INPUTVOL] = { .rt = {3200000, 19520000, 64000} },
	/* uV  input charge voltage*/
	[TBL_INPUTCUR] = {.rt = {0, 6350000, 50000} },
	/*uA input current*/
	[TBL_SYSVMIN] = { .rt = {1024000, 16182000, 256000} },
	/* uV min system voltage*/
	[TBL_OTGVOL] = {.rt = {4480000, 20800000, 64000} },
	/*uV OTG volage*/
	[TBL_OTGCUR] = {.rt = {0, 6350000, 50000} },
};

static u32 bq25700_find_idx(u32 value, enum bq25700_table_ids id)
{
	const struct bq25700_range *rtbl = &bq25700_tables[id].rt;
	u32 rtbl_size;
	u32 idx;

	rtbl_size = (rtbl->max - rtbl->min) / rtbl->step + 1;

	for (idx = 1;
	     idx < rtbl_size && (idx * rtbl->step + rtbl->min <= value);
	     idx++)
		;

	return idx - 1;
}
#endif

static bool bq25700_charger_status(struct bq25700 *charger)
{
#if defined(CONFIG_POWER_FUSB302)
	static u16 charge_flag;
#endif
	int state_of_charger;
	u16 value;

	value = bq25700_read(charger, BQ25700_CHARGERSTAUS_REG);
	state_of_charger = value >> 15;

#if defined(CONFIG_POWER_FUSB302)
	if (state_of_charger) {
		charge_flag = 1;
	} else if (!state_of_charger && charge_flag == 1) {
		typec_discharge();
		charge_flag = 0;
	}
#endif

	return state_of_charger;
}

static bool bq25703_charger_status(struct bq25700 *charger)
{
#if defined(CONFIG_POWER_FUSB302)
	static u16 charge_flag;
#endif
	int state_of_charger;
	u16 value;

	value = bq25700_read(charger, BQ25703_CHARGERSTAUS_REG);
	state_of_charger = value >> 15;

#if defined(CONFIG_POWER_FUSB302)
	if (state_of_charger) {
		charge_flag = 1;
	} else if (!state_of_charger && charge_flag == 1) {
		typec_discharge();
		charge_flag = 0;
	}
#endif

	return state_of_charger;
}

static bool bq257xx_charger_status(struct udevice *dev)
{
	struct bq25700 *charger = dev_get_priv(dev);

	if (charger->chip_id == BQ25700_ID)
		return bq25700_charger_status(charger);
	else
		return bq25703_charger_status(charger);
}

static int bq25700_charger_capability(struct udevice *dev)
{
	return FG_CAP_CHARGER;
}

static int bq25700_get_usb_type(void)
{
#ifdef CONFIG_PHY_ROCKCHIP_INNO_USB2
	return rockchip_chg_get_type();
#else
	return 0;
#endif
}

static void bq25700_charger_current_init(struct bq25700 *charger)
{
	u16 charge_current = BQ25700_CHARGE_CURRENT_1500MA;
	u16 sdp_inputcurrent = BQ25700_SDP_INPUT_CURRENT_500MA;
	u16 dcp_inputcurrent = BQ25700_DCP_INPUT_CURRENT_1500MA;
	u32 pd_inputcurrent = 0;
#if defined(CONFIG_POWER_FUSB302)
	u16 vol_idx, cur_idx, pd_inputvol;
#endif
	u16 temp;

	temp = bq25700_read(charger, BQ25700_CHARGEOPTION0_REG);
	temp &= (~WATCHDOG_ENSABLE);
	bq25700_write(charger, BQ25700_CHARGEOPTION0_REG, temp);

#if defined(CONFIG_POWER_FUSB302)
	if (!get_pd_output_val(&pd_inputvol, &pd_inputcurrent)) {
		printf("%s pd charge input vol:%dmv current:%dma\n",
		       __func__, pd_inputvol, pd_inputcurrent);
		vol_idx = bq25700_find_idx((pd_inputvol - 1280) * 1000,
					   TBL_INPUTVOL);
		cur_idx = bq25700_find_idx(pd_inputcurrent * 1000,
					   TBL_INPUTCUR);
		cur_idx  = cur_idx << 8;
		vol_idx = vol_idx << 6;
		if (pd_inputcurrent != 0) {
			bq25700_write(charger, BQ25700_INPUTCURREN_REG,
				      cur_idx);
			bq25700_write(charger, BQ25700_INPUTVOLTAGE_REG,
				      vol_idx);
			charge_current = bq25700_find_idx(charger.ichg,
							  TBL_ICHG);
			charge_current = charge_current << 8;
		}
	}
#endif

	if (pd_inputcurrent == 0) {
		if (bq25700_get_usb_type() > 1)
			bq25700_write(charger, BQ25700_INPUTCURREN_REG,
				      dcp_inputcurrent);
		else
			bq25700_write(charger, BQ25700_INPUTCURREN_REG,
				      sdp_inputcurrent);
	}

	if (bq25700_charger_status(charger))
		bq25700_write(charger, BQ25700_CHARGECURREN_REG,
			      charge_current);
}

static void bq25703_charger_current_init(struct bq25700 *charger)
{
	u16 charge_current = BQ25700_CHARGE_CURRENT_1500MA;
	u16 sdp_inputcurrent = BQ25700_SDP_INPUT_CURRENT_500MA;
	u16 dcp_inputcurrent = BQ25700_DCP_INPUT_CURRENT_1500MA;
	u32 pd_inputcurrent = 0;
#if defined(CONFIG_POWER_FUSB302)
	u16 vol_idx, cur_idx, pd_inputvol;
#endif
	u16 temp;

	temp = bq25700_read(charger, BQ25703_CHARGEOPTION0_REG);
	temp &= (~WATCHDOG_ENSABLE);
	bq25700_write(charger, BQ25703_CHARGEOPTION0_REG, temp);

#if defined(CONFIG_POWER_FUSB302)
	if (!get_pd_output_val(&pd_inputvol, &pd_inputcurrent)) {
		printf("%s pd charge input vol:%dmv current:%dma\n",
		       __func__, pd_inputvol, pd_inputcurrent);
		vol_idx = bq25700_find_idx((pd_inputvol - 1280) * 1000,
					   TBL_INPUTVOL);
		cur_idx = bq25700_find_idx(pd_inputcurrent * 1000,
					   TBL_INPUTCUR);
		cur_idx  = cur_idx << 8;
		vol_idx = vol_idx << 6;
		if (pd_inputcurrent != 0) {
			bq25700_write(charger, BQ25703_INPUTCURREN_REG,
				      cur_idx);
			bq25700_write(charger, BQ25703_INPUTVOLTAGE_REG,
				      vol_idx);
			charge_current = bq25700_find_idx(charger.ichg,
							  TBL_ICHG);
			charge_current = charge_current << 8;
		}
	}
#endif

	if (pd_inputcurrent == 0) {
		if (bq25700_get_usb_type() > 1)
			bq25700_write(charger, BQ25703_INPUTCURREN_REG,
				      dcp_inputcurrent);
		else
			bq25700_write(charger, BQ25703_INPUTCURREN_REG,
				      sdp_inputcurrent);
	}

	if (bq25703_charger_status(charger))
		bq25700_write(charger, BQ25703_CHARGECURREN_REG,
			      charge_current);
}

static int bq25700_ofdata_to_platdata(struct udevice *dev)
{
	struct bq25700 *charger = dev_get_priv(dev);
	const void *blob = gd->fdt_blob;
	int node, node1;
#if defined(CONFIG_POWER_FUSB302)
	int port_num;
#endif

	charger->dev = dev;

	node = fdt_node_offset_by_compatible(blob, 0, COMPAT_BQ25700);
	node1 = fdt_node_offset_by_compatible(blob, 0, COMPAT_BQ25703);
	if ((node < 0) && (node1 < 0)) {
		printf("Can't find dts node for charger bq25700\n");
		return -ENODEV;
	}

	if (node < 0) {
		node = node1;
		charger->chip_id = BQ25703_ID;
	} else {
		charger->chip_id = BQ25700_ID;
	}

	charger->ichg = fdtdec_get_int(blob, node, "ti,charge-current", 0);

#if defined(CONFIG_POWER_FUSB302)
	gpio_request_by_name(dev, "typec0-enable-gpios", 0,
			     &charger.typec0_enable_gpio);
	gpio_request_by_name(dev, "typec1-enable-gpios", 0,
			     &charger.typec1_enable_gpio);

	if (dm_gpio_is_valid(charger.typec1_enable_gpio.gpio) &&
	    dm_gpio_is_valid(charger.typec0_enable_gpio.gpio)) {
		port_num = get_pd_port_num();
		if (port_num == 0) {
			printf("fusb0 charge typec0:1 typec1:0\n");
			dm_gpio_set_value(&charger.typec0_enable_gpio.gpio, 1);
			dm_gpio_set_value(&charger.typec1_enable_gpio.gpio, 0);
		} else if (port_num == 1) {
			printf("fusb1 charge typec0:0 typec1:1\n");
			dm_gpio_set_value(&charger.typec0_enable_gpio.gpio, 0);
			dm_gpio_set_value(&charger.typec1_enable_gpio.gpio, 1);
		}
		udelay(1000 * 200);
	}
#endif

	return 0;
}

static int bq25700_probe(struct udevice *dev)
{
	struct bq25700 *charger = dev_get_priv(dev);

	if (charger->chip_id == BQ25700_ID)
		bq25700_charger_current_init(charger);
	else
		bq25703_charger_current_init(charger);

	return 0;
}

static const struct udevice_id charger_ids[] = {
	{ .compatible = "ti,bq25700" },
	{ .compatible = "ti,bq25703" },
	{ },
};

static struct dm_fuel_gauge_ops charger_ops = {
	.get_chrg_online = bq257xx_charger_status,
	.capability = bq25700_charger_capability,
};

U_BOOT_DRIVER(bq25700_charger) = {
	.name = "bq25700_charger",
	.id = UCLASS_FG,
	.probe = bq25700_probe,
	.of_match = charger_ids,
	.ops = &charger_ops,
	.ofdata_to_platdata = bq25700_ofdata_to_platdata,
	.priv_auto_alloc_size = sizeof(struct bq25700),
};
