#include "harness.h"

int main()
{
	harness_init();

	harness_begin();

	printf("yoo!\n");

	printf("===!END\n");

	harness_end();

	harness_shutdown();
	return 0;
}
