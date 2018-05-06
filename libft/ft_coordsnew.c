/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlux <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 16:30:41 by tlux              #+#    #+#             */
/*   Updated: 2018/03/30 04:50:26 by tlux             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_coords	*ft_coordsnew(int x, int y, int value)
{
	t_coords *node;

	if (!(node = (t_coords *)malloc(sizeof(*node))))
		return (0);
	node->x = x;
	node->y = y;
	node->v = value;
	node->next = NULL;
	return (node);
}
