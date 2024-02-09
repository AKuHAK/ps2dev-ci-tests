#pragma once

#include <stdio.h>

#include <kernel.h>
#include <ps2_poweroff_driver.h>
#include <sbv_patches.h>
#include <libpwroff.h>
#include <sifrpc.h>

void harness_init()
{
	SifInitRpc(0);
	sbv_patch_enable_lmb();
	sbv_patch_disable_prefix_check();
	init_poweroff_driver();
}

void harness_shutdown()
{
	poweroffShutdown();
}

void harness_begin()
{
	printf("===!BEGIN\n");
}

void harness_end()
{
	printf("===!END\n");
}
