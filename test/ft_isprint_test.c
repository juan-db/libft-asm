#include <stdio.h>
#include <ctype.h>

int ft_isprint(int c);

/**
 *	Returns non-zero if the tests failed.
 */
int isprint_test_compare_isprint()
{
	unsigned char c = 0;
	int failed = 0;
	for (unsigned char e = 0 - 1; c < e; ++c)
	{
		int expected = isprint(c);
		int actual = ft_isprint(c);
		if ((actual && !expected) || (!actual && expected))
		{
			failed = 1;
			fprintf(stderr, "\033[31mft_isprint does not match isprint with value %hhu ('%c')\nExpected: %d; Actual: %d\033[0m\n", c, c, expected, actual);
		}
	}
	int expected = isprint(c);
	int actual = ft_isprint(c);
	if ((actual && !expected) || (!actual && expected))
	{
		failed = 1;
		fprintf(stderr, "\033[31mft_isprint does not match isprint with value %hhu ('%c')\nExpected: %d; Actual: %d\033[0m\n", c, c, expected, actual);
	}
	return failed;
}