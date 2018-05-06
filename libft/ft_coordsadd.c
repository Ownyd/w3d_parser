/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlux <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 16:13:56 by tlux              #+#    #+#             */
/*   Updated: 2018/03/30 04:31:36 by tlux             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_coordsadd(t_coords **alst, t_coords *new)
{
	t_coords *calst;

	calst = *alst;

	if (*alst == NULL)
	{
		*alst = new;
		return ;
	}
	while (calst->next)
		calst = calst->next;
	calst->next = new;
}
