#include <stdio.h>
#include <ctype.h>
#include "test.h"

/**
 *	Returns non-zero if the test fails. 
 */
static int test_pass(const char *name, int c, ctype_fun ft_ctype, ctype_fun ctype)
{
	int expected = ctype(c);
	int actual = ft_ctype(c);
	if (actual != expected)
	{
		fprintf(stderr, "\033[31mft_%s does not match %s with value %hhu ('%c')\n"
						"Expected: %d; Actual: %d\033[0m\n", name, name,
						(unsigned char)c, (unsigned char)c, expected, actual);
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
int tox_test_compare_tox(const char *name, ctype_fun ft_ctype, ctype_fun ctype)
{
	unsigned char c = 0;
	int failed = 0;
	for (unsigned char e = 0 - 1; c < e; ++c)
	{
		if (test_pass(name, c, ft_ctype, ctype))
		{
			failed = 1;
		}
	}
	if (test_pass(name, c, ft_ctype, ctype))
	{
		failed = 1;
	}
	return failed;
}