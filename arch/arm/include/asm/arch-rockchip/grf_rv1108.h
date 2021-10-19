/*
 * Copyright (C) 2018 Rockchip Electronics Co., Ltd
 * Author: Zhihuan He <huan.he@rock-chips.com>
 * SPDX-License-Identifier:	GPL-2.0+
 */

#ifndef _ASM_ARCH_GRF_RV1108_H
#define _ASM_ARCH_GRF_RV1108_H

#include <common.h>

struct rv1108_grf {
	u32 reserved[4];
	u32 gpio1a_iomux;
	u32 gpio1b_iomux;
	u32 gpio1c_iomux;
	u32 gpio1d_iomux;
	u32 gpio2a_iomux;
	u32 gpio2b_iomux;
	u32 gpio2c_iomux;
	u32 gpio2d_iomux;
	u32 gpio3a_iomux;
	u32 gpio3b_iomux;
	u32 gpio3c_iomux;
	u32 gpio3d_iomux;
	u32 reserved1[52];
	u32 gpio1a_pull;
	u32 gpio1b_pull;
	u32 gpio1c_pull;
	u32 gpio1d_pull;
	u32 gpio2a_pull;
	u32 gpio2b_pull;
	u32 gpio2c_pull;
	u32 gpio2d_pull;
	u32 gpio3a_pull;
	u32 gpio3b_pull;
	u32 gpio3c_pull;
	u32 gpio3d_pull;
	u32 reserved2[52];
	u32 gpio1a_drv;
	u32 gpio1b_drv;
	u32 gpio1c_drv;
	u32 gpio1d_drv;
	u32 gpio2a_drv;
	u32 gpio2b_drv;
	u32 gpio2c_drv;
	u32 gpio2d_drv;
	u32 gpio3a_drv;
	u32 gpio3b_drv;
	u32 gpio3c_drv;
	u32 gpio3d_drv;
	u32 reserved3[50];
	u32 gpio1l_sr;
	u32 gpio1h_sr;
	u32 gpio2l_sr;
	u32 gpio2h_sr;
	u32 gpio3l_sr;
	u32 gpio3h_sr;
	u32 reserved4[26];
	u32 gpio1l_smt;
	u32 gpio1h_smt;
	u32 gpio2l_smt;
	u32 gpio2h_smt;
	u32 gpio3l_smt;
	u32 gpio3h_smt;
	u32 reserved5[24];
	u32 soc_con0;
	u32 soc_con1;
	u32 soc_con2;
	u32 soc_con3;
	u32 soc_con4;
	u32 soc_con5;
	u32 soc_con6;
	u32 soc_con7;
	u32 soc_con8;
	u32 soc_con9;
	u32 soc_con10;
	u32 soc_con11;
	u32 reserved6[20];
	u32 soc_status0;
	u32 soc_status1;
	u32 reserved7[30];
	u32 cpu_con0;
	u32 cpu_con1;
	u32 reserved8[30];
	u32 os_reg0;
	u32 os_reg1;
	u32 os_reg2;
	u32 os_reg3;
	u32 reserved9[29];
	u32 ddr_status;
	u32 reserved10[30];
	u32 sig_det_con;
	u32 reserved11[3];
	u32 sig_det_status;
	u32 reserved12[3];
	u32 sig_det_clr;
	u32 reserved13[23];
	u32 host_con0;
	u32 host_con1;
	u32 reserved14[2];
	u32 dma_con0;
	u32 dma_con1;
	u32 reserved15[59];
	u32 uoc_status;
	u32 reserved16[2];
	u32 host_status;
	u32 reserved17[59];
	u32 gmac_con0;
	u32 reserved18[191];
	u32 chip_id;
};

check_member(rv1108_grf, chip_id, 0x0c00);

struct rv1108_pmu_grf {
	u32 gpioa_iomux;
	u32 gpiob_iomux;
	u32 gpioc_iomux;
	u32 reserved1;
	u32 gpioa_p;
	u32 gpiob_p;
	u32 gpioc_p;
	u32 reserved2;
	u32 gpioa_e;
	u32 gpiob_e;
	u32 gpioc_e;
	u32 reserved3;
	u32 gpioa_smt;
	u32 gpiob_smt;
	u32 gpioc_smt;
	u32 reserved4;
	u32 gpio0a_sr;
	u32 gpio0b_sr;
	u32 gpio0c_sr;
	u32 reserved5[(0x100-0x4c)/4];
	u32 soc_con[4];
	u32 reserved6[(0x180-0x110)/4];
	u32 dll_con[2];
	u32 reserved7[2];
	u32 dll_status[2];
	u32 reserved8[(0x200-0x198)/4];
	u32 os_reg[4];
	u32 reserved9[(0x300-0x210)/4];
	u32 fast_boot_addr;
	u32 reserved10[(0x380-0x304)/4];
	u32 a7_jtag_mask;
	u32 reserved11[(0x388-0x384)/4];
	u32 ceva_jtag_mask;
};
check_member(rv1108_pmu_grf, ceva_jtag_mask, 0x388);

enum {
	/* GRF_SOC_CON0 */
	MSCH_MAINDDR3_SHIFT		= 4,
	MSCH_MAINDDR3			= 1 << MSCH_MAINDDR3_SHIFT,
	MSCH_MAINPARTIALPOP_SHIFT	= 5,
	MSCH_MAINPARTIALPOP		= 1 << MSCH_MAINPARTIALPOP_SHIFT,
	MSCH_MAINPARTIALPOP_MASK	= 1 << MSCH_MAINPARTIALPOP_SHIFT,
};

enum {
	/* PMU_GRF_SOC_CON0 */
	DDRPHY_BUFFEREN_CORE_SHIFT	= 2,
	DDRPHY_BUFFEREN_CORE_MASK	= 1 << DDRPHY_BUFFEREN_CORE_SHIFT,
	DDRPHY_BUFFEREN_CORE_EN		= 1 << DDRPHY_BUFFEREN_CORE_SHIFT,
};
#endif
