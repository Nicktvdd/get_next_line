#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#define BUF_SIZE 10

int	errorm(int argc)
{
	if (argc == 1)
	{
		write(2, "File name missing.\n", 20);
		return (1);
	}
	if (argc > 2)
	{
		write(2, "Too many arguments.\n", 21);
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int		fd;
	int		ret;
	char	buf[BUF_SIZE +1];

	if (errorm(argc) == 1)
		return (1);
	fd = open(argv[1], O_RDONLY);
	if (fd)
	{
		ret = read(fd, buf, BUF_SIZE);
		while (ret)
		{
			buf[ret] = '\0';
			printf("%s", buf);
			ret = read(fd, buf, BUF_SIZE);
		}
		close(fd);
		write(1, "\n", 1);
	}
	return (0);
}