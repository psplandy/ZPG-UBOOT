/*
 * (C) Copyright 2012 Henrik Nordstrom <henrik@henriknordstrom.net>
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

enum axp209_reg {
	AXP209_POWER_STATUS = 0x00,
	AXP209_CHIP_VERSION = 0x03,
	AXP209_OUTPUT_CTRL = 0x12,
	AXP209_DCDC2_VOLTAGE = 0x23,
	AXP209_DCDC3_VOLTAGE = 0x27,
	AXP209_LDO24_VOLTAGE = 0x28,
	AXP209_LDO3_VOLTAGE = 0x29,
	AXP209_IRQ_ENABLE1 = 0x40,
	AXP209_IRQ_ENABLE2 = 0x41,
	AXP209_IRQ_ENABLE3 = 0x42,
	AXP209_IRQ_ENABLE4 = 0x43,
	AXP209_IRQ_ENABLE5 = 0x44,
	AXP209_IRQ_STATUS5 = 0x4c,
	AXP209_SHUTDOWN = 0x32,
};

#define AXP209_POWER_STATUS_ON_BY_DC	(1 << 0)
#define AXP209_POWER_STATUS_VBUS_USABLE	(1 << 4)

#define AXP209_OUTPUT_CTRL_EXTEN	(1 << 0)
#define AXP209_OUTPUT_CTRL_DCDC3	(1 << 1)
#define AXP209_OUTPUT_CTRL_LDO2		(1 << 2)
#define AXP209_OUTPUT_CTRL_LDO4		(1 << 3)
#define AXP209_OUTPUT_CTRL_DCDC2	(1 << 4)
#define AXP209_OUTPUT_CTRL_LDO3		(1 << 6)

#define AXP209_IRQ5_PEK_UP		(1 << 6)
#define AXP209_IRQ5_PEK_DOWN		(1 << 5)

#define AXP209_POWEROFF			(1 << 7)

/* For axp_gpio.c */
#define AXP_POWER_STATUS		0x00
#define AXP_POWER_STATUS_VBUS_PRESENT		(1 << 5)
#define AXP_GPIO0_CTRL			0x90
#define AXP_GPIO1_CTRL			0x92
#define AXP_GPIO2_CTRL			0x93
#define AXP_GPIO_CTRL_OUTPUT_LOW		0x00 /* Drive pin low */
#define AXP_GPIO_CTRL_OUTPUT_HIGH		0x01 /* Drive pin high */
#define AXP_GPIO_CTRL_INPUT			0x02 /* Input */
#define AXP_GPIO_STATE			0x94
#define AXP_GPIO_STATE_OFFSET			4
