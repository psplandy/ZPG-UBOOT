/*
 * Copyright (c) 2010-2012, NVIDIA CORPORATION.  All rights reserved.
 *
 * SPDX-License-Identifier:	GPL-2.0
 */

#ifndef _TEGRA30_GPIO_H_
#define _TEGRA30_GPIO_H_

/*
 * The Tegra 3x GPIO controller has 246 GPIOS in 8 banks of 4 ports,
 * each with 8 GPIOs.
 */
#define TEGRA_GPIO_PORTS	4	/* number of ports per bank */
#define TEGRA_GPIO_BANKS	8	/* number of banks */

#include <asm/arch-tegra/gpio.h>

/* GPIO Controller registers for a single bank */
struct gpio_ctlr_bank {
	uint gpio_config[TEGRA_GPIO_PORTS];
	uint gpio_dir_out[TEGRA_GPIO_PORTS];
	uint gpio_out[TEGRA_GPIO_PORTS];
	uint gpio_in[TEGRA_GPIO_PORTS];
	uint gpio_int_status[TEGRA_GPIO_PORTS];
	uint gpio_int_enable[TEGRA_GPIO_PORTS];
	uint gpio_int_level[TEGRA_GPIO_PORTS];
	uint gpio_int_clear[TEGRA_GPIO_PORTS];
	uint gpio_masked_config[TEGRA_GPIO_PORTS];
	uint gpio_masked_dir_out[TEGRA_GPIO_PORTS];
	uint gpio_masked_out[TEGRA_GPIO_PORTS];
	uint gpio_masked_in[TEGRA_GPIO_PORTS];
	uint gpio_masked_int_status[TEGRA_GPIO_PORTS];
	uint gpio_masked_int_enable[TEGRA_GPIO_PORTS];
	uint gpio_masked_int_level[TEGRA_GPIO_PORTS];
	uint gpio_masked_int_clear[TEGRA_GPIO_PORTS];
};

struct gpio_ctlr {
	struct gpio_ctlr_bank gpio_bank[TEGRA_GPIO_BANKS];
};

#endif	/* _TEGRA30_GPIO_H_ */
