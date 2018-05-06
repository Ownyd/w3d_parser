/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlux <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 16:30:41 by tlux              #+#    #+#             */
/*   Updated: 2018/03/21 22:17:52 by tlux             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_point	*ft_pointnew(int x, int y, int z)
{
	t_point *node;

	if (!(node = (t_point *)malloc(sizeof(*node))))
		return (0);
	node->x = x;
	node->y = y;
	node->z = z;
	node->next = NULL;
	return (node);
}
