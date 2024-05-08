/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanaranj <yanaranj@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 16:01:24 by yanaranj          #+#    #+#             */
/*   Updated: 2024/05/08 12:42:51 by yanaranj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "my_libft/libft.h"
#include "minilibx/mlx.h"
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct s_vars
{
	int	heigh;
	int	width;
	//add more
}		t_vars;

typedef struct s_img
{
	int	img_width;
	int	img_height;
	int	i;
	int	j;
}		t_img;

//		-- check_map.c-- (parsing de args)//

