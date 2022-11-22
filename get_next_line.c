/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvan-den <nvan-den@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 12:36:32 by nvan-den          #+#    #+#             */
/*   Updated: 2022/11/22 13:23:05 by nvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char			*buf;
	int				byt;
	char			*result;
	static char		*ret;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
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
	if (!ret)
		return (NULL);
	free(buf);
	result = ft_line(ret);
	ret = ft_next(ret);
	return (result);
}
