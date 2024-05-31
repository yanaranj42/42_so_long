/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanaranj <yanaranj@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 16:01:05 by yanaranj          #+#    #+#             */
/*   Updated: 2024/05/31 15:08:15 by yanaranj         ###   ########.fr       */
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
		exit_error("Error opening file\n", 20);
	line = get_next_line(fd);
	if (!line)
		return (NULL);
	if (line[0] != '1')
		return (NULL);
	raw_map = malloc(sizeof(char *) * 1);
	if (!raw_map)
		return (NULL);
	raw_map[0] = '\0';
	while (line)
	{
		raw_map = gnl_strjoin(raw_map, line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	free(line);
	return (raw_map);
}

char	**get_map(int ac, char **av, t_info *game)
{
	char	*raw_map;
	char	**map;

	if (ac != 2 || !check_name(av[1]))
		exit_error("Invalid arguments\n", 1);
	raw_map = get_raw_map(av[1]);
	if (!raw_map)
		exit_error("Error getting map\n", 1);
	map = ft_split(raw_map, '\n');
	if (!final_map(map, game, raw_map))
	{
		exit_error("Invalid map\n", 1);
		free(raw_map);
	}
	free(raw_map);
	return (map);
}

void	fill_map(char **map, int x, int y, t_info *game)
{
	if (x < 0 || x > game->width || y < 0 || y > game->heigth \
			|| map[y][x] == '1' || map[y][x] == 'F')
		return ;
	if (game->map[y][x] == 'C')
		game->ncollect++;
	if (game->map[y][x] == 'E')
		game->nexit++;
	map[y][x] = 'F';
	fill_map(map, x - 1, y, game);
	fill_map(map, x + 1, y, game);
	fill_map(map, x, y - 1, game);
	fill_map(map, x, y + 1, game);
}

char	**get_final_map(int ac, char **av, t_info *game)
{
	char	**cp_map;

	game->map = get_map(ac, av, game);
	cp_map = get_map(ac, av, game);
	p_pos(game);
	fill_map(cp_map, game->x, game->y, game);
	if (game->ncollect != game->collect || game->nexit != 1)
	{
		write(1, "Error\nInvalid Path\n", 20);
		free_map(game->map);
		free_map(cp_map);
		return (NULL);
	}
	free_map(cp_map);
	return (game->map);
}
