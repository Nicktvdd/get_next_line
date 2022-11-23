/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvan-den <nvan-den@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 12:42:44 by nvan-den          #+#    #+#             */
/*   Updated: 2022/11/23 12:50:03 by nvan-den         ###   ########.fr       */
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

static char	*append(char *rightstr, int i, char *newstr)
{
	int	j;

	j = 0;
	while (rightstr[j])
	{
		newstr[i] = rightstr[j];
		j++;
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
}

char	*ft_strjoin(char *leftstr, char *rightstr)
{
	char	*newstr;
	int		i;

	i = 0;
	if (!leftstr)
	{
		leftstr= (char *)malloc(sizeof(char));
		leftstr[0] = '\0';
	}
	if (!leftstr || !rightstr)
		return (NULL);
	newstr = malloc(sizeof(char) * ((ft_strlen(leftstr) + ft_strlen(rightstr)) + 1));
	if (newstr == NULL)
	{
		free(leftstr);
		return (NULL);
	}
	while (leftstr[i])
	{
		newstr[i] = leftstr[i];
		i++;
	}
	append(rightstr, i, newstr);
	free(leftstr);
	return (newstr);
}

char	*cut_line(char *line)
{
	int		i;
	char	*str;

	i = 0;
	if (!line[i])
		return (NULL);
	while (line[i] && line[i - 1] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (!str)
	{
		free(line);
		return (NULL);
	}
	i = 0;
	while (line[i] && line[i - 1] != '\n')
	{
		str[i] = line[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*store_next_line(char *line)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (!line[i])
	{
		free(line);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(line) - i + 1));
	if (!str)
	{
		free(line);
		return (NULL);
	}
	i++;
	j = 0;
	while (line[i])
		str[j++] = line[i++];
	str[j] = '\0';
	free(line);
	return (str);
}
