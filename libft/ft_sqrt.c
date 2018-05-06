/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlux <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/06 18:03:53 by tlux              #+#    #+#             */
/*   Updated: 2017/11/17 18:40:27 by tlux             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_sqrt(int nb)
{
	int		count;
	long	n;

	n = nb;
	count = 0;
	while (count < 46341)
	{
		if (count * count == n)
			return (count);
		count++;
	}
	return (0);
}