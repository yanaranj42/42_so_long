/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanaranj <yanaranj@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 13:01:28 by yanaranj          #+#    #+#             */
/*   Updated: 2024/05/13 18:54:28 by yanaranj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_free(char **s1, char **s2)
{
	if (s1 && *s1)
	{
		free(*s1);
		*s1 = NULL;
	}
	if (s2 && *s2)
	{
		free(*s2);
		*s2 = NULL;
	}
	return (NULL);
}

size_t	gnl_strlen(const char *c)
{
	int	i;

	i = 0;
	if (!c)
		return (0);
	while (c[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*gnl_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}

char	*gnl_strjoin(char *s1, char *s2)
{
	char	*join;
	size_t	size1;
	size_t	size2;
	size_t	i;

	size1 = gnl_strlen(s1);
	size2 = gnl_strlen(s2);
	if (!s1 && !s2)
		return (NULL);
	join = malloc(sizeof(char) * (size1 + size2 + 1));
	if (!join)
		return (free(s1), NULL);
	i = 0;
	while (i < (size1 + size2))
	{
		if (i < size1)
			join[i] = s1[i];
		else
			join[i] = s2[i - size1];
		i++;
	}
	join[i] = '\0';
	free(s1);
	return (join);
}
