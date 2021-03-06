/*
 * Copyright (C) 2014, Bin Meng <bmeng.cn@gmail.com>
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#include <common.h>
#include <mmc.h>
#include <pci_ids.h>
#include <asm/irq.h>
#include <asm/mrccache.h>
#include <asm/post.h>

#ifndef CONFIG_EFI_APP
int arch_cpu_init(void)
{
	post_code(POST_CPU_INIT);

	return x86_cpu_init_f();
}

int arch_misc_init(void)
{
	if (!ll_boot_init())
		return 0;

#ifdef CONFIG_ENABLE_MRC_CACHE
	/*
	 * We intend not to check any return value here, as even MRC cache
	 * is not saved successfully, it is not a severe error that will
	 * prevent system from continuing to boot.
	 */
	mrccache_save();
#endif

	return 0;
}

#endif

void reset_cpu(ulong addr)
{
	/* cold reset */
	x86_full_reset();
}
