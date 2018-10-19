#ifndef TEST_TEST_H
#define TEST_TEST_H

typedef int(*test_fun)();

// bzero
int bzero_test_input_validation();
int bzero_test_input_validation_2();
int bzero_test_compare_bzero();

// ctype
/**
 *	ctype test function - accepts an integer argument and returns an integer.
 */
typedef int(*ctype_fun)(int);
int ctype_test_compare_ctype(const char *name, ctype_fun ft_ctype, ctype_fun ctype);

// strlen
int strlen_test_input_validation_null_str();
int strlen_test_compare_strlen();
int strlen_test_compare_strlen_empty_string();

// puts
int puts_test_input_validation_null_str();
int puts_test_compare_puts();
int puts_test_compare_puts_empty_string();

// strcat
int strcat_test_input_validation_null_str();
int strcat_test_compare_strcat();
int strcat_test_compare_strcat_empty_string();

// memset
int memset_test_input_validation_null_str();
int memset_test_input_validation_negative_len();
int memset_test_compare_memset();
int memset_test_compare_memset_larger_than_char_value();
int memset_test_compare_memset_zero_nbyte();

#endif