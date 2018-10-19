#include <stdio.h>
#include <string.h>
#include "test.h"
#include "libfts.h"

static void print_array(FILE* stream, void* s, size_t bytes);

int memset_test_input_validation_null_str()
{
	ft_memset(NULL, 0, 0);
	return 0;
}

int memset_test_input_validation_negative_len()
{
	ft_memset(NULL, 0, -1000);
	return 0;
}

int memset_test_compare_memset()
{
	char expected[16];
	bzero(expected, 16);
	char actual[16];
	bzero(actual, 16);
	memset((void*)expected, 'c', 16);
	ft_memset((void*)actual, 'c', 16);
	if (memcmp((void*)expected, (void*)actual, 16))
	{
		fprintf(stderr, "\033[31mft_memset does not match the behaviour of memset with input [char[16], 'c', 16]\n");
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

int memset_test_compare_memset_larger_than_char_value()
{
	char expected[16];
	bzero(expected, 16);
	char actual[16];
	bzero(actual, 16);
	memset((void*)expected, 0x5044, 16);
	ft_memset((void*)actual, 0x5044, 16);
	if (memcmp((void*)expected, (void*)actual, 16))
	{
		fprintf(stderr, "\033[31mft_memset does not match the behaviour of memset with input [char[16], 0x5044, 16]\n");
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


int memset_test_compare_memset_zero_nbyte()
{
	char expected[16];
	bzero(expected, 16);
	char actual[16];
	bzero(actual, 16);
	memset((void*)expected, 'c', 0);
	ft_memset((void*)actual, 'c', 0);
	if (memcmp((void*)expected, (void*)actual, 16))
	{
		fprintf(stderr, "\033[31mft_memset does not match the behaviour of memset with input [char[16], 'c', 0]\n");
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
	if (bytes > 0)
	{
		unsigned char* buff = (unsigned char*)s;
		fprintf(stream, "%hhu (%c)", *buff, *buff);
		++buff;
		while (--bytes)
		{
			fprintf(stream, ", %hhu (%c)", *buff, *buff);
			++buff;
		}
		fprintf(stream, "\n");
	}
}