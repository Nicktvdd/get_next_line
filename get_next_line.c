/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvan-den <nvan-den@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 12:36:32 by nvan-den          #+#    #+#             */
/*   Updated: 2022/11/15 10:47:06 by nvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != '\n')
	{
		i++;
	}
	return (i);
}

char	*get_next_line(int fd)
{
	static int	ret;
	char	*buf;
	static int	once;
	size_t	len;

	buf = (char*)malloc(BUFFER_SIZE + 1);
	once = 0;

	ret = 0;
	if (!fd || BUFFER_SIZE == 0)
		return (NULL);
	if (once == 0)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		once++;
	}
	buf[ret] = '\0';
	len = ft_strlen(buf);
	buf[len] = '\0';

return (buf);

/* 	ft_linelenght(ret) */


}
