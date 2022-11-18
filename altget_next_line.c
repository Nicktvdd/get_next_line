/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   altget_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvan-den <nvan-den@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 13:06:26 by nvan-den          #+#    #+#             */
/*   Updated: 2022/11/18 15:29:00 by nvan-den         ###   ########.fr       */
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
	return (i);
}

size_t	ft_flag(char *s)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != '\n')
	{
		i++;
	}
	if (s[i] == '\n')
		return (1);
	else
		return (0);
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

static char	*ft_append(char *s2, int i, char *newstr)
{
	int	j;

	j = 0;
	while (s2[j] && s2[j] != '\n')
	{
		newstr[i] = s2[j];
		j++;
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*newstr;
	int		i;
	int		s2size;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	s2size = (sizeof(s2) * ft_strlen(s2, '\n'));
	newstr = malloc((sizeof(s1) * ft_strlen(s1, '\n')) + s2size);
	if (newstr == NULL)
		return (NULL);
	while (s1[i])
	{
		newstr[i] = s1[i];
		i++;
	}
	ft_append(s2, i, newstr);
	return (newstr);
}

char	*get_next_line(int fd)
{
	size_t			end;
	static char		*buf;
	static char		*ret;
	static size_t	index;
	static	int 	i;
	static size_t	rindex;
	char			*ptr;

	if (!buf)
		buf = (char*)malloc(BUFFER_SIZE + 1);
	if (!ptr)
		ptr = (char*)malloc(100);
	if (!fd || BUFFER_SIZE == 0)
		return (NULL);
	if (i < 1)
	{
		end = read(fd, buf, BUFFER_SIZE);
		buf[end] = '\0';
		i++;
	}
	printf("ret is now: %s\n", ret);

	printf("buf is now: %s\n", (buf+index));
/* 	if (ft_flag(buf + index)) // if newline is found in buf
	{ */
		if (index)
		{
			ptr = ft_strdup(buf + index, '\0');
			printf("PTR IS: %s\n", ptr);
			ret = ft_strjoin(ret, ptr);
			printf("I ARRIVE AT IF\n");
				printf("ret is now: %s\n", ret);
	printf("buf is now: %s\n", (buf+index));
		}
		else
		{
			ret = ft_strdup((buf + index), '\n'); // store until newline in ret
			printf("I ARRIVE AT ELSE\n");
		}
		index = (index + ft_strlen(ret, '\0')); // get index from where to continue next time
	/* } */
	printf("ret is now: %s\n", ret);
	printf("buf is now: %s\n", (buf+index));
/* 	while (!ft_flag(buf))
	{
			ptr = ft_strdup((buf + index), '\n'); // store string until newline/\0 
			printf("ret is now: %s", ret);
			printf("PTR is now: %s", ptr);
			ret = ft_strjoin(ret, ptr); // join strings
			printf("ret is now: %s", ret);
			end = read(fd, buf, BUFFER_SIZE);
			if (end == 0)
				return (ret);
			else
				buf[end] = '\0';
	} */
/* 	if (ft_strlen((buf + index), '\n') > 0) // if non-'\0' or '\n' is found
	{
			ptr = ft_strdup((buf + index), '\n'); // store string until newline/\0 
			ret = ft_strjoin((buf + index), ptr); // join strings
	}
	else  
	{
			ptr = ft_strdup((buf + index), '\n'); // store string until newline/\0 
			ret = ft_strjoin((buf + index), ptr); // join strings
	} */
	return (ret);
}
