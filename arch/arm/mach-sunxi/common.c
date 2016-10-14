/*
 * Copyright (C) 2014 Antoine Tenart
 *
 * Antoine Tenart <antoine.tenart@free-electrons.com>
 *
 * This file is licensed under the terms of the GNU General Public
 * License version 2. This program is licensed "as is" without any
 * warranty of any kind, whether express or implied.
 */

#include <asm/io.h>
#include <asm/memory.h>
#include <common.h>
#include <init.h>
#include <io.h>
#include <linux/clk.h>

#include <debug_ll.h>

#define CONFIG_SYS_CLK_FREQ	1008000000
#define PIO_BASE	0x01c20800

void clock_init_safe(void);
void clock_init_uart(void);
void clock_set_pll1(unsigned int hz);

void __noreturn reset_cpu(unsigned long addr)
{
	while (1)
	;
}
EXPORT_SYMBOL(reset_cpu);

static int sunxi_init_soc(void)
{
	void __iomem *base = IOMEM(PIO_BASE);
	u32 val;

	clock_init_safe();
	clock_init_uart();

	/*
	 * Fct M4:
	 * PE10: uart1-tx
	 * PE11: uart1-rx + pullup
	 */
	val = readl(base + 0x94);
	val |= BIT(10) | BIT(14);
	writel(val, base + 0x94);

	val = readl(base + 0xac);
	val |= BIT(22);
	writel(val, base + 0xac);

	clock_set_pll1(CONFIG_SYS_CLK_FREQ);

	/* All is parsed from DT */

	puts_ll("\n\nA\n");

	return 0;
}
core_initcall(sunxi_init_soc);
