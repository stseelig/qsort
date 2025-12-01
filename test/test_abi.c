
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int
compare(const void *const a, const void *const b)
/*@*/
{
	return memcmp(a, b, sizeof(char));
}

int
main(void)
{
	char test_array[] = "21308947253712709854627193469127";

	(void) puts(test_array);
	qsort(test_array, (sizeof test_array) - 1u, sizeof(char), compare);
	(void) puts(test_array);

	return 0;
}
