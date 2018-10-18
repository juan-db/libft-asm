#include <stdio.h>
#include <ctype.h>

int ft_isalpha(int c);

/**
 *	Returns non-zero if the tests failed.
 */
int isalpha_test_compare_isalpha()
{
	unsigned char c = 0;
	int failed = 0;
	for (unsigned char e = 0 - 1; c < e; ++c)
	{
		int expected = isalpha(c);
		int actual = ft_isalpha(c);
		if ((actual && !expected) || (!actual && expected))
		{
			failed = 1;
			fprintf(stderr, "\033[31mft_isalpha does not match isalpha with value %hhu ('%c')\nExpected: %d; Actual: %d\033[0m\n", c, c, expected, actual);
		}
	}
	int expected = isalpha(c);
	int actual = ft_isalpha(c);
	if ((actual && !expected) || (!actual && expected))
	{
		failed = 1;
		fprintf(stderr, "\033[31mft_isalpha does not match isalpha with value %hhu ('%c')\nExpected: %d; Actual: %d\033[0m\n", c, c, expected, actual);
	}
	return failed;
}