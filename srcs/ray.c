/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlux <tlux@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 07:03:53 by tlux              #+#    #+#             */
/*   Updated: 2018/03/30 07:09:16 by tlux             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void		ft_init_ray(t_wolf *w, int x)
{
	w->cameraX = x * 2 / (double)WIDTH - 1;
	w->camPosX = w->posX;
	w->camPosY = w->posY;
	w->rayDirX = w->dirX + w->planeX * w->cameraX;
	w->rayDirY = w->dirY + w->planeY * w->cameraX;
	w->mapX = (int)w->camPosX;
	w->mapY = (int)w->camPosY;

	w->deltaDistX = sqrt(1 + (w->rayDirY * w->rayDirY)
			/ ( w->rayDirX * w->rayDirX));
	w->deltaDistY = sqrt(1 + (w->rayDirX * w->rayDirX)
			/ (w->rayDirY * w->rayDirY));

	//w->deltaDistX = fabs(1 / w->rayDirX);
	//	//w->deltaDistY = fabs(1 / w->rayDirY);
}
