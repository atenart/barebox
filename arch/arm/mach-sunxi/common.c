/*
 * Copyright (C) 2014 Antoine Tenart
 *
 * Antoine Tenart <antoine.tenart@free-electrons.com>
 *
 * This file is licensed under the terms of the GNU General Public
 * License version 2. This program is licensed "as is" without any
 * warranty of any kind, whether express or implied.
 */

#include <asm/memory.h>
#include <common.h>
#include <init.h>
#include <io.h>
#include <linux/clk.h>

#include <mach/debug_ll.h>

#if 0
#include <ns16550.h>
#include <linux/clkdev.h>

#define CONSOLE_UART_BASE		0x01c28000

static struct NS16550_plat uart_plat = {
	.shift = 2,
};
#endif

void __noreturn reset_cpu(unsigned long addr)
{
	while (1)
	;
}
EXPORT_SYMBOL(reset_cpu);

static int sunxi_init_soc(void)
{
#if 0
	struct clk *tclk;

	barebox_set_model("Allwinner A1X");
	barebox_set_hostname("sunxi");

	tclk = clk_fixed("tclk", 24000000);
	clkdev_add_physbase(tclk, (unsigned int)0x01c20c00, NULL);

	uart_plat.clock = clk_get_rate(tclk);
	add_ns16550_device(DEVICE_ID_DYNAMIC,
			   (unsigned int)CONSOLE_UART_BASE, 0x400,
			   IORESOURCE_MEM | IORESOURCE_MEM_32BIT,
			   &uart_plat);
#endif
	/* All is parsed from DT */

	PUTC_LL('a');

	return 0;
}
core_initcall(sunxi_init_soc);
