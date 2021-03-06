/*
 * Copyright (c) 2011 The Chromium OS Authors.
 * SPDX-License-Identifier:	GPL-2.0+
 */

#include <common.h>
#include <cros_ec.h>
#include <dm.h>
#include <os.h>
#include <asm/test.h>
#include <asm/u-boot-sandbox.h>

/*
 * Pointer to initial global data area
 *
 * Here we initialize it.
 */
gd_t *gd;

/* Add a simple GPIO device */
U_BOOT_DEVICE(gpio_sandbox) = {
	.name = "gpio_sandbox",
};

void flush_cache(unsigned long start, unsigned long size)
{
}

#ifndef CONFIG_TIMER
/* system timer offset in ms */
static unsigned long sandbox_timer_offset;

void sandbox_timer_add_offset(unsigned long offset)
{
	sandbox_timer_offset += offset;
}

unsigned long timer_read_counter(void)
{
	return os_get_nsec() / 1000 + sandbox_timer_offset * 1000;
}
#endif

int dram_init(void)
{
	gd->ram_size = CONFIG_SYS_SDRAM_SIZE;
	return 0;
}

#ifdef CONFIG_BOARD_LATE_INIT
int board_late_init(void)
{
	if (cros_ec_get_error()) {
		/* Force console on */
		gd->flags &= ~GD_FLG_SILENT;

		printf("cros-ec communications failure %d\n",
		       cros_ec_get_error());
		puts("\nPlease reset with Power+Refresh\n\n");
		panic("Cannot init cros-ec device");
		return -1;
	}
	return 0;
}
#endif
