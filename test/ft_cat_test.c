#include <fcntl.h>
#include <unistd.h>
#include "test.h"

int cat_test_read_empty_file()
{
    // int open(const char *path, int oflag, ...);
    // Assumes the file to read is in the same directory
    int fd = open("empty_file", O_RDONLY);
    if (fd >= 0)
    {
    	ft_cat(fd);
    	close(fd);
	}
}

int cat_test_read_regular_file()
{
	int fd = open("lorem_ipsum", O_RDONLY);
	if (fd >= 0)
	{
		ft_cat(fd);
		close(fd);
	}
}