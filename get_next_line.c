/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvan-den <nvan-den@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 12:36:32 by nvan-den          #+#    #+#             */
/*   Updated: 2022/11/15 11:06:44 by nvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static size_t	ret;
	char	*buf;
	size_t	len;

	buf = (char*)malloc(BUFFER_SIZE + 1);

	ret = 0;
	if (!fd || BUFFER_SIZE == 0)
		return (NULL);
	ret = read(fd, buf, BUFFER_SIZE);
	buf[ret] = '\0';
	buf[ft_strlen(buf) + 1] = '\0';

return (buf);

/* 	ft_linelenght(ret) */


}
