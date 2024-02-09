#include "harness.h"

int main(void)
{
	harness_init();

	harness_begin();

	printf("Hello, World!\n");
	printf("%d\n", 42);
	printf("%s\n", "Hello, World!");
	printf("%X\n", 0xdeadbeef);
	printf("%x\n", 0xdeadbeef);

	harness_end();

	harness_shutdown();
	return 0;
}
