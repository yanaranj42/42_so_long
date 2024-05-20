/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanaranj <yanaranj@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:11:19 by yanaranj          #+#    #+#             */
/*   Updated: 2024/05/20 16:21:01 by yanaranj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_rectangular(char **map, t_info *game)
{
	int	i;
	int	j;

	i = 0;
	game->width = 0;
	while (map[0][i])
		i++;
	game->width = i;
	j = 1;
	while (map[j] != NULL)
	{
		i = 0;
		while (map[j][i])
			i++;
		if (i != game->width)
			return (0);
		j++;
	}
	game->heigth = j;
	printf("ancho: %i\n", game->width);
	printf("altura: %i\n", game->heigth);
	return (1);
}
/* raw_map es una string(antes de splitear map). Hacemos un bucle que mire si
 * la primera parte de string es 1, en caso contrario, es error porque el mapa
 * no esta cerrado.
 * y al salir del bucle, saltamos en \n en el que nos encontramos
 * Si la enterior pos fue \n y lo que lee no es 1, sal de la funcion
 * o* bucle para check a la inversa si toda la parte final del str son todos 1.
 * finalizara cuando encuentre un \n y y significa que el mapa es valido
 * si la la pos siguiente es \n y la pos actual no es 1, sal de la funcion
 */
 
int	is_closed(char *raw_map)
{
	int	i;

	i = 0;

	while (raw_map[i] != '\n')
	{
		if (raw_map[i] != '1')
			return (0);
		i++;
	}
	i++;

	while (raw_map[i])
	{
		if ((raw_map[i - 1] == '\n' && raw_map[i] != '1')
				|| (raw_map[i + 1] == '\n' && raw_map[i] != '1'))
			return (0);
		i++;
	}
	i--;
	while (raw_map[i] != '\n')
	{
		if (raw_map[i] != '1')
			return (0);
		i--;
	}
	return (1);
}

int	min_size(t_info *game)
{
	if (game->heigth < 3 || game->width < 3)
		return (0);
	if (game->heigth > 40 || game->width > 76)
		return (0);
	if (game->heigth * game->width < 15)
		return (0);
	return (1);
}

/* miramos en toda la string si hay chars diferentes a P, E, C, 0, 1.
 * luego check que solo haya 1 P y 1 E
 * check que al menos haya 1 C, so no, no un map valido
 */
int	min_type_char(char *raw_map, t_info *game)
{
	int	i;

	i = 0;
	while (raw_map[i])
	{
		if (raw_map[i] != 'P' && raw_map[i] != 'C' && raw_map[i] != 'E'\
				&& raw_map[i] != '1' && raw_map[i] != '0' && raw_map[i] != '\n')
			return (0);
		i++;
	}
	if (num_strchr(raw_map, 'P') != 1 || num_strchr(raw_map, 'E') != 1)
		return (0);
	game->collect = num_strchr(raw_map, 'C');
	if (game->collect < 1)
		return (0);
	return (1);
}

int	final_map(char **map, t_info *game, char *raw_map)
{
	if (!is_rectangular(map, game))
		return (0);
	if (!is_closed(raw_map))
		return (0);
	if (!min_size(game))
		return (0);
	if (!min_type_char(raw_map, game))
		return (0);
	return (1);
}
