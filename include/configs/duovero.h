/*
 * (C) Copyright: 2013
 * Gumstix, Inc - http://www.gumstix.com
 * Maintainer: Ash Charles  <ash@gumstix.com>
 *
 * Configuration settings for the Gumstix DuoVero board.
 * See omap4_common.h for OMAP4 common part
 *
 * SPDX-License-Identifier:     GPL-2.0+
 */

#ifndef __CONFIG_DUOVERO_H
#define __CONFIG_DUOVERO_H

/*
 * High Level Configuration Options
 */
#define CONFIG_DUOVERO
#define CONFIG_MACH_TYPE                MACH_TYPE_DUOVERO

#include <configs/ti_omap4_common.h>

#undef CONFIG_SYS_EMIF_PRECALCULATED_TIMING_REGS
#define CONFIG_SYS_AUTOMATIC_SDRAM_DETECTION
#define CONFIG_SYS_DEFAULT_LPDDR2_TIMINGS

/* USB UHH support options */
#define CONFIG_OMAP_EHCI_PHY1_RESET_GPIO 1
#define CONFIG_OMAP_EHCI_PHY2_RESET_GPIO 62

#define CONFIG_SYS_ENABLE_PADS_ALL

#define CONFIG_SMC911X
#define CONFIG_SMC911X_32_BIT
#define CONFIG_SMC911X_BASE		0x2C000000

/* GPIO */

/* ENV related config options */

#define CONFIG_ENV_VARS_UBOOT_RUNTIME_CONFIG

#endif /* __CONFIG_DUOVERO_H */
