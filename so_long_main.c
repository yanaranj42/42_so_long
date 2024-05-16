/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanaranj <yanaranj@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 14:31:44 by yanaranj          #+#    #+#             */
/*   Updated: 2024/05/16 13:05:31 by yanaranj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_info	init_info(void)
{
	t_info game;

	game.height = 0;
	game.width = 0;
	game.collect = 0;
	game.x = -1;
	game.y = -1;
	game.moves = 0;
	game.pos_h = 32;
	game.pos_w = 32;
	game.map = NULL;
	return (game);
}

int main(int ac, char **av)
{
	t_info	game;
	t_img	img;

	game = init_info();
	if (!get_final_map(ac, av, &game))
		return (0);
	init_game(game, img);
	return (0);
}
