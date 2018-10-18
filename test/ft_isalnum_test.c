#include <stdio.h>
#include <ctype.h>

int ft_isalnum(int c);

/**
 *	Returns non-zero if the tests failed.
 */
int isalnum_test_compare_isalnum()
{
	unsigned char c = 0;
	int failed = 0;
	for (unsigned char e = 0 - 1; c < e; ++c)
	{
		int expected = isalnum(c);
		int actual = ft_isalnum(c);
		if ((actual && !expected) || (!actual && expected))
		{
			failed = 1;
			fprintf(stderr, "\033[31mft_isalnum does not match isalnum with value %hhu ('%c')\nExpected: %d; Actual: %d\033[0m\n", c, c, expected, actual);
		}
	}
	int expected = isalnum(c);
	int actual = ft_isalnum(c);
	if ((actual && !expected) || (!actual && expected))
	{
		failed = 1;
		fprintf(stderr, "\033[31mft_isalnum does not match isalnum with value %hhu ('%c')\nExpected: %d; Actual: %d\033[0m\n", c, c, expected, actual);
	}
	return failed;
}