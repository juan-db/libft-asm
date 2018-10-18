#include <stdio.h>

int ft_puts(const char* s);

int puts_test_input_validation_null_str()
{
	const char* str = NULL;
	int expected = puts(str);
	int actual = ft_puts(str);
	if (expected < 0 && actual >= 0)
	{
		fprintf(stderr, "\033[31mft_puts does not match puts with value '%s'\nExpected: %d; Actual: %d\n\033[0m", str, expected, actual);
		return 1;
	}
	else
	{
		return 0;
	}
}

int puts_test_compare_puts()
{
	const char* str = "Hello, World!";
	int expected = puts(str);
	int actual = ft_puts(str);
	if (expected < 0 && actual >= 0)
	{
		fprintf(stderr, "\033[31mft_puts does not match puts with value '%s'\nExpected: %d; Actual: %d\n\033[0m", str, expected, actual);
		return 1;
	}
	else
	{
		return 0;
	}
}

int puts_test_compare_puts_empty_string()
{
	const char* str = "";
	int expected = puts(str);
	int actual = ft_puts(str);
	if (expected < 0 && actual >= 0)
	{
		fprintf(stderr, "\033[31mft_puts does not match puts with value '%s'\nExpected: %d; Actual: %d\n\033[0m", str, expected, actual);
		return 1;
	}
	else
	{
		return 0;
	}
}