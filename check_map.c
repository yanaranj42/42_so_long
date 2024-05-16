/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanaranj <yanaranj@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 16:01:05 by yanaranj          #+#    #+#             */
/*   Updated: 2024/05/16 12:55:45 by yanaranj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_name(char *map_path)
{
	if (ft_strlen(map_path) < 5)
		return (0);
	if (ft_strncmp(map_path, ".ber", 4) != 0)
		return (1);
	return (0);
}

char	*get_raw_map(char *map_path)
{
	int		fd;
	char	*line;
	char	*raw_map;
	
	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		return (NULL);
	line = get_next_line(fd);
	if (!line)
		return (NULL);
	raw_map = malloc(sizeof(char *) * 1);
	raw_map[0] = '\0';
	while (line)
	{
		raw_map = gnl_strjoin(raw_map, line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (raw_map);
}

char	**get_map(int ac, char **av, t_info *game)
{
	char	*raw_map;
	char	**map;

	if (ac != 2 || !check_name(av[1]))
		exit_error("Invalid arguments\n", 1);
	raw_map = get_raw_map(av[1]);
	printf("GET_MAP_row:\n%s\n", raw_map);
	if (!raw_map)
		exit_error("Error\n", 1);
	map = ft_split(raw_map, '\n');
	if (!final_map(map, game, raw_map))
	{
		exit_error("Invalid map\n", 1);
		free(raw_map);
	}
	free(raw_map);
	return (map);
}

void	fill_map(char **map, int y, int x, t_info *game)
{
	if (y < 0 || y >= game->height || x < 0 || x >= game->width\
			|| map[y][x] == '1' || map[y][x] == 'F')
			return ;
	map[y][x] = 'F'; 
	fill_map(map, x - 1, y, game);
	fill_map(map, x + 1, y, game);
	fill_map(map, x, y - 1, game);
	fill_map(map, x, y + 1, game);
}

char	**get_final_map(int ac, char **av, t_info *game)
{
	game->map = get_map(ac, av, game);
	p_pos(game);
	fill_map(game->map, game->y, game->x, game);
	if (map_strchr(game->map, 'E') > 0 || map_strchr(game->map, 'C') > 0)
	{
		write(1, "Error\tInvalid Exit\n", 20);
		free_map(game->map);
		return (NULL);
	}
	free_map(game->map);
	game->map = get_map(ac, av, game);
	return (game->map);
}
