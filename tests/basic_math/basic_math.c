#include "harness.h"

int main(void)
{
	harness_init();

	harness_begin();

	printf("2+2=%d\n", 2+2);
	printf("2-2=%d\n", 2-2);
	printf("2*2=%d\n", 2*2);
	printf("2/2=%d\n", 2/2);

	harness_end();

	harness_shutdown();
	return 0;
}
