/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvan-den <nvan-den@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 12:42:44 by nvan-den          #+#    #+#             */
/*   Updated: 2022/11/15 11:04:59 by nvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


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



//make the line to return
/* static char	*ft_lineread(char ret)
{
while ()
}

// read lenght of line
static int ft_linelength(char ret)
{
	int	length;

	length = 0;
	while (ret && ret != '\n')
	{
		length++;
	}
	
} */