/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvan-den <nvan-den@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 12:36:32 by nvan-den          #+#    #+#             */
/*   Updated: 2022/11/23 12:37:28 by nvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(char *s, int c)
{
	size_t	i;
	char	*str;

	if (!s)
		return (0);
	str = (char *)s;
	c = (char)c;
	i = 0;
	while (str[i] != c && str[i] != '\0')
		i++;
	if (str[i] == c)
		return (&str[i]);
	else
		return (NULL);
}

char	*read_line(int fd, char *ret)
{
	char	*buf;
	int		byt;

	buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (NULL);
	byt = 1;
	while (!ft_strchr(ret, '\n') && byt != 0)
	{
		byt = read(fd, buf, BUFFER_SIZE);
		if (byt == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[byt] = '\0';
		ret = ft_strjoin(ret, buf);
	}
	free(buf);
	return (ret);
}

char	*get_next_line(int fd)
{
	char			*result;
	static char		*ret;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	ret = read_line(fd, ret);
	if (!ret)
		return (NULL);
	result = cut_line(ret);
	ret = store_next_line(ret);
	return (result);
}
