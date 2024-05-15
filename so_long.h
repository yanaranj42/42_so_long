/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanaranj <yanaranj@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 16:01:24 by yanaranj          #+#    #+#             */
/*   Updated: 2024/05/15 15:54:40 by yanaranj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mylibs/libft/libft.h"
# include "mylibs/gnl/get_next_line.h"
# include "minilibx/mlx.h"
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_info
{
	int		height;
	int		width;
	int		collect;
	int		x;
	int		y;
	int		moves;
	int		pos_h;
	int		pos_w;
	
	char	*map;
}		t_info;

typedef struct s_img
{
	int	img_width;
	int	img_height;
	int	i;
	int	j;
}		t_img;

//		--SL_main.c--		//
//		-- check_map.c-- (parsing de args)/
int		check_map(char	*map_path);
char	**get_map(int ac, char **av, t_info *game);
char	*get_raw_map(char *map_path);

//		--errors.c--		//
void	exit_error(char *msg, int flag);

//		--SL_utils.c--		//
int		num_strchr(char *str, char c);

//		--parsing_map--		//
int		final_map(char **map, t_info *game, char *raw_map);
int		is_rectangular(char **map, t_info *game);
int		is_closed(char *raw_map);
int		min_size(t_info *game);
int		min_type_char(char *raw_map, t_info *game);

#endif
