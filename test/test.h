#ifndef TEST_TEST_H
#define TEST_TEST_H

// bzero
int bzero_test_input_validation();
int bzero_test_input_validation_2();
int bzero_test_compare_bzero();

// is...
// isalpha
int isalpha_test_compare_isalpha();
// isdigit
int isdigit_test_compare_isdigit();
// isalnum
int isalnum_test_compare_isalnum();
// isprint
int isprint_test_compare_isprint();

// strlen
int strlen_test_input_validation_null_str();
int strlen_test_compare_strlen();
int strlen_test_compare_strlen_empty_string();

// puts
int puts_test_input_validation_null_str();
int puts_test_compare_puts();
int puts_test_compare_puts_empty_string();

#endif