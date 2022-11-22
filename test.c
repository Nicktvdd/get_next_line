/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvan-den <nvan-den@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 16:07:28 by nvan-den          #+#    #+#             */
/*   Updated: 2022/11/22 16:07:29 by nvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int	main(void)
{
	int	fd;
	int	i;
	char *line;
	
	fd = open("./testfile.txt", O_RDONLY);
	i = 0;
	if (fd)
	{
		while (i < 2)
		{
			line = get_next_line(fd);
			printf("FUNCTION CALL:%s:\n", line);
			free(line);
			i++;
		}
	}
	close(fd);
	write(1, "\n", 1);
	return 0;
}
