// SPDX-License-Identifier: GPL-2.0+

#include <env.h>
#include <fdt_support.h>
#include <spl.h>

DECLARE_GLOBAL_DATA_PTR;

int board_init(void)
{
        return 0;
}

int dram_init(void)
{
        return fdtdec_setup_mem_size_base();
}

int dram_init_banksize(void)
{
        return fdtdec_setup_memory_banksize();
}

#ifdef CONFIG_BOARD_LATE_INIT
int board_late_init(void)
{
        char fdtfile[50];

        snprintf(fdtfile, sizeof(fdtfile), "%s.dtb", CONFIG_DEFAULT_DEVICE_TREE);

        env_set("fdtfile", fdtfile);

        return 0;
}
#endif
