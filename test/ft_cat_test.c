#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include "test.h"

static void read_file(const char* file_name);
void ft_cat(int fildes);

/**
 *	Returns non-zero if the test fails.
 */
int cat_test_read_empty_file()
{
    // int open(const char *path, int oflag, ...);
    // Assumes the file to read is in the same directory
    return read_file("empty_file");
}

int cat_test_read_regular_file()
{
	return read_file("lorem_ipsum");
}


int cat_test_read_large_file()
{
	return read_file("large_file");
}

int cat_test_read_closed_fildes()
{
	return ft_cat(150);
}

static int read_file(const char* file_name)
{
	int fd = open(file_name, O_RDONLY);
	if (fd >= 0)
	{
		fprintf(stderr, "\033[35mReading file \033[1m%s\033[0m\n", file_name);
		ft_cat(fd);
		close(fd);
		return exit_status;
	}
	else
	{
		fprintf(stderr, "\033[35mFailed to open file \033[1m%s\033[0m\n", file_name);
		return 1;
	}
}