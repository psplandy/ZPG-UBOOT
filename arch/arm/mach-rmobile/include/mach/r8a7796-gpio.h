/*
 * arch/arm/include/asm/arch-rcar_gen3/r8a7796-gpio.h
 *	This file defines pin function control of gpio.
 *
 * Copyright (C) 2016 Renesas Electronics Corporation
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */
#ifndef __ASM_R8A7796_GPIO_H__
#define __ASM_R8A7796_GPIO_H__

/* Pin Function Controller:
 * GPIO_FN_xx - GPIO used to select pin function
 * GPIO_GP_x_x - GPIO mapped to real I/O pin on CPU
 */
enum {
	GPIO_GP_0_0, GPIO_GP_0_1, GPIO_GP_0_2, GPIO_GP_0_3,
	GPIO_GP_0_4, GPIO_GP_0_5, GPIO_GP_0_6, GPIO_GP_0_7,
	GPIO_GP_0_8, GPIO_GP_0_9, GPIO_GP_0_10, GPIO_GP_0_11,
	GPIO_GP_0_12, GPIO_GP_0_13, GPIO_GP_0_14, GPIO_GP_0_15,

	GPIO_GP_1_0, GPIO_GP_1_1, GPIO_GP_1_2, GPIO_GP_1_3,
	GPIO_GP_1_4, GPIO_GP_1_5, GPIO_GP_1_6, GPIO_GP_1_7,
	GPIO_GP_1_8, GPIO_GP_1_9, GPIO_GP_1_10, GPIO_GP_1_11,
	GPIO_GP_1_12, GPIO_GP_1_13, GPIO_GP_1_14, GPIO_GP_1_15,
	GPIO_GP_1_16, GPIO_GP_1_17, GPIO_GP_1_18, GPIO_GP_1_19,
	GPIO_GP_1_20, GPIO_GP_1_21, GPIO_GP_1_22, GPIO_GP_1_23,
	GPIO_GP_1_24, GPIO_GP_1_25, GPIO_GP_1_26, GPIO_GP_1_27,
	GPIO_GP_1_28,

	GPIO_GP_2_0, GPIO_GP_2_1, GPIO_GP_2_2, GPIO_GP_2_3,
	GPIO_GP_2_4, GPIO_GP_2_5, GPIO_GP_2_6, GPIO_GP_2_7,
	GPIO_GP_2_8, GPIO_GP_2_9, GPIO_GP_2_10, GPIO_GP_2_11,
	GPIO_GP_2_12, GPIO_GP_2_13, GPIO_GP_2_14,

	GPIO_GP_3_0, GPIO_GP_3_1, GPIO_GP_3_2, GPIO_GP_3_3,
	GPIO_GP_3_4, GPIO_GP_3_5, GPIO_GP_3_6, GPIO_GP_3_7,
	GPIO_GP_3_8, GPIO_GP_3_9, GPIO_GP_3_10, GPIO_GP_3_11,
	GPIO_GP_3_12, GPIO_GP_3_13, GPIO_GP_3_14, GPIO_GP_3_15,

	GPIO_GP_4_0, GPIO_GP_4_1, GPIO_GP_4_2, GPIO_GP_4_3,
	GPIO_GP_4_4, GPIO_GP_4_5, GPIO_GP_4_6, GPIO_GP_4_7,
	GPIO_GP_4_8, GPIO_GP_4_9, GPIO_GP_4_10, GPIO_GP_4_11,
	GPIO_GP_4_12, GPIO_GP_4_13, GPIO_GP_4_14, GPIO_GP_4_15,
	GPIO_GP_4_16, GPIO_GP_4_17,

	GPIO_GP_5_0, GPIO_GP_5_1, GPIO_GP_5_2, GPIO_GP_5_3,
	GPIO_GP_5_4, GPIO_GP_5_5, GPIO_GP_5_6, GPIO_GP_5_7,
	GPIO_GP_5_8, GPIO_GP_5_9, GPIO_GP_5_10, GPIO_GP_5_11,
	GPIO_GP_5_12, GPIO_GP_5_13, GPIO_GP_5_14, GPIO_GP_5_15,
	GPIO_GP_5_16, GPIO_GP_5_17, GPIO_GP_5_18, GPIO_GP_5_19,
	GPIO_GP_5_20, GPIO_GP_5_21, GPIO_GP_5_22, GPIO_GP_5_23,
	GPIO_GP_5_24, GPIO_GP_5_25,

	GPIO_GP_6_0, GPIO_GP_6_1, GPIO_GP_6_2, GPIO_GP_6_3,
	GPIO_GP_6_4, GPIO_GP_6_5, GPIO_GP_6_6, GPIO_GP_6_7,
	GPIO_GP_6_8, GPIO_GP_6_9, GPIO_GP_6_10, GPIO_GP_6_11,
	GPIO_GP_6_12, GPIO_GP_6_13, GPIO_GP_6_14, GPIO_GP_6_15,
	GPIO_GP_6_16, GPIO_GP_6_17, GPIO_GP_6_18, GPIO_GP_6_19,
	GPIO_GP_6_20, GPIO_GP_6_21, GPIO_GP_6_22, GPIO_GP_6_23,
	GPIO_GP_6_24, GPIO_GP_6_25, GPIO_GP_6_26, GPIO_GP_6_27,
	GPIO_GP_6_28, GPIO_GP_6_29, GPIO_GP_6_30, GPIO_GP_6_31,

	GPIO_GP_7_0, GPIO_GP_7_1, GPIO_GP_7_2, GPIO_GP_7_3,

	/* GPSR0 */
	GPIO_GFN_D15,
	GPIO_GFN_D14,
	GPIO_GFN_D13,
	GPIO_GFN_D12,
	GPIO_GFN_D11,
	GPIO_GFN_D10,
	GPIO_GFN_D9,
	GPIO_GFN_D8,
	GPIO_GFN_D7,
	GPIO_GFN_D6,
	GPIO_GFN_D5,
	GPIO_GFN_D4,
	GPIO_GFN_D3,
	GPIO_GFN_D2,
	GPIO_GFN_D1,
	GPIO_GFN_D0,

	/* GPSR1 */
	GPIO_GFN_CLKOUT,
	GPIO_GFN_EX_WAIT0_A,
	GPIO_GFN_WE1x,
	GPIO_GFN_WE0x,
	GPIO_GFN_RD_WRx,
	GPIO_GFN_RDx,
	GPIO_GFN_BSx,
	GPIO_GFN_CS1x_A26,
	GPIO_GFN_CS0x,
	GPIO_GFN_A19,
	GPIO_GFN_A18,
	GPIO_GFN_A17,
	GPIO_GFN_A16,
	GPIO_GFN_A15,
	GPIO_GFN_A14,
	GPIO_GFN_A13,
	GPIO_GFN_A12,
	GPIO_GFN_A11,
	GPIO_GFN_A10,
	GPIO_GFN_A9,
	GPIO_GFN_A8,
	GPIO_GFN_A7,
	GPIO_GFN_A6,
	GPIO_GFN_A5,
	GPIO_GFN_A4,
	GPIO_GFN_A3,
	GPIO_GFN_A2,
	GPIO_GFN_A1,
	GPIO_GFN_A0,

	/* GPSR2 */
	GPIO_GFN_AVB_AVTP_CAPTURE_A,
	GPIO_GFN_AVB_AVTP_MATCH_A,
	GPIO_GFN_AVB_LINK,
	GPIO_GFN_AVB_PHY_INT,
	GPIO_GFN_AVB_MAGIC,
	GPIO_GFN_AVB_MDC,
	GPIO_GFN_PWM2_A,
	GPIO_GFN_PWM1_A,
	GPIO_GFN_PWM0,
	GPIO_GFN_IRQ5,
	GPIO_GFN_IRQ4,
	GPIO_GFN_IRQ3,
	GPIO_GFN_IRQ2,
	GPIO_GFN_IRQ1,
	GPIO_GFN_IRQ0,

	/* GPSR3 */
	GPIO_GFN_SD1_WP,
	GPIO_GFN_SD1_CD,
	GPIO_GFN_SD0_WP,
	GPIO_GFN_SD0_CD,
	GPIO_GFN_SD1_DAT3,
	GPIO_GFN_SD1_DAT2,
	GPIO_GFN_SD1_DAT1,
	GPIO_GFN_SD1_DAT0,
	GPIO_GFN_SD1_CMD,
	GPIO_GFN_SD1_CLK,
	GPIO_GFN_SD0_DAT3,
	GPIO_GFN_SD0_DAT2,
	GPIO_GFN_SD0_DAT1,
	GPIO_GFN_SD0_DAT0,
	GPIO_GFN_SD0_CMD,
	GPIO_GFN_SD0_CLK,

	/* GPSR4 */
	GPIO_GFN_SD3_DS,
	GPIO_GFN_SD3_DAT7,
	GPIO_GFN_SD3_DAT6,
	GPIO_GFN_SD3_DAT5,
	GPIO_GFN_SD3_DAT4,
	GPIO_FN_SD3_DAT3,
	GPIO_FN_SD3_DAT2,
	GPIO_FN_SD3_DAT1,
	GPIO_FN_SD3_DAT0,
	GPIO_FN_SD3_CMD,
	GPIO_FN_SD3_CLK,
	GPIO_GFN_SD2_DS,
	GPIO_GFN_SD2_DAT3,
	GPIO_GFN_SD2_DAT2,
	GPIO_GFN_SD2_DAT1,
	GPIO_GFN_SD2_DAT0,
	GPIO_FN_SD2_CMD,
	GPIO_GFN_SD2_CLK,

	/* GPSR5 */
	GPIO_GFN_MLB_DAT,
	GPIO_GFN_MLB_SIG,
	GPIO_GFN_MLB_CLK,
	GPIO_FN_MSIOF0_RXD,
	GPIO_GFN_MSIOF0_SS2,
	GPIO_FN_MSIOF0_TXD,
	GPIO_GFN_MSIOF0_SS1,
	GPIO_GFN_MSIOF0_SYNC,
	GPIO_FN_MSIOF0_SCK,
	GPIO_GFN_HRTS0x,
	GPIO_GFN_HCTS0x,
	GPIO_GFN_HTX0,
	GPIO_GFN_HRX0,
	GPIO_GFN_HSCK0,
	GPIO_GFN_RX2_A,
	GPIO_GFN_TX2_A,
	GPIO_GFN_SCK2,
	GPIO_GFN_RTS1x_TANS,
	GPIO_GFN_CTS1x,
	GPIO_GFN_TX1_A,
	GPIO_GFN_RX1_A,
	GPIO_GFN_RTS0x_TANS,
	GPIO_GFN_CTS0x,
	GPIO_GFN_TX0,
	GPIO_GFN_RX0,
	GPIO_GFN_SCK0,

	/* GPSR6 */
	GPIO_GFN_GP6_31,
	GPIO_GFN_GP6_30,
	GPIO_GFN_USB30_OVC,
	GPIO_GFN_USB30_PWEN,
	GPIO_GFN_USB1_OVC,
	GPIO_GFN_USB1_PWEN,
	GPIO_GFN_USB0_OVC,
	GPIO_GFN_USB0_PWEN,
	GPIO_GFN_AUDIO_CLKB_B,
	GPIO_GFN_AUDIO_CLKA_A,
	GPIO_GFN_SSI_SDATA9_A,
	GPIO_GFN_SSI_SDATA8,
	GPIO_GFN_SSI_SDATA7,
	GPIO_GFN_SSI_WS78,
	GPIO_GFN_SSI_SCK78,
	GPIO_GFN_SSI_SDATA6,
	GPIO_GFN_SSI_WS6,
	GPIO_GFN_SSI_SCK6,
	GPIO_FN_SSI_SDATA5,
	GPIO_FN_SSI_WS5,
	GPIO_FN_SSI_SCK5,
	GPIO_GFN_SSI_SDATA4,
	GPIO_GFN_SSI_WS4,
	GPIO_GFN_SSI_SCK4,
	GPIO_GFN_SSI_SDATA3,
	GPIO_GFN_SSI_WS34,
	GPIO_GFN_SSI_SCK34,
	GPIO_GFN_SSI_SDATA2_A,
	GPIO_GFN_SSI_SDATA1_A,
	GPIO_GFN_SSI_SDATA0,
	GPIO_GFN_SSI_WS01239,
	GPIO_GFN_SSI_SCK01239,

	/* GPSR7 */
	GPIO_FN_HDMI1_CEC,
	GPIO_FN_HDMI0_CEC,
	GPIO_FN_AVS2,
	GPIO_FN_AVS1,

	/* IPSR0 */
	GPIO_IFN_AVB_MDC,
	GPIO_FN_MSIOF2_SS2_C,
	GPIO_IFN_AVB_MAGIC,
	GPIO_FN_MSIOF2_SS1_C,
	GPIO_FN_SCK4_A,
	GPIO_IFN_AVB_PHY_INT,
	GPIO_FN_MSIOF2_SYNC_C,
	GPIO_FN_RX4_A,
	GPIO_IFN_AVB_LINK,
	GPIO_FN_MSIOF2_SCK_C,
	GPIO_FN_TX4_A,
	GPIO_IFN_AVB_AVTP_MATCH_A,
	GPIO_FN_MSIOF2_RXD_C,
	GPIO_FN_CTS4x_A,
	GPIO_IFN_AVB_AVTP_CAPTURE_A,
	GPIO_FN_MSIOF2_TXD_C,
	GPIO_FN_RTS4x_TANS_A,
	GPIO_IFN_IRQ0,
	GPIO_FN_QPOLB,
	GPIO_FN_DU_CDE,
	GPIO_FN_VI4_DATA0_B,
	GPIO_FN_CAN0_TX_B,
	GPIO_FN_CANFD0_TX_B,
	GPIO_FN_MSIOF3_SS2_E,
	GPIO_IFN_IRQ1,
	GPIO_FN_QPOLA,
	GPIO_FN_DU_DISP,
	GPIO_FN_VI4_DATA1_B,
	GPIO_FN_CAN0_RX_B,
	GPIO_FN_CANFD0_RX_B,
	GPIO_FN_MSIOF3_SS1_E,

	/* IPSR1 */
	GPIO_IFN_IRQ2,
	GPIO_FN_QCPV_QDE,
	GPIO_FN_DU_EXODDF_DU_ODDF_DISP_CDE,
	GPIO_FN_VI4_DATA2_B,
	GPIO_FN_MSIOF3_SYNC_E,
	GPIO_FN_PWM3_B,
	GPIO_IFN_IRQ3,
	GPIO_FN_QSTVB_QVE,
	GPIO_FN_DU_DOTCLKOUT1,
	GPIO_FN_VI4_DATA3_B,
	GPIO_FN_MSIOF3_SCK_E,
	GPIO_FN_PWM4_B,
	GPIO_IFN_IRQ4,
	GPIO_FN_QSTH_QHS,
	GPIO_FN_DU_EXHSYNC_DU_HSYNC,
	GPIO_FN_VI4_DATA4_B,
	GPIO_FN_MSIOF3_RXD_E,
	GPIO_FN_PWM5_B,
	GPIO_IFN_IRQ5,
	GPIO_FN_QSTB_QHE,
	GPIO_FN_DU_EXVSYNC_DU_VSYNC,
	GPIO_FN_VI4_DATA5_B,
	GPIO_FN_MSIOF3_TXD_E,
	GPIO_FN_PWM6_B,
	GPIO_IFN_PWM0,
	GPIO_FN_AVB_AVTP_PPS,
	GPIO_FN_VI4_DATA6_B,
	GPIO_FN_IECLK_B,
	GPIO_IFN_PWM1_A,
	GPIO_FN_HRX3_D,
	GPIO_FN_VI4_DATA7_B,
	GPIO_FN_IERX_B,
	GPIO_IFN_PWM2_A,
	GPIO_FN_PWMFSW0,
	GPIO_FN_HTX3_D,
	GPIO_FN_IETX_B,
	GPIO_IFN_A0,
	GPIO_FN_LCDOUT16,
	GPIO_FN_MSIOF3_SYNC_B,
	GPIO_FN_VI4_DATA8,
	GPIO_FN_DU_DB0,
	GPIO_FN_PWM3_A,

	/* IPSR2 */
	GPIO_IFN_A1,
	GPIO_FN_LCDOUT17,
	GPIO_FN_MSIOF3_TXD_B,
	GPIO_FN_VI4_DATA9,
	GPIO_FN_DU_DB1,
	GPIO_FN_PWM4_A,
	GPIO_IFN_A2,
	GPIO_FN_LCDOUT18,
	GPIO_FN_MSIOF3_SCK_B,
	GPIO_FN_VI4_DATA10,
	GPIO_FN_DU_DB2,
	GPIO_FN_PWM5_A,
	GPIO_IFN_A3,
	GPIO_FN_LCDOUT19,
	GPIO_FN_MSIOF3_RXD_B,
	GPIO_FN_VI4_DATA11,
	GPIO_FN_DU_DB3,
	GPIO_FN_PWM6_A,
	GPIO_IFN_A4,
	GPIO_FN_LCDOUT20,
	GPIO_FN_MSIOF3_SS1_B,
	GPIO_FN_VI4_DATA12,
	GPIO_FN_VI5_DATA12,
	GPIO_FN_DU_DB4,
	GPIO_IFN_A5,
	GPIO_FN_LCDOUT21,
	GPIO_FN_MSIOF3_SS2_B,
	GPIO_FN_SCK4_B,
	GPIO_FN_VI4_DATA13,
	GPIO_FN_VI5_DATA13,
	GPIO_FN_DU_DB5,
	GPIO_IFN_A6,
	GPIO_FN_LCDOUT22,
	GPIO_FN_MSIOF2_SS1_A,
	GPIO_FN_RX4_B,
	GPIO_FN_VI4_DATA14,
	GPIO_FN_VI5_DATA14,
	GPIO_FN_DU_DB6,
	GPIO_IFN_A7,
	GPIO_FN_LCDOUT23,
	GPIO_FN_MSIOF2_SS2_A,
	GPIO_FN_TX4_B,
	GPIO_FN_VI4_DATA15,
	GPIO_FN_V15_DATA15,
	GPIO_FN_DU_DB7,
	GPIO_IFN_A8,
	GPIO_FN_RX3_B,
	GPIO_FN_MSIOF2_SYNC_A,
	GPIO_FN_HRX4_B,
	GPIO_FN_SDA6_A,
	GPIO_FN_AVB_AVTP_MATCH_B,
	GPIO_FN_PWM1_B,

	/* IPSR3 */
	GPIO_IFN_A9,
	GPIO_FN_MSIOF2_SCK_A,
	GPIO_FN_CTS4x_B,
	GPIO_FN_VI5_VSYNCx,
	GPIO_IFN_A10,
	GPIO_FN_MSIOF2_RXD_A,
	GPIO_FN_RTS4n_TANS_B,
	GPIO_FN_VI5_HSYNCx,
	GPIO_IFN_A11,
	GPIO_FN_TX3_B,
	GPIO_FN_MSIOF2_TXD_A,
	GPIO_FN_HTX4_B,
	GPIO_FN_HSCK4,
	GPIO_FN_VI5_FIELD,
	GPIO_FN_SCL6_A,
	GPIO_FN_AVB_AVTP_CAPTURE_B,
	GPIO_FN_PWM2_B,
	GPIO_FN_SPV_EVEN,
	GPIO_IFN_A12,
	GPIO_FN_LCDOUT12,
	GPIO_FN_MSIOF3_SCK_C,
	GPIO_FN_HRX4_A,
	GPIO_FN_VI5_DATA8,
	GPIO_FN_DU_DG4,
	GPIO_IFN_A13,
	GPIO_FN_LCDOUT13,
	GPIO_FN_MSIOF3_SYNC_C,
	GPIO_FN_HTX4_A,
	GPIO_FN_VI5_DATA9,
	GPIO_FN_DU_DG5,
	GPIO_IFN_A14,
	GPIO_FN_LCDOUT14,
	GPIO_FN_MSIOF3_RXD_C,
	GPIO_FN_HCTS4x,
	GPIO_FN_VI5_DATA10,
	GPIO_FN_DU_DG6,
	GPIO_IFN_A15,
	GPIO_FN_LCDOUT15,
	GPIO_FN_MSIOF3_TXD_C,
	GPIO_FN_HRTS4x,
	GPIO_FN_VI5_DATA11,
	GPIO_FN_DU_DG7,
	GPIO_IFN_A16,
	GPIO_FN_LCDOUT8,
	GPIO_FN_VI4_FIELD,
	GPIO_FN_DU_DG0,

	/* IPSR4 */
	GPIO_IFN_A17,
	GPIO_FN_LCDOUT9,
	GPIO_FN_VI4_VSYNCx,
	GPIO_FN_DU_DG1,
	GPIO_IFN_A18,
	GPIO_FN_LCDOUT10,
	GPIO_FN_VI4_HSYNCx,
	GPIO_FN_DU_DG2,
	GPIO_IFN_A19,
	GPIO_FN_LCDOUT11,
	GPIO_FN_VI4_CLKENB,
	GPIO_FN_DU_DG3,
	GPIO_IFN_CS0x,
	GPIO_FN_VI5_CLKENB,
	GPIO_IFN_CS1x_A26,
	GPIO_FN_VI5_CLK,
	GPIO_FN_EX_WAIT0_B,
	GPIO_IFN_BSx,
	GPIO_FN_QSTVA_QVS,
	GPIO_FN_MSIOF3_SCK_D,
	GPIO_FN_SCK3,
	GPIO_FN_HSCK3,
	GPIO_FN_CAN1_TX,
	GPIO_FN_CANFD1_TX,
	GPIO_FN_IETX_A,
	GPIO_IFN_RDx,
	GPIO_FN_MSIOF3_SYNC_D,
	GPIO_FN_RX3_A,
	GPIO_FN_HRX3_A,
	GPIO_FN_CAN0_TX_A,
	GPIO_FN_CANFD0_TX_A,
	GPIO_IFN_RD_WRx,
	GPIO_FN_MSIOF3_RXD_D,
	GPIO_FN_TX3_A,
	GPIO_FN_HTX3_A,
	GPIO_FN_CAN0_RX_A,
	GPIO_FN_CANFD0_RX_A,

	/* IPSR5 */
	GPIO_IFN_WE0x,
	GPIO_FN_MSIIOF3_TXD_D,
	GPIO_FN_CTS3x,
	GPIO_FN_HCTS3x,
	GPIO_FN_SCL6_B,
	GPIO_FN_CAN_CLK,
	GPIO_FN_IECLK_A,
	GPIO_IFN_WE1x,
	GPIO_FN_MSIOF3_SS1_D,
	GPIO_FN_RTS3x_TANS,
	GPIO_FN_HRTS3x,
	GPIO_FN_SDA6_B,
	GPIO_FN_CAN1_RX,
	GPIO_FN_CANFD1_RX,
	GPIO_FN_IERX_A,
	GPIO_IFN_EX_WAIT0_A,
	GPIO_FN_QCLK,
	GPIO_FN_VI4_CLK,
	GPIO_FN_DU_DOTCLKOUT0,
	GPIO_IFN_D0,
	GPIO_FN_MSIOF2_SS1_B,
	GPIO_FN_MSIOF3_SCK_A,
	GPIO_FN_VI4_DATA16,
	GPIO_FN_VI5_DATA0,
	GPIO_IFN_D1,
	GPIO_FN_MSIOF2_SS2_B,
	GPIO_FN_MSIOF3_SYNC_A,
	GPIO_FN_VI4_DATA17,
	GPIO_FN_VI5_DATA1,
	GPIO_IFN_D2,
	GPIO_FN_MSIOF3_RXD_A,
	GPIO_FN_VI4_DATA18,
	GPIO_FN_VI5_DATA2,
	GPIO_IFN_D3,
	GPIO_FN_MSIOF3_TXD_A,
	GPIO_FN_VI4_DATA19,
	GPIO_FN_VI5_DATA3,
	GPIO_IFN_D4,
	GPIO_FN_MSIOF2_SCK_B,
	GPIO_FN_VI4_DATA20,
	GPIO_FN_VI5_DATA4,

	/* IPSR6 */
	GPIO_IFN_D5,
	GPIO_FN_MSIOF2_SYNC_B,
	GPIO_FN_VI4_DATA21,
	GPIO_FN_VI5_DATA5,
	GPIO_IFN_D6,
	GPIO_FN_MSIOF2_RXD_B,
	GPIO_FN_VI4_DATA22,
	GPIO_FN_VI5_DATA6,
	GPIO_IFN_D7,
	GPIO_FN_MSIOF2_TXD_B,
	GPIO_FN_VI4_DATA23,
	GPIO_FN_VI5_DATA7,
	GPIO_IFN_D8,
	GPIO_FN_LCDOUT0,
	GPIO_FN_MSIOF2_SCK_D,
	GPIO_FN_SCK4_C,
	GPIO_FN_VI4_DATA0_A,
	GPIO_FN_DU_DR0,
	GPIO_IFN_D9,
	GPIO_FN_LCDOUT1,
	GPIO_FN_MSIOF2_SYNC_D,
	GPIO_FN_VI4_DATA1_A,
	GPIO_FN_DU_DR1,
	GPIO_IFN_D10,
	GPIO_FN_LCDOUT2,
	GPIO_FN_MSIOF2_RXD_D,
	GPIO_FN_HRX3_B,
	GPIO_FN_VI4_DATA2_A,
	GPIO_FN_CTS4x_C,
	GPIO_FN_DU_DR2,
	GPIO_IFN_D11,
	GPIO_FN_LCDOUT3,
	GPIO_FN_MSIOF2_TXD_D,
	GPIO_FN_HTX3_B,
	GPIO_FN_VI4_DATA3_A,
	GPIO_FN_RTS4x_TANS_C,
	GPIO_FN_DU_DR3,
	GPIO_IFN_D12,
	GPIO_FN_LCDOUT4,
	GPIO_FN_MSIOF2_SS1_D,
	GPIO_FN_RX4_C,
	GPIO_FN_VI4_DATA4_A,
	GPIO_FN_DU_DR4,

	/* IPSR7 */
	GPIO_IFN_D13,
	GPIO_FN_LCDOUT5,
	GPIO_FN_MSIOF2_SS2_D,
	GPIO_FN_TX4_C,
	GPIO_FN_VI4_DATA5_A,
	GPIO_FN_DU_DR5,
	GPIO_IFN_D14,
	GPIO_FN_LCDOUT6,
	GPIO_FN_MSIOF3_SS1_A,
	GPIO_FN_HRX3_C,
	GPIO_FN_VI4_DATA6_A,
	GPIO_FN_DU_DR6,
	GPIO_FN_SCL6_C,
	GPIO_IFN_D15,
	GPIO_FN_LCDOUT7,
	GPIO_FN_MSIOF3_SS2_A,
	GPIO_FN_HTX3_C,
	GPIO_FN_VI4_DATA7_A,
	GPIO_FN_DU_DR7,
	GPIO_FN_SDA6_C,
	GPIO_FN_FSCLKST,
	GPIO_IFN_SD0_CLK,
	GPIO_FN_MSIOF1_SCK_E,
	GPIO_FN_STP_OPWM_0_B,
	GPIO_IFN_SD0_CMD,
	GPIO_FN_MSIOF1_SYNC_E,
	GPIO_FN_STP_IVCXO27_0_B,
	GPIO_IFN_SD0_DAT0,
	GPIO_FN_MSIOF1_RXD_E,
	GPIO_FN_TS_SCK0_B,
	GPIO_FN_STP_ISCLK_0_B,
	GPIO_IFN_SD0_DAT1,
	GPIO_FN_MSIOF1_TXD_E,
	GPIO_FN_TS_SPSYNC0_B,
	GPIO_FN_STP_ISSYNC_0_B,

	/* IPSR8 */
	GPIO_IFN_SD0_DAT2,
	GPIO_FN_MSIOF1_SS1_E,
	GPIO_FN_TS_SDAT0_B,
	GPIO_FN_STP_ISD_0_B,

	GPIO_IFN_SD0_DAT3,
	GPIO_FN_MSIOF1_SS2_E,
	GPIO_FN_TS_SDEN0_B,
	GPIO_FN_STP_ISEN_0_B,

	GPIO_IFN_SD1_CLK,
	GPIO_FN_MSIOF1_SCK_G,
	GPIO_FN_SIM0_CLK_A,

	GPIO_IFN_SD1_CMD,
	GPIO_FN_MSIOF1_SYNC_G,
	GPIO_FN_NFCEx_B,
	GPIO_FN_SIM0_D_A,
	GPIO_FN_STP_IVCXO27_1_B,

	GPIO_IFN_SD1_DAT0,
	GPIO_FN_SD2_DAT4,
	GPIO_FN_MSIOF1_RXD_G,
	GPIO_FN_NFWPx_B,
	GPIO_FN_TS_SCK1_B,
	GPIO_FN_STP_ISCLK_1_B,

	GPIO_IFN_SD1_DAT1,
	GPIO_FN_SD2_DAT5,
	GPIO_FN_MSIOF1_TXD_G,
	GPIO_FN_NFDATA14_B,
	GPIO_FN_TS_SPSYNC1_B,
	GPIO_FN_STP_ISSYNC_1_B,

	GPIO_IFN_SD1_DAT2,
	GPIO_FN_SD2_DAT6,
	GPIO_FN_MSIOF1_SS1_G,
	GPIO_FN_NFDATA15_B,
	GPIO_FN_TS_SDAT1_B,
	GPIO_FN_STP_IOD_1_B,

	GPIO_IFN_SD1_DAT3,
	GPIO_FN_SD2_DAT7,
	GPIO_FN_MSIOF1_SS2_G,
	GPIO_FN_NFRBx_B,
	GPIO_FN_TS_SDEN1_B,
	GPIO_FN_STP_ISEN_1_B,

	/* IPSR9 */
	GPIO_IFN_SD2_CLK,
	GPIO_FN_NFDATA8,

	GPIO_IFN_SD2_CMD,
	GPIO_FN_NFDATA9,

	GPIO_IFN_SD2_DAT0,
	GPIO_FN_NFDATA10,

	GPIO_IFN_SD2_DAT1,
	GPIO_FN_NFDATA11,

	GPIO_IFN_SD2_DAT2,
	GPIO_FN_NFDATA12,

	GPIO_IFN_SD2_DAT3,
	GPIO_FN_NFDATA13,

	GPIO_IFN_SD2_DS,
	GPIO_FN_NFALE,

	GPIO_IFN_SD3_CLK,
	GPIO_FN_NFWEx,

	/* IPSR10 */
	GPIO_IFN_SD3_CMD,
	GPIO_FN_NFREx,

	GPIO_IFN_SD3_DAT0,
	GPIO_FN_NFDATA0,

	GPIO_IFN_SD3_DAT1,
	GPIO_FN_NFDATA1,

	GPIO_IFN_SD3_DAT2,
	GPIO_FN_NFDATA2,

	GPIO_IFN_SD3_DAT3,
	GPIO_FN_NFDATA3,

	GPIO_IFN_SD3_DAT4,
	GPIO_FN_SD2_CD_A,
	GPIO_FN_NFDATA4,

	GPIO_IFN_SD3_DAT5,
	GPIO_FN_SD2_WP_A,
	GPIO_FN_NFDATA5,

	GPIO_IFN_SD3_DAT6,
	GPIO_FN_SD3_CD,
	GPIO_FN_NFDATA6,

	/* IPSR11 */
	GPIO_IFN_SD3_DAT7,
	GPIO_FN_SD3_WP,
	GPIO_FN_NFDATA7,

	GPIO_IFN_SD3_DS,
	GPIO_FN_NFCLE,

	GPIO_IFN_SD0_CD,
	GPIO_FN_NFDATA14_A,
	GPIO_FN_SCL2_B,
	GPIO_FN_SIM0_RST_A,

	GPIO_IFN_SD0_WP,
	GPIO_FN_NFDATA15_A,
	GPIO_FN_SDA2_B,

	GPIO_IFN_SD1_CD,
	GPIO_FN_NFRBx_A,
	GPIO_FN_SIM0_CLK_B,

	GPIO_IFN_SD1_WP,
	GPIO_FN_NFCEx_A,
	GPIO_FN_SIM0_D_B,

	GPIO_IFN_SCK0,
	GPIO_FN_HSCK1_B,
	GPIO_FN_MSIOF1_SS2_B,
	GPIO_FN_AUDIO_CLKC_B,
	GPIO_FN_SDA2_A,
	GPIO_FN_SIM0_RST_B,
	GPIO_FN_STP_OPWM_0_C,
	GPIO_FN_RIF0_CLK_B,
	GPIO_FN_ADICHS2,
	GPIO_FN_SCK5_B,

	GPIO_IFN_RX0,
	GPIO_FN_HRX1_B,
	GPIO_FN_TS_SCK0_C,
	GPIO_FN_STP_ISCLK_0_C,
	GPIO_FN_RIF0_D0_B,

	/* IPSR12 */
	GPIO_IFN_TX0,
	GPIO_FN_HTX1_B,
	GPIO_FN_TS_SPSYNC0_C,
	GPIO_FN_STP_ISSYNC_0_C,
	GPIO_FN_RIF0_D1_B,

	GPIO_IFN_CTS0x,
	GPIO_FN_HCTS1x_B,
	GPIO_FN_MSIOF1_SYNC_B,
	GPIO_FN_TS_SPSYNC1_C,
	GPIO_FN_STP_ISSYNC_1_C,
	GPIO_FN_RIF1_SYNC_B,
	GPIO_FN_AUDIO_CLKOUT_C,
	GPIO_FN_ADICS_SAMP,

	GPIO_IFN_RTS0x_TANS,
	GPIO_FN_HRTS1x_B,
	GPIO_FN_MSIOF1_SS1_B,
	GPIO_FN_AUDIO_CLKA_B,
	GPIO_FN_SCL2_A,
	GPIO_FN_STP_IVCXO27_1_C,
	GPIO_FN_RIF0_SYNC_B,
	GPIO_FN_ADICHS1,

	GPIO_IFN_RX1_A,
	GPIO_FN_HRX1_A,
	GPIO_FN_TS_SDAT0_C,
	GPIO_FN_STP_ISD_0_C,
	GPIO_FN_RIF1_CLK_C,

	GPIO_IFN_TX1_A,
	GPIO_FN_HTX1_A,
	GPIO_FN_TS_SDEN0_C,
	GPIO_FN_STP_ISEN_0_C,
	GPIO_FN_RIF1_D0_C,

	GPIO_IFN_CTS1x,
	GPIO_FN_HCTS1x_A,
	GPIO_FN_MSIOF1_RXD_B,
	GPIO_FN_TS_SDEN1_C,
	GPIO_FN_STP_ISEN_1_C,
	GPIO_FN_RIF1_D0_B,
	GPIO_FN_ADIDATA,

	GPIO_IFN_RTS1x_TANS,
	GPIO_FN_HRTS1x_A,
	GPIO_FN_MSIOF1_TXD_B,
	GPIO_FN_TS_SDAT1_C,
	GPIO_FN_STP_ISD_1_C,
	GPIO_FN_RIF1_D1_B,
	GPIO_FN_ADICHS0,

	GPIO_IFN_SCK2,
	GPIO_FN_SCIF_CLK_B,
	GPIO_FN_MSIOF1_SCK_B,
	GPIO_FN_TS_SCK1_C,
	GPIO_FN_STP_ISCLK_1_C,
	GPIO_FN_RIF1_CLK_B,
	GPIO_FN_ADICLK,

	/* IPSR13 */
	GPIO_IFN_TX2_A,
	GPIO_FN_SD2_CD_B,
	GPIO_FN_SCL1_A,
	GPIO_FN_FMCLK_A,
	GPIO_FN_RIF1_D1_C,
	GPIO_FN_FSO_CFE_0_B,

	GPIO_IFN_RX2_A,
	GPIO_FN_SD2_WP_B,
	GPIO_FN_SDA1_A,
	GPIO_FN_FMIN_A,
	GPIO_FN_RIF1_SYNC_C,
	GPIO_FN_FSO_CEF_1_B,

	GPIO_IFN_HSCK0,
	GPIO_FN_MSIOF1_SCK_D,
	GPIO_FN_AUDIO_CLKB_A,
	GPIO_FN_SSI_SDATA1_B,
	GPIO_FN_TS_SCK0_D,
	GPIO_FN_STP_ISCLK_0_D,
	GPIO_FN_RIF0_CLK_C,
	GPIO_FN_RX5_B,

	GPIO_IFN_HRX0,
	GPIO_FN_MSIOF1_RXD_D,
	GPIO_FN_SS1_SDATA2_B,
	GPIO_FN_TS_SDEN0_D,
	GPIO_FN_STP_ISEN_0_D,
	GPIO_FN_RIF0_D0_C,

	GPIO_IFN_HTX0,
	GPIO_FN_MSIOF1_TXD_D,
	GPIO_FN_SSI_SDATA9_B,
	GPIO_FN_TS_SDAT0_D,
	GPIO_FN_STP_ISD_0_D,
	GPIO_FN_RIF0_D1_C,

	GPIO_IFN_HCTS0x,
	GPIO_FN_RX2_B,
	GPIO_FN_MSIOF1_SYNC_D,
	GPIO_FN_SSI_SCK9_A,
	GPIO_FN_TS_SPSYNC0_D,
	GPIO_FN_STP_ISSYNC_0_D,
	GPIO_FN_RIF0_SYNC_C,
	GPIO_FN_AUDIO_CLKOUT1_A,

	GPIO_IFN_HRTS0x,
	GPIO_FN_TX2_B,
	GPIO_FN_MSIOF1_SS1_D,
	GPIO_FN_SSI_WS9_A,
	GPIO_FN_STP_IVCXO27_0_D,
	GPIO_FN_BPFCLK_A,
	GPIO_FN_AUDIO_CLKOUT2_A,

	GPIO_IFN_MSIOF0_SYNC,
	GPIO_FN_AUDIO_CLKOUT_A,
	GPIO_FN_TX5_B,
	GPIO_FN_BPFCLK_D,

	/* IPSR14 */
	GPIO_IFN_MSIOF0_SS1,
	GPIO_FN_RX5_A,
	GPIO_FN_NFWPx_A,
	GPIO_FN_AUDIO_CLKA_C,
	GPIO_FN_SSI_SCK2_A,
	GPIO_FN_STP_IVCXO27_0_C,
	GPIO_FN_AUDIO_CLKOUT3_A,
	GPIO_FN_TCLK1_B,

	GPIO_IFN_MSIOF0_SS2,
	GPIO_FN_TX5_A,
	GPIO_FN_MSIOF1_SS2_D,
	GPIO_FN_AUDIO_CLKC_A,
	GPIO_FN_SSI_WS2_A,
	GPIO_FN_STP_OPWM_0_D,
	GPIO_FN_AUDIO_CLKOUT_D,
	GPIO_FN_SPEEDIN_B,

	GPIO_IFN_MLB_CLK,
	GPIO_FN_MSIOF1_SCK_F,
	GPIO_FN_SCL1_B,

	GPIO_IFN_MLB_SIG,
	GPIO_FN_RX1_B,
	GPIO_FN_MSIOF1_SYNC_F,
	GPIO_FN_SDA1_B,

	GPIO_IFN_MLB_DAT,
	GPIO_FN_TX1_B,
	GPIO_FN_MSIOF1_RXD_F,

	GPIO_IFN_SSI_SCK0129,
	GPIO_FN_MSIOF1_TXD_F,
	GPIO_FN_MOUT0,

	GPIO_IFN_SSI_WS0129,
	GPIO_FN_MSIOF1_SS1_F,
	GPIO_FN_MOUT1,

	GPIO_IFN_SSI_SDATA0,
	GPIO_FN_MSIOF1_SS2_F,
	GPIO_FN_MOUT2,

	/* IPSR15 */
	GPIO_IFN_SSI_SDATA1_A,
	GPIO_FN_MOUT5,

	GPIO_IFN_SSI_SDATA2_A,
	GPIO_FN_SSI_SCK1_B,
	GPIO_FN_MOUT6,

	GPIO_IFN_SSI_SCK34,
	GPIO_FN_MSIOF1_SS1_A,
	GPIO_FN_STP_OPWM_0_A,

	GPIO_IFN_SSI_WS34,
	GPIO_FN_HCTS2x_A,
	GPIO_FN_MSIOF1_SS2_A,
	GPIO_FN_STP_IVCXO27_0_A,

	GPIO_IFN_SSI_SDATA3,
	GPIO_FN_HRTS2x_A,
	GPIO_FN_MSIOF1_TXD_A,
	GPIO_FN_TS_SCK0_A,
	GPIO_FN_STP_ISCLK_0_A,
	GPIO_FN_RIF0_D1_A,
	GPIO_FN_RIF2_D0_A,

	GPIO_IFN_SSI_SCK4,
	GPIO_FN_HRX2_A,
	GPIO_FN_MSIOF1_SCK_A,
	GPIO_FN_TS_SDAT0_A,
	GPIO_FN_STP_ISD_0_A,
	GPIO_FN_RIF0_CLK_A,
	GPIO_FN_RIF2_CLK_A,

	GPIO_IFN_SSI_WS4,
	GPIO_FN_HTX2_A,
	GPIO_FN_MSIOF1_SYNC_A,
	GPIO_FN_TS_SDEN0_A,
	GPIO_FN_STP_ISEN_0_A,
	GPIO_FN_RIF0_SYNC_A,
	GPIO_FN_RIF2_SYNC_A,

	GPIO_IFN_SSI_SDATA4,
	GPIO_FN_HSCK2_A,
	GPIO_FN_MSIOF1_RXD_A,
	GPIO_FN_TS_SPSYNC0_A,
	GPIO_FN_STP_ISSYNC_0_A,
	GPIO_FN_RIF0_D0_A,
	GPIO_FN_RIF2_D1_A,

	/* IPSR16 */
	GPIO_IFN_SSI_SCK6,
	GPIO_FN_SIM0_RST_D,
	GPIO_FN_FSO_TOE_A,

	GPIO_IFN_SSI_WS6,
	GPIO_FN_SIM0_D_D,

	GPIO_IFN_SSI_SDATA6,
	GPIO_FN_SIM0_CLK_D,

	GPIO_IFN_SSI_SCK78,
	GPIO_FN_HRX2_B,
	GPIO_FN_MSIOF1_SCK_C,
	GPIO_FN_TS_SCK1_A,
	GPIO_FN_STP_ISCLK_1_A,
	GPIO_FN_RIF1_CLK_A,
	GPIO_FN_RIF3_CLK_A,

	GPIO_IFN_SSI_WS78,
	GPIO_FN_HTX2_B,
	GPIO_FN_MSIOF1_SYNC_C,
	GPIO_FN_TS_SDAT1_A,
	GPIO_FN_STP_ISD_1_A,
	GPIO_FN_RIF1_SYNC_A,
	GPIO_FN_RIF3_SYNC_A,

	GPIO_IFN_SSI_SDATA7,
	GPIO_FN_HCTS2x_B,
	GPIO_FN_MSIOF1_RXD_C,
	GPIO_FN_TS_SDEN1_A,
	GPIO_FN_STP_IEN_1_A,
	GPIO_FN_RIF1_D0_A,
	GPIO_FN_RIF3_D0_A,
	GPIO_FN_TCLK2_A,

	GPIO_IFN_SSI_SDATA8,
	GPIO_FN_HRTS2x_B,
	GPIO_FN_MSIOF1_TXD_C,
	GPIO_FN_TS_SPSYNC1_A,
	GPIO_FN_STP_ISSYNC_1_A,
	GPIO_FN_RIF1_D1_A,
	GPIO_FN_EIF3_D1_A,

	GPIO_IFN_SSI_SDATA9_A,
	GPIO_FN_HSCK2_B,
	GPIO_FN_MSIOF1_SS1_C,
	GPIO_FN_HSCK1_A,
	GPIO_FN_SSI_WS1_B,
	GPIO_FN_SCK1,
	GPIO_FN_STP_IVCXO27_1_A,
	GPIO_FN_SCK5,

	/* IPSR17 */
	GPIO_IFN_AUDIO_CLKA_A,
	GPIO_FN_CC5_OSCOUT,

	GPIO_IFN_AUDIO_CLKB_B,
	GPIO_FN_SCIF_CLK_A,
	GPIO_FN_STP_IVCXO27_1_D,
	GPIO_FN_REMOCON_A,
	GPIO_FN_TCLK1_A,

	GPIO_IFN_USB0_PWEN,
	GPIO_FN_SIM0_RST_C,
	GPIO_FN_TS_SCK1_D,
	GPIO_FN_STP_ISCLK_1_D,
	GPIO_FN_BPFCLK_B,
	GPIO_FN_RIF3_CLK_B,
	GPIO_FN_FSO_CFE_1_A,
	GPIO_FN_HSCK2_C,

	GPIO_IFN_USB0_OVC,
	GPIO_FN_SIM0_D_C,
	GPIO_FN_TS_SDAT1_D,
	GPIO_FN_STP_ISD_1_D,
	GPIO_FN_RIF3_SYNC_B,
	GPIO_FN_HRX2_C,

	GPIO_IFN_USB1_PWEN,
	GPIO_FN_SIM0_CLK_C,
	GPIO_FN_SSI_SCK1_A,
	GPIO_FN_TS_SCK0_E,
	GPIO_FN_STP_ISCLK_0_E,
	GPIO_FN_FMCLK_B,
	GPIO_FN_RIF2_CLK_B,
	GPIO_FN_SPEEDIN_A,
	GPIO_FN_HTX2_C,

	GPIO_IFN_USB1_OVC,
	GPIO_FN_MSIOF1_SS2_C,
	GPIO_FN_SSI_WS1_A,
	GPIO_FN_TS_SDAT0_E,
	GPIO_FN_STP_ISD_0_E,
	GPIO_FN_FMIN_B,
	GPIO_FN_RIF2_SYNC_B,
	GPIO_FN_REMOCON_B,
	GPIO_FN_HCTS2x_C,

	GPIO_IFN_USB30_PWEN,
	GPIO_FN_AUDIO_CLKOUT_B,
	GPIO_FN_SSI_SCK2_B,
	GPIO_FN_TS_SDEN1_D,
	GPIO_FN_STP_ISEN_1_D,
	GPIO_FN_STP_OPWM_0_E,
	GPIO_FN_RIF3_D0_B,
	GPIO_FN_TCLK2_B,
	GPIO_FN_TPU0TO0,
	GPIO_FN_BPFCLK_C,
	GPIO_FN_HRTS2x_C,

	GPIO_IFN_USB30_OVC,
	GPIO_FN_AUDIO_CLKOUT1_B,
	GPIO_FN_SSI_WS2_B,
	GPIO_FN_TS_SPSYNC1_D,
	GPIO_FN_STP_ISSYNC_1_D,
	GPIO_FN_STP_IVCXO27_0_E,
	GPIO_FN_RIF3_D1_B,
	GPIO_FN_FSO_TOE_B,
	GPIO_FN_TPU0TO1,

	/* IPSR18 */
	GPIO_IFN_GP6_30,
	GPIO_FN_AUDIO_CLKOUT2_B,
	GPIO_FN_SSI_SCK9_B,
	GPIO_FN_TS_SDEN0_E,
	GPIO_FN_STP_ISEN_0_E,
	GPIO_FN_RIF2_D0_B,
	GPIO_FN_FSO_CFE_0_A,
	GPIO_FN_TPU0TO2,
	GPIO_FN_FMCLK_C,
	GPIO_FN_FMCLK_D,

	GPIO_IFN_GP6_31,
	GPIO_FN_AUDIO_CLKOUT3_B,
	GPIO_FN_SSI_WS9_B,
	GPIO_FN_TS_SPSYNC0_E,
	GPIO_FN_STP_ISSYNC_0_E,
	GPIO_FN_RIF2_D1_B,
	GPIO_FN_TPU0TO3,
	GPIO_FN_FMIN_C,
	GPIO_FN_FMIN_D,

};

#endif /* __ASM_R8A7796_GPIO_H__ */
