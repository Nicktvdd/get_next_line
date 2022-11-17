/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   altget_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvan-den <nvan-den@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 13:06:26 by nvan-den          #+#    #+#             */
/*   Updated: 2022/11/17 15:55:08 by nvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

size_t	ft_strlen(char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
	{
		i++;
	}
	if (s[i] == c)
		return (i);
	else
		return (0);
}

char	*ft_strdup(char *src, char c)
{
	int		i;
	char	*str;

	i = 0;
	str = (char *)malloc(sizeof(*src) * (ft_strlen(src, c)+ 1));
	if (str == NULL)
		return (0);
	while (src[i] && src[i - 1] != c)
	{
		str[i] = src[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*get_next_line(int fd)
{
	size_t			end;
	static char		*buf;
	static char		*ret;
	static size_t	index;
	static	int 	i;
	static size_t	rindex;

	buf = (char*)malloc(BUFFER_SIZE + 1);
	if (!fd || BUFFER_SIZE == 0)
		return (NULL);
	end = read(fd, buf, BUFFER_SIZE);
	buf[end] = '\0';

/* 	while (i < 3) // fix the condition
	{ */
		if (ft_strlen((buf + index), '\n') > 0) // if there is a newline found
		{
			ret = ft_strdup((buf + index), '\n'); // store the string until the newline
			index = (index + ft_strlen((buf + index), '\n')); // get the index and store in static int
		}
		else
			ret = ft_strdup(buf, '\n'); // continue growing the string until \n is found
/* 		i++;
	} */
	
	return (ret);
}