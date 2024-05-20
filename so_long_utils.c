/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanaranj <yanaranj@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:15:58 by yanaranj          #+#    #+#             */
/*   Updated: 2024/05/20 15:31:16 by yanaranj         ###   ########.fr       */
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
	return (n);
}
int	num_strchr(char *str, char c)
{
	int	n;

	n = 0;
	while (*str)
	{
		if (*str == c)
			n++;
		str++;
	}
	return (n);
}

void	p_pos(t_info *game)
{
//	printf("P_POS: %s\n", game->map[++game->y]);
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
