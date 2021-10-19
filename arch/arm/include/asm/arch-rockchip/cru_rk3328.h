/*
 * (C) Copyright 2016 Rockchip Electronics Co., Ltd
 *
 * SPDX-License-Identifier:     GPL-2.0+
 */

#ifndef __ASM_ARCH_CRU_RK3328_H_
#define __ASM_ARCH_CRU_RK3328_H_

#include <common.h>

struct rk3328_clk_priv {
	struct rk3328_cru *cru;
	ulong rate;
	ulong cpll_hz;
	ulong gpll_hz;
	ulong armclk_hz;
	ulong armclk_enter_hz;
	ulong armclk_init_hz;
	bool sync_kernel;
	bool set_armclk_rate;
};

struct rk3328_cru {
	u32 apll_con[5];
	u32 reserved1[3];
	u32 dpll_con[5];
	u32 reserved2[3];
	u32 cpll_con[5];
	u32 reserved3[3];
	u32 gpll_con[5];
	u32 reserved4[3];
	u32 mode_con;
	u32 misc;
	u32 reserved5[2];
	u32 glb_cnt_th;
	u32 glb_rst_st;
	u32 glb_srst_snd_value;
	u32 glb_srst_fst_value;
	u32 npll_con[5];
	u32 reserved6[(0x100 - 0xb4) / 4];
	u32 clksel_con[53];
	u32 reserved7[(0x200 - 0x1d4) / 4];
	u32 clkgate_con[29];
	u32 reserved8[3];
	u32 ssgtbl[32];
	u32 softrst_con[12];
	u32 reserved9[(0x380 - 0x330) / 4];
	u32 sdmmc_con[2];
	u32 sdio_con[2];
	u32 emmc_con[2];
	u32 sdmmc_ext_con[2];
};
check_member(rk3328_cru, sdmmc_ext_con[1], 0x39c);

/* PX30 pll id */
enum rk3328_pll_id {
	APLL,
	DPLL,
	CPLL,
	GPLL,
	NPLL,
	PLL_COUNT,
};

struct rk3328_clk_info {
	unsigned long id;
	char *name;
	bool is_cru;
};

#define MHz				1000 * 1000
#define OSC_HZ				(24 * MHz)
#define APLL_HZ				(600 * MHz)
#define GPLL_HZ				491520000
#define CPLL_HZ				(1200 * MHz)
#define ACLK_BUS_HZ			(150 * MHz)
#define ACLK_PERI_HZ			(150 * MHz)
#define PWM_CLOCK_HZ			(74 * MHz)

#define RK3328_PLL_CON(x)		((x) * 0x4)
#define RK3328_CLKSEL_CON(x)		((x) * 0x4 + 0x100)
#define RK3328_CLKGATE_CON(x)		((x) * 0x4 + 0x200)
#define RK3328_MODE_CON			0x80

enum {
	/* CLKSEL_CON0 */
	CLK_BUS_PLL_SEL_CPLL		= 0,
	CLK_BUS_PLL_SEL_GPLL		= 1,
	CLK_BUS_PLL_SEL_SHIFT		= 13,
	CLK_BUS_PLL_SEL_MASK		= 3 << CLK_BUS_PLL_SEL_SHIFT,
	ACLK_BUS_DIV_CON_SHIFT		= 8,
	ACLK_BUS_DIV_CON_MASK		= 0x1f << ACLK_BUS_DIV_CON_SHIFT,
	CORE_CLK_PLL_SEL_SHIFT		= 6,
	CORE_CLK_PLL_SEL_MASK		= 3 << CORE_CLK_PLL_SEL_SHIFT,
	CORE_CLK_PLL_SEL_APLL		= 0,
	CORE_CLK_PLL_SEL_GPLL,
	CORE_CLK_PLL_SEL_NPLL		= 3,
	CORE_DIV_CON_SHIFT		= 0,
	CORE_DIV_CON_MASK		= 0x1f << CORE_DIV_CON_SHIFT,

	/* CLKSEL_CON1 */
	PCLK_BUS_DIV_CON_SHIFT		= 12,
	PCLK_BUS_DIV_CON_MASK		= 0x7 << PCLK_BUS_DIV_CON_SHIFT,
	HCLK_BUS_DIV_CON_SHIFT		= 8,
	HCLK_BUS_DIV_CON_MASK		= 0x3 << HCLK_BUS_DIV_CON_SHIFT,
	CORE_ACLK_DIV_SHIFT		= 4,
	CORE_ACLK_DIV_MASK		= 0x07 << CORE_ACLK_DIV_SHIFT,
	CORE_DBG_DIV_SHIFT		= 0,
	CORE_DBG_DIV_MASK		= 0x0f << CORE_DBG_DIV_SHIFT,

	/* CLKSEL_CON27 */
	GMAC2IO_PLL_SEL_SHIFT		= 7,
	GMAC2IO_PLL_SEL_MASK		= 1 << GMAC2IO_PLL_SEL_SHIFT,
	GMAC2IO_PLL_SEL_CPLL		= 0,
	GMAC2IO_PLL_SEL_GPLL		= 1,
	GMAC2IO_CLK_DIV_MASK		= 0x1f,
	GMAC2IO_CLK_DIV_SHIFT		= 0,

	/* CLKSEL_CON28 */
	CLK_PERI_PLL_SEL_CPLL		= 0,
	CLK_PERI_PLL_SEL_GPLL,
	CLK_PERI_PLL_SEL_HDMIPHY,
	CLK_PERI_PLL_SEL_SHIFT		= 6,
	CLK_PERI_PLL_SEL_MASK		= 3 << CLK_PERI_PLL_SEL_SHIFT,
	ACLK_PERI_DIV_CON_SHIFT		= 0,
	ACLK_PERI_DIV_CON_MASK		= 0x1f,

	/* CLKSEL_CON29 */
	PCLK_PERI_DIV_CON_SHIFT		= 4,
	PCLK_PERI_DIV_CON_MASK		= 0x7 << PCLK_PERI_DIV_CON_SHIFT,
	HCLK_PERI_DIV_CON_SHIFT		= 0,
	HCLK_PERI_DIV_CON_MASK		= 3 << HCLK_PERI_DIV_CON_SHIFT,

	/* CLKSEL_CON20 */
	CRYPTO_PLL_SEL_SHIFT		= 7,
	CRYPTO_PLL_SEL_MASK		= 0x1 << CRYPTO_PLL_SEL_SHIFT,
	CRYPTO_PLL_SEL_CPLL		= 0,
	CRYPTO_PLL_SEL_GPLL,
	CRYPTO_DIV_SHIFT		= 0,
	CRYPTO_DIV_MASK			= 0x7f << CRYPTO_DIV_SHIFT,

	/* CLKSEL_CON22 */
	CLK_TSADC_DIV_CON_SHIFT		= 0,
	CLK_TSADC_DIV_CON_MASK		= 0x3ff,

	/* CLKSEL_CON23 */
	CLK_SARADC_DIV_CON_SHIFT	= 0,
	CLK_SARADC_DIV_CON_MASK		= GENMASK(9, 0),
	CLK_SARADC_DIV_CON_WIDTH	= 10,

	/* CLKSEL_CON24 */
	CLK_PWM_PLL_SEL_CPLL		= 0,
	CLK_PWM_PLL_SEL_GPLL,
	CLK_PWM_PLL_SEL_SHIFT		= 15,
	CLK_PWM_PLL_SEL_MASK		= 1 << CLK_PWM_PLL_SEL_SHIFT,
	CLK_PWM_DIV_CON_SHIFT		= 8,
	CLK_PWM_DIV_CON_MASK		= 0x7f << CLK_PWM_DIV_CON_SHIFT,

	CLK_SPI_PLL_SEL_CPLL		= 0,
	CLK_SPI_PLL_SEL_GPLL,
	CLK_SPI_PLL_SEL_SHIFT		= 7,
	CLK_SPI_PLL_SEL_MASK		= 1 << CLK_SPI_PLL_SEL_SHIFT,
	CLK_SPI_DIV_CON_SHIFT		= 0,
	CLK_SPI_DIV_CON_MASK		= 0x7f << CLK_SPI_DIV_CON_SHIFT,

	/* CLKSEL_CON30 */
	CLK_SDMMC_PLL_SEL_CPLL		= 0,
	CLK_SDMMC_PLL_SEL_GPLL,
	CLK_SDMMC_PLL_SEL_24M,
	CLK_SDMMC_PLL_SEL_USBPHY,
	CLK_SDMMC_PLL_SHIFT		= 8,
	CLK_SDMMC_PLL_MASK		= 0x3 << CLK_SDMMC_PLL_SHIFT,
	CLK_SDMMC_DIV_CON_SHIFT          = 0,
	CLK_SDMMC_DIV_CON_MASK           = 0xff << CLK_SDMMC_DIV_CON_SHIFT,

	/* CLKSEL_CON32 */
	CLK_EMMC_PLL_SEL_CPLL		= 0,
	CLK_EMMC_PLL_SEL_GPLL,
	CLK_EMMC_PLL_SEL_24M,
	CLK_EMMC_PLL_SEL_USBPHY,
	CLK_EMMC_PLL_SHIFT		= 8,
	CLK_EMMC_PLL_MASK		= 0x3 << CLK_EMMC_PLL_SHIFT,
	CLK_EMMC_DIV_CON_SHIFT          = 0,
	CLK_EMMC_DIV_CON_MASK           = 0xff << CLK_EMMC_DIV_CON_SHIFT,

	/* CLKSEL_CON34 */
	CLK_I2C_PLL_SEL_CPLL		= 0,
	CLK_I2C_PLL_SEL_GPLL,
	CLK_I2C_DIV_CON_MASK		= 0x7f,
	CLK_I2C_PLL_SEL_MASK		= 1,
	CLK_I2C1_PLL_SEL_SHIFT		= 15,
	CLK_I2C1_DIV_CON_SHIFT		= 8,
	CLK_I2C0_PLL_SEL_SHIFT		= 7,
	CLK_I2C0_DIV_CON_SHIFT		= 0,

	/* CLKSEL_CON35 */
	CLK_I2C3_PLL_SEL_SHIFT		= 15,
	CLK_I2C3_DIV_CON_SHIFT		= 8,
	CLK_I2C2_PLL_SEL_SHIFT		= 7,
	CLK_I2C2_DIV_CON_SHIFT		= 0,

	/* CRU_CLK_SEL37_CON */
	ACLK_VIO_PLL_SEL_CPLL		= 0,
	ACLK_VIO_PLL_SEL_GPLL		= 1,
	ACLK_VIO_PLL_SEL_HDMIPHY	= 2,
	ACLK_VIO_PLL_SEL_USB480M	= 3,
	ACLK_VIO_PLL_SEL_SHIFT		= 6,
	ACLK_VIO_PLL_SEL_MASK		= 3 << ACLK_VIO_PLL_SEL_SHIFT,
	ACLK_VIO_DIV_CON_SHIFT		= 0,
	ACLK_VIO_DIV_CON_MASK		= 0x1f << ACLK_VIO_DIV_CON_SHIFT,
	HCLK_VIO_DIV_CON_SHIFT		= 8,
	HCLK_VIO_DIV_CON_MASK		= 0x1f << HCLK_VIO_DIV_CON_SHIFT,

	/* CRU_CLK_SEL39_CON */
	ACLK_VOP_PLL_SEL_CPLL		= 0,
	ACLK_VOP_PLL_SEL_GPLL		= 1,
	ACLK_VOP_PLL_SEL_HDMIPHY	= 2,
	ACLK_VOP_PLL_SEL_USB480M	= 3,
	ACLK_VOP_PLL_SEL_SHIFT		= 6,
	ACLK_VOP_PLL_SEL_MASK		= 3 << ACLK_VOP_PLL_SEL_SHIFT,
	ACLK_VOP_DIV_CON_SHIFT		= 0,
	ACLK_VOP_DIV_CON_MASK		= 0x1f << ACLK_VOP_DIV_CON_SHIFT,

	/* CRU_CLK_SEL40_CON */
	DCLK_LCDC_PLL_SEL_GPLL		= 0,
	DCLK_LCDC_PLL_SEL_CPLL		= 1,
	DCLK_LCDC_PLL_SEL_SHIFT		= 0,
	DCLK_LCDC_PLL_SEL_MASK		= 1 << DCLK_LCDC_PLL_SEL_SHIFT,
	DCLK_LCDC_SEL_HDMIPHY		= 0,
	DCLK_LCDC_SEL_PLL		= 1,
	DCLK_LCDC_SEL_SHIFT		= 1,
	DCLK_LCDC_SEL_MASK		= 1 << DCLK_LCDC_SEL_SHIFT,
	DCLK_LCDC_DIV_CON_SHIFT		= 8,
	DCLK_LCDC_DIV_CON_MASK		= 0xFf << DCLK_LCDC_DIV_CON_SHIFT,
};

#endif	/* __ASM_ARCH_CRU_RK3328_H_ */
