/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanaranj <yanaranj@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 16:18:22 by yanaranj          #+#    #+#             */
/*   Updated: 2024/05/14 13:58:53 by yanaranj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//SALIDA JUNTO CON LA FLAG
void	exit_error(char *msg, int flag)
{
	write(2, msg, ft_strlen(msg));
	exit(flag);
}
