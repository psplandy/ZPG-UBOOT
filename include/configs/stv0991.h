/*
 * (C) Copyright 2014
 * Vikas Manocha, STMicroelectronics, <vikas.manocha@st.com>
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#ifndef __CONFIG_STV0991_H
#define __CONFIG_STV0991_H
#define CONFIG_SYS_DCACHE_OFF
#define CONFIG_SYS_EXCEPTION_VECTORS_HIGH

#define CONFIG_SYS_CORTEX_R4

/* ram memory-related information */
#define CONFIG_NR_DRAM_BANKS			1
#define PHYS_SDRAM_1				0x00000000
#define CONFIG_SYS_SDRAM_BASE			PHYS_SDRAM_1
#define PHYS_SDRAM_1_SIZE			0x00198000

#define CONFIG_ENV_SIZE				0x10000
#define CONFIG_ENV_SECT_SIZE			CONFIG_ENV_SIZE
#define CONFIG_ENV_OFFSET			0x30000
#define CONFIG_ENV_ADDR				\
	(PHYS_SDRAM_1_SIZE - CONFIG_ENV_SIZE)
#define CONFIG_SYS_MALLOC_LEN			(CONFIG_ENV_SIZE + 16 * 1024)

/* serial port (PL011) configuration */
#define CONFIG_PL01X_SERIAL

/* user interface */
#define CONFIG_SYS_CBSIZE			1024

/* MISC */
#define CONFIG_SYS_LOAD_ADDR			0x00000000
#define CONFIG_SYS_INIT_RAM_SIZE		0x8000
#define CONFIG_SYS_INIT_RAM_ADDR		0x00190000
#define CONFIG_SYS_INIT_SP_OFFSET		\
	(CONFIG_SYS_INIT_RAM_SIZE - GENERATED_GBL_DATA_SIZE)
/* U-Boot Load Address */
#define CONFIG_SYS_TEXT_BASE			0x00010000
#define CONFIG_SYS_INIT_SP_ADDR			\
	(CONFIG_SYS_INIT_RAM_ADDR + CONFIG_SYS_INIT_SP_OFFSET)

/* GMAC related configs */

#define CONFIG_MII
#define CONFIG_DW_ALTDESCRIPTOR

/* Command support defines */
#define CONFIG_PHY_RESET_DELAY			10000		/* in usec */

#define CONFIG_SYS_MEMTEST_START               0x0000
#define CONFIG_SYS_MEMTEST_END                 1024*1024

/* Misc configuration */
#define CONFIG_SYS_LONGHELP
#define CONFIG_CMDLINE_EDITING

#define CONFIG_BOOTCOMMAND                     "go 0x40040000"

/*
+ * QSPI support
+ */
#ifdef CONFIG_OF_CONTROL		/* QSPI is controlled via DT */
#define CONFIG_CQSPI_DECODER		0
#define CONFIG_CQSPI_REF_CLK		((30/4)/2)*1000*1000

#endif

#endif /* __CONFIG_H */
