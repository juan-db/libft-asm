#include <unistd.h>
#include <string.h>
#include <stdio.h>

#define ARRAY_LENGTH 14
#define STRING "Hello, world!"

void ft_bzero(void* s, size_t n);

int main(void) {
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
		fprintf(stderr, "ft_bzero behaviour does not match bzero...");
		return 1;
	}
	else
	{
		return 0;
	}
}