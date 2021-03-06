/*
 * (C) Copyright 2011
 * Heiko Schocher, DENX Software Engineering, hs@denx.de.
 *
 * A bootcount driver for the RTC IP block found on many TI platforms.
 * This requires the RTC clocks, etc, to be enabled prior to use and
 * not all boards with this IP block on it will have the RTC in use.
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#include <bootcount.h>
#include <asm/davinci_rtc.h>

void bootcount_store(ulong a)
{
	struct davinci_rtc *reg =
		(struct davinci_rtc *)CONFIG_SYS_BOOTCOUNT_ADDR;

	/*
	 * write RTC kick register to enable write
	 * for RTC Scratch registers. Scratch0 and 1 are
	 * used for bootcount values.
	 */
	writel(RTC_KICK0R_WE, &reg->kick0r);
	writel(RTC_KICK1R_WE, &reg->kick1r);
	raw_bootcount_store(&reg->scratch2,
			    (BOOTCOUNT_MAGIC & 0xffff0000) | (a & 0x0000ffff));
}

ulong bootcount_load(void)
{
	unsigned long val;
	struct davinci_rtc *reg =
		(struct davinci_rtc *)CONFIG_SYS_BOOTCOUNT_ADDR;

	val = raw_bootcount_load(&reg->scratch2);
	if ((val & 0xffff0000) != (BOOTCOUNT_MAGIC & 0xffff0000))
		return 0;
	else
		return val & 0x0000ffff;
}
