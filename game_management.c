/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_management.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanaranj <yanaranj@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 13:59:58 by yanaranj          #+#    #+#             */
/*   Updated: 2024/05/21 14:02:42 by yanaranj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    move_up(t_info *game)
{
    if (game->map[game->y - 1][game->x] != '1')
    {
        if (game->map[game->y][game->x] == 'C')
        {
            game->collect--;
            game->map[game->y][game->x] = '0';
        }
        if (game->map[game->y][game->x] != 'E')
            mlx_put_image_to_window(game->mlx, game->window, game->ground,\
                game->x * game->pos_w, game->y * game->pos_h);
        game->y--;
        game->moves++;
        print_moves(game);
        if (game->map[game->y][game->x] == 'E' && game->collect == 0)
            exit_win(game);
        if (game->map[game->y][game->x] != 'E')
            mlx_put_image_to_window(game->mlx, game->window, game->bear_r,\
                game->x * game->pos_w, game->y * game->pos_h);
    }
}

void    move_down(t_info *game)
{
    if (game->map[game->y + 1][game->x] != '1')
    {
        if (game->map[game->y][game->x] == 'C')
        {
            game->collect--;
            game->map[game->y][game->x] = '0';
        }
        if (game->map[game->y][game->x] != 'E')
            mlx_put_image_to_window(game->mlx, game->window, game->ground,\
                game->x * game->pos_w, game->y * game->pos_h);
        game->y++;
        game->moves++;
        print_moves(game);
        if (game->map[game->y][game->x] == 'E' && game->collect == 0)
            exit_win(game);
        if (game->map[game->y][game->x] !='E')
            mlx_put_image_to_window(game->mlx, game->window, game->bear_l,\
                game->x * game->pos_w, game->y * game->pos_h);
    }
}

void    move_left(t_info *game)
{
    if (game->map[game->y][game->x - 1] != '1')
    {
        if (game->map[game->y][game->x] == 'C')
        {
            game->collect--;
            game->map[game->y][game->x] = '0';
        }
        if (game->map[game->y][game->x] != 'E')
            mlx_put_image_to_window(game->mlx, game->window, game->ground,\
                game->x * game->pos_w, game->y * game->pos_h);
        game->x--;
        game->moves++;
        print_moves(game);
        if (game->map[game->y][game->x] == 'E' && game->collect == 0)
            exit_win(game);
        if (game->map[game->y][game->x] != 'E')
        {
            mlx_put_image_to_window(game->mlx, game->window, game->bear_l,\
                game->x * game->pos_w, game->y * game->pos_h);
        }
    }
}

void    move_rigth(t_info *game)
{
    if (game->map[game->y][game->x + 1]  != '1')
    {
        if (game->map[game->y][game->x] == 'C')
        {
            game->collect--;
            game->map[game->y][game->x] = '0';
        }
        if (game->map[game->y][game->x] != 'E')
        {
            mlx_put_image_to_window(game->mlx, game->window, game->ground,\
                game->x * game->pos_w, game->y * game->pos_h);
        }
        game->x++;
        game->moves++;
        print_moves(game);
        if (game->map[game->y][game->x] == 'E' && game->collect == 0)
            exit_win(game);
        if (game->map[game->y][game->x] != 'E')
        {
            mlx_put_image_to_window(game->mlx, game->window, game->bear_r,\
                 game->x * game->pos_w, game->y * game->pos_h);
        }
    }
}

int key_press(int keycode, t_info *game)
{
    if (keycode == 53)
        exit_me(game);
    if (keycode == 13 || keycode == 126)
        move_up(game);
    if (keycode == 1 || keycode == 125)
        move_down(game);
    if (keycode == 0 || keycode == 123)
        move_left(game);
    if (keycode == 2 || keycode == 124)
        move_rigth(game);
    return (1);
}