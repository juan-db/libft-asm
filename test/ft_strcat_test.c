#include <stdio.h>
#include <string.h>

char* ft_strcat(char* s1, const char *s2);

int strcat_test_input_validation_null_str()
{
	ft_strcat(NULL, NULL);
	return 0;
}

int strcat_test_compare_strcat()
{
	char expected[14];
	char actual[14];
	const char* str1 = "Hello, ";
	const char* str2 = "World!";
	strcpy(expected, str1);
	strcpy(actual, str1);
	strcat(expected, str2);
	ft_strcat(actual, str2);

	if (strcmp(expected, actual) != 0)
	{
		fprintf(stderr, "\033[31mft_strcat does not match strcat with values '%s' and '%s'\n"
						"Expected: '%s'; Actual: '%s'\n\033[0m", str1, str2, expected, actual);
		return 1;
	}
	else
	{
		return 0;
	}
}

int strcat_test_compare_strcat_empty_string()
{
	char expected[1];
	char actual[1];
	const char* str1 = "";
	const char* str2 = "";
	strcpy(expected, str1);
	strcpy(actual, str1);
	strcat(expected, str2);
	ft_strcat(actual, str2);

	if (strcmp(expected, actual) != 0)
	{
		fprintf(stderr, "\033[31mft_strcat does not match strcat with values '%s' and '%s'\n"
						"Expected: '%s'; Actual: '%s'\n\033[0m", str1, str2, expected, actual);
		return 1;
	}
	else
	{
		return 0;
	}
}