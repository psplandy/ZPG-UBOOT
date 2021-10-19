/*
 * (C) Copyright 2016
 * Vikas Manocha, STMicroelectronics, <vikas.manocha@st.com>
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#ifndef _ASM_ARCH_HARDWARE_H
#define _ASM_ARCH_HARDWARE_H

#include <asm/arch-stm32/stm32f.h>

static const u32 sect_sz_kb[CONFIG_SYS_MAX_FLASH_SECT] = {
	[0 ... 3] =	32 * 1024,
	[4] =		128 * 1024,
	[5 ... 7] =	256 * 1024
};

#endif /* _ASM_ARCH_HARDWARE_H */
