#include <stdio.h>
#include <ctype.h>

int ft_isalnum(int c);

void isalnum_test_compare_isalnum()
{
	unsigned char c = 0;
	for (unsigned char e = 0 - 1; c < e; ++c)
	{
		int expected = isalnum(c);
		int actual = ft_isalnum(c);
		if ((actual && !expected) || (!actual && expected))
		{
			fprintf(stderr, "ft_isalnum does not match isalnum with value %hhu ('%c')\nExpected: %d; Actual: %d\n", c, c, expected, actual);
		}
	}
	int expected = isalnum(c);
	int actual = ft_isalnum(c);
	if ((actual && !expected) || (!actual && expected))
	{
		fprintf(stderr, "ft_isalnum does not match isalnum with value %hhu ('%c')\nExpected: %d; Actual: %d\n", c, c, expected, actual);
	}
}