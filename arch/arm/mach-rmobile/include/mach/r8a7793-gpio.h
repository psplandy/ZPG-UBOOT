#ifndef __ASM_R8A7793_H__
#define __ASM_R8A7793_H__

/* Pin Function Controller:
 * GPIO_FN_xx - GPIO used to select pin function
 * GPIO_GP_x_x - GPIO mapped to real I/O pin on CPU
 */
enum {
	GPIO_GP_0_0, GPIO_GP_0_1, GPIO_GP_0_2, GPIO_GP_0_3,
	GPIO_GP_0_4, GPIO_GP_0_5, GPIO_GP_0_6, GPIO_GP_0_7,
	GPIO_GP_0_8, GPIO_GP_0_9, GPIO_GP_0_10, GPIO_GP_0_11,
	GPIO_GP_0_12, GPIO_GP_0_13, GPIO_GP_0_14, GPIO_GP_0_15,
	GPIO_GP_0_16, GPIO_GP_0_17, GPIO_GP_0_18, GPIO_GP_0_19,
	GPIO_GP_0_20, GPIO_GP_0_21, GPIO_GP_0_22, GPIO_GP_0_23,
	GPIO_GP_0_24, GPIO_GP_0_25, GPIO_GP_0_26, GPIO_GP_0_27,
	GPIO_GP_0_28, GPIO_GP_0_29, GPIO_GP_0_30, GPIO_GP_0_31,

	GPIO_GP_1_0, GPIO_GP_1_1, GPIO_GP_1_2, GPIO_GP_1_3,
	GPIO_GP_1_4, GPIO_GP_1_5, GPIO_GP_1_6, GPIO_GP_1_7,
	GPIO_GP_1_8, GPIO_GP_1_9, GPIO_GP_1_10, GPIO_GP_1_11,
	GPIO_GP_1_12, GPIO_GP_1_13, GPIO_GP_1_14, GPIO_GP_1_15,
	GPIO_GP_1_16, GPIO_GP_1_17, GPIO_GP_1_18, GPIO_GP_1_19,
	GPIO_GP_1_20, GPIO_GP_1_21, GPIO_GP_1_22, GPIO_GP_1_23,
	GPIO_GP_1_24, GPIO_GP_1_25,

	GPIO_GP_2_0, GPIO_GP_2_1, GPIO_GP_2_2, GPIO_GP_2_3,
	GPIO_GP_2_4, GPIO_GP_2_5, GPIO_GP_2_6, GPIO_GP_2_7,
	GPIO_GP_2_8, GPIO_GP_2_9, GPIO_GP_2_10, GPIO_GP_2_11,
	GPIO_GP_2_12, GPIO_GP_2_13, GPIO_GP_2_14, GPIO_GP_2_15,
	GPIO_GP_2_16, GPIO_GP_2_17, GPIO_GP_2_18, GPIO_GP_2_19,
	GPIO_GP_2_20, GPIO_GP_2_21, GPIO_GP_2_22, GPIO_GP_2_23,
	GPIO_GP_2_24, GPIO_GP_2_25, GPIO_GP_2_26, GPIO_GP_2_27,
	GPIO_GP_2_28, GPIO_GP_2_29, GPIO_GP_2_30, GPIO_GP_2_31,

	GPIO_GP_3_0, GPIO_GP_3_1, GPIO_GP_3_2, GPIO_GP_3_3,
	GPIO_GP_3_4, GPIO_GP_3_5, GPIO_GP_3_6, GPIO_GP_3_7,
	GPIO_GP_3_8, GPIO_GP_3_9, GPIO_GP_3_10, GPIO_GP_3_11,
	GPIO_GP_3_12, GPIO_GP_3_13, GPIO_GP_3_14, GPIO_GP_3_15,
	GPIO_GP_3_16, GPIO_GP_3_17, GPIO_GP_3_18, GPIO_GP_3_19,
	GPIO_GP_3_20, GPIO_GP_3_21, GPIO_GP_3_22, GPIO_GP_3_23,
	GPIO_GP_3_24, GPIO_GP_3_25, GPIO_GP_3_26, GPIO_GP_3_27,
	GPIO_GP_3_28, GPIO_GP_3_29, GPIO_GP_3_30, GPIO_GP_3_31,

	GPIO_GP_4_0, GPIO_GP_4_1, GPIO_GP_4_2, GPIO_GP_4_3,
	GPIO_GP_4_4, GPIO_GP_4_5, GPIO_GP_4_6, GPIO_GP_4_7,
	GPIO_GP_4_8, GPIO_GP_4_9, GPIO_GP_4_10, GPIO_GP_4_11,
	GPIO_GP_4_12, GPIO_GP_4_13, GPIO_GP_4_14, GPIO_GP_4_15,
	GPIO_GP_4_16, GPIO_GP_4_17, GPIO_GP_4_18, GPIO_GP_4_19,
	GPIO_GP_4_20, GPIO_GP_4_21, GPIO_GP_4_22, GPIO_GP_4_23,
	GPIO_GP_4_24, GPIO_GP_4_25, GPIO_GP_4_26, GPIO_GP_4_27,
	GPIO_GP_4_28, GPIO_GP_4_29, GPIO_GP_4_30, GPIO_GP_4_31,

	GPIO_GP_5_0, GPIO_GP_5_1, GPIO_GP_5_2, GPIO_GP_5_3,
	GPIO_GP_5_4, GPIO_GP_5_5, GPIO_GP_5_6, GPIO_GP_5_7,
	GPIO_GP_5_8, GPIO_GP_5_9, GPIO_GP_5_10, GPIO_GP_5_11,
	GPIO_GP_5_12, GPIO_GP_5_13, GPIO_GP_5_14, GPIO_GP_5_15,
	GPIO_GP_5_16, GPIO_GP_5_17, GPIO_GP_5_18, GPIO_GP_5_19,
	GPIO_GP_5_20, GPIO_GP_5_21, GPIO_GP_5_22, GPIO_GP_5_23,
	GPIO_GP_5_24, GPIO_GP_5_25, GPIO_GP_5_26, GPIO_GP_5_27,
	GPIO_GP_5_28, GPIO_GP_5_29, GPIO_GP_5_30, GPIO_GP_5_31,

	GPIO_GP_6_0, GPIO_GP_6_1, GPIO_GP_6_2, GPIO_GP_6_3,
	GPIO_GP_6_4, GPIO_GP_6_5, GPIO_GP_6_6, GPIO_GP_6_7,
	GPIO_GP_6_8, GPIO_GP_6_9, GPIO_GP_6_10, GPIO_GP_6_11,
	GPIO_GP_6_12, GPIO_GP_6_13, GPIO_GP_6_14, GPIO_GP_6_15,
	GPIO_GP_6_16, GPIO_GP_6_17, GPIO_GP_6_18, GPIO_GP_6_19,
	GPIO_GP_6_20, GPIO_GP_6_21, GPIO_GP_6_22, GPIO_GP_6_23,
	GPIO_GP_6_24, GPIO_GP_6_25, GPIO_GP_6_26, GPIO_GP_6_27,
	GPIO_GP_6_28, GPIO_GP_6_29, GPIO_GP_6_30, GPIO_GP_6_31,

	GPIO_GP_7_0, GPIO_GP_7_1, GPIO_GP_7_2, GPIO_GP_7_3,
	GPIO_GP_7_4, GPIO_GP_7_5, GPIO_GP_7_6, GPIO_GP_7_7,
	GPIO_GP_7_8, GPIO_GP_7_9, GPIO_GP_7_10, GPIO_GP_7_11,
	GPIO_GP_7_12, GPIO_GP_7_13, GPIO_GP_7_14, GPIO_GP_7_15,
	GPIO_GP_7_16, GPIO_GP_7_17, GPIO_GP_7_18, GPIO_GP_7_19,
	GPIO_GP_7_20, GPIO_GP_7_21, GPIO_GP_7_22, GPIO_GP_7_23,
	GPIO_GP_7_24, GPIO_GP_7_25,

	GPIO_FN_EX_CS0_N, GPIO_FN_RD_N, GPIO_FN_AUDIO_CLKA,
	GPIO_FN_VI0_CLK, GPIO_FN_VI0_DATA0_VI0_B0,
	GPIO_FN_VI0_DATA0_VI0_B1, GPIO_FN_VI0_DATA0_VI0_B2,
	GPIO_FN_VI0_DATA0_VI0_B4, GPIO_FN_VI0_DATA0_VI0_B5,
	GPIO_FN_VI0_DATA0_VI0_B6, GPIO_FN_VI0_DATA0_VI0_B7,
	GPIO_FN_USB0_PWEN, GPIO_FN_USB0_OVC, GPIO_FN_USB1_PWEN,

	/* IPSR0 */
	GPIO_FN_D0, GPIO_FN_D1, GPIO_FN_D2, GPIO_FN_D3, GPIO_FN_D4, GPIO_FN_D5,
	GPIO_FN_D6, GPIO_FN_D7, GPIO_FN_D8, GPIO_FN_D9, GPIO_FN_D10,
	GPIO_FN_D11, GPIO_FN_D12, GPIO_FN_D13, GPIO_FN_D14, GPIO_FN_D15,
	GPIO_FN_A0, GPIO_FN_ATAWR0_N_C, GPIO_FN_MSIOF0_SCK_B,
	GPIO_FN_SCL0_C, GPIO_FN_PWM2_B,
	GPIO_FN_A1, GPIO_FN_MSIOF0_SYNC_B, GPIO_FN_A2, GPIO_FN_MSIOF0_SS1_B,
	GPIO_FN_A3, GPIO_FN_MSIOF0_SS2_B, GPIO_FN_A4, GPIO_FN_MSIOF0_TXD_B,
	GPIO_FN_A5, GPIO_FN_MSIOF0_RXD_B, GPIO_FN_A6, GPIO_FN_MSIOF1_SCK,

	/* IPSR1 */
	GPIO_FN_A7, GPIO_FN_MSIOF1_SYNC, GPIO_FN_A8,
	GPIO_FN_MSIOF1_SS1, GPIO_FN_SCL0,
	GPIO_FN_A9, GPIO_FN_MSIOF1_SS2, GPIO_FN_SDA0,
	GPIO_FN_A10, GPIO_FN_MSIOF1_TXD, GPIO_FN_MSIOF1_TXD_D,
	GPIO_FN_A11, GPIO_FN_MSIOF1_RXD, GPIO_FN_SCL3_D, GPIO_FN_MSIOF1_RXD_D,
	GPIO_FN_A12, GPIO_FN_FMCLK, GPIO_FN_SDA3_D, GPIO_FN_MSIOF1_SCK_D,
	GPIO_FN_A13, GPIO_FN_ATAG0_N_C, GPIO_FN_BPFCLK, GPIO_FN_MSIOF1_SS1_D,
	GPIO_FN_A14, GPIO_FN_ATADIR0_N_C, GPIO_FN_FMIN,
	GPIO_FN_FMIN_C, GPIO_FN_MSIOF1_SYNC_D,
	GPIO_FN_A15, GPIO_FN_BPFCLK_C,
	GPIO_FN_A16, GPIO_FN_DREQ2_B, GPIO_FN_FMCLK_C, GPIO_FN_SCIFA1_SCK_B,
	GPIO_FN_A17, GPIO_FN_DACK2_B, GPIO_FN_SDA0_C,
	GPIO_FN_A18, GPIO_FN_DREQ1, GPIO_FN_SCIFA1_RXD_C, GPIO_FN_SCIFB1_RXD_C,

	/* IPSR2 */
	GPIO_FN_A19, GPIO_FN_DACK1, GPIO_FN_SCIFA1_TXD_C,
	GPIO_FN_SCIFB1_TXD_C, GPIO_FN_SCIFB1_SCK_B,
	GPIO_FN_A20, GPIO_FN_SPCLK,
	GPIO_FN_A21, GPIO_FN_ATAWR0_N_B, GPIO_FN_MOSI_IO0,
	GPIO_FN_A22, GPIO_FN_MISO_IO1, GPIO_FN_FMCLK_B,
	GPIO_FN_TX0, GPIO_FN_SCIFA0_TXD,
	GPIO_FN_A23, GPIO_FN_IO2, GPIO_FN_BPFCLK_B,
	GPIO_FN_RX0, GPIO_FN_SCIFA0_RXD,
	GPIO_FN_A24, GPIO_FN_DREQ2, GPIO_FN_IO3,
	GPIO_FN_TX1, GPIO_FN_SCIFA1_TXD,
	GPIO_FN_A25, GPIO_FN_DACK2, GPIO_FN_SSL, GPIO_FN_DREQ1_C,
	GPIO_FN_RX1, GPIO_FN_SCIFA1_RXD,
	GPIO_FN_CS0_N, GPIO_FN_ATAG0_N_B, GPIO_FN_SCL1,
	GPIO_FN_CS1_N_A26, GPIO_FN_ATADIR0_N_B, GPIO_FN_SDA1,
	GPIO_FN_EX_CS1_N, GPIO_FN_MSIOF2_SCK,
	GPIO_FN_EX_CS2_N, GPIO_FN_ATAWR0_N, GPIO_FN_MSIOF2_SYNC,
	GPIO_FN_EX_CS3_N, GPIO_FN_ATADIR0_N, GPIO_FN_MSIOF2_TXD,
	GPIO_FN_ATAG0_N, GPIO_FN_EX_WAIT1,

	/* IPSR3 */
	GPIO_FN_EX_CS4_N, GPIO_FN_ATARD0_N,
	GPIO_FN_MSIOF2_RXD, GPIO_FN_EX_WAIT2,
	GPIO_FN_EX_CS5_N, GPIO_FN_ATACS00_N, GPIO_FN_MSIOF2_SS1,
	GPIO_FN_HRX1_B, GPIO_FN_SCIFB1_RXD_B,
	GPIO_FN_PWM1, GPIO_FN_TPU_TO1,
	GPIO_FN_BS_N, GPIO_FN_ATACS10_N, GPIO_FN_MSIOF2_SS2,
	GPIO_FN_HTX1_B, GPIO_FN_SCIFB1_TXD_B,
	GPIO_FN_PWM2, GPIO_FN_TPU_TO2,
	GPIO_FN_RD_WR_N, GPIO_FN_HRX2_B, GPIO_FN_FMIN_B,
	GPIO_FN_SCIFB0_RXD_B, GPIO_FN_DREQ1_D,
	GPIO_FN_WE0_N, GPIO_FN_HCTS2_N_B, GPIO_FN_SCIFB0_TXD_B,
	GPIO_FN_WE1_N, GPIO_FN_ATARD0_N_B,
	GPIO_FN_HTX2_B, GPIO_FN_SCIFB0_RTS_N_B,
	GPIO_FN_EX_WAIT0, GPIO_FN_HRTS2_N_B, GPIO_FN_SCIFB0_CTS_N_B,
	GPIO_FN_DREQ0, GPIO_FN_PWM3, GPIO_FN_TPU_TO3,
	GPIO_FN_DACK0, GPIO_FN_DRACK0, GPIO_FN_REMOCON,
	GPIO_FN_SPEEDIN, GPIO_FN_HSCK0_C, GPIO_FN_HSCK2_C,
	GPIO_FN_SCIFB0_SCK_B, GPIO_FN_SCIFB2_SCK_B,
	GPIO_FN_DREQ2_C, GPIO_FN_HTX2_D,
	GPIO_FN_SSI_SCK0129, GPIO_FN_HRX0_C, GPIO_FN_HRX2_C,
	GPIO_FN_SCIFB0_RXD_C, GPIO_FN_SCIFB2_RXD_C,
	GPIO_FN_SSI_WS0129, GPIO_FN_HTX0_C, GPIO_FN_HTX2_C,
	GPIO_FN_SCIFB0_TXD_C, GPIO_FN_SCIFB2_TXD_C,

	/* IPSR4 */
	GPIO_FN_SSI_SDATA0, GPIO_FN_SCL0_B,
	GPIO_FN_SCL7_B, GPIO_FN_MSIOF2_SCK_C,
	GPIO_FN_SSI_SCK1, GPIO_FN_SDA0_B, GPIO_FN_SDA7_B,
	GPIO_FN_MSIOF2_SYNC_C, GPIO_FN_GLO_I0_D,
	GPIO_FN_SSI_WS1, GPIO_FN_SCL1_B, GPIO_FN_SCL8_B,
	GPIO_FN_MSIOF2_TXD_C, GPIO_FN_GLO_I1_D,
	GPIO_FN_SSI_SDATA1, GPIO_FN_SDA1_B,
	GPIO_FN_SDA8_B, GPIO_FN_MSIOF2_RXD_C,
	GPIO_FN_SSI_SCK2, GPIO_FN_SCL2, GPIO_FN_GPS_CLK_B,
	GPIO_FN_GLO_Q0_D, GPIO_FN_HSCK1_E,
	GPIO_FN_SSI_WS2, GPIO_FN_SDA2, GPIO_FN_GPS_SIGN_B,
	GPIO_FN_RX2_E, GPIO_FN_GLO_Q1_D, GPIO_FN_HCTS1_N_E,
	GPIO_FN_SSI_SDATA2, GPIO_FN_GPS_MAG_B,
	GPIO_FN_TX2_E, GPIO_FN_HRTS1_N_E,
	GPIO_FN_SSI_SCK34, GPIO_FN_SSI_WS34, GPIO_FN_SSI_SDATA3,
	GPIO_FN_SSI_SCK4, GPIO_FN_GLO_SS_D,
	GPIO_FN_SSI_WS4, GPIO_FN_GLO_RFON_D,
	GPIO_FN_SSI_SDATA4, GPIO_FN_MSIOF2_SCK_D,
	GPIO_FN_SSI_SCK5, GPIO_FN_MSIOF1_SCK_C,
	GPIO_FN_TS_SDATA0, GPIO_FN_GLO_I0,
	GPIO_FN_MSIOF2_SYNC_D, GPIO_FN_VI1_R2_B,

	/* IPSR5 */
	GPIO_FN_SSI_WS5, GPIO_FN_MSIOF1_SYNC_C, GPIO_FN_TS_SCK0,
	GPIO_FN_GLO_I1, GPIO_FN_MSIOF2_TXD_D, GPIO_FN_VI1_R3_B,
	GPIO_FN_SSI_SDATA5, GPIO_FN_MSIOF1_TXD_C, GPIO_FN_TS_SDEN0,
	GPIO_FN_GLO_Q0, GPIO_FN_MSIOF2_SS1_D, GPIO_FN_VI1_R4_B,
	GPIO_FN_SSI_SCK6, GPIO_FN_MSIOF1_RXD_C, GPIO_FN_TS_SPSYNC0,
	GPIO_FN_GLO_Q1, GPIO_FN_MSIOF2_RXD_D, GPIO_FN_VI1_R5_B,
	GPIO_FN_SSI_WS6, GPIO_FN_GLO_SCLK,
	GPIO_FN_MSIOF2_SS2_D, GPIO_FN_VI1_R6_B,
	GPIO_FN_SSI_SDATA6, GPIO_FN_STP_IVCXO27_0_B,
	GPIO_FN_GLO_SDATA, GPIO_FN_VI1_R7_B,
	GPIO_FN_SSI_SCK78, GPIO_FN_STP_ISCLK_0_B, GPIO_FN_GLO_SS,
	GPIO_FN_SSI_WS78, GPIO_FN_TX0_D, GPIO_FN_STP_ISD_0_B, GPIO_FN_GLO_RFON,
	GPIO_FN_SSI_SDATA7, GPIO_FN_RX0_D, GPIO_FN_STP_ISEN_0_B,
	GPIO_FN_SSI_SDATA8, GPIO_FN_TX1_D, GPIO_FN_STP_ISSYNC_0_B,
	GPIO_FN_SSI_SCK9, GPIO_FN_RX1_D, GPIO_FN_GLO_SCLK_D,
	GPIO_FN_SSI_WS9, GPIO_FN_TX3_D, GPIO_FN_CAN0_TX_D, GPIO_FN_GLO_SDATA_D,
	GPIO_FN_SSI_SDATA9, GPIO_FN_RX3_D, GPIO_FN_CAN0_RX_D,

	/* IPSR6 */
	GPIO_FN_AUDIO_CLKB, GPIO_FN_STP_OPWM_0_B, GPIO_FN_MSIOF1_SCK_B,
	GPIO_FN_SCIF_CLK, GPIO_FN_BPFCLK_E,
	GPIO_FN_AUDIO_CLKC, GPIO_FN_SCIFB0_SCK_C, GPIO_FN_MSIOF1_SYNC_B,
	GPIO_FN_RX2, GPIO_FN_SCIFA2_RXD, GPIO_FN_FMIN_E,
	GPIO_FN_AUDIO_CLKOUT, GPIO_FN_MSIOF1_SS1_B,
	GPIO_FN_TX2, GPIO_FN_SCIFA2_TXD,
	GPIO_FN_IRQ0, GPIO_FN_SCIFB1_RXD_D, GPIO_FN_INTC_IRQ0_N,
	GPIO_FN_IRQ1, GPIO_FN_SCIFB1_SCK_C, GPIO_FN_INTC_IRQ1_N,
	GPIO_FN_IRQ2, GPIO_FN_SCIFB1_TXD_D, GPIO_FN_INTC_IRQ2_N,
	GPIO_FN_IRQ3, GPIO_FN_SCL4_C,
	GPIO_FN_MSIOF2_TXD_E, GPIO_FN_INTC_IRQ3_N,
	GPIO_FN_IRQ4, GPIO_FN_HRX1_C, GPIO_FN_SDA4_C,
	GPIO_FN_MSIOF2_RXD_E, GPIO_FN_INTC_IRQ4_N,
	GPIO_FN_IRQ5, GPIO_FN_HTX1_C, GPIO_FN_SCL1_E, GPIO_FN_MSIOF2_SCK_E,
	GPIO_FN_IRQ6, GPIO_FN_HSCK1_C, GPIO_FN_MSIOF1_SS2_B,
	GPIO_FN_SDA1_E, GPIO_FN_MSIOF2_SYNC_E,
	GPIO_FN_IRQ7, GPIO_FN_HCTS1_N_C, GPIO_FN_MSIOF1_TXD_B,
	GPIO_FN_GPS_CLK_C, GPIO_FN_GPS_CLK_D,
	GPIO_FN_IRQ8, GPIO_FN_HRTS1_N_C, GPIO_FN_MSIOF1_RXD_B,
	GPIO_FN_GPS_SIGN_C, GPIO_FN_GPS_SIGN_D,

	/* IPSR7 */
	GPIO_FN_IRQ9, GPIO_FN_DU1_DOTCLKIN_B, GPIO_FN_CAN_CLK_D,
	GPIO_FN_GPS_MAG_C, GPIO_FN_SCIF_CLK_B, GPIO_FN_GPS_MAG_D,
	GPIO_FN_DU1_DR0, GPIO_FN_LCDOUT0, GPIO_FN_VI1_DATA0_B, GPIO_FN_TX0_B,
	GPIO_FN_SCIFA0_TXD_B, GPIO_FN_MSIOF2_SCK_B,
	GPIO_FN_DU1_DR1, GPIO_FN_LCDOUT1, GPIO_FN_VI1_DATA1_B, GPIO_FN_RX0_B,
	GPIO_FN_SCIFA0_RXD_B, GPIO_FN_MSIOF2_SYNC_B,
	GPIO_FN_DU1_DR2, GPIO_FN_LCDOUT2, GPIO_FN_SSI_SCK0129_B,
	GPIO_FN_DU1_DR3, GPIO_FN_LCDOUT3, GPIO_FN_SSI_WS0129_B,
	GPIO_FN_DU1_DR4, GPIO_FN_LCDOUT4, GPIO_FN_SSI_SDATA0_B,
	GPIO_FN_DU1_DR5, GPIO_FN_LCDOUT5, GPIO_FN_SSI_SCK1_B,
	GPIO_FN_DU1_DR6, GPIO_FN_LCDOUT6, GPIO_FN_SSI_WS1_B,
	GPIO_FN_DU1_DR7, GPIO_FN_LCDOUT7, GPIO_FN_SSI_SDATA1_B,
	GPIO_FN_DU1_DG0, GPIO_FN_LCDOUT8, GPIO_FN_VI1_DATA2_B, GPIO_FN_TX1_B,
	GPIO_FN_SCIFA1_TXD_B, GPIO_FN_MSIOF2_SS1_B,
	GPIO_FN_DU1_DG1, GPIO_FN_LCDOUT9, GPIO_FN_VI1_DATA3_B, GPIO_FN_RX1_B,
	GPIO_FN_SCIFA1_RXD_B, GPIO_FN_MSIOF2_SS2_B,
	GPIO_FN_DU1_DG2, GPIO_FN_LCDOUT10, GPIO_FN_VI1_DATA4_B,
	GPIO_FN_SCIF1_SCK_B, GPIO_FN_SCIFA1_SCK, GPIO_FN_SSI_SCK78_B,

	/* IPSR8 */
	GPIO_FN_DU1_DG3, GPIO_FN_LCDOUT11,
	GPIO_FN_VI1_DATA5_B, GPIO_FN_SSI_WS78_B,
	GPIO_FN_DU1_DG4, GPIO_FN_LCDOUT12, GPIO_FN_VI1_DATA6_B,
	GPIO_FN_HRX0_B, GPIO_FN_SCIFB2_RXD_B, GPIO_FN_SSI_SDATA7_B,
	GPIO_FN_DU1_DG5, GPIO_FN_LCDOUT13, GPIO_FN_VI1_DATA7_B,
	GPIO_FN_HCTS0_N_B, GPIO_FN_SCIFB2_TXD_B, GPIO_FN_SSI_SDATA8_B,
	GPIO_FN_DU1_DG6, GPIO_FN_LCDOUT14, GPIO_FN_HRTS0_N_B,
	GPIO_FN_SCIFB2_CTS_N_B, GPIO_FN_SSI_SCK9_B,
	GPIO_FN_DU1_DG7, GPIO_FN_LCDOUT15, GPIO_FN_HTX0_B,
	GPIO_FN_SCIFB2_RTS_N_B, GPIO_FN_SSI_WS9_B,
	GPIO_FN_DU1_DB0, GPIO_FN_LCDOUT16, GPIO_FN_VI1_CLK_B, GPIO_FN_TX2_B,
	GPIO_FN_SCIFA2_TXD_B, GPIO_FN_MSIOF2_TXD_B,
	GPIO_FN_DU1_DB1, GPIO_FN_LCDOUT17, GPIO_FN_VI1_HSYNC_N_B,
	GPIO_FN_RX2_B, GPIO_FN_SCIFA2_RXD_B, GPIO_FN_MSIOF2_RXD_B,
	GPIO_FN_DU1_DB2, GPIO_FN_LCDOUT18, GPIO_FN_VI1_VSYNC_N_B,
	GPIO_FN_SCIF2_SCK_B, GPIO_FN_SCIFA2_SCK, GPIO_FN_SSI_SDATA9_B,
	GPIO_FN_DU1_DB3, GPIO_FN_LCDOUT19, GPIO_FN_VI1_CLKENB_B,
	GPIO_FN_DU1_DB4, GPIO_FN_LCDOUT20,
	GPIO_FN_VI1_FIELD_B, GPIO_FN_CAN1_RX,
	GPIO_FN_DU1_DB5, GPIO_FN_LCDOUT21, GPIO_FN_TX3,
	GPIO_FN_SCIFA3_TXD, GPIO_FN_CAN1_TX,

	/* IPSR9 */
	GPIO_FN_DU1_DB6, GPIO_FN_LCDOUT22, GPIO_FN_SCL3_C,
	GPIO_FN_RX3, GPIO_FN_SCIFA3_RXD,
	GPIO_FN_DU1_DB7, GPIO_FN_LCDOUT23, GPIO_FN_SDA3_C,
	GPIO_FN_SCIF3_SCK, GPIO_FN_SCIFA3_SCK,
	GPIO_FN_DU1_DOTCLKIN, GPIO_FN_QSTVA_QVS,
	GPIO_FN_DU1_DOTCLKOUT0, GPIO_FN_QCLK,
	GPIO_FN_DU1_DOTCLKOUT1, GPIO_FN_QSTVB_QVE, GPIO_FN_CAN0_TX,
	GPIO_FN_TX3_B, GPIO_FN_SCL2_B, GPIO_FN_PWM4,
	GPIO_FN_DU1_EXHSYNC_DU1_HSYNC, GPIO_FN_QSTH_QHS,
	GPIO_FN_DU1_EXVSYNC_DU1_VSYNC, GPIO_FN_QSTB_QHE,
	GPIO_FN_DU1_EXODDF_DU1_ODDF_DISP_CDE, GPIO_FN_QCPV_QDE,
	GPIO_FN_CAN0_RX, GPIO_FN_RX3_B, GPIO_FN_SDA2_B,
	GPIO_FN_DU1_DISP, GPIO_FN_QPOLA,
	GPIO_FN_DU1_CDE, GPIO_FN_QPOLB, GPIO_FN_PWM4_B,
	GPIO_FN_VI0_CLKENB, GPIO_FN_TX4,
	GPIO_FN_SCIFA4_TXD, GPIO_FN_TS_SDATA0_D,
	GPIO_FN_VI0_FIELD, GPIO_FN_RX4, GPIO_FN_SCIFA4_RXD, GPIO_FN_TS_SCK0_D,
	GPIO_FN_VI0_HSYNC_N, GPIO_FN_TX5,
	GPIO_FN_SCIFA5_TXD, GPIO_FN_TS_SDEN0_D,
	GPIO_FN_VI0_VSYNC_N, GPIO_FN_RX5,
	GPIO_FN_SCIFA5_RXD, GPIO_FN_TS_SPSYNC0_D,
	GPIO_FN_VI0_DATA3_VI0_B3, GPIO_FN_SCIF3_SCK_B, GPIO_FN_SCIFA3_SCK_B,
	GPIO_FN_VI0_G0, GPIO_FN_SCL8, GPIO_FN_STP_IVCXO27_0_C, GPIO_FN_SCL4,
	GPIO_FN_HCTS2_N, GPIO_FN_SCIFB2_CTS_N, GPIO_FN_ATAWR1_N,

	/* IPSR10 */
	GPIO_FN_VI0_G1, GPIO_FN_SDA8, GPIO_FN_STP_ISCLK_0_C, GPIO_FN_SDA4,
	GPIO_FN_HRTS2_N, GPIO_FN_SCIFB2_RTS_N, GPIO_FN_ATADIR1_N,
	GPIO_FN_VI0_G2, GPIO_FN_VI2_HSYNC_N, GPIO_FN_STP_ISD_0_C,
	GPIO_FN_SCL3_B, GPIO_FN_HSCK2, GPIO_FN_SCIFB2_SCK, GPIO_FN_ATARD1_N,
	GPIO_FN_VI0_G3, GPIO_FN_VI2_VSYNC_N, GPIO_FN_STP_ISEN_0_C,
	GPIO_FN_SDA3_B, GPIO_FN_HRX2, GPIO_FN_SCIFB2_RXD, GPIO_FN_ATACS01_N,
	GPIO_FN_VI0_G4, GPIO_FN_VI2_CLKENB, GPIO_FN_STP_ISSYNC_0_C,
	GPIO_FN_HTX2, GPIO_FN_SCIFB2_TXD, GPIO_FN_SCIFB0_SCK_D,
	GPIO_FN_VI0_G5, GPIO_FN_VI2_FIELD, GPIO_FN_STP_OPWM_0_C,
	GPIO_FN_FMCLK_D, GPIO_FN_CAN0_TX_E,
	GPIO_FN_HTX1_D, GPIO_FN_SCIFB0_TXD_D,
	GPIO_FN_VI0_G6, GPIO_FN_VI2_CLK, GPIO_FN_BPFCLK_D,
	GPIO_FN_VI0_G7, GPIO_FN_VI2_DATA0, GPIO_FN_FMIN_D,
	GPIO_FN_VI0_R0, GPIO_FN_VI2_DATA1, GPIO_FN_GLO_I0_B,
	GPIO_FN_TS_SDATA0_C, GPIO_FN_ATACS11_N,
	GPIO_FN_VI0_R1, GPIO_FN_VI2_DATA2, GPIO_FN_GLO_I1_B,
	GPIO_FN_TS_SCK0_C, GPIO_FN_ATAG1_N,
	GPIO_FN_VI0_R2, GPIO_FN_VI2_DATA3,
	GPIO_FN_GLO_Q0_B, GPIO_FN_TS_SDEN0_C,
	GPIO_FN_VI0_R3, GPIO_FN_VI2_DATA4,
	GPIO_FN_GLO_Q1_B, GPIO_FN_TS_SPSYNC0_C,
	GPIO_FN_VI0_R4, GPIO_FN_VI2_DATA5, GPIO_FN_GLO_SCLK_B,
	GPIO_FN_TX0_C, GPIO_FN_SCL1_D,

	/* IPSR11 */
	GPIO_FN_VI0_R5, GPIO_FN_VI2_DATA6, GPIO_FN_GLO_SDATA_B,
	GPIO_FN_RX0_C, GPIO_FN_SDA1_D,
	GPIO_FN_VI0_R6, GPIO_FN_VI2_DATA7, GPIO_FN_GLO_SS_B,
	GPIO_FN_TX1_C, GPIO_FN_SCL4_B,
	GPIO_FN_VI0_R7, GPIO_FN_GLO_RFON_B, GPIO_FN_RX1_C, GPIO_FN_CAN0_RX_E,
	GPIO_FN_SDA4_B, GPIO_FN_HRX1_D, GPIO_FN_SCIFB0_RXD_D,
	GPIO_FN_VI1_HSYNC_N, GPIO_FN_AVB_RXD0, GPIO_FN_TS_SDATA0_B,
	GPIO_FN_TX4_B, GPIO_FN_SCIFA4_TXD_B,
	GPIO_FN_VI1_VSYNC_N, GPIO_FN_AVB_RXD1, GPIO_FN_TS_SCK0_B,
	GPIO_FN_RX4_B, GPIO_FN_SCIFA4_RXD_B,
	GPIO_FN_VI1_CLKENB, GPIO_FN_AVB_RXD2, GPIO_FN_TS_SDEN0_B,
	GPIO_FN_VI1_FIELD, GPIO_FN_AVB_RXD3, GPIO_FN_TS_SPSYNC0_B,
	GPIO_FN_VI1_CLK, GPIO_FN_AVB_RXD4, GPIO_FN_VI1_DATA0, GPIO_FN_AVB_RXD5,
	GPIO_FN_VI1_DATA1, GPIO_FN_AVB_RXD6,
	GPIO_FN_VI1_DATA2, GPIO_FN_AVB_RXD7,
	GPIO_FN_VI1_DATA3, GPIO_FN_AVB_RX_ER,
	GPIO_FN_VI1_DATA4, GPIO_FN_AVB_MDIO,
	GPIO_FN_VI1_DATA5, GPIO_FN_AVB_RX_DV,
	GPIO_FN_VI1_DATA6, GPIO_FN_AVB_MAGIC,
	GPIO_FN_VI1_DATA7, GPIO_FN_AVB_MDC,
	GPIO_FN_ETH_MDIO, GPIO_FN_AVB_RX_CLK, GPIO_FN_SCL2_C,
	GPIO_FN_ETH_CRS_DV, GPIO_FN_AVB_LINK, GPIO_FN_SDA2_C,

	/* IPSR12 */
	GPIO_FN_ETH_RX_ER, GPIO_FN_AVB_CRS, GPIO_FN_SCL3, GPIO_FN_SCL7,
	GPIO_FN_ETH_RXD0, GPIO_FN_AVB_PHY_INT, GPIO_FN_SDA3, GPIO_FN_SDA7,
	GPIO_FN_ETH_RXD1, GPIO_FN_AVB_GTXREFCLK, GPIO_FN_CAN0_TX_C,
	GPIO_FN_SCL2_D, GPIO_FN_MSIOF1_RXD_E,
	GPIO_FN_ETH_LINK, GPIO_FN_AVB_TXD0, GPIO_FN_CAN0_RX_C,
	GPIO_FN_SDA2_D, GPIO_FN_MSIOF1_SCK_E,
	GPIO_FN_ETH_REFCLK, GPIO_FN_AVB_TXD1, GPIO_FN_SCIFA3_RXD_B,
	GPIO_FN_CAN1_RX_C, GPIO_FN_MSIOF1_SYNC_E,
	GPIO_FN_ETH_TXD1, GPIO_FN_AVB_TXD2, GPIO_FN_SCIFA3_TXD_B,
	GPIO_FN_CAN1_TX_C, GPIO_FN_MSIOF1_TXD_E,
	GPIO_FN_ETH_TX_EN, GPIO_FN_AVB_TXD3,
	GPIO_FN_TCLK1_B, GPIO_FN_CAN_CLK_B,
	GPIO_FN_ETH_MAGIC, GPIO_FN_AVB_TXD4, GPIO_FN_IETX_C,
	GPIO_FN_ETH_TXD0, GPIO_FN_AVB_TXD5, GPIO_FN_IECLK_C,
	GPIO_FN_ETH_MDC, GPIO_FN_AVB_TXD6, GPIO_FN_IERX_C,
	GPIO_FN_STP_IVCXO27_0, GPIO_FN_AVB_TXD7, GPIO_FN_SCIFB2_TXD_D,
	GPIO_FN_ADIDATA_B, GPIO_FN_MSIOF0_SYNC_C,
	GPIO_FN_STP_ISCLK_0, GPIO_FN_AVB_TX_EN, GPIO_FN_SCIFB2_RXD_D,
	GPIO_FN_ADICS_SAMP_B, GPIO_FN_MSIOF0_SCK_C,

	/* IPSR13 */
	GPIO_FN_STP_ISD_0, GPIO_FN_AVB_TX_ER, GPIO_FN_SCIFB2_SCK_C,
	GPIO_FN_ADICLK_B, GPIO_FN_MSIOF0_SS1_C,
	GPIO_FN_STP_ISEN_0, GPIO_FN_AVB_TX_CLK,
	GPIO_FN_ADICHS0_B, GPIO_FN_MSIOF0_SS2_C,
	GPIO_FN_STP_ISSYNC_0, GPIO_FN_AVB_COL,
	GPIO_FN_ADICHS1_B, GPIO_FN_MSIOF0_RXD_C,
	GPIO_FN_STP_OPWM_0, GPIO_FN_AVB_GTX_CLK, GPIO_FN_PWM0_B,
	GPIO_FN_ADICHS2_B, GPIO_FN_MSIOF0_TXD_C,
	GPIO_FN_SD0_CLK, GPIO_FN_SPCLK_B, GPIO_FN_SD0_CMD, GPIO_FN_MOSI_IO0_B,
	GPIO_FN_SD0_DATA0, GPIO_FN_MISO_IO1_B,
	GPIO_FN_SD0_DATA1, GPIO_FN_IO2_B,
	GPIO_FN_SD0_DATA2, GPIO_FN_IO3_B, GPIO_FN_SD0_DATA3, GPIO_FN_SSL_B,
	GPIO_FN_SD0_CD, GPIO_FN_MMC_D6_B,
	GPIO_FN_SIM0_RST_B, GPIO_FN_CAN0_RX_F,
	GPIO_FN_SCIFA5_TXD_B, GPIO_FN_TX3_C,
	GPIO_FN_SD0_WP, GPIO_FN_MMC_D7_B, GPIO_FN_SIM0_D_B, GPIO_FN_CAN0_TX_F,
	GPIO_FN_SCIFA5_RXD_B, GPIO_FN_RX3_C,
	GPIO_FN_SD1_CMD, GPIO_FN_REMOCON_B,
	GPIO_FN_SD1_DATA0, GPIO_FN_SPEEDIN_B,
	GPIO_FN_SD1_DATA1, GPIO_FN_IETX_B, GPIO_FN_SD1_DATA2, GPIO_FN_IECLK_B,
	GPIO_FN_SD1_DATA3, GPIO_FN_IERX_B,
	GPIO_FN_SD1_CD, GPIO_FN_PWM0, GPIO_FN_TPU_TO0, GPIO_FN_SCL1_C,

	/* IPSR14 */
	GPIO_FN_SD1_WP, GPIO_FN_PWM1_B, GPIO_FN_SDA1_C,
	GPIO_FN_SD2_CLK, GPIO_FN_MMC_CLK, GPIO_FN_SD2_CMD, GPIO_FN_MMC_CMD,
	GPIO_FN_SD2_DATA0, GPIO_FN_MMC_D0, GPIO_FN_SD2_DATA1, GPIO_FN_MMC_D1,
	GPIO_FN_SD2_DATA2, GPIO_FN_MMC_D2, GPIO_FN_SD2_DATA3, GPIO_FN_MMC_D3,
	GPIO_FN_SD2_CD, GPIO_FN_MMC_D4, GPIO_FN_SCL8_C,
	GPIO_FN_TX5_B, GPIO_FN_SCIFA5_TXD_C,
	GPIO_FN_SD2_WP, GPIO_FN_MMC_D5, GPIO_FN_SDA8_C,
	GPIO_FN_RX5_B, GPIO_FN_SCIFA5_RXD_C,
	GPIO_FN_MSIOF0_SCK, GPIO_FN_RX2_C, GPIO_FN_ADIDATA,
	GPIO_FN_VI1_CLK_C, GPIO_FN_VI1_G0_B,
	GPIO_FN_MSIOF0_SYNC, GPIO_FN_TX2_C, GPIO_FN_ADICS_SAMP,
	GPIO_FN_VI1_CLKENB_C, GPIO_FN_VI1_G1_B,
	GPIO_FN_MSIOF0_TXD, GPIO_FN_ADICLK,
	GPIO_FN_VI1_FIELD_C, GPIO_FN_VI1_G2_B,
	GPIO_FN_MSIOF0_RXD, GPIO_FN_ADICHS0,
	GPIO_FN_VI1_DATA0_C, GPIO_FN_VI1_G3_B,
	GPIO_FN_MSIOF0_SS1, GPIO_FN_MMC_D6, GPIO_FN_ADICHS1, GPIO_FN_TX0_E,
	GPIO_FN_VI1_HSYNC_N_C, GPIO_FN_SCL7_C, GPIO_FN_VI1_G4_B,
	GPIO_FN_MSIOF0_SS2, GPIO_FN_MMC_D7, GPIO_FN_ADICHS2, GPIO_FN_RX0_E,
	GPIO_FN_VI1_VSYNC_N_C, GPIO_FN_SDA7_C, GPIO_FN_VI1_G5_B,

	/* IPSR15 */
	GPIO_FN_SIM0_RST, GPIO_FN_IETX, GPIO_FN_CAN1_TX_D,
	GPIO_FN_SIM0_CLK, GPIO_FN_IECLK, GPIO_FN_CAN_CLK_C,
	GPIO_FN_SIM0_D, GPIO_FN_IERX, GPIO_FN_CAN1_RX_D,
	GPIO_FN_GPS_CLK, GPIO_FN_DU1_DOTCLKIN_C, GPIO_FN_AUDIO_CLKB_B,
	GPIO_FN_PWM5_B, GPIO_FN_SCIFA3_TXD_C,
	GPIO_FN_GPS_SIGN, GPIO_FN_TX4_C, GPIO_FN_SCIFA4_TXD_C, GPIO_FN_PWM5,
	GPIO_FN_VI1_G6_B, GPIO_FN_SCIFA3_RXD_C,
	GPIO_FN_GPS_MAG, GPIO_FN_RX4_C, GPIO_FN_SCIFA4_RXD_C, GPIO_FN_PWM6,
	GPIO_FN_VI1_G7_B, GPIO_FN_SCIFA3_SCK_C,
	GPIO_FN_HCTS0_N, GPIO_FN_SCIFB0_CTS_N, GPIO_FN_GLO_I0_C,
	GPIO_FN_TCLK1, GPIO_FN_VI1_DATA1_C,
	GPIO_FN_HRTS0_N, GPIO_FN_SCIFB0_RTS_N,
	GPIO_FN_GLO_I1_C, GPIO_FN_VI1_DATA2_C,
	GPIO_FN_HSCK0, GPIO_FN_SCIFB0_SCK, GPIO_FN_GLO_Q0_C, GPIO_FN_CAN_CLK,
	GPIO_FN_TCLK2, GPIO_FN_VI1_DATA3_C,
	GPIO_FN_HRX0, GPIO_FN_SCIFB0_RXD, GPIO_FN_GLO_Q1_C,
	GPIO_FN_CAN0_RX_B, GPIO_FN_VI1_DATA4_C,
	GPIO_FN_HTX0, GPIO_FN_SCIFB0_TXD, GPIO_FN_GLO_SCLK_C,
	GPIO_FN_CAN0_TX_B, GPIO_FN_VI1_DATA5_C,

	/* IPSR16 */
	GPIO_FN_HRX1, GPIO_FN_SCIFB1_RXD, GPIO_FN_VI1_R0_B,
	GPIO_FN_GLO_SDATA_C, GPIO_FN_VI1_DATA6_C,
	GPIO_FN_HTX1, GPIO_FN_SCIFB1_TXD, GPIO_FN_VI1_R1_B,
	GPIO_FN_GLO_SS_C, GPIO_FN_VI1_DATA7_C,
	GPIO_FN_HSCK1, GPIO_FN_SCIFB1_SCK, GPIO_FN_MLB_CK, GPIO_FN_GLO_RFON_C,
	GPIO_FN_HCTS1_N, GPIO_FN_SCIFB1_CTS_N,
	GPIO_FN_MLB_SIG, GPIO_FN_CAN1_TX_B,
	GPIO_FN_HRTS1_N, GPIO_FN_SCIFB1_RTS_N,
	GPIO_FN_MLB_DAT, GPIO_FN_CAN1_RX_B,
};

#endif /* __ASM_R8A7793_H__ */
