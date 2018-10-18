#include <stdio.h>
#include "test.h"

int main(void)
{
	int bzero_result = 0;
	if (bzero_test_input_validation())
		bzero_result = 1;
	if (bzero_test_input_validation_2())
		bzero_result = 1;
	if (bzero_test_compare_bzero())
		bzero_result = 1;
	if (!bzero_result)
		printf("\033[32mAll \033[4mbzero\033[0m\033[32m tests passed!\033[0m\n");

	if (!isalpha_test_compare_isalpha())
		printf("\033[32mAll \033[4misalpha\033[0m\033[32m tests passed!\033[0m\n");
	if (!isdigit_test_compare_isdigit())
		printf("\033[32mAll \033[4misalpha\033[0m\033[32m tests passed!\033[0m\n");
	if (!isalnum_test_compare_isalnum())
		printf("\033[32mAll \033[4misalpha\033[0m\033[32m tests passed!\033[0m\n");
	if (!isprint_test_compare_isprint())
		printf("\033[32mAll \033[4misalpha\033[0m\033[32m tests passed!\033[0m\n");
	

	int strlen_result = 0;
	if (strlen_test_input_validation_null_str())
		strlen_result = 1;
	if (strlen_test_compare_strlen())
		strlen_result = 1;
	if (strlen_test_compare_strlen_empty_string())
		strlen_result = 1;
	if (!strlen_result)
		printf("\033[32mAll \033[4mstrlen\033[0m\033[32m tests passed!\033[0m\n");

	int puts_result = 0;
	if (puts_test_input_validation_null_str())
		puts_result = 1;
	if (puts_test_compare_puts())
		puts_result = 1;
	if (puts_test_compare_puts_empty_string())
		puts_result = 1;
	if (!puts_result)
		printf("\033[32mAll \033[4mputs\033[0m\033[32m tests passed!\033[0m\n");
}