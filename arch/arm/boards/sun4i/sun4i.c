#include <init.h>
#include <types.h>
#include <mach/dram_sun4i.h>

#define CONFIG_DRAM_CLK			360
#define CONFIG_DRAM_MBUS_CLK		300
#define CONFIG_DRAM_ZQ			123
#define CONFIG_DRAM_ODT_EN		0
#define CONFIG_DRAM_TPR3		0
#define CONFIG_DRAM_EMR1		4
#define CONFIG_DRAM_DQS_GATING_DELAY	0

static struct dram_para dram_para = {
	.clock = CONFIG_DRAM_CLK,
	.mbus_clock = CONFIG_DRAM_MBUS_CLK,
	.type = 3,
	.rank_num = 1,
	.density = 0,
	.io_width = 0,
	.bus_width = 0,
	.zq = CONFIG_DRAM_ZQ,
	.odt_en = CONFIG_DRAM_ODT_EN,
	.size = 0,
#if 1
	.cas = 9,
	.tpr0 = 0x42d899b7,
	.tpr1 = 0xa090,
	.tpr2 = 0x22a00,
	.emr2 = 0x10,
#else
#	include "dram_timings_sun4i.h"
	.active_windowing = 1,
#endif
	.tpr3 = CONFIG_DRAM_TPR3,
	.tpr4 = 0,
	.tpr5 = 0,
	.emr1 = CONFIG_DRAM_EMR1,
	.emr3 = 0,
	.dqs_gating_delay = CONFIG_DRAM_DQS_GATING_DELAY,
};

static int sun4i_dram_init(void)
{
	return dramc_init(&dram_para);
}

mem_initcall(sun4i_dram_init);
