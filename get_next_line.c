/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvan-den <nvan-den@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 12:36:32 by nvan-den          #+#    #+#             */
/*   Updated: 2022/11/15 10:29:02 by nvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static int	ret;
	static char	buf[BUFFER_SIZE + 1];
	static int	once;

	once = 0;

	ret = 0;
	if (!fd || BUFFER_SIZE == 0)
		return (NULL);
	if (once == 0)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		once++;
	}
/* 	while (ret && ret != '\n')
	{ */
		buf[ret] = '\0';
/* 		ret = read(fd, buf, BUFFER_SIZE); */
/* 	} */
return (buf);

/* 	ft_linelenght(ret) */


}
