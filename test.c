#include "get_next_line.h"
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	int	fd;
	int	ret;


	fd = open(argv[1], O_RDONLY);
	if (fd)
	{
		while (get_next_line(fd))
		{
			printf("%s", get_next_line(fd));
		}
	}
	close(fd);
	write(1, "\n", 1);
	return 0;
}