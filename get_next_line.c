/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvan-den <nvan-den@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 12:36:32 by nvan-den          #+#    #+#             */
/*   Updated: 2022/11/10 16:49:48 by nvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	int		ret;
	char	buf[BUFFER_SIZE + 1];


	if (!fd || BUFFER_SIZE == 0)
		return (NULL);
	
	ret = read(fd, buf, BUFFER_SIZE);
	while (ret && ret != '\n')
	{
		buf[ret] = '\0';
		ret = read(fd, buf, BUFFER_SIZE);
	}

return (buf);

/* 	ft_linelenght(ret) */


}
