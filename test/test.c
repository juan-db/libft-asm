#include <stdio.h>
#include <ctype.h>
#include "libfts.h"
#include "test.h"

static void test_suite(const char *name, test_fun* test_funs, int test_count);
static void tests_passed_print(const char* name);

int main(void)
{
	// ========= bzero =========
	test_fun bzero_tests[] = {&bzero_test_input_validation,
							  &bzero_test_input_validation_2,
							  &bzero_test_compare_bzero};
	test_suite("bzero", bzero_tests, sizeof(bzero_tests) / sizeof(test_fun));


	// ========= strcat =========
	test_fun strcat_tests[] = {&strcat_test_input_validation_null_str,
							   &strcat_test_compare_strcat,
							   &strcat_test_compare_strcat_empty_string};
	test_suite("strcat", strcat_tests, sizeof(strcat_tests) / sizeof(test_fun));


	// ========= ctype =========
	if (!ctype_test_compare_ctype("isalpha", &ft_isalpha, &isalpha))
		tests_passed_print("isalpha");
	if (!ctype_test_compare_ctype("isdigit", &ft_isdigit, &isdigit))
		tests_passed_print("isdigit");
	if (!ctype_test_compare_ctype("isalnum", &ft_isalnum, &isalnum))
		tests_passed_print("isalnum");
	if (!ctype_test_compare_ctype("isascii", &ft_isascii, &isascii))
		tests_passed_print("isascii");
	if (!ctype_test_compare_ctype("isprint", &ft_isprint, &isprint))
		tests_passed_print("isprint");
	if (!tox_test_compare_tox("toupper", &ft_toupper, &toupper))
		tests_passed_print("toupper");
	if (!tox_test_compare_tox("tolower", &ft_tolower, &tolower))
		tests_passed_print("tolower");


	// ========= puts =========
	test_fun puts_tests[] = {&puts_test_input_validation_null_str,
							 &puts_test_compare_puts,
							 &puts_test_compare_puts_empty_string};
	test_suite("puts", puts_tests, sizeof(puts_tests) / sizeof(test_fun));


	// ========= strlen =========
	test_fun strlen_tests[] = {&strlen_test_input_validation_null_str,
							   &strlen_test_compare_strlen,
							   &strlen_test_compare_strlen_empty_string};
	test_suite("strlen", strlen_tests, sizeof(strlen_tests) / sizeof(test_fun));

	// ========= memset =========
	test_fun memset_tests[] = {&memset_test_input_validation_null_str,
							   &memset_test_input_validation_negative_len,
							   &memset_test_compare_memset,
							   &memset_test_compare_memset_larger_than_char_value,
							   &memset_test_compare_memset_zero_nbyte};
	test_suite("memset", memset_tests, sizeof(memset_tests) / sizeof(test_fun));
}

static void test_suite(const char *name, test_fun* test_funs, int test_count)
{
	int failed = 0;
	for (int counter = 0; counter < test_count; ++counter)
	{
		if (test_funs[counter]())
		{
			failed = 1;
		}
	}
	if (!failed)
	{
		tests_passed_print(name);
	}
}

static void tests_passed_print(const char* name)
{
	printf("\033[32mAll \033[4m%s\033[0m\033[32m tests passed!\033[0m\n", name);
}