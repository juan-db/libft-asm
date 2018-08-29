#include <stdio.h>
#include <ctype.h>

int ft_isdigit(int c);

void isdigit_test_compare_isdigit()
{
	unsigned char c = 0;
	for (unsigned char e = 0 - 1; c < e; ++c)
	{
		int expected = isdigit(c);
		int actual = ft_isdigit(c);
		if ((actual && !expected) || (!actual && expected))
		{
			fprintf(stderr, "ft_isdigit does not match isdigit with value %hhu ('%c')\nExpected: %d; Actual: %d\n", c, c, expected, actual);
		}
	}
	int expected = isdigit(c);
	int actual = ft_isdigit(c);
	if ((actual && !expected) || (!actual && expected))
	{
		fprintf(stderr, "ft_isdigit does not match isdigit with value %hhu ('%c')\nExpected: %d; Actual: %d\n", c, c, expected, actual);
	}
}