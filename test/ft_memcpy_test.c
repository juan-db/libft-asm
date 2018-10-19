#include <stdio.h>
#include <string.h>
#include "test.h"
#include "libfts.h"

static void print_array(FILE* stream, void* s, size_t bytes);

int memcpy_test_input_validation_null_dest()
{
	ft_memcpy(NULL, (void*)1, 0);
	return 0;
}

int memcpy_test_input_validation_null_src()
{
	ft_memcpy((void*)1, NULL, 0);
	return 0;
}

int memcpy_test_input_validation_negative_n()
{
	ft_memcpy((void*)1, (void*)1, -10);
	return 0;
}

int memcpy_test_compare_memcpy()
{
	// Assign
	const char* str = "Hello, World!";
	char expected[16];
	bzero(expected, 16);
	char actual[16];
	bzero(actual, 16);

	// Act
	memcpy((void*)expected, str, 14);
	ft_memcpy((void*)actual, str, 14);

	// Assert
	if (memcmp((void*)expected, (void*)actual, 16))
	{
		fprintf(stderr, "\033[31mft_memcpy does not match the behaviour of memcpy with input [char[16], \"%s\", 14]\n", str);
		fprintf(stderr, "Expected: ");
		print_array(stderr, expected, 16);
		fprintf(stderr, "Actual: ");
		print_array(stderr, actual, 16);
		return 1;
	}
	else
	{
		return 0;
	}
}


int memcpy_test_compare_memcpy_zero_nbyte()
{
	const char* str = "Hello, World!";
	char expected[16];
	bzero(expected, 16);
	char actual[16];
	bzero(actual, 16);

	memcpy((void*)expected, str, 0);
	ft_memcpy((void*)actual, str, 0);
	if (memcmp((void*)expected, (void*)actual, 16))
	{
		fprintf(stderr, "\033[31mft_memcpy does not match the behaviour of memcpy with input [char[16], \"%s\", 0]\n", str);
		fprintf(stderr, "Expected: ");
		print_array(stderr, expected, 16);
		fprintf(stderr, "Actual: ");
		print_array(stderr, actual, 16);
		return 1;
	}
	else
	{
		return 0;
	}
}

static void print_array(FILE* stream, void* s, size_t bytes)
{
	unsigned char* buff = (unsigned char*)s;
	fprintf(stream, "%hhu", *buff);
	++buff;
	for (size_t counter = 0; counter < bytes; ++counter)
	{
		fprintf(stream, ", %hhu", *buff);
	}
	fprintf(stream, "\n");
}