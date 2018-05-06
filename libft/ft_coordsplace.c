/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlux <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 16:13:56 by tlux              #+#    #+#             */
/*   Updated: 2018/03/30 05:18:36 by tlux             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_coordsplace(t_coords **alst, t_coords *new)
{
	t_coords *calst;

	calst = *alst;

	if (*alst == NULL)
	{
		*alst = new;
		return ;
	}
	while (calst->y != new->y)
	{
		calst = calst->next;
	}
	while (calst->y == new->y && calst->x < new->x - 1)
	{
		calst = calst->next;
	}
	new->next = calst->next;
	calst->next = new;
}
