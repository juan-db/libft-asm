#ifndef TEST_TEST_H
#define TEST_TEST_H

// bzero
int bzero_test_input_validation();
int bzero_test_input_validation_2();
int bzero_test_compare_bzero();

// is...
/**
 *	ctype test function - accepts an integer argument and returns an integer.
 */
typedef int(*isx_fun)(int);
int isx_test_compare_isx(const char *name, isx_fun ft_isx, isx_fun isx);

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

#endif