/*
 * Copyright (c) 2015, NVIDIA CORPORATION. All rights reserved.
 *
 * SPDX-License-Identifier: GPL-2.0+
 */

/*
 * THIS FILE IS AUTO-GENERATED - DO NOT EDIT!
 *
 * To generate this file, use the tegra-pinmux-scripts tool available from
 * https://github.com/NVIDIA/tegra-pinmux-scripts
 * Run "board-to-uboot.py jetson-tk1".
 */

#ifndef _PINMUX_CONFIG_JETSON_TK1_H_
#define _PINMUX_CONFIG_JETSON_TK1_H_

#define GPIO_INIT(_port, _gpio, _init)			\
	{						\
		.gpio	= TEGRA_GPIO(_port, _gpio),	\
		.init	= TEGRA_GPIO_INIT_##_init,	\
	}

static const struct tegra_gpio_config jetson_tk1_gpio_inits[] = {
	/*        port, pin, init_val */
	GPIO_INIT(G,    0,   IN),
	GPIO_INIT(G,    1,   IN),
	GPIO_INIT(G,    2,   IN),
	GPIO_INIT(G,    3,   IN),
	GPIO_INIT(G,    4,   IN),
	GPIO_INIT(H,    2,   OUT0),
	GPIO_INIT(H,    4,   IN),
	GPIO_INIT(H,    7,   IN),
	GPIO_INIT(I,    0,   OUT0),
	GPIO_INIT(I,    1,   IN),
	GPIO_INIT(I,    6,   IN),
	GPIO_INIT(J,    0,   IN),
	GPIO_INIT(K,    1,   OUT0),
	GPIO_INIT(K,    2,   IN),
	GPIO_INIT(K,    4,   OUT0),
	GPIO_INIT(K,    6,   OUT0),
	GPIO_INIT(N,    7,   IN),
	GPIO_INIT(O,    1,   IN),
	GPIO_INIT(O,    4,   IN),
	GPIO_INIT(P,    2,   OUT0),
	GPIO_INIT(Q,    0,   IN),
	GPIO_INIT(Q,    3,   IN),
	GPIO_INIT(Q,    5,   IN),
	GPIO_INIT(R,    0,   OUT0),
	GPIO_INIT(R,    2,   OUT0),
	GPIO_INIT(R,    4,   IN),
	GPIO_INIT(R,    7,   IN),
	GPIO_INIT(S,    7,   IN),
	GPIO_INIT(T,    0,   OUT0),
	GPIO_INIT(T,    1,   IN),
	GPIO_INIT(U,    0,   IN),
	GPIO_INIT(U,    1,   IN),
	GPIO_INIT(U,    2,   IN),
	GPIO_INIT(U,    3,   IN),
	GPIO_INIT(U,    4,   IN),
	GPIO_INIT(U,    5,   IN),
	GPIO_INIT(U,    6,   IN),
	GPIO_INIT(V,    0,   IN),
	GPIO_INIT(V,    1,   IN),
	GPIO_INIT(X,    1,   IN),
	GPIO_INIT(X,    4,   IN),
	GPIO_INIT(X,    7,   OUT0),
	GPIO_INIT(BB,   3,   OUT0),
	GPIO_INIT(BB,   5,   OUT0),
	GPIO_INIT(BB,   6,   OUT0),
	GPIO_INIT(BB,   7,   OUT0),
	GPIO_INIT(CC,   1,   IN),
	GPIO_INIT(CC,   2,   IN),
	GPIO_INIT(EE,   2,   OUT1),
};

#define PINCFG(_pingrp, _mux, _pull, _tri, _io, _od, _rcv_sel)	\
	{							\
		.pingrp		= PMUX_PINGRP_##_pingrp,	\
		.func		= PMUX_FUNC_##_mux,		\
		.pull		= PMUX_PULL_##_pull,		\
		.tristate	= PMUX_TRI_##_tri,		\
		.io		= PMUX_PIN_##_io,		\
		.od		= PMUX_PIN_OD_##_od,		\
		.rcv_sel	= PMUX_PIN_RCV_SEL_##_rcv_sel,	\
		.lock		= PMUX_PIN_LOCK_DEFAULT,	\
		.ioreset	= PMUX_PIN_IO_RESET_DEFAULT,	\
	}

static const struct pmux_pingrp_config jetson_tk1_pingrps[] = {
	/*     pingrp,                 mux,          pull,   tri,      e_input, od,      rcv_sel */
	PINCFG(CLK_32K_OUT_PA0,        SOC,          UP,     TRISTATE, INPUT,   DEFAULT, DEFAULT),
	PINCFG(UART3_CTS_N_PA1,        GMI,          DOWN,   TRISTATE, OUTPUT,  DEFAULT, DEFAULT),
	PINCFG(DAP2_FS_PA2,            I2S1,         NORMAL, NORMAL,   OUTPUT,  DEFAULT, DEFAULT),
	PINCFG(DAP2_SCLK_PA3,          I2S1,         NORMAL, NORMAL,   OUTPUT,  DEFAULT, DEFAULT),
	PINCFG(DAP2_DIN_PA4,           I2S1,         NORMAL, TRISTATE, INPUT,   DEFAULT, DEFAULT),
	PINCFG(DAP2_DOUT_PA5,          I2S1,         NORMAL, NORMAL,   OUTPUT,  DEFAULT, DEFAULT),
	PINCFG(SDMMC3_CLK_PA6,         SDMMC3,       NORMAL, NORMAL,   INPUT,   DEFAULT, DEFAULT),
	PINCFG(SDMMC3_CMD_PA7,         SDMMC3,       UP,     NORMAL,   INPUT,   DEFAULT, DEFAULT),
	PINCFG(PB0,                    UARTD,        UP,     TRISTATE, INPUT,   DEFAULT, DEFAULT),
	PINCFG(PB1,                    UARTD,        UP,     TRISTATE, INPUT,   DEFAULT, DEFAULT),
	PINCFG(SDMMC3_DAT3_PB4,        SDMMC3,       UP,     NORMAL,   INPUT,   DEFAULT, DEFAULT),
	PINCFG(SDMMC3_DAT2_PB5,        SDMMC3,       UP,     NORMAL,   INPUT,   DEFAULT, DEFAULT),
	PINCFG(SDMMC3_DAT1_PB6,        SDMMC3,       UP,     NORMAL,   INPUT,   DEFAULT, DEFAULT),
	PINCFG(SDMMC3_DAT0_PB7,        SDMMC3,       UP,     NORMAL,   INPUT,   DEFAULT, DEFAULT),
	PINCFG(UART3_RTS_N_PC0,        GMI,          DOWN,   TRISTATE, OUTPUT,  DEFAULT, DEFAULT),
	PINCFG(UART2_TXD_PC2,          IRDA,         NORMAL, NORMAL,   OUTPUT,  DEFAULT, DEFAULT),
	PINCFG(UART2_RXD_PC3,          IRDA,         UP,     TRISTATE, INPUT,   DEFAULT, DEFAULT),
	PINCFG(GEN1_I2C_SCL_PC4,       I2C1,         NORMAL, NORMAL,   INPUT,   ENABLE,  DEFAULT),
	PINCFG(GEN1_I2C_SDA_PC5,       I2C1,         NORMAL, NORMAL,   INPUT,   ENABLE,  DEFAULT),
	PINCFG(PC7,                    RSVD1,        DOWN,   TRISTATE, OUTPUT,  DEFAULT, DEFAULT),
	PINCFG(PG0,                    DEFAULT,      NORMAL, TRISTATE, INPUT,   DEFAULT, DEFAULT),
	PINCFG(PG1,                    DEFAULT,      NORMAL, TRISTATE, INPUT,   DEFAULT, DEFAULT),
	PINCFG(PG2,                    DEFAULT,      NORMAL, TRISTATE, INPUT,   DEFAULT, DEFAULT),
	PINCFG(PG3,                    DEFAULT,      NORMAL, TRISTATE, INPUT,   DEFAULT, DEFAULT),
	PINCFG(PG4,                    DEFAULT,      NORMAL, TRISTATE, INPUT,   DEFAULT, DEFAULT),
	PINCFG(PG5,                    SPI4,         NORMAL, NORMAL,   OUTPUT,  DEFAULT, DEFAULT),
	PINCFG(PG6,                    SPI4,         NORMAL, NORMAL,   OUTPUT,  DEFAULT, DEFAULT),
	PINCFG(PG7,                    SPI4,         NORMAL, TRISTATE, INPUT,   DEFAULT, DEFAULT),
	PINCFG(PH0,                    GMI,          DOWN,   TRISTATE, OUTPUT,  DEFAULT, DEFAULT),
	PINCFG(PH1,                    PWM1,         NORMAL, NORMAL,   OUTPUT,  DEFAULT, DEFAULT),
	PINCFG(PH2,                    DEFAULT,      NORMAL, NORMAL,   OUTPUT,  DEFAULT, DEFAULT),
	PINCFG(PH3,                    GMI,          DOWN,   TRISTATE, OUTPUT,  DEFAULT, DEFAULT),
	PINCFG(PH4,                    DEFAULT,      NORMAL, TRISTATE, INPUT,   DEFAULT, DEFAULT),
	PINCFG(PH5,                    RSVD2,        DOWN,   TRISTATE, OUTPUT,  DEFAULT, DEFAULT),
	PINCFG(PH6,                    GMI,          DOWN,   TRISTATE, OUTPUT,  DEFAULT, DEFAULT),
	PINCFG(PH7,                    DEFAULT,      NORMAL, NORMAL,   INPUT,   DEFAULT, DEFAULT),
	PINCFG(PI0,                    DEFAULT,      NORMAL, NORMAL,   OUTPUT,  DEFAULT, DEFAULT),
	PINCFG(PI1,                    DEFAULT,      NORMAL, TRISTATE, INPUT,   DEFAULT, DEFAULT),
	PINCFG(PI2,                    RSVD4,        DOWN,   TRISTATE, OUTPUT,  DEFAULT, DEFAULT),
	PINCFG(PI3,                    SPI4,         NORMAL, NORMAL,   OUTPUT,  DEFAULT, DEFAULT),
	PINCFG(PI4,                    GMI,          DOWN,   TRISTATE, OUTPUT,  DEFAULT, DEFAULT),
	PINCFG(PI5,                    RSVD2,        DOWN,   TRISTATE, OUTPUT,  DEFAULT, DEFAULT),
	PINCFG(PI6,                    DEFAULT,      NORMAL, TRISTATE, INPUT,   DEFAULT, DEFAULT),
	PINCFG(PI7,                    RSVD1,        DOWN,   TRISTATE, OUTPUT,  DEFAULT, DEFAULT),
	PINCFG(PJ0,                    DEFAULT,      NORMAL, TRISTATE, INPUT,   DEFAULT, DEFAULT),
	PINCFG(PJ2,                    RSVD1,        DOWN,   TRISTATE, OUTPUT,  DEFAULT, DEFAULT),
	PINCFG(UART2_CTS_N_PJ5,        UARTB,        UP,     TRISTATE, INPUT,   DEFAULT, DEFAULT),
	PINCFG(UART2_RTS_N_PJ6,        UARTB,        NORMAL, NORMAL,   OUTPUT,  DEFAULT, DEFAULT),
	PINCFG(PJ7,                    UARTD,        NORMAL, NORMAL,   OUTPUT,  DEFAULT, DEFAULT),
	PINCFG(PK0,                    RSVD1,        DOWN,   TRISTATE, OUTPUT,  DEFAULT, DEFAULT),
	PINCFG(PK1,                    DEFAULT,      NORMAL, NORMAL,   OUTPUT,  DEFAULT, DEFAULT),
	PINCFG(PK2,                    DEFAULT,      NORMAL, NORMAL,   INPUT,   DEFAULT, DEFAULT),
	PINCFG(PK3,                    GMI,          DOWN,   TRISTATE, OUTPUT,  DEFAULT, DEFAULT),
	PINCFG(PK4,                    DEFAULT,      NORMAL, NORMAL,   OUTPUT,  DEFAULT, DEFAULT),
	PINCFG(SPDIF_OUT_PK5,          RSVD2,        DOWN,   TRISTATE, OUTPUT,  DEFAULT, DEFAULT),
	PINCFG(SPDIF_IN_PK6,           DEFAULT,      NORMAL, NORMAL,   OUTPUT,  DEFAULT, DEFAULT),
	PINCFG(PK7,                    UARTD,        NORMAL, NORMAL,   OUTPUT,  DEFAULT, DEFAULT),
	PINCFG(DAP1_FS_PN0,            RSVD4,        DOWN,   TRISTATE, OUTPUT,  DEFAULT, DEFAULT),
	PINCFG(DAP1_DIN_PN1,           RSVD4,        DOWN,   TRISTATE, OUTPUT,  DEFAULT, DEFAULT),
	PINCFG(DAP1_DOUT_PN2,          SATA,         NORMAL, NORMAL,   OUTPUT,  DEFAULT, DEFAULT),
	PINCFG(DAP1_SCLK_PN3,          RSVD4,        DOWN,   TRISTATE, OUTPUT,  DEFAULT, DEFAULT),
	PINCFG(USB_VBUS_EN0_PN4,       USB,          NORMAL, NORMAL,   INPUT,   DISABLE, DEFAULT),
	PINCFG(USB_VBUS_EN1_PN5,       USB,          NORMAL, NORMAL,   INPUT,   DISABLE, DEFAULT),
	PINCFG(HDMI_INT_PN7,           DEFAULT,      DOWN,   TRISTATE, INPUT,   DEFAULT, NORMAL),
	PINCFG(ULPI_DATA7_PO0,         ULPI,         DOWN,   TRISTATE, OUTPUT,  DEFAULT, DEFAULT),
	PINCFG(ULPI_DATA0_PO1,         DEFAULT,      NORMAL, TRISTATE, INPUT,   DEFAULT, DEFAULT),
	PINCFG(ULPI_DATA1_PO2,         ULPI,         DOWN,   TRISTATE, OUTPUT,  DEFAULT, DEFAULT),
	PINCFG(ULPI_DATA2_PO3,         ULPI,         DOWN,   TRISTATE, OUTPUT,  DEFAULT, DEFAULT),
	PINCFG(ULPI_DATA3_PO4,         DEFAULT,      NORMAL, TRISTATE, INPUT,   DEFAULT, DEFAULT),
	PINCFG(ULPI_DATA4_PO5,         ULPI,         DOWN,   TRISTATE, OUTPUT,  DEFAULT, DEFAULT),
	PINCFG(ULPI_DATA5_PO6,         ULPI,         DOWN,   TRISTATE, OUTPUT,  DEFAULT, DEFAULT),
	PINCFG(ULPI_DATA6_PO7,         ULPI,         DOWN,   TRISTATE, OUTPUT,  DEFAULT, DEFAULT),
	PINCFG(DAP3_FS_PP0,            I2S2,         DOWN,   TRISTATE, OUTPUT,  DEFAULT, DEFAULT),
	PINCFG(DAP3_DIN_PP1,           I2S2,         DOWN,   TRISTATE, OUTPUT,  DEFAULT, DEFAULT),
	PINCFG(DAP3_DOUT_PP2,          DEFAULT,      NORMAL, NORMAL,   OUTPUT,  DEFAULT, DEFAULT),
	PINCFG(DAP3_SCLK_PP3,          RSVD3,        DOWN,   TRISTATE, OUTPUT,  DEFAULT, DEFAULT),
	PINCFG(DAP4_FS_PP4,            RSVD4,        DOWN,   TRISTATE, OUTPUT,  DEFAULT, DEFAULT),
	PINCFG(DAP4_DIN_PP5,           RSVD3,        DOWN,   TRISTATE, OUTPUT,  DEFAULT, DEFAULT),
	PINCFG(DAP4_DOUT_PP6,          RSVD4,        DOWN,   TRISTATE, OUTPUT,  DEFAULT, DEFAULT),
	PINCFG(DAP4_SCLK_PP7,          RSVD3,        DOWN,   TRISTATE, OUTPUT,  DEFAULT, DEFAULT),
	PINCFG(KB_COL0_PQ0,            DEFAULT,      UP,     TRISTATE, INPUT,   DEFAULT, DEFAULT),
	PINCFG(KB_COL1_PQ1,            RSVD2,        DOWN,   TRISTATE, OUTPUT,  DEFAULT, DEFAULT),
	PINCFG(KB_COL2_PQ2,            RSVD2,        DOWN,   TRISTATE, OUTPUT,  DEFAULT, DEFAULT),
	PINCFG(KB_COL3_PQ3,            DEFAULT,      NORMAL, TRISTATE, INPUT,   DEFAULT, DEFAULT),
	PINCFG(KB_COL4_PQ4,            SDMMC3,       UP,     TRISTATE, INPUT,   DEFAULT, DEFAULT),
	PINCFG(KB_COL5_PQ5,            DEFAULT,      NORMAL, TRISTATE, INPUT,   DEFAULT, DEFAULT),
	PINCFG(KB_COL6_PQ6,            RSVD2,        DOWN,   TRISTATE, OUTPUT,  DEFAULT, DEFAULT),
	PINCFG(KB_COL7_PQ7,            RSVD2,        DOWN,   TRISTATE, OUTPUT,  DEFAULT, DEFAULT),
	PINCFG(KB_ROW0_PR0,            DEFAULT,      NORMAL, NORMAL,   OUTPUT,  DEFAULT, DEFAULT),
	PINCFG(KB_ROW1_PR1,            RSVD2,        DOWN,   TRISTATE, OUTPUT,  DEFAULT, DEFAULT),
	PINCFG(KB_ROW2_PR2,            DEFAULT,      NORMAL, NORMAL,   OUTPUT,  DEFAULT, DEFAULT),
	PINCFG(KB_ROW3_PR3,            KBC,          DOWN,   TRISTATE, OUTPUT,  DEFAULT, DEFAULT),
	PINCFG(KB_ROW4_PR4,            DEFAULT,      NORMAL, TRISTATE, INPUT,   DEFAULT, DEFAULT),
	PINCFG(KB_ROW5_PR5,            RSVD3,        DOWN,   TRISTATE, OUTPUT,  DEFAULT, DEFAULT),
	PINCFG(KB_ROW6_PR6,            DISPLAYA_ALT, NORMAL, TRISTATE, INPUT,   DEFAULT, DEFAULT),
	PINCFG(KB_ROW7_PR7,            DEFAULT,      NORMAL, TRISTATE, INPUT,   DEFAULT, DEFAULT),
	PINCFG(KB_ROW8_PS0,            RSVD2,        DOWN,   TRISTATE, OUTPUT,  DEFAULT, DEFAULT),
	PINCFG(KB_ROW9_PS1,            UARTA,        NORMAL, NORMAL,   OUTPUT,  DEFAULT, DEFAULT),
	PINCFG(KB_ROW10_PS2,           UARTA,        UP,     TRISTATE, INPUT,   DEFAULT, DEFAULT),
	PINCFG(KB_ROW11_PS3,           RSVD2,        DOWN,   TRISTATE, OUTPUT,  DEFAULT, DEFAULT),
	PINCFG(KB_ROW12_PS4,           RSVD2,        DOWN,   TRISTATE, OUTPUT,  DEFAULT, DEFAULT),
	PINCFG(KB_ROW13_PS5,           RSVD2,        DOWN,   TRISTATE, OUTPUT,  DEFAULT, DEFAULT),
	PINCFG(KB_ROW14_PS6,           RSVD2,        DOWN,   TRISTATE, OUTPUT,  DEFAULT, DEFAULT),
	PINCFG(KB_ROW15_PS7,           DEFAULT,      NORMAL, TRISTATE, INPUT,   DEFAULT, DEFAULT),
	PINCFG(KB_ROW16_PT0,           DEFAULT,      NORMAL, NORMAL,   OUTPUT,  DEFAULT, DEFAULT),
	PINCFG(KB_ROW17_PT1,           DEFAULT,      NORMAL, TRISTATE, INPUT,   DEFAULT, DEFAULT),
	PINCFG(GEN2_I2C_SCL_PT5,       I2C2,         NORMAL, NORMAL,   INPUT,   ENABLE,  DEFAULT),
	PINCFG(GEN2_I2C_SDA_PT6,       I2C2,         NORMAL, NORMAL,   INPUT,   ENABLE,  DEFAULT),
	PINCFG(SDMMC4_CMD_PT7,         SDMMC4,       UP,     NORMAL,   INPUT,   DEFAULT, DEFAULT),
	PINCFG(PU0,                    DEFAULT,      NORMAL, NORMAL,   INPUT,   DEFAULT, DEFAULT),
	PINCFG(PU1,                    DEFAULT,      NORMAL, NORMAL,   INPUT,   DEFAULT, DEFAULT),
	PINCFG(PU2,                    DEFAULT,      NORMAL, NORMAL,   INPUT,   DEFAULT, DEFAULT),
	PINCFG(PU3,                    DEFAULT,      NORMAL, NORMAL,   INPUT,   DEFAULT, DEFAULT),
	PINCFG(PU4,                    DEFAULT,      NORMAL, NORMAL,   INPUT,   DEFAULT, DEFAULT),
	PINCFG(PU5,                    DEFAULT,      NORMAL, NORMAL,   INPUT,   DEFAULT, DEFAULT),
	PINCFG(PU6,                    DEFAULT,      NORMAL, NORMAL,   INPUT,   DEFAULT, DEFAULT),
	PINCFG(PV0,                    DEFAULT,      NORMAL, TRISTATE, INPUT,   DEFAULT, DEFAULT),
	PINCFG(PV1,                    DEFAULT,      NORMAL, TRISTATE, INPUT,   DEFAULT, DEFAULT),
	PINCFG(SDMMC3_CD_N_PV2,        SDMMC3,       UP,     TRISTATE, INPUT,   DEFAULT, DEFAULT),
	PINCFG(SDMMC1_WP_N_PV3,        SDMMC1,       DOWN,   TRISTATE, OUTPUT,  DEFAULT, DEFAULT),
	PINCFG(DDC_SCL_PV4,            I2C4,         NORMAL, NORMAL,   INPUT,   DEFAULT, NORMAL),
	PINCFG(DDC_SDA_PV5,            I2C4,         NORMAL, NORMAL,   INPUT,   DEFAULT, NORMAL),
	PINCFG(GPIO_W2_AUD_PW2,        RSVD2,        DOWN,   TRISTATE, OUTPUT,  DEFAULT, DEFAULT),
	PINCFG(GPIO_W3_AUD_PW3,        SPI6,         DOWN,   TRISTATE, OUTPUT,  DEFAULT, DEFAULT),
	PINCFG(DAP_MCLK1_PW4,          EXTPERIPH1,   NORMAL, NORMAL,   OUTPUT,  DEFAULT, DEFAULT),
	PINCFG(CLK2_OUT_PW5,           EXTPERIPH2,   NORMAL, NORMAL,   OUTPUT,  DEFAULT, DEFAULT),
	PINCFG(UART3_TXD_PW6,          RSVD2,        DOWN,   TRISTATE, OUTPUT,  DEFAULT, DEFAULT),
	PINCFG(UART3_RXD_PW7,          RSVD2,        DOWN,   TRISTATE, OUTPUT,  DEFAULT, DEFAULT),
	PINCFG(DVFS_PWM_PX0,           CLDVFS,       NORMAL, NORMAL,   OUTPUT,  DEFAULT, DEFAULT),
	PINCFG(GPIO_X1_AUD_PX1,        DEFAULT,      NORMAL, TRISTATE, INPUT,   DEFAULT, DEFAULT),
	PINCFG(DVFS_CLK_PX2,           CLDVFS,       NORMAL, NORMAL,   OUTPUT,  DEFAULT, DEFAULT),
	PINCFG(GPIO_X3_AUD_PX3,        RSVD4,        DOWN,   TRISTATE, OUTPUT,  DEFAULT, DEFAULT),
	PINCFG(GPIO_X4_AUD_PX4,        DEFAULT,      NORMAL, TRISTATE, INPUT,   DEFAULT, DEFAULT),
	PINCFG(GPIO_X5_AUD_PX5,        RSVD4,        DOWN,   TRISTATE, OUTPUT,  DEFAULT, DEFAULT),
	PINCFG(GPIO_X6_AUD_PX6,        GMI,          DOWN,   TRISTATE, OUTPUT,  DEFAULT, DEFAULT),
	PINCFG(GPIO_X7_AUD_PX7,        DEFAULT,      NORMAL, NORMAL,   OUTPUT,  DEFAULT, DEFAULT),
	PINCFG(ULPI_CLK_PY0,           SPI1,         NORMAL, NORMAL,   OUTPUT,  DEFAULT, DEFAULT),
	PINCFG(ULPI_DIR_PY1,           SPI1,         NORMAL, TRISTATE, INPUT,   DEFAULT, DEFAULT),
	PINCFG(ULPI_NXT_PY2,           SPI1,         NORMAL, NORMAL,   OUTPUT,  DEFAULT, DEFAULT),
	PINCFG(ULPI_STP_PY3,           SPI1,         NORMAL, NORMAL,   OUTPUT,  DEFAULT, DEFAULT),
	PINCFG(SDMMC1_DAT3_PY4,        SDMMC1,       DOWN,   TRISTATE, OUTPUT,  DEFAULT, DEFAULT),
	PINCFG(SDMMC1_DAT2_PY5,        SDMMC1,       DOWN,   TRISTATE, OUTPUT,  DEFAULT, DEFAULT),
	PINCFG(SDMMC1_DAT1_PY6,        SDMMC1,       DOWN,   TRISTATE, OUTPUT,  DEFAULT, DEFAULT),
	PINCFG(SDMMC1_DAT0_PY7,        RSVD2,        DOWN,   TRISTATE, OUTPUT,  DEFAULT, DEFAULT),
	PINCFG(SDMMC1_CLK_PZ0,         RSVD3,        DOWN,   TRISTATE, OUTPUT,  DEFAULT, DEFAULT),
	PINCFG(SDMMC1_CMD_PZ1,         SDMMC1,       DOWN,   TRISTATE, OUTPUT,  DEFAULT, DEFAULT),
	PINCFG(PWR_I2C_SCL_PZ6,        I2CPWR,       NORMAL, NORMAL,   INPUT,   ENABLE,  DEFAULT),
	PINCFG(PWR_I2C_SDA_PZ7,        I2CPWR,       NORMAL, NORMAL,   INPUT,   ENABLE,  DEFAULT),
	PINCFG(SDMMC4_DAT0_PAA0,       SDMMC4,       UP,     NORMAL,   INPUT,   DEFAULT, DEFAULT),
	PINCFG(SDMMC4_DAT1_PAA1,       SDMMC4,       UP,     NORMAL,   INPUT,   DEFAULT, DEFAULT),
	PINCFG(SDMMC4_DAT2_PAA2,       SDMMC4,       UP,     NORMAL,   INPUT,   DEFAULT, DEFAULT),
	PINCFG(SDMMC4_DAT3_PAA3,       SDMMC4,       UP,     NORMAL,   INPUT,   DEFAULT, DEFAULT),
	PINCFG(SDMMC4_DAT4_PAA4,       SDMMC4,       UP,     NORMAL,   INPUT,   DEFAULT, DEFAULT),
	PINCFG(SDMMC4_DAT5_PAA5,       SDMMC4,       UP,     NORMAL,   INPUT,   DEFAULT, DEFAULT),
	PINCFG(SDMMC4_DAT6_PAA6,       SDMMC4,       UP,     NORMAL,   INPUT,   DEFAULT, DEFAULT),
	PINCFG(SDMMC4_DAT7_PAA7,       SDMMC4,       UP,     NORMAL,   INPUT,   DEFAULT, DEFAULT),
	PINCFG(PBB0,                   VIMCLK2_ALT,  NORMAL, NORMAL,   OUTPUT,  DEFAULT, DEFAULT),
	PINCFG(CAM_I2C_SCL_PBB1,       I2C3,         NORMAL, NORMAL,   INPUT,   ENABLE,  DEFAULT),
	PINCFG(CAM_I2C_SDA_PBB2,       I2C3,         NORMAL, NORMAL,   INPUT,   ENABLE,  DEFAULT),
	PINCFG(PBB3,                   DEFAULT,      NORMAL, NORMAL,   OUTPUT,  DEFAULT, DEFAULT),
	PINCFG(PBB4,                   VGP4,         NORMAL, NORMAL,   OUTPUT,  DEFAULT, DEFAULT),
	PINCFG(PBB5,                   DEFAULT,      NORMAL, NORMAL,   OUTPUT,  DEFAULT, DEFAULT),
	PINCFG(PBB6,                   DEFAULT,      NORMAL, NORMAL,   OUTPUT,  DEFAULT, DEFAULT),
	PINCFG(PBB7,                   DEFAULT,      NORMAL, NORMAL,   OUTPUT,  DEFAULT, DEFAULT),
	PINCFG(CAM_MCLK_PCC0,          VI_ALT3,      NORMAL, NORMAL,   OUTPUT,  DEFAULT, DEFAULT),
	PINCFG(PCC1,                   DEFAULT,      NORMAL, NORMAL,   INPUT,   DEFAULT, DEFAULT),
	PINCFG(PCC2,                   DEFAULT,      NORMAL, NORMAL,   INPUT,   DEFAULT, DEFAULT),
	PINCFG(SDMMC4_CLK_PCC4,        SDMMC4,       NORMAL, NORMAL,   INPUT,   DEFAULT, DEFAULT),
	PINCFG(CLK2_REQ_PCC5,          RSVD2,        DOWN,   TRISTATE, OUTPUT,  DEFAULT, DEFAULT),
	PINCFG(PEX_L0_RST_N_PDD1,      PE0,          NORMAL, NORMAL,   OUTPUT,  DEFAULT, DEFAULT),
	PINCFG(PEX_L0_CLKREQ_N_PDD2,   PE0,          NORMAL, TRISTATE, INPUT,   DEFAULT, DEFAULT),
	PINCFG(PEX_WAKE_N_PDD3,        PE,           NORMAL, TRISTATE, INPUT,   DEFAULT, DEFAULT),
	PINCFG(PEX_L1_RST_N_PDD5,      PE1,          NORMAL, NORMAL,   OUTPUT,  DEFAULT, DEFAULT),
	PINCFG(PEX_L1_CLKREQ_N_PDD6,   PE1,          NORMAL, TRISTATE, INPUT,   DEFAULT, DEFAULT),
	PINCFG(CLK3_OUT_PEE0,          EXTPERIPH3,   NORMAL, NORMAL,   OUTPUT,  DEFAULT, DEFAULT),
	PINCFG(CLK3_REQ_PEE1,          RSVD2,        DOWN,   TRISTATE, OUTPUT,  DEFAULT, DEFAULT),
	PINCFG(DAP_MCLK1_REQ_PEE2,     DEFAULT,      NORMAL, NORMAL,   OUTPUT,  DEFAULT, DEFAULT),
	PINCFG(HDMI_CEC_PEE3,          CEC,          NORMAL, NORMAL,   INPUT,   DISABLE, DEFAULT),
	PINCFG(SDMMC3_CLK_LB_OUT_PEE4, SDMMC3,       UP,     NORMAL,   INPUT,   DEFAULT, DEFAULT),
	PINCFG(SDMMC3_CLK_LB_IN_PEE5,  SDMMC3,       UP,     NORMAL,   INPUT,   DEFAULT, DEFAULT),
	PINCFG(DP_HPD_PFF0,            DP,           NORMAL, TRISTATE, INPUT,   DEFAULT, DEFAULT),
	PINCFG(USB_VBUS_EN2_PFF1,      RSVD2,        DOWN,   TRISTATE, OUTPUT,  DISABLE, DEFAULT),
	PINCFG(PFF2,                   RSVD2,        DOWN,   TRISTATE, OUTPUT,  DISABLE, DEFAULT),
	PINCFG(CORE_PWR_REQ,           PWRON,        NORMAL, NORMAL,   OUTPUT,  DEFAULT, DEFAULT),
	PINCFG(CPU_PWR_REQ,            CPU,          NORMAL, NORMAL,   OUTPUT,  DEFAULT, DEFAULT),
	PINCFG(PWR_INT_N,              PMI,          UP,     TRISTATE, INPUT,   DEFAULT, DEFAULT),
	PINCFG(RESET_OUT_N,            RESET_OUT_N,  NORMAL, NORMAL,   INPUT,   DEFAULT, DEFAULT),
	PINCFG(CLK_32K_IN,             CLK,          NORMAL, TRISTATE, INPUT,   DEFAULT, DEFAULT),
	PINCFG(JTAG_RTCK,              RTCK,         UP,     NORMAL,   OUTPUT,  DEFAULT, DEFAULT),
};

#define DRVCFG(_drvgrp, _slwf, _slwr, _drvup, _drvdn, _lpmd, _schmt, _hsm) \
	{						\
		.drvgrp = PMUX_DRVGRP_##_drvgrp,	\
		.slwf   = _slwf,			\
		.slwr   = _slwr,			\
		.drvup  = _drvup,			\
		.drvdn  = _drvdn,			\
		.lpmd   = PMUX_LPMD_##_lpmd,		\
		.schmt  = PMUX_SCHMT_##_schmt,		\
		.hsm    = PMUX_HSM_##_hsm,		\
	}

static const struct pmux_drvgrp_config jetson_tk1_drvgrps[] = {
};

#define MIPIPADCTRLCFG(_grp, _mux) \
	{							\
		.grp		= PMUX_MIPIPADCTRLGRP_##_grp,	\
		.func		= PMUX_FUNC_##_mux,		\
	}

static const struct pmux_mipipadctrlgrp_config jetson_tk1_mipipadctrlgrps[] = {
	/*             grp,   mux */
	MIPIPADCTRLCFG(DSI_B, DSI_B),
};

#endif /* PINMUX_CONFIG_JETSON_TK1_H */
