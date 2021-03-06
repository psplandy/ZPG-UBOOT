/*
 * (C) Copyright 2016 Rockchip Electronics Co., Ltd
 *
 * SPDX-License-Identifier:     GPL-2.0+
 */

#ifndef __ASM_ARCH_CRU_RK3399_H_
#define __ASM_ARCH_CRU_RK3399_H_

#include <common.h>

/* Private data for the clock driver - used by rockchip_get_cru() */
struct rk3399_clk_priv {
	struct rk3399_cru *cru;
	ulong armlclk_hz;
	ulong armlclk_enter_hz;
	ulong armlclk_init_hz;
	ulong armbclk_hz;
	ulong armbclk_enter_hz;
	ulong armbclk_init_hz;
	bool sync_kernel;
	bool set_armclk_rate;
};

struct rk3399_pmuclk_priv {
	struct rk3399_pmucru *pmucru;
};

struct rk3399_pmucru {
	u32 ppll_con[6];
	u32 reserved[0x1a];
	u32 pmucru_clksel[6];
	u32 pmucru_clkfrac_con[2];
	u32 reserved2[0x18];
	u32 pmucru_clkgate_con[3];
	u32 reserved3;
	u32 pmucru_softrst_con[2];
	u32 reserved4[2];
	u32 pmucru_rstnhold_con[2];
	u32 reserved5[2];
	u32 pmucru_gatedis_con[2];
};
check_member(rk3399_pmucru, pmucru_gatedis_con[1], 0x134);

struct rk3399_cru {
	u32 apll_l_con[6];
	u32 reserved[2];
	u32 apll_b_con[6];
	u32 reserved1[2];
	u32 dpll_con[6];
	u32 reserved2[2];
	u32 cpll_con[6];
	u32 reserved3[2];
	u32 gpll_con[6];
	u32 reserved4[2];
	u32 npll_con[6];
	u32 reserved5[2];
	u32 vpll_con[6];
	u32 reserved6[0x0a];
	u32 clksel_con[108];
	u32 reserved7[0x14];
	u32 clkgate_con[35];
	u32 reserved8[0x1d];
	u32 softrst_con[21];
	u32 reserved9[0x2b];
	u32 glb_srst_fst_value;
	u32 glb_srst_snd_value;
	u32 glb_cnt_th;
	u32 misc_con;
	u32 glb_rst_con;
	u32 glb_rst_st;
	u32 reserved10[0x1a];
	u32 sdmmc_con[2];
	u32 sdio0_con[2];
	u32 sdio1_con[2];
};
check_member(rk3399_cru, sdio1_con[1], 0x594);
#define MHz		1000000
#define KHz		1000
#define OSC_HZ		(24*MHz)
#define APLL_HZ		(600*MHz)
#define GPLL_HZ		(800 * MHz)
#define CPLL_HZ		(384*MHz)
#define NPLL_HZ		(600 * MHz)
#define PPLL_HZ		(676*MHz)

#define PMU_PCLK_HZ	(48*MHz)

#define ACLKM_CORE_HZ	(300*MHz)
#define ATCLK_CORE_HZ	(300*MHz)
#define PCLK_DBG_HZ	(100*MHz)

#define PERIHP_ACLK_HZ	(150 * MHz)
#define PERIHP_HCLK_HZ	(75 * MHz)
#define PERIHP_PCLK_HZ	(37500 * KHz)

#define PERILP0_ACLK_HZ	(300 * MHz)
#define PERILP0_HCLK_HZ	(100 * MHz)
#define PERILP0_PCLK_HZ	(50 * MHz)

#define PERILP1_HCLK_HZ	(100 * MHz)
#define PERILP1_PCLK_HZ	(50 * MHz)

#define PWM_CLOCK_HZ    PMU_PCLK_HZ

enum apll_frequencies {
	APLL_1600_MHZ,
	APLL_816_MHZ,
	APLL_600_MHZ,
};

enum cpu_cluster {
	CPU_CLUSTER_LITTLE,
	CPU_CLUSTER_BIG,
};

enum rk3399_pll_id {
	APLLL_ID = 0,
	APLLB_ID,
	DPLL_ID,
	CPLL_ID,
	GPLL_ID,
	NPLL_ID,
	VPLL_ID,

	PPLL_ID,

	END_PLL_ID
};

struct rk3399_clk_info {
	unsigned long id;
	char *name;
	bool is_cru;
};

#endif	/* __ASM_ARCH_CRU_RK3399_H_ */
