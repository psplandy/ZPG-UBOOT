/*
 * Copyright (C) 2013 Marek Vasut <marex@denx.de>
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */
#ifndef __CONFIGS_SANSA_FUZE_PLUS_H__
#define __CONFIGS_SANSA_FUZE_PLUS_H__

/* System configurations */
#define CONFIG_MX23				/* i.MX23 SoC */

/* U-Boot Commands */

/* Memory configuration */
#define CONFIG_NR_DRAM_BANKS		1		/* 1 bank of DRAM */
#define PHYS_SDRAM_1			0x40000000	/* Base address */
#define PHYS_SDRAM_1_SIZE		0x08000000	/* Max 128 MB RAM */
#define CONFIG_SYS_SDRAM_BASE		PHYS_SDRAM_1

/* Environment */
#define CONFIG_ENV_SIZE			(16 * 1024)
#define CONFIG_ENV_OVERWRITE

/* Booting Linux */
#define CONFIG_BOOTFILE		"uImage"
#define CONFIG_LOADADDR		0x42000000
#define CONFIG_SYS_LOAD_ADDR	CONFIG_LOADADDR

/* LCD */
#ifdef CONFIG_VIDEO
#define CONFIG_VIDEO_FONT_4X6
#define CONFIG_VIDEO_MXS_MODE_SYSTEM
#define CONFIG_SYS_BLACK_IN_WRITE
#define LCD_BPP	LCD_COLOR16
#endif

/* USB */
#ifdef CONFIG_CMD_USB
#define CONFIG_EHCI_MXS_PORT0
#define CONFIG_USB_MAX_CONTROLLER_COUNT 1

#define CONFIG_USB_ETHER
#define CONFIG_USB_ETH_CDC
#define CONFIG_NETCONSOLE
#endif

/* The rest of the configuration is shared */
#include <configs/mxs.h>

#endif	/* __CONFIGS_SANSA_FUZE_PLUS_H__ */
