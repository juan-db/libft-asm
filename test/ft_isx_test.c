#include <stdio.h>
#include <ctype.h>
#include "test.h"

typedef int(*isx_fun)(int);

/**
 *	Returns non-zero if the test fails. 
 */
static int test_pass(const char *name, int c, isx_fun ft_isx, isx_fun isx)
{
	int expected = isx(c);
	int actual = ft_isx(c);
	if ((actual && !expected) || (!actual && expected))
	{
		fprintf(stderr, "\033[31mft_%s does not match %s with value %hhu ('%c')\n"
						"Expected: %d; Actual: %d\033[0m\n", name, name, c, c, expected, actual);
		return 1;
	}
	else
	{
		return 0;
	}
}

/**
 *	Returns non-zero if the tests failed.
 */
int isx_test_compare_isx(const char *name, isx_fun ft_isx, isx_fun isx)
{
	unsigned char c = 0;
	int failed = 0;
	for (unsigned char e = 0 - 1; c < e; ++c)
	{
		if (!test_pass(name, c, ft_isx, isx))
		{
			failed = 1;
		}
	}
	if (!test_pass(name, c, ft_isx, isx))
	{
		failed = 1;
	}
	return failed;
}