#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "test.h"
#include "libfts.h"

int strdup_test_input_validation_null_str()
{
	ft_strdup(NULL);
	return 0;
}
int strdup_test_compare_strdup()
{
	// Assign
	const char* str = "Hello, World!";

	// Act
	char* expected = strdup(str);
	char* actual = ft_strdup(str);

	// Assert
	if (strcmp(expected, actual))
	{
		fprintf(stderr, "\033[31mft_strdup does not match the behaviour of strdup with input \"%s\"\n"
						"Expected: '%s'\nActual: '%s'\033[0m\n", str, expected, actual);
		free(expected);
		free(actual);
		return 1;
	}
	else
	{
		free(expected);
		free(actual);
		return 0;
	}
}


int strdup_test_compare_strdup_empty_string()
{
	const char* str = "";

	char* expected = strdup(str);
	char* actual = ft_strdup(str);

	if (strcmp(expected, actual))
	{
		fprintf(stderr, "\033[31mft_strdup does not match the behaviour of strdup with input \"%s\"\n"
						"Expected: '%s'\nActual: '%s'\033[0m\n", str, expected, actual);
		free(expected);
		free(actual);
		return 1;
	}
	else
	{
		free(expected);
		free(actual);
		return 0;
	}
}