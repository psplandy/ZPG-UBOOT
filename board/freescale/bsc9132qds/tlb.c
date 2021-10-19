/*
 * Copyright 2013 Freescale Semiconductor, Inc.
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#include <common.h>
#include <asm/mmu.h>

struct fsl_e_tlb_entry tlb_table[] = {
	/* TLB 0 - for temp stack in cache */
	SET_TLB_ENTRY(0, CONFIG_SYS_INIT_RAM_ADDR, CONFIG_SYS_INIT_RAM_ADDR,
			MAS3_SX|MAS3_SW|MAS3_SR, 0,
			0, 0, BOOKE_PAGESZ_4K, 0),
	SET_TLB_ENTRY(0, CONFIG_SYS_INIT_RAM_ADDR + 4 * 1024 ,
			CONFIG_SYS_INIT_RAM_ADDR + 4 * 1024,
			MAS3_SX|MAS3_SW|MAS3_SR, 0,
			0, 0, BOOKE_PAGESZ_4K, 0),
	SET_TLB_ENTRY(0, CONFIG_SYS_INIT_RAM_ADDR + 8 * 1024 ,
			CONFIG_SYS_INIT_RAM_ADDR + 8 * 1024,
			MAS3_SX|MAS3_SW|MAS3_SR, 0,
			0, 0, BOOKE_PAGESZ_4K, 0),
	SET_TLB_ENTRY(0, CONFIG_SYS_INIT_RAM_ADDR + 12 * 1024 ,
			CONFIG_SYS_INIT_RAM_ADDR + 12 * 1024,
			MAS3_SX|MAS3_SW|MAS3_SR, 0,
			0, 0, BOOKE_PAGESZ_4K, 0),

	/* TLB 1 */
	/* *I*** - Covers boot page */
	SET_TLB_ENTRY(1, 0xfffff000, 0xfffff000,
		      MAS3_SX|MAS3_SW|MAS3_SR, MAS2_I|MAS2_G,
		      0, 0, BOOKE_PAGESZ_4K, 1),
#ifdef CONFIG_SPL_NAND_BOOT
	SET_TLB_ENTRY(1, 0xffffe000, 0xffffe000,
		      MAS3_SX|MAS3_SW|MAS3_SR, MAS2_I|MAS2_G,
		      0, 10, BOOKE_PAGESZ_4K, 1),
#endif

	/* *I*G* - CCSRBAR (PA) */
	SET_TLB_ENTRY(1, CONFIG_SYS_CCSRBAR, CONFIG_SYS_CCSRBAR_PHYS,
			MAS3_SX|MAS3_SW|MAS3_SR, MAS2_I|MAS2_G,
			0, 1, BOOKE_PAGESZ_1M, 1),

	/* CCSRBAR (DSP) */
	SET_TLB_ENTRY(1, CONFIG_SYS_FSL_DSP_CCSRBAR,
		      CONFIG_SYS_FSL_DSP_CCSRBAR_PHYS, MAS3_SW|MAS3_SR,
		      MAS2_I|MAS2_G, 0, 2, BOOKE_PAGESZ_1M, 1),

#ifndef CONFIG_SPL_BUILD
	SET_TLB_ENTRY(1, CONFIG_SYS_FLASH_BASE, CONFIG_SYS_FLASH_BASE_PHYS,
			MAS3_SX|MAS3_SR, MAS2_W|MAS2_G,
			0, 3, BOOKE_PAGESZ_64M, 1),

	SET_TLB_ENTRY(1, CONFIG_SYS_FLASH_BASE + 0x4000000,
			CONFIG_SYS_FLASH_BASE_PHYS + 0x4000000,
			MAS3_SX|MAS3_SR, MAS2_W|MAS2_G,
			0, 4, BOOKE_PAGESZ_64M, 1),

#ifdef CONFIG_PCI
	/* *I*G* - PCI */
	SET_TLB_ENTRY(1, CONFIG_SYS_PCIE1_MEM_VIRT, CONFIG_SYS_PCIE1_MEM_PHYS,
			MAS3_SX|MAS3_SW|MAS3_SR, MAS2_I|MAS2_G,
			0, 6, BOOKE_PAGESZ_256M, 1),

	/* *I*G* - PCI I/O */
	SET_TLB_ENTRY(1, CONFIG_SYS_PCIE1_IO_VIRT, CONFIG_SYS_PCIE1_IO_PHYS,
			MAS3_SX|MAS3_SW|MAS3_SR, MAS2_I|MAS2_G,
			0, 7, BOOKE_PAGESZ_64K, 1),
#endif
#endif

#if defined(CONFIG_SYS_RAMBOOT) || defined(CONFIG_SPL)
	SET_TLB_ENTRY(1, CONFIG_SYS_DDR_SDRAM_BASE, CONFIG_SYS_DDR_SDRAM_BASE,
		      MAS3_SX|MAS3_SW|MAS3_SR, 0,
		      0, 8, BOOKE_PAGESZ_1G, 1),
#endif

#ifdef CONFIG_SYS_FPGA_BASE
		/* *I*G - Board FPGA  */
	SET_TLB_ENTRY(1, CONFIG_SYS_FPGA_BASE, CONFIG_SYS_FPGA_BASE_PHYS,
			MAS3_SX|MAS3_SW|MAS3_SR, MAS2_I|MAS2_G,
			0, 9, BOOKE_PAGESZ_256K, 1),
#endif

#ifdef CONFIG_SYS_NAND_BASE_PHYS
	SET_TLB_ENTRY(1, CONFIG_SYS_NAND_BASE, CONFIG_SYS_NAND_BASE_PHYS,
			MAS3_SX|MAS3_SW|MAS3_SR, MAS2_I|MAS2_G,
			0, 5, BOOKE_PAGESZ_1M, 1),
#endif
};

int num_tlb_entries = ARRAY_SIZE(tlb_table);
