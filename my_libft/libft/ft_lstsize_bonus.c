/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanaranj <yanaranj@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 17:55:47 by yanaranj          #+#    #+#             */
/*   Updated: 2024/01/29 11:43:10 by yanaranj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* lst_size: counter for size.
 * WHILE: lst exist, every time the lst moves to next node, increment the
 * counter and return this value 
 */
int	ft_lstsize(t_list *lst)
{
	int		lst_size;

	lst_size = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		lst_size++;
	}
	return (lst_size);
}
