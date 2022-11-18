/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvan-den <nvan-den@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 12:37:03 by nvan-den          #+#    #+#             */
/*   Updated: 2022/11/18 14:42:11 by nvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE
# define GET_NEXT_LINE
# include <stdlib.h>
# include <unistd.h>
# define BUFFER_SIZE 50


char	*get_next_line(int fd);
size_t	ft_strlen(char *s, char c);

#endif