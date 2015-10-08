/*
 * DRAM init helper functions
 *
 * (C) Copyright 2015 Hans de Goede <hdegoede@redhat.com>
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#include <common.h>
#include <types.h>
#include <asm/io.h>
#include <mach/dram_sun4i.h>

/* FIXME */
#define CONFIG_SYS_SDRAM_BASE	0x40000000

/*
 * Wait up to 1s for value to be set in given part of reg.
 */
void mctl_await_completion(u32 *reg, u32 mask, u32 val)
{
//	unsigned long tmo = timer_get_us() + 1000000;

	while ((readl(reg) & mask) != val) {
//		if (timer_get_us() > tmo)
//			printk(KERN_ERR "Timeout initialising DRAM\n");
	}
}

/*
 * Test if memory at offset offset matches memory at begin of DRAM
 */
bool mctl_mem_matches(u32 offset)
{
	/* Try to write different values to RAM at two addresses */
	writel(0, CONFIG_SYS_SDRAM_BASE);
	writel(0xaa55aa55, CONFIG_SYS_SDRAM_BASE + offset);
	/* Check if the same value is actually observed when reading back */
	return readl(CONFIG_SYS_SDRAM_BASE) ==
	       readl(CONFIG_SYS_SDRAM_BASE + offset);
}
