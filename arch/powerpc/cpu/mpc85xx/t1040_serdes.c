/*
 * Copyright 2012 Freescale Semiconductor, Inc.
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#include <common.h>
#include <asm/fsl_serdes.h>
#include <asm/processor.h>
#include <asm/io.h>


static u8 serdes_cfg_tbl[][SRDS_MAX_LANES] = {
	[0x00] = {PCIE1, PCIE1, PCIE1, PCIE1,
		PCIE2, PCIE2, PCIE2, PCIE2},
	[0x06] = {PCIE1, PCIE1, PCIE1, PCIE1,
		PCIE2, PCIE3, PCIE4, SATA1},
	[0x08] = {PCIE1, PCIE1, PCIE1, PCIE1,
		PCIE2, PCIE3, SATA2, SATA1},
	[0x40] = {PCIE1, PCIE1, SGMII_FM1_DTSEC1, SGMII_FM1_DTSEC2,
		PCIE2, PCIE2, PCIE2, PCIE2},
	[0x60] = {PCIE1, SGMII_FM1_DTSEC3, QSGMII_SW1_A, QSGMII_SW1_B,
		PCIE2, PCIE2, PCIE2, PCIE2},
	[0x66] = {PCIE1, SGMII_FM1_DTSEC3, QSGMII_SW1_A, QSGMII_SW1_B,
		PCIE2, PCIE3, PCIE4, SATA1},
	[0x67] = {PCIE1, SGMII_FM1_DTSEC3, QSGMII_SW1_A, QSGMII_SW1_B,
		PCIE2, PCIE3, PCIE4, SGMII_FM1_DTSEC5},
	[0x69] = {PCIE1, SGMII_FM1_DTSEC3, QSGMII_SW1_A, QSGMII_SW1_B,
		PCIE2, PCIE3, SGMII_FM1_DTSEC4, SATA1},
	[0x86] = {PCIE1, SGMII_FM1_DTSEC3, SGMII_FM1_DTSEC1, SGMII_FM1_DTSEC2,
		PCIE2, PCIE3, PCIE4, SATA1},
	[0x85] = {PCIE1, SGMII_FM1_DTSEC3, SGMII_FM1_DTSEC1, SGMII_FM1_DTSEC2,
		PCIE2, PCIE2, SGMII_FM1_DTSEC4, SGMII_FM1_DTSEC5},
	[0x87] = {PCIE1, SGMII_FM1_DTSEC3, SGMII_FM1_DTSEC1, SGMII_FM1_DTSEC2,
		PCIE2, PCIE3, PCIE4, SGMII_FM1_DTSEC5},
	[0x89] = {PCIE1, SGMII_SW1_MAC3, SGMII_SW1_MAC1, SGMII_SW1_MAC2,
		PCIE2, PCIE3, SGMII_SW1_MAC4, SATA1},
	[0x8D] = {PCIE1, SGMII_SW1_MAC3, SGMII_SW1_MAC1, SGMII_SW1_MAC2,
		PCIE2, SGMII_SW1_MAC6, SGMII_SW1_MAC4, SGMII_SW1_MAC5},
	[0x8F] = {PCIE1, SGMII_FM1_DTSEC3, SGMII_FM1_DTSEC1, SGMII_FM1_DTSEC2,
		AURORA, NONE, SGMII_FM1_DTSEC4, SGMII_FM1_DTSEC5},
	[0xA5] = {PCIE1, SGMII_FM1_DTSEC3, SGMII_FM1_DTSEC1, SGMII_FM1_DTSEC2,
		PCIE2, PCIE2, SGMII_FM1_DTSEC4, SGMII_FM1_DTSEC5},
	[0xA7] = {PCIE1, SGMII_FM1_DTSEC3, SGMII_FM1_DTSEC1, SGMII_FM1_DTSEC2,
		 PCIE2, PCIE3, PCIE4, SGMII_FM1_DTSEC5},
	[0xAA] = {PCIE1, SGMII_FM1_DTSEC3, SGMII_FM1_DTSEC1, SGMII_FM1_DTSEC2,
		 PCIE2, PCIE3, SGMII_FM1_DTSEC4, SGMII_FM1_DTSEC5},
};

enum srds_prtcl serdes_get_prtcl(int serdes, int cfg, int lane)
{
	return serdes_cfg_tbl[cfg][lane];
}

int is_serdes_prtcl_valid(int serdes, u32 prtcl)
{
	int i;

	if (prtcl >= ARRAY_SIZE(serdes_cfg_tbl))
		return 0;

	for (i = 0; i < SRDS_MAX_LANES; i++) {
		if (serdes_cfg_tbl[prtcl][i] != NONE)
			return 1;
	}

	return 0;
}
