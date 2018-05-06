/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_txt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlux <tlux@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 07:12:45 by tlux              #+#    #+#             */
/*   Updated: 2018/05/06 17:55:23 by tlux             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void			ft_sky(t_wolf *w)
{
	void *point;

	w->texX = 0;
	w->texHeight = 512;
	w->texWidth = 512;
	while ( w->texX < WIDTH)
	{
		w->texY = 0;
		while (w->texY < HEIGHT / 2)
		{
			point = 4 * WIDTH * w->texY + w->texX * 4 + w->mlx.data_ptr;
			ft_memcpy(point, &w->tex[0].data_ptr[w->texY % w->texHeight *
					w->tex[0].sl + w->texX % w->texWidth *
					w->tex[0].bpp / 8], sizeof(int));
			w->texY++;
		}
		w->texX++;
	}
}
