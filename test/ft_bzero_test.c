#include <unistd.h>
#include <string.h>
#include <stdio.h>

#define ARRAY_LENGTH 14
#define STRING "Hello, world!"

void ft_bzero(void* s, size_t n);

/**
 *	Returns non-zero if the test fails.
 */
int bzero_test_input_validation()
{
	// Assign
	char* buff = NULL;
	size_t count = 2;

	// Act
	ft_bzero(buff, count);

	return 0;
}

/**
 *	Returns non-zero if the test fails.
 */
int bzero_test_input_validation_2()
{
	// Assign
	char* buff = (char*)1;
	size_t count = 0;

	// Act
	ft_bzero(buff, count);

	return 0;
}

/**
 *	Returns non-zero if the test fails.
 */
int bzero_test_compare_bzero()
{
	// Assign
	char chars1[ARRAY_LENGTH];
	char chars2[ARRAY_LENGTH];

	strcpy(chars1, STRING);
	strcpy(chars2, STRING);

	// Act
	bzero(chars1, ARRAY_LENGTH);
	ft_bzero(chars2, ARRAY_LENGTH);

	// Assert
	int result = memcmp(chars1, chars2, ARRAY_LENGTH);

	if (result != 0)
	{
		fprintf(stderr, "\033[31mft_bzero behaviour does not match bzero...\n\033[0m");
		return 1;
	}
	else
	{
		return 0;
	}
}