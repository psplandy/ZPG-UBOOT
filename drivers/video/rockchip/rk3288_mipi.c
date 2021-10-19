/*
 * Copyright (c) 2017, Fuzhou Rockchip Electronics Co., Ltd
 * Author: Eric Gao <eric.gao@rock-chips.com>
 *
 * SPDX-License-Identifier: GPL-2.0+
 */

#include <common.h>
#include <clk.h>
#include <display.h>
#include <dm.h>
#include <fdtdec.h>
#include <panel.h>
#include <regmap.h>
#include "rk_mipi.h"
#include <syscon.h>
#include <asm/gpio.h>
#include <asm/hardware.h>
#include <asm/io.h>
#include <dm/uclass-internal.h>
#include <linux/kernel.h>
#include <asm/arch/clock.h>
#include <asm/arch/cru_rk3288.h>
#include <asm/arch/grf_rk3288.h>
#include <asm/arch/rockchip_mipi_dsi.h>

DECLARE_GLOBAL_DATA_PTR;

#define MHz 1000000

/* Select mipi dsi source, big or little vop */
static int rk_mipi_dsi_source_select(struct udevice *dev)
{
	struct rk_mipi_priv *priv = dev_get_priv(dev);
	struct rk3288_grf *grf = priv->grf;
	struct display_plat *disp_uc_plat = dev_get_uclass_platdata(dev);

	/* Select the video source */
	switch (disp_uc_plat->source_id) {
	case VOP_B:
		rk_clrsetreg(&grf->soc_con6, RK3288_DSI0_LCDC_SEL_MASK,
			     RK3288_DSI0_LCDC_SEL_BIG
			     << RK3288_DSI0_LCDC_SEL_SHIFT);
		break;
	case VOP_L:
		rk_clrsetreg(&grf->soc_con6, RK3288_DSI0_LCDC_SEL_MASK,
			     RK3288_DSI0_LCDC_SEL_LIT
			     << RK3288_DSI0_LCDC_SEL_SHIFT);
		break;
	default:
		debug("%s: Invalid VOP id\n", __func__);
		return -EINVAL;
	}

	return 0;
}

/* Setup mipi dphy working mode */
static void rk_mipi_dphy_mode_set(struct udevice *dev)
{
	struct rk_mipi_priv *priv = dev_get_priv(dev);
	struct rk3288_grf *grf = priv->grf;
	int val;

	/* Set Controller as TX mode */
	val = RK3288_DPHY_TX0_RXMODE_DIS << RK3288_DPHY_TX0_RXMODE_SHIFT;
	rk_clrsetreg(&grf->soc_con8, RK3288_DPHY_TX0_RXMODE_MASK, val);

	/* Exit tx stop mode */
	val |= RK3288_DPHY_TX0_TXSTOPMODE_EN
			<< RK3288_DPHY_TX0_TXSTOPMODE_SHIFT;
	rk_clrsetreg(&grf->soc_con8,
		     RK3288_DPHY_TX0_TXSTOPMODE_MASK, val);

	/* Disable turnequest */
	val |= RK3288_DPHY_TX0_TURNREQUEST_EN
		<< RK3288_DPHY_TX0_TURNREQUEST_SHIFT;
	rk_clrsetreg(&grf->soc_con8,
		     RK3288_DPHY_TX0_TURNREQUEST_MASK, val);
}

/*
 * This function is called by rk_display_init() using rk_mipi_dsi_enable() and
 * rk_mipi_phy_enable() to initialize mipi controller and dphy. If success,
 * enable backlight.
 */
static int rk_mipi_enable(struct udevice *dev, int panel_bpp,
			  const struct display_timing *timing)
{
	int ret;
	struct rk_mipi_priv *priv = dev_get_priv(dev);

	/* Fill the mipi controller parameter */
	priv->ref_clk = 24 * MHz;
	priv->sys_clk = priv->ref_clk;
	priv->pix_clk = timing->pixelclock.typ;
	priv->phy_clk = priv->pix_clk * 6;
	priv->txbyte_clk = priv->phy_clk / 8;
	priv->txesc_clk = 20 * MHz;

	/* Select vop port, big or little */
	rk_mipi_dsi_source_select(dev);

	/* Set mipi dphy work mode */
	rk_mipi_dphy_mode_set(dev);

	/* Config  and enable mipi dsi according to timing */
	ret = rk_mipi_dsi_enable(dev, timing);
	if (ret) {
		debug("%s: rk_mipi_dsi_enable() failed (err=%d)\n",
		      __func__, ret);
		return ret;
	}

	/* Config and enable mipi phy */
	ret = rk_mipi_phy_enable(dev);
	if (ret) {
		debug("%s: rk_mipi_phy_enable() failed (err=%d)\n",
		      __func__, ret);
		return ret;
	}

	/* Enable backlight */
	ret = panel_enable_backlight(priv->panel);
	if (ret) {
		debug("%s: panel_enable_backlight() failed (err=%d)\n",
		      __func__, ret);
		return ret;
	}

	return 0;
}

static int rk_mipi_ofdata_to_platdata(struct udevice *dev)
{
	struct rk_mipi_priv *priv = dev_get_priv(dev);

	priv->grf = syscon_get_first_range(ROCKCHIP_SYSCON_GRF);
	if (IS_ERR(priv->grf)) {
		debug("%s: Get syscon grf failed (ret=%p)\n",
		      __func__, priv->grf);
		return  -ENXIO;
	}
	priv->regs = dev_read_addr(dev);
	if (priv->regs == FDT_ADDR_T_NONE) {
		debug("%s: Get MIPI dsi address failed (ret=%lu)\n", __func__,
		      priv->regs);
		return  -ENXIO;
	}

	return 0;
}

/*
 * Probe function: check panel existence and readingit's timing. Then config
 * mipi dsi controller and enable it according to the timing parameter.
 */
static int rk_mipi_probe(struct udevice *dev)
{
	int ret;
	struct rk_mipi_priv *priv = dev_get_priv(dev);

	ret = uclass_get_device_by_phandle(UCLASS_PANEL, dev, "rockchip,panel",
					   &priv->panel);
	if (ret) {
		debug("%s: Can not find panel (err=%d)\n", __func__, ret);
		return ret;
	}

	return 0;
}

static const struct dm_display_ops rk_mipi_dsi_ops = {
	.read_timing = rk_mipi_read_timing,
	.enable = rk_mipi_enable,
};

static const struct udevice_id rk_mipi_dsi_ids[] = {
	{ .compatible = "rockchip,rk3288_mipi_dsi" },
	{ }
};

U_BOOT_DRIVER(rk_mipi_dsi) = {
	.name	= "rk_mipi_dsi",
	.id	= UCLASS_DISPLAY,
	.of_match = rk_mipi_dsi_ids,
	.ofdata_to_platdata = rk_mipi_ofdata_to_platdata,
	.probe	= rk_mipi_probe,
	.ops	= &rk_mipi_dsi_ops,
	.priv_auto_alloc_size   = sizeof(struct rk_mipi_priv),
};
