#include "get_next_line.h"
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int	main(int argc, char **argv)
{
	int	fd;
	int	i;
	char *line;
	
	if (argc == 0)
		return 0;
	fd = open(argv[1], O_RDONLY);
	if (fd)
	{
		while (i < 2)
		{
			line = get_next_line(fd);
			printf("FUNCTION CALL\n %s", line);
			free(line);
			i++;
		}
	}
	close(fd);
	write(1, "\n", 1);
	return 0;
}
