#include <stdio.h>

#include <kernel.h>
#include <ps2_poweroff_driver.h>
#include <sbv_patches.h>
#include <libpwroff.h>
#include <sifrpc.h>

int main(void)
{
	SifInitRpc(0);
	sbv_patch_enable_lmb();
	sbv_patch_disable_prefix_check();
	init_poweroff_driver();

	printf("===!BEGIN\n");

	printf("Hello, World!\n");
	printf("%d\n", 42);
	printf("%s\n", "Hello, World!");
	printf("%X\n", 0xdeadbeef);
	printf("%x\n", 0xdeadbeef);

	printf("===!END\n");


	poweroffShutdown();
	return 0;
}
