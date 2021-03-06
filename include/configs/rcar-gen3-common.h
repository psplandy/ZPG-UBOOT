/*
 * include/configs/rcar-gen3-common.h
 *	This file is R-Car Gen3 common configuration file.
 *
 * Copyright (C) 2015-2017 Renesas Electronics Corporation
 *
 * SPDX-License-Identifier: GPL-2.0+
 */

#ifndef __RCAR_GEN3_COMMON_H
#define __RCAR_GEN3_COMMON_H

#include <asm/arch/rmobile.h>

#define CONFIG_CMD_EXT2
#define CONFIG_CMD_EXT4
#define CONFIG_CMD_EXT4_WRITE

#define CONFIG_REMAKE_ELF

/* boot option */
#define CONFIG_SUPPORT_RAW_INITRD

/* Support File sytems */
#define CONFIG_SUPPORT_VFAT
#define CONFIG_FS_EXT4
#define CONFIG_EXT4_WRITE

#define CONFIG_CMDLINE_TAG
#define CONFIG_SETUP_MEMORY_TAGS
#define CONFIG_INITRD_TAG
#define CONFIG_CMDLINE_EDITING

#undef	CONFIG_SHOW_BOOT_PROGRESS

#define CONFIG_ARCH_CPU_INIT

#define CONFIG_SH_GPIO_PFC

/* console */
#define CONFIG_SYS_CBSIZE		2048
#define CONFIG_SYS_BARGSIZE		CONFIG_SYS_CBSIZE
#define CONFIG_SYS_LONGHELP
#define CONFIG_SYS_MAXARGS		64
#define CONFIG_SYS_BAUDRATE_TABLE	{ 115200, 38400 }

/* MEMORY */
#define CONFIG_SYS_TEXT_BASE		0x50000000
#define CONFIG_SYS_INIT_SP_ADDR		(CONFIG_SYS_TEXT_BASE + 0x7fff0)

#define DRAM_RSV_SIZE			0x08000000
#if defined(CONFIG_R8A7795)
#define CONFIG_NR_DRAM_BANKS		4
#define PHYS_SDRAM_1			(0x40000000 + DRAM_RSV_SIZE)
#define PHYS_SDRAM_1_SIZE		(0x40000000u - DRAM_RSV_SIZE)
#define PHYS_SDRAM_2			0x500000000
#define PHYS_SDRAM_2_SIZE		0x40000000u
#define PHYS_SDRAM_3			0x600000000
#define PHYS_SDRAM_3_SIZE		0x40000000u
#define PHYS_SDRAM_4			0x700000000
#define PHYS_SDRAM_4_SIZE		0x40000000u
#define CONFIG_SYS_SDRAM_BASE		PHYS_SDRAM_1
#define CONFIG_SYS_SDRAM_SIZE		PHYS_SDRAM_1_SIZE
#elif defined(CONFIG_R8A7796)
#define CONFIG_NR_DRAM_BANKS		2
#define PHYS_SDRAM_1			(0x40000000 + DRAM_RSV_SIZE)
#define PHYS_SDRAM_1_SIZE		(0x80000000u - DRAM_RSV_SIZE)
#define PHYS_SDRAM_2			0x0600000000
#define PHYS_SDRAM_2_SIZE		0x80000000u
#define CONFIG_SYS_SDRAM_BASE		PHYS_SDRAM_1
#define CONFIG_SYS_SDRAM_SIZE		PHYS_SDRAM_1_SIZE
#endif
#define CONFIG_SYS_LOAD_ADDR		0x48080000
#define CONFIG_VERY_BIG_RAM
#define CONFIG_MAX_MEM_MAPPED		CONFIG_SYS_SDRAM_SIZE

#define CONFIG_SYS_MONITOR_BASE		0x00000000
#define CONFIG_SYS_MONITOR_LEN		(256 * 1024)
#define CONFIG_SYS_MALLOC_LEN		(1 * 1024 * 1024)
#define CONFIG_SYS_BOOTMAPSZ		(8 * 1024 * 1024)

/* ENV setting */
#define CONFIG_ENV_OVERWRITE
#define CONFIG_ENV_SECT_SIZE	(128 * 1024)
#define CONFIG_ENV_SIZE		(CONFIG_ENV_SECT_SIZE)
#define CONFIG_ENV_SIZE_REDUND	(CONFIG_ENV_SIZE)

#define CONFIG_EXTRA_ENV_SETTINGS	\
	"fdt_high=0xffffffffffffffff\0"	\
	"initrd_high=0xffffffffffffffff\0"

#define CONFIG_BOOTCOMMAND	\
	"tftp 0x48080000 Image; " \
	"tftp 0x48000000 Image-"CONFIG_DEFAULT_FDT_FILE"; " \
	"booti 0x48080000 - 0x48000000"

#endif	/* __RCAR_GEN3_COMMON_H */
