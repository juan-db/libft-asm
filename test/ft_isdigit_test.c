#include <stdio.h>
#include <ctype.h>

int ft_isdigit(int c);

/**
 *	Returns non-zero if the tests failed.
 */
int isdigit_test_compare_isdigit()
{
	unsigned char c = 0;
	int failed = 0;
	for (unsigned char e = 0 - 1; c < e; ++c)
	{
		int expected = isdigit(c);
		int actual = ft_isdigit(c);
		if ((actual && !expected) || (!actual && expected))
		{
			failed = 1;
			fprintf(stderr, "\033[31mft_isdigit does not match isdigit with value %hhu ('%c')\nExpected: %d; Actual: %d\033[0m\n", c, c, expected, actual);
		}
	}
	int expected = isdigit(c);
	int actual = ft_isdigit(c);
	if ((actual && !expected) || (!actual && expected))
	{
		failed = 1;
		fprintf(stderr, "\033[31mft_isdigit does not match isdigit with value %hhu ('%c')\nExpected: %d; Actual: %d\033[0m\n", c, c, expected, actual);
	}
	return failed;
}