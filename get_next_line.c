/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvan-den <nvan-den@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 12:36:32 by nvan-den          #+#    #+#             */
/*   Updated: 2022/11/15 13:58:43 by nvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
	{
		i++;
	}
	return (i);
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

size_t	ft_stringcounter(const char *s, char c)
{
	size_t	i;
	size_t	counter;

	i = 0;
	counter = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i] != '\0')
			counter++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (counter);
}

char	**ft_split(char *s, char c)
{
	size_t	i;
	size_t	j;
	char	**array;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	array = malloc(sizeof(s) * (ft_stringcounter(s, c) + 1));
	if (array == NULL)
		return (NULL);
	while (j < ft_stringcounter(s, c))
	{
		while (s[i] == c && s[i] != '\0')
		{
			i++;
		}
		array[j] = ft_strdup(&s[i], c);
		i += ft_strlen(&s[i], c);
		j++;
	}
	array[j] = NULL;
	return (array);
}

char	*get_next_line(int fd)
{
	size_t	ret;
	static char	*buf;
	static char	**store;
	size_t	len;
	static	int i;

	buf = (char*)malloc(BUFFER_SIZE + 1);
	if (!fd || BUFFER_SIZE == 0)
		return (NULL);
	ret = read(fd, buf, BUFFER_SIZE);
	buf[ret] = '\0';
	store = ft_split(buf, '\n');
	
/* 	store = ft_strdup(buf);
	store[ft_strlen(buf) + 1] = '\0'; */


return (store[i++]);
}
