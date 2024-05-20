//Header

#include "so_long.h"

void	put_img_struct(t_info *game, t_img *img)
{
	game->ground = mlx_xpm_file_to_image(game->mlx, "textures/ground.xpm",\
	&img->img_w, &img->img_h);
	game->ground = mlx_xpm_file_to_image(game->mlx, "textures/ground.xpm", &img->img_w,\
		&img->img_h);
	if (game->ground == NULL)
		error_exit(game);
	game->bush = mlx_xpm_file_to_image(game->mlx, "textures/wall.xpm", &img->img_w,\
		&img->img_h);
	if (game->bush == NULL)
		error_exit(game);
	game->portal = mlx_xpm_file_to_image(game->mlx, "textures/portal.xpm", &img->img_w,\
		&img->img_h);
	if (game->portal == NULL)
		error_exit(game);
	game->honey = mlx_xpm_file_to_image(game->mlx, "textures/collect.xpm", &img->img_w,\
		&img->img_h);
	if (game->honey == NULL)
		error_exit(game);
	put_img_struct_player(game, img);
}

void	put_img_struct_player(t_info *game, t_img *img)
{
	game->bear_l = mlx_xpm_file_to_image(game->mlx, "textures\bear_l.xpm", &img->img_w,\
		&img->img_h);
	if (game->bear_l == NULL)
		error_exit(game);
	game->bear_r = mlx_xpm_file_to_image(game->mlx, "textures\bear_r.xpm", &img->img_w,\
		&img->img_h);
	if(game->bear_r == NULL)
		error_exit(game);
	//WIP...
}

void	put_background(t_info *game, t_img *img)
{
	while (game->map[img->j])
	{
		img->i = 0;
		while (game->map[img->j][img->i])
		{
			mlx_put_image_to_window(game->mlx, game->window, game->ground,\
				img->i * img->img_w, img->j * img->img_h);
			img->i++;
		}
		img->j++;
	}
}

void	put_img(t_info *game, t_img *img)
{
	img->j = 0;
	while (game->map[img->j])
	{
		img->i = 0;
		while (game->map[img->j][img->i])
		{
			if (game->map[img->j][img->i] == '1')
				mlx_put_image_to_window(game->mlx, )//ESTAS AQUI
		}
	}
}

void	init_game(t_info *game, t_img *img)
{
	game->window = mlx_new_window(game->mlx, game->width * img->img_w,\
game->heigth * img->img_h, "PedroP");
	put_img_struct(game, img);
	put_background(game, img);
	put_images(game, img);
}
