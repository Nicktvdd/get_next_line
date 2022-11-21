/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvan-den <nvan-den@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 12:36:32 by nvan-den          #+#    #+#             */
/*   Updated: 2022/11/21 14:37:38 by nvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>


char	*get_next_line(int fd)
{
	char		*ret;
	static char	*buf;
	int			byt;
	char		*result;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = (char*)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (NULL);
	while (!ft_strchr(buf, '\n') && ret != 0)
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
	result = ft_line(ret);
	ret = ft_next(ret);

return (result);
}
