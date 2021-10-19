/*
 *  (C) Copyright 2010,2011
 *  NVIDIA Corporation <www.nvidia.com>
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#ifndef _TEGRA20_PINMUX_H_
#define _TEGRA20_PINMUX_H_

/*
 * Pin groups which we adjust. There are three basic attributes of each pin
 * group which use this enum:
 *
 *	- function
 *	- pullup / pulldown
 *	- tristate or normal
 */
enum pmux_pingrp {
	/* APB_MISC_PP_TRISTATE_REG_A_0 */
	PMUX_PINGRP_ATA,
	PMUX_PINGRP_ATB,
	PMUX_PINGRP_ATC,
	PMUX_PINGRP_ATD,
	PMUX_PINGRP_CDEV1,
	PMUX_PINGRP_CDEV2,
	PMUX_PINGRP_CSUS,
	PMUX_PINGRP_DAP1,

	PMUX_PINGRP_DAP2,
	PMUX_PINGRP_DAP3,
	PMUX_PINGRP_DAP4,
	PMUX_PINGRP_DTA,
	PMUX_PINGRP_DTB,
	PMUX_PINGRP_DTC,
	PMUX_PINGRP_DTD,
	PMUX_PINGRP_DTE,

	PMUX_PINGRP_GPU,
	PMUX_PINGRP_GPV,
	PMUX_PINGRP_I2CP,
	PMUX_PINGRP_IRTX,
	PMUX_PINGRP_IRRX,
	PMUX_PINGRP_KBCB,
	PMUX_PINGRP_KBCA,
	PMUX_PINGRP_PMC,

	PMUX_PINGRP_PTA,
	PMUX_PINGRP_RM,
	PMUX_PINGRP_KBCE,
	PMUX_PINGRP_KBCF,
	PMUX_PINGRP_GMA,
	PMUX_PINGRP_GMC,
	PMUX_PINGRP_SDIO1,
	PMUX_PINGRP_OWC,

	/* 32: APB_MISC_PP_TRISTATE_REG_B_0 */
	PMUX_PINGRP_GME,
	PMUX_PINGRP_SDC,
	PMUX_PINGRP_SDD,
	PMUX_PINGRP_RESERVED0,
	PMUX_PINGRP_SLXA,
	PMUX_PINGRP_SLXC,
	PMUX_PINGRP_SLXD,
	PMUX_PINGRP_SLXK,

	PMUX_PINGRP_SPDI,
	PMUX_PINGRP_SPDO,
	PMUX_PINGRP_SPIA,
	PMUX_PINGRP_SPIB,
	PMUX_PINGRP_SPIC,
	PMUX_PINGRP_SPID,
	PMUX_PINGRP_SPIE,
	PMUX_PINGRP_SPIF,

	PMUX_PINGRP_SPIG,
	PMUX_PINGRP_SPIH,
	PMUX_PINGRP_UAA,
	PMUX_PINGRP_UAB,
	PMUX_PINGRP_UAC,
	PMUX_PINGRP_UAD,
	PMUX_PINGRP_UCA,
	PMUX_PINGRP_UCB,

	PMUX_PINGRP_RESERVED1,
	PMUX_PINGRP_ATE,
	PMUX_PINGRP_KBCC,
	PMUX_PINGRP_RESERVED2,
	PMUX_PINGRP_RESERVED3,
	PMUX_PINGRP_GMB,
	PMUX_PINGRP_GMD,
	PMUX_PINGRP_DDC,

	/* 64: APB_MISC_PP_TRISTATE_REG_C_0 */
	PMUX_PINGRP_LD0,
	PMUX_PINGRP_LD1,
	PMUX_PINGRP_LD2,
	PMUX_PINGRP_LD3,
	PMUX_PINGRP_LD4,
	PMUX_PINGRP_LD5,
	PMUX_PINGRP_LD6,
	PMUX_PINGRP_LD7,

	PMUX_PINGRP_LD8,
	PMUX_PINGRP_LD9,
	PMUX_PINGRP_LD10,
	PMUX_PINGRP_LD11,
	PMUX_PINGRP_LD12,
	PMUX_PINGRP_LD13,
	PMUX_PINGRP_LD14,
	PMUX_PINGRP_LD15,

	PMUX_PINGRP_LD16,
	PMUX_PINGRP_LD17,
	PMUX_PINGRP_LHP0,
	PMUX_PINGRP_LHP1,
	PMUX_PINGRP_LHP2,
	PMUX_PINGRP_LVP0,
	PMUX_PINGRP_LVP1,
	PMUX_PINGRP_HDINT,

	PMUX_PINGRP_LM0,
	PMUX_PINGRP_LM1,
	PMUX_PINGRP_LVS,
	PMUX_PINGRP_LSC0,
	PMUX_PINGRP_LSC1,
	PMUX_PINGRP_LSCK,
	PMUX_PINGRP_LDC,
	PMUX_PINGRP_LCSN,

	/* 96: APB_MISC_PP_TRISTATE_REG_D_0 */
	PMUX_PINGRP_LSPI,
	PMUX_PINGRP_LSDA,
	PMUX_PINGRP_LSDI,
	PMUX_PINGRP_LPW0,
	PMUX_PINGRP_LPW1,
	PMUX_PINGRP_LPW2,
	PMUX_PINGRP_LDI,
	PMUX_PINGRP_LHS,

	PMUX_PINGRP_LPP,
	PMUX_PINGRP_RESERVED4,
	PMUX_PINGRP_KBCD,
	PMUX_PINGRP_GPU7,
	PMUX_PINGRP_DTF,
	PMUX_PINGRP_UDA,
	PMUX_PINGRP_CRTP,
	PMUX_PINGRP_SDB,

	/* these pin groups only have pullup and pull down control */
	PMUX_PINGRP_CK32,
	PMUX_PINGRP_DDRC,
	PMUX_PINGRP_PMCA,
	PMUX_PINGRP_PMCB,
	PMUX_PINGRP_PMCC,
	PMUX_PINGRP_PMCD,
	PMUX_PINGRP_PMCE,
	PMUX_PINGRP_XM2C,
	PMUX_PINGRP_XM2D,
	PMUX_PINGRP_COUNT,
};

/*
 * Functions which can be assigned to each of the pin groups. The values here
 * bear no relation to the values programmed into pinmux registers and are
 * purely a convenience. The translation is done through a table search.
 */
enum pmux_func {
	PMUX_FUNC_DEFAULT,
	PMUX_FUNC_AHB_CLK,
	PMUX_FUNC_APB_CLK,
	PMUX_FUNC_AUDIO_SYNC,
	PMUX_FUNC_CRT,
	PMUX_FUNC_DAP1,
	PMUX_FUNC_DAP2,
	PMUX_FUNC_DAP3,
	PMUX_FUNC_DAP4,
	PMUX_FUNC_DAP5,
	PMUX_FUNC_DISPA,
	PMUX_FUNC_DISPB,
	PMUX_FUNC_EMC_TEST0_DLL,
	PMUX_FUNC_EMC_TEST1_DLL,
	PMUX_FUNC_GMI,
	PMUX_FUNC_GMI_INT,
	PMUX_FUNC_HDMI,
	PMUX_FUNC_I2C,
	PMUX_FUNC_I2C2,
	PMUX_FUNC_I2C3,
	PMUX_FUNC_IDE,
	PMUX_FUNC_KBC,
	PMUX_FUNC_MIO,
	PMUX_FUNC_MIPI_HS,
	PMUX_FUNC_NAND,
	PMUX_FUNC_OSC,
	PMUX_FUNC_OWR,
	PMUX_FUNC_PCIE,
	PMUX_FUNC_PLLA_OUT,
	PMUX_FUNC_PLLC_OUT1,
	PMUX_FUNC_PLLM_OUT1,
	PMUX_FUNC_PLLP_OUT2,
	PMUX_FUNC_PLLP_OUT3,
	PMUX_FUNC_PLLP_OUT4,
	PMUX_FUNC_PWM,
	PMUX_FUNC_PWR_INTR,
	PMUX_FUNC_PWR_ON,
	PMUX_FUNC_RTCK,
	PMUX_FUNC_SDIO1,
	PMUX_FUNC_SDIO2,
	PMUX_FUNC_SDIO3,
	PMUX_FUNC_SDIO4,
	PMUX_FUNC_SFLASH,
	PMUX_FUNC_SPDIF,
	PMUX_FUNC_SPI1,
	PMUX_FUNC_SPI2,
	PMUX_FUNC_SPI2_ALT,
	PMUX_FUNC_SPI3,
	PMUX_FUNC_SPI4,
	PMUX_FUNC_TRACE,
	PMUX_FUNC_TWC,
	PMUX_FUNC_UARTA,
	PMUX_FUNC_UARTB,
	PMUX_FUNC_UARTC,
	PMUX_FUNC_UARTD,
	PMUX_FUNC_UARTE,
	PMUX_FUNC_ULPI,
	PMUX_FUNC_VI,
	PMUX_FUNC_VI_SENSOR_CLK,
	PMUX_FUNC_XIO,
	PMUX_FUNC_RSVD1,
	PMUX_FUNC_RSVD2,
	PMUX_FUNC_RSVD3,
	PMUX_FUNC_RSVD4,
	PMUX_FUNC_COUNT,
};

#define TEGRA_PMX_SOC_DRV_GROUP_BASE_REG 0x868
#include <asm/arch-tegra/pinmux.h>

#endif /* _TEGRA20_PINMUX_H_ */
