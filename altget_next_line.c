/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   altget_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvan-den <nvan-den@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 13:06:26 by nvan-den          #+#    #+#             */
/*   Updated: 2022/11/17 15:01:44 by nvan-den         ###   ########.fr       */
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

char	*ft_strcpy(char *dst, char *src)
{
	size_t	i;

	i = 0;
	while (src[i] != '\n' && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
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

	while (i) // fix the condition
	{
		if (ft_strlen(buf, '\n')) // if there is a newline found
		{
			ft_strcpy((&ret[rindex]), buf);
			/* *(ret + index) = strcpy(buf, '\n'); // store the string until the newline
			index = (index + ft_strlen(buf, '\n')); */ // get the index and store in static int
		}
		else
			ft_strcpy((&ret[rindex]), buf);
			/* *(ret + index) = strcpy(buf, '\n'); */ // continue growing the string until \n is found
	}
	
	return (ret);
}