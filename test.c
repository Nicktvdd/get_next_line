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
	int	i;
	
	if (argc == 0)
		return 0;
	fd = open(argv[1], O_RDONLY);
	if (fd)
	{
		while (i < 2)
		{
			printf("FUNCTION CALL\n %s", get_next_line(fd));
	/* 		get_next_line(fd); */
			i++;
		}
	}
	close(fd);
	write(1, "\n", 1);
	return 0;
}
