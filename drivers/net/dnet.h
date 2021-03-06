/*
 * Dave Ethernet Controller driver
 *
 * Copyright (C) 2008 Dave S.r.l. <www.dave.eu>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */

#ifndef __DRIVERS_DNET_H__
#define __DRIVERS_DNET_H__

#define DRIVERNAME "dnet"

struct dnet_registers {
	/* ALL DNET FIFO REGISTERS */
	u32 RX_LEN_FIFO;
	u32 RX_DATA_FIFO;
	u32 TX_LEN_FIFO;
	u32 TX_DATA_FIFO;
	u32 pad1[0x3c];
	/* ALL DNET CONTROL/STATUS REGISTERS */
	u32 VERCAPS;
	u32 INTR_SRC;
	u32 INTR_ENB;
	u32 RX_STATUS;
	u32 TX_STATUS;
	u32 RX_FRAMES_CNT;
	u32 TX_FRAMES_CNT;
	u32 RX_FIFO_TH;
	u32 TX_FIFO_TH;
	u32 SYS_CTL;
	u32 PAUSE_TMR;
	u32 RX_FIFO_WCNT;
	u32 TX_FIFO_WCNT;
	u32 pad2[0x33];
	/* ALL DNET MAC REGISTERS */
	u32 MACREG_DATA;	/* Mac-Reg Data */
	u32 MACREG_ADDR;	/* Mac-Reg Addr */
	u32 pad3[0x3e];
	/* ALL DNET RX STATISTICS COUNTERS  */
	u32 RX_PKT_IGNR_CNT;
	u32 RX_LEN_CHK_ERR_CNT;
	u32 RX_LNG_FRM_CNT;
	u32 RX_SHRT_FRM_CNT;
	u32 RX_IPG_VIOL_CNT;
	u32 RX_CRC_ERR_CNT;
	u32 RX_OK_PKT_CNT;
	u32 RX_CTL_FRM_CNT;
	u32 RX_PAUSE_FRM_CNT;
	u32 RX_MULTICAST_CNT;
	u32 RX_BROADCAST_CNT;
	u32 RX_VLAN_TAG_CNT;
	u32 RX_PRE_SHRINK_CNT;
	u32 RX_DRIB_NIB_CNT;
	u32 RX_UNSUP_OPCD_CNT;
	u32 RX_BYTE_CNT;
	u32 pad4[0x30];
	/* DNET TX STATISTICS COUNTERS */
	u32 TX_UNICAST_CNT;
	u32 TX_PAUSE_FRM_CNT;
	u32 TX_MULTICAST_CNT;
	u32 TX_BRDCAST_CNT;
	u32 TX_VLAN_TAG_CNT;
	u32 TX_BAD_FCS_CNT;
	u32 TX_JUMBO_CNT;
	u32 TX_BYTE_CNT;
};

/* SOME INTERNAL MAC-CORE REGISTER */
#define DNET_INTERNAL_MODE_REG			0x0
#define DNET_INTERNAL_RXTX_CONTROL_REG		0x2
#define DNET_INTERNAL_MAX_PKT_SIZE_REG		0x4
#define DNET_INTERNAL_IGP_REG			0x8
#define DNET_INTERNAL_MAC_ADDR_0_REG		0xa
#define DNET_INTERNAL_MAC_ADDR_1_REG		0xc
#define DNET_INTERNAL_MAC_ADDR_2_REG		0xe
#define DNET_INTERNAL_TX_RX_STS_REG		0x12
#define DNET_INTERNAL_GMII_MNG_CTL_REG		0x14
#define DNET_INTERNAL_GMII_MNG_DAT_REG		0x16

#define DNET_INTERNAL_GMII_MNG_CMD_FIN		(1 << 14)

#define DNET_INTERNAL_WRITE			(1 << 31)

/* MAC-CORE REGISTER FIELDS */

/* MAC-CORE MODE REGISTER FIELDS */
#define DNET_INTERNAL_MODE_GBITEN			(1 << 0)
#define DNET_INTERNAL_MODE_FCEN				(1 << 1)
#define DNET_INTERNAL_MODE_RXEN				(1 << 2)
#define DNET_INTERNAL_MODE_TXEN				(1 << 3)

/* MAC-CORE RXTX CONTROL REGISTER FIELDS */
#define DNET_INTERNAL_RXTX_CONTROL_RXSHORTFRAME		(1 << 8)
#define DNET_INTERNAL_RXTX_CONTROL_RXBROADCAST		(1 << 7)
#define DNET_INTERNAL_RXTX_CONTROL_RXMULTICAST		(1 << 4)
#define DNET_INTERNAL_RXTX_CONTROL_RXPAUSE		(1 << 3)
#define DNET_INTERNAL_RXTX_CONTROL_DISTXFCS		(1 << 2)
#define DNET_INTERNAL_RXTX_CONTROL_DISCFXFCS		(1 << 1)
#define DNET_INTERNAL_RXTX_CONTROL_ENPROMISC		(1 << 0)
#define DNET_INTERNAL_RXTX_CONTROL_DROPCONTROL		(1 << 6)
#define DNET_INTERNAL_RXTX_CONTROL_ENABLEHALFDUP	(1 << 5)

/* SYSTEM CONTROL REGISTER FIELDS */
#define DNET_SYS_CTL_IGNORENEXTPKT			(1 << 0)
#define DNET_SYS_CTL_SENDPAUSE				(1 << 2)
#define DNET_SYS_CTL_RXFIFOFLUSH			(1 << 3)
#define DNET_SYS_CTL_TXFIFOFLUSH			(1 << 4)

/* TX STATUS REGISTER FIELDS */
#define DNET_TX_STATUS_FIFO_ALMOST_EMPTY		(1 << 2)
#define DNET_TX_STATUS_FIFO_ALMOST_FULL			(1 << 1)

/* INTERRUPT SOURCE REGISTER FIELDS */
#define DNET_INTR_SRC_TX_PKTSENT			(1 << 0)
#define DNET_INTR_SRC_TX_FIFOAF				(1 << 1)
#define DNET_INTR_SRC_TX_FIFOAE				(1 << 2)
#define DNET_INTR_SRC_TX_DISCFRM			(1 << 3)
#define DNET_INTR_SRC_TX_FIFOFULL			(1 << 4)
#define DNET_INTR_SRC_RX_CMDFIFOAF			(1 << 8)
#define DNET_INTR_SRC_RX_CMDFIFOFF			(1 << 9)
#define DNET_INTR_SRC_RX_DATAFIFOFF			(1 << 10)
#define DNET_INTR_SRC_TX_SUMMARY			(1 << 16)
#define DNET_INTR_SRC_RX_SUMMARY			(1 << 17)
#define DNET_INTR_SRC_PHY				(1 << 19)

/* INTERRUPT ENABLE REGISTER FIELDS */
#define DNET_INTR_ENB_TX_PKTSENT			(1 << 0)
#define DNET_INTR_ENB_TX_FIFOAF				(1 << 1)
#define DNET_INTR_ENB_TX_FIFOAE				(1 << 2)
#define DNET_INTR_ENB_TX_DISCFRM			(1 << 3)
#define DNET_INTR_ENB_TX_FIFOFULL			(1 << 4)
#define DNET_INTR_ENB_RX_PKTRDY				(1 << 8)
#define DNET_INTR_ENB_RX_FIFOAF				(1 << 9)
#define DNET_INTR_ENB_RX_FIFOERR			(1 << 10)
#define DNET_INTR_ENB_RX_ERROR				(1 << 11)
#define DNET_INTR_ENB_RX_FIFOFULL			(1 << 12)
#define DNET_INTR_ENB_RX_FIFOAE				(1 << 13)
#define DNET_INTR_ENB_TX_SUMMARY			(1 << 16)
#define DNET_INTR_ENB_RX_SUMMARY			(1 << 17)
#define DNET_INTR_ENB_GLOBAL_ENABLE			(1 << 18)

/*
 * Capabilities. Used by the driver to know the capabilities that
 * the ethernet controller inside the FPGA have.
 */

#define DNET_HAS_MDIO		(1 << 0)
#define DNET_HAS_IRQ		(1 << 1)
#define DNET_HAS_GIGABIT	(1 << 2)
#define DNET_HAS_DMA		(1 << 3)

#define DNET_HAS_MII		(1 << 4) /* or GMII */
#define DNET_HAS_RMII		(1 << 5) /* or RGMII */

#define DNET_CAPS_MASK		0xFFFF

#define DNET_FIFO_SIZE		2048 /* 2K x 32 bit */
#define DNET_FIFO_TX_DATA_AF_TH	(DNET_FIFO_SIZE - 384) /* 384 = 1536 / 4 */
#define DNET_FIFO_TX_DATA_AE_TH	(384)

#define DNET_FIFO_RX_CMD_AF_TH	(1 << 16) /* just one frame inside the FIFO */

#endif
