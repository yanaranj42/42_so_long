/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanaranj <yanaranj@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 16:01:05 by yanaranj          #+#    #+#             */
/*   Updated: 2024/05/06 16:27:55 by yanaranj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_name(char *map_path)
{
	if (ft_strlen < 5)
		return (0);
	if (ft_strncmp(map_path, ".ber", 4) != 0)
		return (0);
	return (1);
}
