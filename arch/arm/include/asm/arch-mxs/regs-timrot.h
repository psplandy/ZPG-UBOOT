/*
 * Freescale i.MX28 TIMROT Register Definitions
 *
 * Copyright (C) 2011 Marek Vasut <marek.vasut@gmail.com>
 *
 * Based on code from LTIB:
 * Copyright 2008-2010 Freescale Semiconductor, Inc. All Rights Reserved.
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#ifndef __MX28_REGS_TIMROT_H__
#define __MX28_REGS_TIMROT_H__

#include <asm/mach-imx/regs-common.h>

#ifndef	__ASSEMBLY__
struct mxs_timrot_regs {
	mxs_reg_32(hw_timrot_rotctrl)
	mxs_reg_32(hw_timrot_rotcount)
#if defined(CONFIG_MX23)
	mxs_reg_32(hw_timrot_timctrl0)
	mxs_reg_32(hw_timrot_timcount0)
	mxs_reg_32(hw_timrot_timctrl1)
	mxs_reg_32(hw_timrot_timcount1)
	mxs_reg_32(hw_timrot_timctrl2)
	mxs_reg_32(hw_timrot_timcount2)
	mxs_reg_32(hw_timrot_timctrl3)
	mxs_reg_32(hw_timrot_timcount3)
#elif defined(CONFIG_MX28)
	mxs_reg_32(hw_timrot_timctrl0)
	mxs_reg_32(hw_timrot_running_count0)
	mxs_reg_32(hw_timrot_fixed_count0)
	mxs_reg_32(hw_timrot_match_count0)
	mxs_reg_32(hw_timrot_timctrl1)
	mxs_reg_32(hw_timrot_running_count1)
	mxs_reg_32(hw_timrot_fixed_count1)
	mxs_reg_32(hw_timrot_match_count1)
	mxs_reg_32(hw_timrot_timctrl2)
	mxs_reg_32(hw_timrot_running_count2)
	mxs_reg_32(hw_timrot_fixed_count2)
	mxs_reg_32(hw_timrot_match_count2)
	mxs_reg_32(hw_timrot_timctrl3)
	mxs_reg_32(hw_timrot_running_count3)
	mxs_reg_32(hw_timrot_fixed_count3)
	mxs_reg_32(hw_timrot_match_count3)
#endif
	mxs_reg_32(hw_timrot_version)
};
#endif

#define	TIMROT_ROTCTRL_SFTRST				(1 << 31)
#define	TIMROT_ROTCTRL_CLKGATE				(1 << 30)
#define	TIMROT_ROTCTRL_ROTARY_PRESENT			(1 << 29)
#define	TIMROT_ROTCTRL_TIM3_PRESENT			(1 << 28)
#define	TIMROT_ROTCTRL_TIM2_PRESENT			(1 << 27)
#define	TIMROT_ROTCTRL_TIM1_PRESENT			(1 << 26)
#define	TIMROT_ROTCTRL_TIM0_PRESENT			(1 << 25)
#define	TIMROT_ROTCTRL_STATE_MASK			(0x7 << 22)
#define	TIMROT_ROTCTRL_STATE_OFFSET			22
#define	TIMROT_ROTCTRL_DIVIDER_MASK			(0x3f << 16)
#define	TIMROT_ROTCTRL_DIVIDER_OFFSET			16
#define	TIMROT_ROTCTRL_RELATIVE				(1 << 12)
#define	TIMROT_ROTCTRL_OVERSAMPLE_MASK			(0x3 << 10)
#define	TIMROT_ROTCTRL_OVERSAMPLE_OFFSET		10
#define	TIMROT_ROTCTRL_OVERSAMPLE_8X			(0x0 << 10)
#define	TIMROT_ROTCTRL_OVERSAMPLE_4X			(0x1 << 10)
#define	TIMROT_ROTCTRL_OVERSAMPLE_2X			(0x2 << 10)
#define	TIMROT_ROTCTRL_OVERSAMPLE_1X			(0x3 << 10)
#define	TIMROT_ROTCTRL_POLARITY_B			(1 << 9)
#define	TIMROT_ROTCTRL_POLARITY_A			(1 << 8)
#if defined(CONFIG_MX23)
#define	TIMROT_ROTCTRL_SELECT_B_MASK			(0x7 << 4)
#elif defined(CONFIG_MX28)
#define	TIMROT_ROTCTRL_SELECT_B_MASK			(0xf << 4)
#endif
#define	TIMROT_ROTCTRL_SELECT_B_OFFSET			4
#define	TIMROT_ROTCTRL_SELECT_B_NEVER_TICK		(0x0 << 4)
#define	TIMROT_ROTCTRL_SELECT_B_PWM0			(0x1 << 4)
#define	TIMROT_ROTCTRL_SELECT_B_PWM1			(0x2 << 4)
#define	TIMROT_ROTCTRL_SELECT_B_PWM2			(0x3 << 4)
#define	TIMROT_ROTCTRL_SELECT_B_PWM3			(0x4 << 4)
#define	TIMROT_ROTCTRL_SELECT_B_PWM4			(0x5 << 4)
#if defined(CONFIG_MX23)
#define	TIMROT_ROTCTRL_SELECT_B_ROTARYA		(0x6 << 4)
#define	TIMROT_ROTCTRL_SELECT_B_ROTARYB		(0x7 << 4)
#elif defined(CONFIG_MX28)
#define	TIMROT_ROTCTRL_SELECT_B_PWM5			(0x6 << 4)
#define	TIMROT_ROTCTRL_SELECT_B_PWM6			(0x7 << 4)
#define	TIMROT_ROTCTRL_SELECT_B_PWM7			(0x8 << 4)
#define	TIMROT_ROTCTRL_SELECT_B_ROTARYA			(0x9 << 4)
#define	TIMROT_ROTCTRL_SELECT_B_ROTARYB			(0xa << 4)
#endif
#if defined(CONFIG_MX23)
#define	TIMROT_ROTCTRL_SELECT_A_MASK			0x7
#elif defined(CONFIG_MX28)
#define	TIMROT_ROTCTRL_SELECT_A_MASK			0xf
#endif
#define	TIMROT_ROTCTRL_SELECT_A_OFFSET			0
#define	TIMROT_ROTCTRL_SELECT_A_NEVER_TICK		0x0
#define	TIMROT_ROTCTRL_SELECT_A_PWM0			0x1
#define	TIMROT_ROTCTRL_SELECT_A_PWM1			0x2
#define	TIMROT_ROTCTRL_SELECT_A_PWM2			0x3
#define	TIMROT_ROTCTRL_SELECT_A_PWM3			0x4
#define	TIMROT_ROTCTRL_SELECT_A_PWM4			0x5
#if defined(CONFIG_MX23)
#define	TIMROT_ROTCTRL_SELECT_A_ROTARYA		0x6
#define	TIMROT_ROTCTRL_SELECT_A_ROTARYB		0x7
#elif defined(CONFIG_MX28)
#define	TIMROT_ROTCTRL_SELECT_A_PWM5			0x6
#define	TIMROT_ROTCTRL_SELECT_A_PWM6			0x7
#define	TIMROT_ROTCTRL_SELECT_A_PWM7			0x8
#define	TIMROT_ROTCTRL_SELECT_A_ROTARYA			0x9
#define	TIMROT_ROTCTRL_SELECT_A_ROTARYB			0xa
#endif

#define	TIMROT_ROTCOUNT_UPDOWN_MASK			0xffff
#define	TIMROT_ROTCOUNT_UPDOWN_OFFSET			0

#define	TIMROT_TIMCTRLn_IRQ				(1 << 15)
#define	TIMROT_TIMCTRLn_IRQ_EN				(1 << 14)
#if defined(CONFIG_MX28)
#define	TIMROT_TIMCTRLn_MATCH_MODE			(1 << 11)
#endif
#define	TIMROT_TIMCTRLn_POLARITY			(1 << 8)
#define	TIMROT_TIMCTRLn_UPDATE				(1 << 7)
#define	TIMROT_TIMCTRLn_RELOAD				(1 << 6)
#define	TIMROT_TIMCTRLn_PRESCALE_MASK			(0x3 << 4)
#define	TIMROT_TIMCTRLn_PRESCALE_OFFSET			4
#define	TIMROT_TIMCTRLn_PRESCALE_DIV_BY_1		(0x0 << 4)
#define	TIMROT_TIMCTRLn_PRESCALE_DIV_BY_2		(0x1 << 4)
#define	TIMROT_TIMCTRLn_PRESCALE_DIV_BY_4		(0x2 << 4)
#define	TIMROT_TIMCTRLn_PRESCALE_DIV_BY_8		(0x3 << 4)
#define	TIMROT_TIMCTRLn_SELECT_MASK			0xf
#define	TIMROT_TIMCTRLn_SELECT_OFFSET			0
#define	TIMROT_TIMCTRLn_SELECT_NEVER_TICK		0x0
#define	TIMROT_TIMCTRLn_SELECT_PWM0			0x1
#define	TIMROT_TIMCTRLn_SELECT_PWM1			0x2
#define	TIMROT_TIMCTRLn_SELECT_PWM2			0x3
#define	TIMROT_TIMCTRLn_SELECT_PWM3			0x4
#define	TIMROT_TIMCTRLn_SELECT_PWM4			0x5
#if defined(CONFIG_MX23)
#define	TIMROT_TIMCTRLn_SELECT_ROTARYA		0x6
#define	TIMROT_TIMCTRLn_SELECT_ROTARYB		0x7
#define	TIMROT_TIMCTRLn_SELECT_32KHZ_XTAL		0x8
#define	TIMROT_TIMCTRLn_SELECT_8KHZ_XTAL		0x9
#define	TIMROT_TIMCTRLn_SELECT_4KHZ_XTAL		0xa
#define	TIMROT_TIMCTRLn_SELECT_1KHZ_XTAL		0xb
#define	TIMROT_TIMCTRLn_SELECT_TICK_ALWAYS		0xc
#elif defined(CONFIG_MX28)
#define	TIMROT_TIMCTRLn_SELECT_PWM5			0x6
#define	TIMROT_TIMCTRLn_SELECT_PWM6			0x7
#define	TIMROT_TIMCTRLn_SELECT_PWM7			0x8
#define	TIMROT_TIMCTRLn_SELECT_ROTARYA			0x9
#define	TIMROT_TIMCTRLn_SELECT_ROTARYB			0xa
#define	TIMROT_TIMCTRLn_SELECT_32KHZ_XTAL		0xb
#define	TIMROT_TIMCTRLn_SELECT_8KHZ_XTAL		0xc
#define	TIMROT_TIMCTRLn_SELECT_4KHZ_XTAL		0xd
#define	TIMROT_TIMCTRLn_SELECT_1KHZ_XTAL		0xe
#define	TIMROT_TIMCTRLn_SELECT_TICK_ALWAYS		0xf
#endif

#if defined(CONFIG_MX23)
#define	TIMROT_RUNNING_COUNTn_RUNNING_COUNT_MASK	(0xffff << 16)
#define	TIMROT_RUNNING_COUNTn_RUNNING_COUNT_OFFSET	16
#elif defined(CONFIG_MX28)
#define	TIMROT_RUNNING_COUNTn_RUNNING_COUNT_MASK	0xffffffff
#define	TIMROT_RUNNING_COUNTn_RUNNING_COUNT_OFFSET	0
#endif

#if defined(CONFIG_MX23)
#define	TIMROT_FIXED_COUNTn_FIXED_COUNT_MASK		0xffff
#define	TIMROT_FIXED_COUNTn_FIXED_COUNT_OFFSET		0
#elif defined(CONFIG_MX28)
#define	TIMROT_FIXED_COUNTn_FIXED_COUNT_MASK		0xffffffff
#define	TIMROT_FIXED_COUNTn_FIXED_COUNT_OFFSET		0
#endif

#if defined(CONFIG_MX28)
#define	TIMROT_MATCH_COUNTn_MATCH_COUNT_MASK		0xffffffff
#define	TIMROT_MATCH_COUNTn_MATCH_COUNT_OFFSET		0
#endif

#define	TIMROT_TIMCTRL3_TEST_SIGNAL_MASK		(0xf << 16)
#define	TIMROT_TIMCTRL3_TEST_SIGNAL_OFFSET		16
#define	TIMROT_TIMCTRL3_TEST_SIGNAL_NEVER_TICK		(0x0 << 16)
#define	TIMROT_TIMCTRL3_TEST_SIGNAL_PWM0		(0x1 << 16)
#define	TIMROT_TIMCTRL3_TEST_SIGNAL_PWM1		(0x2 << 16)
#define	TIMROT_TIMCTRL3_TEST_SIGNAL_PWM2		(0x3 << 16)
#define	TIMROT_TIMCTRL3_TEST_SIGNAL_PWM3		(0x4 << 16)
#define	TIMROT_TIMCTRL3_TEST_SIGNAL_PWM4		(0x5 << 16)
#if defined(CONFIG_MX23)
#define	TIMROT_TIMCTRL3_TEST_SIGNAL_ROTARYA		(0x6 << 16)
#define	TIMROT_TIMCTRL3_TEST_SIGNAL_ROTARYB		(0x7 << 16)
#define	TIMROT_TIMCTRL3_TEST_SIGNAL_32KHZ_XTAL		(0x8 << 16)
#define	TIMROT_TIMCTRL3_TEST_SIGNAL_8KHZ_XTAL		(0x9 << 16)
#define	TIMROT_TIMCTRL3_TEST_SIGNAL_4KHZ_XTAL		(0xa << 16)
#define	TIMROT_TIMCTRL3_TEST_SIGNAL_1KHZ_XTAL		(0xb << 16)
#define	TIMROT_TIMCTRL3_TEST_SIGNAL_TICK_ALWAYS		(0xc << 16)
#elif defined(CONFIG_MX28)
#define	TIMROT_TIMCTRL3_TEST_SIGNAL_PWM5		(0x6 << 16)
#define	TIMROT_TIMCTRL3_TEST_SIGNAL_PWM6		(0x7 << 16)
#define	TIMROT_TIMCTRL3_TEST_SIGNAL_PWM7		(0x8 << 16)
#define	TIMROT_TIMCTRL3_TEST_SIGNAL_ROTARYA		(0x9 << 16)
#define	TIMROT_TIMCTRL3_TEST_SIGNAL_ROTARYB		(0xa << 16)
#define	TIMROT_TIMCTRL3_TEST_SIGNAL_32KHZ_XTAL		(0xb << 16)
#define	TIMROT_TIMCTRL3_TEST_SIGNAL_8KHZ_XTAL		(0xc << 16)
#define	TIMROT_TIMCTRL3_TEST_SIGNAL_4KHZ_XTAL		(0xd << 16)
#define	TIMROT_TIMCTRL3_TEST_SIGNAL_1KHZ_XTAL		(0xe << 16)
#define	TIMROT_TIMCTRL3_TEST_SIGNAL_TICK_ALWAYS		(0xf << 16)
#endif
#if defined(CONFIG_MX23)
#define	TIMROT_TIMCTRL3_IRQ				(1 << 15)
#define	TIMROT_TIMCTRL3_IRQ_EN				(1 << 14)
#define	TIMROT_TIMCTRL3_DUTU_VALID			(1 << 10)
#endif
#define	TIMROT_TIMCTRL3_DUTY_CYCLE			(1 << 9)
#if defined(CONFIG_MX23)
#define	TIMROT_TIMCTRL3_POLARITY_MASK			(0x1 << 8)
#define	TIMROT_TIMCTRL3_POLARITY_OFFSET		8
#define	TIMROT_TIMCTRL3_POLARITY_POSITIVE		(0x0 << 8)
#define	TIMROT_TIMCTRL3_POLARITY_NEGATIVE		(0x1 << 8)
#define	TIMROT_TIMCTRL3_UPDATE				(1 << 7)
#define	TIMROT_TIMCTRL3_RELOAD				(1 << 6)
#define	TIMROT_TIMCTRL3_PRESCALE_MASK			(0x3 << 4)
#define	TIMROT_TIMCTRL3_PRESCALE_OFFSET		4
#define	TIMROT_TIMCTRL3_PRESCALE_DIV_BY_1		(0x0 << 4)
#define	TIMROT_TIMCTRL3_PRESCALE_DIV_BY_2		(0x1 << 4)
#define	TIMROT_TIMCTRL3_PRESCALE_DIV_BY_4		(0x2 << 4)
#define	TIMROT_TIMCTRL3_PRESCALE_DIV_BY_8		(0x3 << 4)
#define	TIMROT_TIMCTRL3_SELECT_MASK			0xf
#define	TIMROT_TIMCTRL3_SELECT_OFFSET			0
#define	TIMROT_TIMCTRL3_SELECT_NEVER_TICK		0x0
#define	TIMROT_TIMCTRL3_SELECT_PWM0			0x1
#define	TIMROT_TIMCTRL3_SELECT_PWM1			0x2
#define	TIMROT_TIMCTRL3_SELECT_PWM2			0x3
#define	TIMROT_TIMCTRL3_SELECT_PWM3			0x4
#define	TIMROT_TIMCTRL3_SELECT_PWM4			0x5
#define	TIMROT_TIMCTRL3_SELECT_ROTARYA		0x6
#define	TIMROT_TIMCTRL3_SELECT_ROTARYB		0x7
#define	TIMROT_TIMCTRL3_SELECT_32KHZ_XTAL		0x8
#define	TIMROT_TIMCTRL3_SELECT_8KHZ_XTAL		0x9
#define	TIMROT_TIMCTRL3_SELECT_4KHZ_XTAL		0xa
#define	TIMROT_TIMCTRL3_SELECT_1KHZ_XTAL		0xb
#define	TIMROT_TIMCTRL3_SELECT_TICK_ALWAYS		0xc
#define	TIMROT_TIMCOUNT3_LOW_RUNNING_COUNT_MASK	(0xffff << 16)
#define	TIMROT_TIMCOUNT3_LOW_RUNNING_COUNT_OFFSET	16
#define	TIMROT_TIMCOUNT3_HIGH_FIXED_COUNT_MASK	0xffff
#define	TIMROT_TIMCOUNT3_HIGH_FIXED_COUNT_OFFSET	0
#endif

#define	TIMROT_VERSION_MAJOR_MASK			(0xff << 24)
#define	TIMROT_VERSION_MAJOR_OFFSET			24
#define	TIMROT_VERSION_MINOR_MASK			(0xff << 16)
#define	TIMROT_VERSION_MINOR_OFFSET			16
#define	TIMROT_VERSION_STEP_MASK			0xffff
#define	TIMROT_VERSION_STEP_OFFSET			0

#endif /* __MX28_REGS_TIMROT_H__ */
