/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanaranj <yanaranj@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 16:18:22 by yanaranj          #+#    #+#             */
/*   Updated: 2024/05/14 13:58:53 by yanaranj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//SALIDA JUNTO CON LA FLAG
void	exit_error(char *msg, int flag)
{
	write(2, msg, ft_strlen(msg));
	exit(flag);
}

char	*free_map(char **map)
{
	int	j;

	j = -1;
	while (map[++j])
		free(map[j]);
	free(map);
	return (0);
}

int	error_exit(t_info *game)
{
	write(2, "Error\n", 7);
	free_map(game->map);
	mlx_destroy_window(game->mlx, game->window);
	exit(0);
}
int	exit_me(t_info *game)
{
	free_map(game->map);
	mlx_destroy_window(game->mlx, game->window);
	exit(0);
}