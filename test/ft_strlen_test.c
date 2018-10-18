#include <stdio.h>
#include <stddef.h>
#include <string.h>

size_t ft_strlen(const char *s);

int strlen_test_input_validation_null_str()
{
	const char* str = NULL;
	ft_strlen(str);
	return 0;
}

int strlen_test_compare_strlen()
{
	const char* str = "Hello, World!";
	size_t expected = strlen(str);
	size_t actual = ft_strlen(str);
	if (actual != expected)
	{
		fprintf(stderr, "\033[31mft_strlen does not match strlen with value '%s'\nExpected: %zu; Actual: %zu\033[0m\n", str, expected, actual);
		return 1;
	}
	else
	{
		return 0;
	}
}

int strlen_test_compare_strlen_empty_string()
{
	const char* str = "";
	size_t expected = strlen(str);
	size_t actual = ft_strlen(str);
	if (actual != expected)
	{
		fprintf(stderr, "\033[31mft_strlen does not match strlen with value '%s'\nExpected: %zu; Actual: %zu\n\033[0m", str, expected, actual);
		return 1;
	}
	else
	{
		return 0;
	}
}