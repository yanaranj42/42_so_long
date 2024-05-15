/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanaranj <yanaranj@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:15:58 by yanaranj          #+#    #+#             */
/*   Updated: 2024/05/15 16:00:36 by yanaranj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_strchr(char **map, char c)
{
	int n;
	int	j;

	n = 0;
	j = -1;
	while (map[++j])
		n += num_strchr(map[j], c);
	return (j);
}
int	num_strchr(char *str, char c)
{
	int	n;

	n = 0;
	while (*str)
	{
		if (*str == (char)c)
			n++;
		str++;
	}
	return (n);
}

void	p_pos(t_info *game)
{
	while (game->map[++game->y])
	{
		game->x = 0;
		while (game->map[game->y][game->x])
		{
			if (game->map[game->y][game->x] == 'P')
				break ;
			game->x++;
		}
		if (game->map[game->y][game->x] == 'P')
			break ;
	}
}
