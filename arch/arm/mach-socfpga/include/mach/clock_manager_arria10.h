/*
 * Copyright (C) 2016-2017 Intel Corporation
 *
 * SPDX-License-Identifier:	GPL-2.0
 */

#ifndef CLOCK_MANAGER_ARRIA10
#define CLOCK_MANAGER_ARRIA10

#ifndef __ASSEMBLER__

struct socfpga_clock_manager_main_pll {
	u32  vco0;
	u32  vco1;
	u32  en;
	u32  ens;
	u32  enr;
	u32  bypass;
	u32  bypasss;
	u32  bypassr;
	u32  mpuclk;
	u32  nocclk;
	u32  cntr2clk;
	u32  cntr3clk;
	u32  cntr4clk;
	u32  cntr5clk;
	u32  cntr6clk;
	u32  cntr7clk;
	u32  cntr8clk;
	u32  cntr9clk;
	u32  pad_0x48_0x5b[5];
	u32  cntr15clk;
	u32  outrst;
	u32  outrststat;
	u32  nocdiv;
	u32  pad_0x6c_0x80[5];
};

struct socfpga_clock_manager_per_pll {
	u32  vco0;
	u32  vco1;
	u32  en;
	u32  ens;
	u32  enr;
	u32  bypass;
	u32  bypasss;
	u32  bypassr;
	u32  pad_0x20_0x27[2];
	u32  cntr2clk;
	u32  cntr3clk;
	u32  cntr4clk;
	u32  cntr5clk;
	u32  cntr6clk;
	u32  cntr7clk;
	u32  cntr8clk;
	u32  cntr9clk;
	u32  pad_0x48_0x5f[6];
	u32  outrst;
	u32  outrststat;
	u32  emacctl;
	u32  gpiodiv;
	u32  pad_0x70_0x80[4];
};

struct socfpga_clock_manager_altera {
	u32	mpuclk;
	u32	nocclk;
	u32	mainmisc0;
	u32	mainmisc1;
	u32	perimisc0;
	u32	perimisc1;
};

struct socfpga_clock_manager {
	/* clkmgr */
	u32  ctrl;
	u32  intr;
	u32  intrs;
	u32  intrr;
	u32  intren;
	u32  intrens;
	u32  intrenr;
	u32  stat;
	u32  testioctrl;
	u32  _pad_0x24_0x40[7];
	/* mainpllgrp */
	struct socfpga_clock_manager_main_pll main_pll;
	/* perpllgrp */
	struct socfpga_clock_manager_per_pll per_pll;
	struct socfpga_clock_manager_altera altera;
};

void cm_use_intosc(void);
unsigned int cm_get_noc_clk_hz(void);
unsigned int cm_get_l4_noc_hz(unsigned int nocdivshift);
int cm_basic_init(const void *blob);

unsigned int cm_get_l4_sp_clk_hz(void);
unsigned int cm_get_main_vco_clk_hz(void);
unsigned int cm_get_per_vco_clk_hz(void);
unsigned long cm_get_mpu_clk_hz(void);

unsigned int cm_get_qspi_controller_clk_hz(void);
unsigned int cm_get_mmc_controller_clk_hz(void);
unsigned int cm_get_spi_controller_clk_hz(void);

#endif /* __ASSEMBLER__ */

#define CLKMGR_ALTERAGRP_MPU_CLK_OFFSET			0x140
#define CLKMGR_MAINPLL_NOC_CLK_OFFSET			0x144
#define LOCKED_MASK	(CLKMGR_CLKMGR_STAT_MAINPLLLOCKED_SET_MSK  | \
			 CLKMGR_CLKMGR_STAT_PERPLLLOCKED_SET_MSK)

/* value */
#define CLKMGR_MAINPLL_BYPASS_RESET			0x0000003f
#define CLKMGR_PERPLL_BYPASS_RESET			0x000000ff
#define CLKMGR_MAINPLL_VCO0_RESET			0x00010053
#define CLKMGR_MAINPLL_VCO1_RESET			0x00010001
#define CLKMGR_PERPLL_VCO0_RESET			0x00010053
#define CLKMGR_PERPLL_VCO1_RESET			0x00010001
#define CLKMGR_MAINPLL_VCO0_PSRC_EOSC			0x0
#define CLKMGR_MAINPLL_VCO0_PSRC_E_INTOSC		0x1
#define CLKMGR_MAINPLL_VCO0_PSRC_F2S			0x2
#define CLKMGR_PERPLL_VCO0_PSRC_EOSC			0x0
#define CLKMGR_PERPLL_VCO0_PSRC_E_INTOSC		0x1
#define CLKMGR_PERPLL_VCO0_PSRC_F2S			0x2
#define CLKMGR_PERPLL_VCO0_PSRC_MAIN			0x3

/* mask */
#define CLKMGR_MAINPLL_EN_S2FUSER0CLKEN_SET_MSK		BIT(6)
#define CLKMGR_MAINPLL_EN_HMCPLLREFCLKEN_SET_MSK	BIT(7)
#define CLKMGR_CLKMGR_STAT_MAINPLLLOCKED_SET_MSK	BIT(8)
#define CLKMGR_CLKMGR_STAT_PERPLLLOCKED_SET_MSK		BIT(9)
#define CLKMGR_CLKMGR_STAT_BOOTCLKSRC_SET_MSK		BIT(17)
#define CLKMGR_MAINPLL_VCO0_BGPWRDN_SET_MSK		BIT(0)
#define CLKMGR_MAINPLL_VCO0_PWRDN_SET_MSK		BIT(1)
#define CLKMGR_MAINPLL_VCO0_EN_SET_MSK			BIT(2)
#define CLKMGR_MAINPLL_VCO0_OUTRSTALL_SET_MSK		BIT(3)
#define CLKMGR_MAINPLL_VCO0_REGEXTSEL_SET_MSK		BIT(4)
#define CLKMGR_PERPLL_VCO0_BGPWRDN_SET_MSK		BIT(0)
#define CLKMGR_PERPLL_VCO0_PWRDN_SET_MSK		BIT(1)
#define CLKMGR_PERPLL_VCO0_EN_SET_MSK			BIT(2)
#define CLKMGR_PERPLL_VCO0_OUTRSTALL_SET_MSK		BIT(3)
#define CLKMGR_PERPLL_VCO0_REGEXTSEL_SET_MSK		BIT(4)
#define CLKMGR_CLKMGR_INTR_MAINPLLACHIEVED_SET_MSK	BIT(0)
#define CLKMGR_CLKMGR_INTR_PERPLLACHIEVED_SET_MSK	BIT(1)
#define CLKMGR_CLKMGR_INTR_MAINPLLLOST_SET_MSK		BIT(2)
#define CLKMGR_CLKMGR_INTR_PERPLLLOST_SET_MSK		BIT(3)
#define CLKMGR_CLKMGR_INTR_MAINPLLRFSLIP_SET_MSK	BIT(8)
#define CLKMGR_CLKMGR_INTR_PERPLLRFSLIP_SET_MSK		BIT(9)
#define CLKMGR_CLKMGR_INTR_MAINPLLFBSLIP_SET_MSK	BIT(10)
#define CLKMGR_CLKMGR_INTR_PERPLLFBSLIP_SET_MSK		BIT(11)
#define CLKMGR_CLKMGR_CTL_BOOTMOD_SET_MSK		BIT(0)
#define CLKMGR_CLKMGR_CTL_BOOTCLK_INTOSC_SET_MSK	0x00000300
#define CLKMGR_PERPLL_EN_RESET				0x00000f7f
#define CLKMGR_PERPLLGRP_EN_SDMMCCLK_MASK		BIT(5)
#define CLKMGR_MAINPLL_VCO0_PSRC_MSK			0x00000003
#define CLKMGR_MAINPLL_VCO1_NUMER_MSK			0x00001fff
#define CLKMGR_MAINPLL_VCO1_DENOM_MSK			0x0000003f
#define CLKMGR_MAINPLL_CNTRCLK_MSK			0x000003ff
#define CLKMGR_PERPLL_VCO0_PSRC_MSK			0x00000003
#define CLKMGR_PERPLL_VCO1_NUMER_MSK			0x00001fff
#define CLKMGR_PERPLL_VCO1_DENOM_MSK			0x0000003f
#define CLKMGR_PERPLL_CNTRCLK_MSK			0x000003ff
#define CLKMGR_MAINPLL_MPUCLK_SRC_MSK			0x00000007
#define CLKMGR_MAINPLL_MPUCLK_CNT_MSK			0x000003ff
#define CLKMGR_MAINPLL_MPUCLK_SRC_MAIN			0
#define CLKMGR_MAINPLL_MPUCLK_SRC_PERI			1
#define CLKMGR_MAINPLL_MPUCLK_SRC_OSC1			2
#define CLKMGR_MAINPLL_MPUCLK_SRC_INTOSC		3
#define CLKMGR_MAINPLL_MPUCLK_SRC_FPGA			4
#define CLKMGR_MAINPLL_NOCDIV_MSK			0x00000003
#define CLKMGR_MAINPLL_NOCCLK_CNT_MSK			0x000003ff
#define CLKMGR_MAINPLL_NOCCLK_SRC_MSK			0x00000007
#define CLKMGR_MAINPLL_NOCCLK_SRC_MAIN			0
#define CLKMGR_MAINPLL_NOCCLK_SRC_PERI			1
#define CLKMGR_MAINPLL_NOCCLK_SRC_OSC1			2
#define CLKMGR_MAINPLL_NOCCLK_SRC_INTOSC		3
#define CLKMGR_MAINPLL_NOCCLK_SRC_FPGA			4

#define CLKMGR_PERPLLGRP_SRC_MSK			0x00000007
#define CLKMGR_PERPLLGRP_SRC_MAIN			0
#define CLKMGR_PERPLLGRP_SRC_PERI			1
#define CLKMGR_PERPLLGRP_SRC_OSC1			2
#define CLKMGR_PERPLLGRP_SRC_INTOSC			3
#define CLKMGR_PERPLLGRP_SRC_FPGA			4

/* bit shifting macro */
#define CLKMGR_MAINPLL_VCO0_PSRC_LSB		8
#define CLKMGR_PERPLL_VCO0_PSRC_LSB		8
#define CLKMGR_MAINPLL_VCO1_DENOM_LSB		16
#define CLKMGR_PERPLL_VCO1_DENOM_LSB		16
#define CLKMGR_MAINPLL_NOCCLK_PERICNT_LSB	16
#define CLKMGR_MAINPLL_NOCCLK_SRC_LSB		16
#define CLKMGR_MAINPLL_NOCDIV_L4MAINCLK_LSB	0
#define CLKMGR_MAINPLL_NOCDIV_L4MPCLK_LSB	8
#define CLKMGR_MAINPLL_NOCDIV_L4SPCLK_LSB	16
#define CLKMGR_MAINPLL_NOCDIV_CSATCLK_LSB	24
#define CLKMGR_MAINPLL_NOCDIV_CSTRACECLK_LSB	26
#define CLKMGR_MAINPLL_NOCDIV_CSPDBGCLK_LSB	28
#define CLKMGR_MAINPLL_MPUCLK_SRC_LSB		16
#define CLKMGR_MAINPLL_MPUCLK_PERICNT_LSB	16
#define CLKMGR_MAINPLL_NOCCLK_SRC_LSB		16
#define CLKMGR_MAINPLL_CNTR7CLK_SRC_LSB		16
#define CLKMGR_MAINPLL_CNTR9CLK_SRC_LSB		16
#define CLKMGR_PERPLL_CNTR2CLK_SRC_LSB		16
#define CLKMGR_PERPLL_CNTR3CLK_SRC_LSB		16
#define CLKMGR_PERPLL_CNTR4CLK_SRC_LSB		16
#define CLKMGR_PERPLL_CNTR5CLK_SRC_LSB		16
#define CLKMGR_PERPLL_CNTR6CLK_SRC_LSB		16
#define CLKMGR_PERPLL_CNTR8CLK_SRC_LSB		16
#define CLKMGR_PERPLL_EMACCTL_EMAC0SEL_LSB	26
#define CLKMGR_PERPLL_EMACCTL_EMAC1SEL_LSB	27
#define CLKMGR_PERPLL_EMACCTL_EMAC2SEL_LSB	28

/* PLL ramping work around */
#define CLKMGR_PLL_RAMP_MPUCLK_THRESHOLD_HZ	900000000
#define CLKMGR_PLL_RAMP_NOCCLK_THRESHOLD_HZ	300000000
#define CLKMGR_PLL_RAMP_MPUCLK_INCREMENT_HZ	100000000
#define CLKMGR_PLL_RAMP_NOCCLK_INCREMENT_HZ	33000000

#define CLKMGR_STAT_BUSY			BIT(0)

#endif /* CLOCK_MANAGER_ARRIA10 */
