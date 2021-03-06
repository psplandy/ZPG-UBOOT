/*
 * (C) Copyright 2008-2017 Fuzhou Rockchip Electronics Co., Ltd
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#include <config.h>
#include <common.h>
#include <errno.h>
#include <dm/device.h>
#include <dm/read.h>
#include <dm/ofnode.h>
#include <syscon.h>
#include <regmap.h>
#include <dm/device.h>
#include <dm/read.h>
#include <linux/media-bus-format.h>

#include "rockchip_display.h"
#include "rockchip_connector.h"
#include "rockchip_phy.h"
#include "rockchip_panel.h"

#define HIWORD_UPDATE(v, h, l)		(((v) << (l)) | (GENMASK(h, l) << 16))

#define PX30_GRF_PD_VO_CON1		0x0438
#define PX30_LVDS_SELECT(x)		HIWORD_UPDATE(x, 14, 13)
#define PX30_LVDS_MODE_EN(x)		HIWORD_UPDATE(x, 12, 12)
#define PX30_LVDS_MSBSEL(x)		HIWORD_UPDATE(x, 11, 11)
#define PX30_LVDS_P2S_EN(x)		HIWORD_UPDATE(x,  6,  6)
#define PX30_LVDS_VOP_SEL(x)		HIWORD_UPDATE(x,  1,  1)

#define RK3126_GRF_LVDS_CON0		0x0150
#define RK3126_LVDS_P2S_EN(x)		HIWORD_UPDATE(x,  9,  9)
#define RK3126_LVDS_MODE_EN(x)		HIWORD_UPDATE(x,  6,  6)
#define RK3126_LVDS_MSBSEL(x)		HIWORD_UPDATE(x,  3,  3)
#define RK3126_LVDS_SELECT(x)		HIWORD_UPDATE(x,  2,  1)

#define RK3288_GRF_SOC_CON6		0x025c
#define RK3288_LVDS_LCDC_SEL(x)		HIWORD_UPDATE(x,  3,  3)
#define RK3288_GRF_SOC_CON7		0x0260
#define RK3288_LVDS_PWRDWN(x)		HIWORD_UPDATE(x, 15, 15)
#define RK3288_LVDS_CON_ENABLE_2(x)	HIWORD_UPDATE(x, 12, 12)
#define RK3288_LVDS_CON_ENABLE_1(x)	HIWORD_UPDATE(x, 11, 11)
#define RK3288_LVDS_CON_DEN_POL(x)	HIWORD_UPDATE(x, 10, 10)
#define RK3288_LVDS_CON_HS_POL(x)	HIWORD_UPDATE(x,  9,  9)
#define RK3288_LVDS_CON_CLKINV(x)	HIWORD_UPDATE(x,  8,  8)
#define RK3288_LVDS_CON_STARTPHASE(x)	HIWORD_UPDATE(x,  7,  7)
#define RK3288_LVDS_CON_TTL_EN(x)	HIWORD_UPDATE(x,  6,  6)
#define RK3288_LVDS_CON_STARTSEL(x)	HIWORD_UPDATE(x,  5,  5)
#define RK3288_LVDS_CON_CHASEL(x)	HIWORD_UPDATE(x,  4,  4)
#define RK3288_LVDS_CON_MSBSEL(x)	HIWORD_UPDATE(x,  3,  3)
#define RK3288_LVDS_CON_SELECT(x)	HIWORD_UPDATE(x,  2,  0)

#define RK3368_GRF_SOC_CON7		0x041c
#define RK3368_LVDS_SELECT(x)		HIWORD_UPDATE(x, 14, 13)
#define RK3368_LVDS_MODE_EN(x)		HIWORD_UPDATE(x, 12, 12)
#define RK3368_LVDS_MSBSEL(x)		HIWORD_UPDATE(x, 11, 11)
#define RK3368_LVDS_P2S_EN(x)		HIWORD_UPDATE(x,  6,  6)

enum lvds_format {
	LVDS_8BIT_MODE_FORMAT_1,
	LVDS_8BIT_MODE_FORMAT_2,
	LVDS_8BIT_MODE_FORMAT_3,
	LVDS_6BIT_MODE,
};

struct rockchip_lvds;

struct rockchip_lvds_funcs {
	void (*enable)(struct rockchip_lvds *lvds, int pipe);
	void (*disable)(struct rockchip_lvds *lvds);
};

struct rockchip_lvds {
	struct udevice *dev;
	struct regmap *grf;
	struct rockchip_phy *phy;
	const struct drm_display_mode *mode;
	const struct rockchip_lvds_funcs *funcs;
	enum lvds_format format;
	bool data_swap;
	bool dual_channel;
};

static inline struct rockchip_lvds *state_to_lvds(struct display_state *state)
{
	struct connector_state *conn_state = &state->conn_state;

	return dev_get_priv(conn_state->dev);
}

static int rockchip_lvds_connector_init(struct display_state *state)
{
	struct rockchip_lvds *lvds = state_to_lvds(state);
	struct connector_state *conn_state = &state->conn_state;
	struct rockchip_panel *panel = state_get_panel(state);

	lvds->mode = &conn_state->mode;
	lvds->phy = conn_state->phy;

	switch (panel->bus_format) {
	case MEDIA_BUS_FMT_RGB666_1X7X3_JEIDA:	/* jeida-18 */
		lvds->format = LVDS_6BIT_MODE;
		break;
	case MEDIA_BUS_FMT_RGB888_1X7X4_JEIDA:	/* jeida-24 */
		lvds->format = LVDS_8BIT_MODE_FORMAT_2;
		break;
	case MEDIA_BUS_FMT_RGB666_1X7X3_SPWG:	/* vesa-18 */
		lvds->format = LVDS_8BIT_MODE_FORMAT_3;
		break;
	case MEDIA_BUS_FMT_RGB888_1X7X4_SPWG:	/* vesa-24 */
	default:
		lvds->format = LVDS_8BIT_MODE_FORMAT_1;
		break;
	}

	conn_state->type = DRM_MODE_CONNECTOR_LVDS;
	conn_state->output_mode = ROCKCHIP_OUT_MODE_P888;
	conn_state->color_space = V4L2_COLORSPACE_DEFAULT;

	return 0;
}

static int rockchip_lvds_connector_enable(struct display_state *state)
{
	struct rockchip_lvds *lvds = state_to_lvds(state);
	struct crtc_state *crtc_state = &state->crtc_state;
	int pipe = crtc_state->crtc_id;
	int ret;

	if (lvds->funcs->enable)
		lvds->funcs->enable(lvds, pipe);

	ret = rockchip_phy_set_mode(lvds->phy, PHY_MODE_VIDEO_LVDS);
	if (ret) {
		dev_err(lvds->dev, "failed to set phy mode: %d\n", ret);
		return ret;
	}

	rockchip_phy_power_on(lvds->phy);

	return 0;
}

static int rockchip_lvds_connector_disable(struct display_state *state)
{
	struct rockchip_lvds *lvds = state_to_lvds(state);

	rockchip_phy_power_off(lvds->phy);

	if (lvds->funcs->disable)
		lvds->funcs->disable(lvds);

	return 0;
}

static const struct rockchip_connector_funcs rockchip_lvds_connector_funcs = {
	.init = rockchip_lvds_connector_init,
	.enable = rockchip_lvds_connector_enable,
	.disable = rockchip_lvds_connector_disable,
};

static int rockchip_lvds_probe(struct udevice *dev)
{
	struct rockchip_lvds *lvds = dev_get_priv(dev);
	const struct rockchip_connector *connector =
		(const struct rockchip_connector *)dev_get_driver_data(dev);

	lvds->dev = dev;
	lvds->funcs = connector->data;
	lvds->grf = syscon_get_regmap(dev_get_parent(dev));
	lvds->dual_channel = dev_read_bool(dev, "dual-channel");
	lvds->data_swap = dev_read_bool(dev, "rockchip,data-swap");

	return 0;
}

static void px30_lvds_enable(struct rockchip_lvds *lvds, int pipe)
{
	regmap_write(lvds->grf, PX30_GRF_PD_VO_CON1,
		     PX30_LVDS_SELECT(lvds->format) |
		     PX30_LVDS_MODE_EN(1) | PX30_LVDS_MSBSEL(1) |
		     PX30_LVDS_P2S_EN(1) | PX30_LVDS_VOP_SEL(pipe));
}

static void px30_lvds_disable(struct rockchip_lvds *lvds)
{
	regmap_write(lvds->grf, PX30_GRF_PD_VO_CON1,
		     PX30_LVDS_MODE_EN(0) | PX30_LVDS_P2S_EN(0));
}

static const struct rockchip_lvds_funcs px30_lvds_funcs = {
	.enable = px30_lvds_enable,
	.disable = px30_lvds_disable,
};

static const struct rockchip_connector px30_lvds_driver_data = {
	 .funcs = &rockchip_lvds_connector_funcs,
	 .data = &px30_lvds_funcs,
};

static void rk3126_lvds_enable(struct rockchip_lvds *lvds, int pipe)
{
	regmap_write(lvds->grf, RK3126_GRF_LVDS_CON0,
		     RK3126_LVDS_P2S_EN(1) | RK3126_LVDS_MODE_EN(1) |
		     RK3126_LVDS_MSBSEL(1) | RK3126_LVDS_SELECT(lvds->format));
}

static void rk3126_lvds_disable(struct rockchip_lvds *lvds)
{
	regmap_write(lvds->grf, RK3126_GRF_LVDS_CON0,
		     RK3126_LVDS_P2S_EN(0) | RK3126_LVDS_MODE_EN(0));
}

static const struct rockchip_lvds_funcs rk3126_lvds_funcs = {
	.enable = rk3126_lvds_enable,
	.disable = rk3126_lvds_disable,
};

static const struct rockchip_connector rk3126_lvds_driver_data = {
	 .funcs = &rockchip_lvds_connector_funcs,
	 .data = &rk3126_lvds_funcs,
};

static void rk3288_lvds_enable(struct rockchip_lvds *lvds, int pipe)
{
	const struct drm_display_mode *mode = lvds->mode;
	u32 val;

	regmap_write(lvds->grf, RK3288_GRF_SOC_CON6,
		     RK3288_LVDS_LCDC_SEL(pipe));

	val = RK3288_LVDS_PWRDWN(0) | RK3288_LVDS_CON_CLKINV(0) |
	      RK3288_LVDS_CON_CHASEL(lvds->dual_channel) |
	      RK3288_LVDS_CON_SELECT(lvds->format);

	if (lvds->dual_channel) {
		u32 h_bp = mode->htotal - mode->hsync_start;

		val |= RK3288_LVDS_CON_ENABLE_2(1) |
		       RK3288_LVDS_CON_ENABLE_1(1) |
		       RK3288_LVDS_CON_STARTSEL(lvds->data_swap);

		if (h_bp % 2)
			val |= RK3288_LVDS_CON_STARTPHASE(1);
		else
			val |= RK3288_LVDS_CON_STARTPHASE(0);
	} else {
		val |= RK3288_LVDS_CON_ENABLE_2(0) |
		       RK3288_LVDS_CON_ENABLE_1(1);
	}

	regmap_write(lvds->grf, RK3288_GRF_SOC_CON7, val);

	rockchip_phy_set_bus_width(lvds->phy, lvds->dual_channel ? 2 : 1);
}

static void rk3288_lvds_disable(struct rockchip_lvds *lvds)
{
	regmap_write(lvds->grf, RK3288_GRF_SOC_CON7, RK3288_LVDS_PWRDWN(1));
}

static const struct rockchip_lvds_funcs rk3288_lvds_funcs = {
	.enable = rk3288_lvds_enable,
	.disable = rk3288_lvds_disable,
};

static const struct rockchip_connector rk3288_lvds_driver_data = {
	 .funcs = &rockchip_lvds_connector_funcs,
	 .data = &rk3288_lvds_funcs,
};

static void rk3368_lvds_enable(struct rockchip_lvds *lvds, int pipe)
{
	regmap_write(lvds->grf, RK3368_GRF_SOC_CON7,
		     RK3368_LVDS_SELECT(lvds->format) |
		     RK3368_LVDS_MODE_EN(1) | RK3368_LVDS_MSBSEL(1) |
		     RK3368_LVDS_P2S_EN(1));
}

static void rk3368_lvds_disable(struct rockchip_lvds *lvds)
{
	regmap_write(lvds->grf, RK3368_GRF_SOC_CON7,
		     RK3368_LVDS_MODE_EN(0) | RK3368_LVDS_P2S_EN(0));
}

static const struct rockchip_lvds_funcs rk3368_lvds_funcs = {
	.enable = rk3368_lvds_enable,
	.disable = rk3368_lvds_disable,
};

static const struct rockchip_connector rk3368_lvds_driver_data = {
	 .funcs = &rockchip_lvds_connector_funcs,
	 .data = &rk3368_lvds_funcs,
};

static const struct udevice_id rockchip_lvds_ids[] = {
	{
		.compatible = "rockchip,px30-lvds",
		.data = (ulong)&px30_lvds_driver_data,
	},
	{
		.compatible = "rockchip,rk3126-lvds",
		.data = (ulong)&rk3126_lvds_driver_data,
	},
	{
		.compatible = "rockchip,rk3288-lvds",
		.data = (ulong)&rk3288_lvds_driver_data,
	},
	{
		.compatible = "rockchip,rk3368-lvds",
		.data = (ulong)&rk3368_lvds_driver_data,
	},
	{}
};

U_BOOT_DRIVER(rockchip_lvds) = {
	.name = "rockchip_lvds",
	.id = UCLASS_DISPLAY,
	.of_match = rockchip_lvds_ids,
	.probe = rockchip_lvds_probe,
	.priv_auto_alloc_size = sizeof(struct rockchip_lvds),
};
