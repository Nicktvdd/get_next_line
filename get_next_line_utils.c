/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nick <nick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 12:42:44 by nvan-den          #+#    #+#             */
/*   Updated: 2022/11/22 08:53:33 by nick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

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
	{
		str = &str[i];
		return (str);
	}
	else
		return (NULL);
}

static char	*ft_append(char *s2, int i, char *newstr)
{
	int	j;

	j = 0;
	while (s2[j])
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
	if (!s1)
	{
		s1 = (char*)malloc(sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	newstr = malloc(sizeof(char) * ((ft_strlen(s1) + ft_strlen(s2)) + 1));
	if (newstr == NULL)
		return (NULL);
	while (s1[i])
	{
		newstr[i] = s1[i];
		i++;
	}
	ft_append(s2, i, newstr);
	free(s1);
	return (newstr);
}

char	*ft_line(char *ret)
{
	int		i;
	char	*str;

	i = 0;
	if (!ret[i])
		return (NULL);
	while (ret[i] && ret[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	while (ret[i] && ret[i] != '\n')
	{
		str[i] = ret [i];
		i++;
	}
	if (ret[i] == '\n')
	{
		str[i] = '\n';
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_next(char *ret)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (ret[i] && ret[i] != '\n')
	i++;
	if (!ret[i])
	{
		free(ret);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(ret) - i + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (ret[i])
		str[j++] = ret[i++];
	str[j] = '\0';
	free(ret);
	return (str);
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