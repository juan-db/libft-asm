#include <stdio.h>
#include <ctype.h>

int ft_isalpha(int c);

void test_compare_isalpha()
{
	unsigned char c = 0;
	for (unsigned char e = 0 - 1; c < e; ++c)
	{
		int expected = isalpha(c);
		int actual = ft_isalpha(c);
		if ((actual && !expected) || (!actual && expected))
		{
			fprintf(stderr, "ft_isalpha does not match isalpha with value %hhu ('%c')\nExpected: %d; Actual: %d\n", c, c, expected, actual);
		}
	}
	int expected = isalpha(c);
	int actual = ft_isalpha(c);
	if ((actual && !expected) || (!actual && expected))
	{
		fprintf(stderr, "ft_isalpha does not match isalpha with value %hhu ('%c')\nExpected: %d; Actual: %d\n", c, c, expected, actual);
	}
}

int main()
{
	test_compare_isalpha();
}