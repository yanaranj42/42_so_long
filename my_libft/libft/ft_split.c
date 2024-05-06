/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanaranj <yanaranj@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 19:05:12 by yanaranj          #+#    #+#             */
/*   Updated: 2024/01/26 17:18:14 by yanaranj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	w_len(const char *str, char c)
{
	size_t	count;

	count = 0;
	while (str[count] && str[count] != c)
		count++;
	return (count);
}

static int	w_count(const char *str, char c)
{
	size_t	words;
	size_t	i;

	words = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if (str[i] != '\0')
			words++;
		while (str[i] && str[i] != c)
			i++;
	}
	return (words);
}

static void	free_malloc(char **str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

static char	**mem_alloc(char **str, char *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	len;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			len = w_len(&s[i], c);
			str[j] = ft_substr(s, i, len);
			if (!str[j])
			{
				free_malloc(str);
				return (NULL);
			}
			j++;
			i = i + len;
		}
		else
			i++;
	}
	str[j] = NULL;
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**split_text;
	int		words;

	words = w_count(s, c);
	split_text = (char **)malloc(sizeof(char *) * (words + 1));
	if (!split_text)
		return (NULL);
	return (mem_alloc(split_text, (char *)s, c));
}

/*
void print(char **strings)
{
    int i = 0;
    while (strings[i] != NULL)
    {
        printf("%s\n", strings[i]);
        i++;
    }
}

int main(void)
{
    const char  str[] = "Hoy es martes 13 de junio";
    char        c = ' ';
    char        **lel;
    lel = ft_split(str, c);
    print(lel);
    free(lel);
    return (0);
}
*/
