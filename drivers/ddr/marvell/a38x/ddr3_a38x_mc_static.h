/*
 * Copyright (C) Marvell International Ltd. and its affiliates
 *
 * SPDX-License-Identifier:	GPL-2.0
 */

#ifndef _DDR3_A38X_MC_STATIC_H
#define _DDR3_A38X_MC_STATIC_H

#include "ddr3_a38x.h"

#ifdef SUPPORT_STATIC_DUNIT_CONFIG

#ifdef CONFIG_CUSTOMER_BOARD_SUPPORT
static struct reg_data ddr3_customer_800[] = {
	/* parameters for customer board (based on 800MHZ) */
	{0x1400,	0x7b00cc30, 0xffffffff},
	{0x1404,	0x36301820, 0xffffffff},
	{0x1408,	0x5415baab, 0xffffffff},
	{0x140c,	0x38411def, 0xffffffff},
	{0x1410,	0x18300000, 0xffffffff},
	{0x1414,	0x00000700, 0xffffffff},
	{0x1424,	0x0060f3ff, 0xffffffff},
	{0x1428,	0x0011a940, 0xffffffff},
	{0x142c,	0x28c5134,  0xffffffff},
	{0x1474,	0x00000000, 0xffffffff},
	{0x147c,	0x0000d771, 0xffffffff},
	{0x1494,	0x00030000, 0xffffffff},
	{0x149c,	0x00000300, 0xffffffff},
	{0x14a8,	0x00000000, 0xffffffff},
	{0x14cc,	0xbd09000d, 0xffffffff},
	{0x1504,	0xfffffff1, 0xffffffff},
	{0x150c,	0xffffffe5, 0xffffffff},
	{0x1514,	0x00000000, 0xffffffff},
	{0x151c,	0x00000000, 0xffffffff},
	{0x1538,	0x00000b0b, 0xffffffff},
	{0x153c,	0x00000c0c, 0xffffffff},
	{0x15d0,	0x00000670, 0xffffffff},
	{0x15d4,	0x00000046, 0xffffffff},
	{0x15d8,	0x00000010, 0xffffffff},
	{0x15dc,	0x00000000, 0xffffffff},
	{0x15e0,	0x00000023, 0xffffffff},
	{0x15e4,	0x00203c18, 0xffffffff},
	{0x15ec,	0xf8000019, 0xffffffff},
	{0x16a0,	0xcc000006, 0xffffffff},	/* Clock Delay */
	{0xe4124,	0x08008073, 0xffffffff},	/* AVS BG default */
	{0, 0, 0}
};

#else /* CONFIG_CUSTOMER_BOARD_SUPPORT */

struct reg_data ddr3_a38x_933[MV_MAX_DDR3_STATIC_SIZE] = {
	/* parameters for 933MHZ */
	{0x1400,	0x7b00ce3a, 0xffffffff},
	{0x1404,	0x36301820, 0xffffffff},
	{0x1408,	0x7417eccf, 0xffffffff},
	{0x140c,	0x3e421f98, 0xffffffff},
	{0x1410,	0x1a300000, 0xffffffff},
	{0x1414,	0x00000700, 0xffffffff},
	{0x1424,	0x0060f3ff, 0xffffffff},
	{0x1428,	0x0013ca50, 0xffffffff},
	{0x142c,	0x028c5165, 0xffffffff},
	{0x1474,	0x00000000, 0xffffffff},
	{0x147c,	0x0000e871, 0xffffffff},
	{0x1494,	0x00010000, 0xffffffff},
	{0x149c,	0x00000001, 0xffffffff},
	{0x14a8,	0x00000000, 0xffffffff},
	{0x14cc,	0xbd09000d, 0xffffffff},
	{0x1504,	0xffffffe1, 0xffffffff},
	{0x150c,	0xffffffe5, 0xffffffff},
	{0x1514,	0x00000000, 0xffffffff},
	{0x151c,	0x00000000, 0xffffffff},
	{0x1538,	0x00000d0d, 0xffffffff},
	{0x153c,	0x00000d0d, 0xffffffff},
	{0x15d0,	0x00000608, 0xffffffff},
	{0x15d4,	0x00000044, 0xffffffff},
	{0x15d8,	0x00000020, 0xffffffff},
	{0x15dc,	0x00000000, 0xffffffff},
	{0x15e0,	0x00000021, 0xffffffff},
	{0x15e4,	0x00203c18, 0xffffffff},
	{0x15ec,	0xf8000019, 0xffffffff},
	{0x16a0,	0xcc000006, 0xffffffff},	/* Clock Delay */
	{0xe4124,	0x08008073, 0xffffffff},	/* AVS BG default */
	{0, 0, 0}
};

static struct reg_data ddr3_a38x_800[] = {
	/* parameters for 800MHZ */
	{0x1400,	0x7b00cc30, 0xffffffff},
	{0x1404,	0x36301820, 0xffffffff},
	{0x1408,	0x5415baab, 0xffffffff},
	{0x140c,	0x38411def, 0xffffffff},
	{0x1410,	0x18300000, 0xffffffff},
	{0x1414,	0x00000700, 0xffffffff},
	{0x1424,	0x0060f3ff, 0xffffffff},
	{0x1428,	0x0011a940, 0xffffffff},
	{0x142c,	0x28c5134,  0xffffffff},
	{0x1474,	0x00000000, 0xffffffff},
	{0x147c,	0x0000d771, 0xffffffff},
	{0x1494,	0x00030000, 0xffffffff},
	{0x149c,	0x00000300, 0xffffffff},
	{0x14a8,	0x00000000, 0xffffffff},
	{0x14cc,	0xbd09000d, 0xffffffff},
	{0x1504,	0xfffffff1, 0xffffffff},
	{0x150c,	0xffffffe5, 0xffffffff},
	{0x1514,	0x00000000, 0xffffffff},
	{0x151c,	0x00000000, 0xffffffff},
	{0x1538,	0x00000b0b, 0xffffffff},
	{0x153c,	0x00000c0c, 0xffffffff},
	{0x15d0,	0x00000670, 0xffffffff},
	{0x15d4,	0x00000046, 0xffffffff},
	{0x15d8,	0x00000010, 0xffffffff},
	{0x15dc,	0x00000000, 0xffffffff},
	{0x15e0,	0x00000023, 0xffffffff},
	{0x15e4,	0x00203c18, 0xffffffff},
	{0x15ec,	0xf8000019, 0xffffffff},
	{0x16a0,	0xcc000006, 0xffffffff},	/* Clock Delay */
	{0xe4124,	0x08008073, 0xffffffff},	/* AVS BG default */
	{0,   0, 0}
};

static struct reg_data ddr3_a38x_667[] = {
	/* parameters for 667MHZ */
	/* DDR SDRAM Configuration Register */
	{0x1400,    0x7b00ca28, 0xffffffff},
	/* Dunit Control Low Register - kw28 bit12 low (disable CLK1) */
	{0x1404,    0x36301820, 0xffffffff},
	/* DDR SDRAM Timing (Low) Register */
	{0x1408,    0x43149997, 0xffffffff},
	/* DDR SDRAM Timing (High) Register */
	{0x140c,    0x38411bc7, 0xffffffff},
	/* DDR SDRAM Address Control Register */
	{0x1410,    0x14330000, 0xffffffff},
	/* DDR SDRAM Open Pages Control Register */
	{0x1414,    0x00000700, 0xffffffff},
	/* Dunit Control High Register (2 :1 - bits 15:12 = 0xd) */
	{0x1424,    0x0060f3ff, 0xffffffff},
	/* Dunit Control High Register */
	{0x1428,    0x000f8830, 0xffffffff},
	/* Dunit Control High Register  (2:1 -  bit 29 = '1') */
	{0x142c,    0x28c50f8,  0xffffffff},
	{0x147c,    0x0000c671, 0xffffffff},
	/* DDR SDRAM ODT Control (Low) Register */
	{0x1494,    0x00030000, 0xffffffff},
	/* DDR SDRAM ODT Control (High) Register, will be configured at WL */
	{0x1498,    0x00000000, 0xffffffff},
	/* DDR Dunit ODT Control Register */
	{0x149c,    0x00000300, 0xffffffff},
	{0x14a8,    0x00000000, 0xffffffff}, /*  */
	{0x14cc,    0xbd09000d, 0xffffffff}, /*  */
	{0x1474,    0x00000000, 0xffffffff},
	/* Read Data Sample Delays Register */
	{0x1538,    0x00000009, 0xffffffff},
	/* Read Data Ready Delay Register */
	{0x153c,    0x0000000c, 0xffffffff},
	{0x1504,    0xfffffff1, 0xffffffff}, /*  */
	{0x150c,    0xffffffe5, 0xffffffff}, /*  */
	{0x1514,    0x00000000, 0xffffffff}, /*  */
	{0x151c,    0x0,	0xffffffff}, /*  */
	{0x15d0,    0x00000650, 0xffffffff}, /* MR0 */
	{0x15d4,    0x00000046, 0xffffffff}, /* MR1 */
	{0x15d8,    0x00000010, 0xffffffff}, /* MR2 */
	{0x15dc,    0x00000000, 0xffffffff}, /* MR3 */
	{0x15e0,    0x23,	0xffffffff}, /*  */
	{0x15e4,    0x00203c18, 0xffffffff}, /* ZQC Configuration Register */
	{0x15ec,    0xf8000019, 0xffffffff}, /* DDR PHY */
	{0x16a0,    0xcc000006, 0xffffffff}, /* Clock Delay */
	{0xe4124,   0x08008073, 0xffffffff}, /* AVS BG default */
	{0, 0, 0}
};

static struct reg_data ddr3_a38x_533[] = {
	/* parameters for 533MHZ */
	/* DDR SDRAM Configuration Register */
	{0x1400,    0x7b00d040, 0xffffffff},
	/* Dunit Control Low Register - kw28 bit12 low (disable CLK1) */
	{0x1404,    0x36301820, 0xffffffff},
	/* DDR SDRAM Timing (Low) Register */
	{0x1408,    0x33137772, 0xffffffff},
	/* DDR SDRAM Timing (High) Register */
	{0x140c,    0x3841199f, 0xffffffff},
	/* DDR SDRAM Address Control Register */
	{0x1410,    0x10330000, 0xffffffff},
	/* DDR SDRAM Open Pages Control Register */
	{0x1414,    0x00000700, 0xffffffff},
	/* Dunit Control High Register (2 :1 - bits 15:12 = 0xd) */
	{0x1424,    0x0060f3ff, 0xffffffff},
	/* Dunit Control High Register */
	{0x1428,    0x000d6720, 0xffffffff},
	/* Dunit Control High Register  (2:1 -  bit 29 = '1') */
	{0x142c,    0x028c50c3, 0xffffffff},
	{0x147c,    0x0000b571, 0xffffffff},
	/* DDR SDRAM ODT Control (Low) Register */
	{0x1494,    0x00030000, 0xffffffff},
	/* DDR SDRAM ODT Control (High) Register, will be configured at WL */
	{0x1498,    0x00000000, 0xffffffff},
	/* DDR Dunit ODT Control Register */
	{0x149c,    0x00000003, 0xffffffff},
	{0x14a8,    0x00000000, 0xffffffff}, /*  */
	{0x14cc,    0xbd09000d, 0xffffffff}, /*  */
	{0x1474,    0x00000000, 0xffffffff},
	/* Read Data Sample Delays Register */
	{0x1538,    0x00000707, 0xffffffff},
	/* Read Data Ready Delay Register */
	{0x153c,    0x00000707, 0xffffffff},
	{0x1504,    0xffffffe1, 0xffffffff}, /*  */
	{0x150c,    0xffffffe5, 0xffffffff}, /*  */
	{0x1514,    0x00000000, 0xffffffff}, /*  */
	{0x151c,    0x00000000,	0xffffffff}, /*  */
	{0x15d0,    0x00000630, 0xffffffff}, /* MR0 */
	{0x15d4,    0x00000046, 0xffffffff}, /* MR1 */
	{0x15d8,    0x00000008, 0xffffffff}, /* MR2 */
	{0x15dc,    0x00000000, 0xffffffff}, /* MR3 */
	{0x15e0,    0x00000023,	0xffffffff}, /*  */
	{0x15e4,    0x00203c18, 0xffffffff}, /* ZQC Configuration Register */
	{0x15ec,    0xf8000019, 0xffffffff}, /* DDR PHY */
	{0x16a0,    0xcc000006, 0xffffffff}, /* Clock Delay */
	{0xe4124,   0x08008073, 0xffffffff}, /* AVS BG default */
	{0, 0, 0}
};

#endif /* CONFIG_CUSTOMER_BOARD_SUPPORT */

#endif /* SUPPORT_STATIC_DUNIT_CONFIG */

#endif /* _DDR3_A38X_MC_STATIC_H */
