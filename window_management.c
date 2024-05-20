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
}

void	init_game(t_info *game, t_img *img)
{
	printf("HOLA MUNDO\n");
	game->window = mlx_new_window(game->mlx, game->width * img->img_w,\
game->heigth * img->img_h, "so_far_so_long");
	put_img_struct(game, img);
}
