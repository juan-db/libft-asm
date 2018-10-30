#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include "test.h"

static int read_file(const char* file_name);
void ft_cat(int fildes);

/**
 *	Returns non-zero if the test fails.
 */
int cat_test_read_empty_file()
{
    // int open(const char *path, int oflag, ...);
    // Assumes the file to read is in the same directory
    return read_file("test/empty_file");
}

int cat_test_read_regular_file()
{
	return read_file("test/lorem_ipsum");
}


int cat_test_read_large_file()
{
	return read_file("test/large_file");
}

int cat_test_read_from_stdin()
{
	fprintf(stderr, "\033[34mReading from \033[1m%s\033[0m (\033[1;34m%d\033[0m)\n", "stdin", 0);
	ft_cat(0);
	return 0;
}

static int read_file(const char* file_name)
{
	int fd = open(file_name, O_RDONLY);
	if (fd >= 0)
	{
		fprintf(stderr, "\033[34mReading file \033[1m%s\033[0m (\033[1;34m%d\033[0m)\n", file_name, fd);
		ft_cat(fd);
		close(fd);
		return 0;
	}
	else
	{
		fprintf(stderr, "\033[31mFailed to open file \033[1m%s\033[0m\n", file_name);
		return 1;
	}
}