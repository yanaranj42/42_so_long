/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanaranj <yanaranj@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 14:31:44 by yanaranj          #+#    #+#             */
/*   Updated: 2024/05/15 16:04:18 by yanaranj         ###   ########.fr       */
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

	game = init_info();
	get_map(ac, av, &game);
	printf("WIP...\n");
	return (0);
}


