/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanaranj <yanaranj@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 16:01:24 by yanaranj          #+#    #+#             */
/*   Updated: 2024/05/30 16:24:46 by yanaranj         ###   ########.fr       */
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
	void	*mlx;
	void	*window;
	char	**map;
	int		heigth;
	int		width;
	int		x;
	int		y;
	int		moves;
	int		collect;
	int		pos_h;
	int		pos_w;
	void	*img;
	void	*ground;
	void	*bush;
	void	*honey;
	void	*portal;
	void	*bear_r;
	void	*bear_l;
	void	*bear_up;
	void	*bear_down;
	int		ncollect;
	int		nexit;
}			t_info;

typedef struct s_img
{
	int	img_w;
	int	img_h;
	int	i;
	int	j;
}		t_img;

//		-- check_map.c-- (parsing de args)/
char	**get_final_map(int ac, char **av, t_info *game);
void	fill_map(char **map, int y, int x, t_info *game);
int		check_name(char	*map_path);
char	**get_map(int ac, char **av, t_info *game);
char	*get_raw_map(char *map_path);

//		--errors.c--		//
char	*free_map(char **map);
void	exit_error(char *msg, int flag);
int		error_exit(t_info *game);
int		exit_me(t_info *game);
int		exit_win(t_info *game);

//		--SL_utils.c--		//
int		num_strchr(char *str, char c);
void	p_pos(t_info *game);
void	print_moves(t_info *game);

//		--parsing_map--		// OK
int		final_map(char **map, t_info *game, char *raw_map);
int		is_rectangular(char **map, t_info *game);
int		is_closed(char *raw_map);
int		min_size(t_info *game);
int		min_type_char(char *raw_map, t_info *game);

//		--window_management.c--		//
void	init_game(t_info *game, t_img *img);
void	put_img_struct(t_info *game, t_img *img);
void	put_img_struct_player(t_info *game, t_img *img);
void	put_background(t_info *game, t_img *img);
void	get_image(t_info *game, t_img *img);

//		--game_management.c--		//
int		key_press(int keycode, t_info *game);
void	move_up(t_info *game);
void	move_down(t_info *game);
void	move_left(t_info *game);
void	move_rigth(t_info *game);
#endif
