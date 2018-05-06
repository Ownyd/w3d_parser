/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   txt.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoccard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 12:04:48 by vpoccard          #+#    #+#             */
/*   Updated: 2018/03/30 06:37:48 by tlux             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

int			ft_load_txt_1(t_wolf *w)
{
	w->texWidth = 512;
	w->texHeight = 512;
		if ((w->tex[0].img_ptr = mlx_xpm_file_to_image(w->mlx.mlx_ptr,
					"../textures/sky.xpm",&w->texWidth, &w->texHeight)) == NULL)
		return (-1);
	if ((w->tex[0].data_ptr = (char *)mlx_get_data_addr(w->tex[0].img_ptr,
					&w->tex[0].bpp, &w->tex[0].sl, &w->tex[0].endian)) == NULL)
		return (-1);
	w->texWidth = 64;
	w->texHeight = 64;
	if ((w->tex[1].img_ptr = mlx_xpm_file_to_image(w->mlx.mlx_ptr,
					"../textures/redbrick.xpm",&w->texWidth, &w->texHeight))
			== NULL)
		return (-1);
	if ((w->tex[1].data_ptr = (char *)mlx_get_data_addr(w->tex[1].img_ptr,
					&w->tex[1].bpp, &w->tex[1].sl, &w->tex[1].endian)) == NULL)
		return (-1);
	return (0);
}

int			ft_load_txt_2(t_wolf *w)
{
	w->texWidth = 32;
	w->texHeight = 32;
	if ((w->tex[2].img_ptr = mlx_xpm_file_to_image(w->mlx.mlx_ptr,
					"../textures/stone.xpm",&w->texWidth, &w->texHeight))
			== NULL)
		return (-1);
	if ((w->tex[2].data_ptr = (char *)mlx_get_data_addr(w->tex[2].img_ptr,
					&w->tex[2].bpp, &w->tex[2].sl, &w->tex[2].endian)) == NULL)
		return (-1);

	w->texWidth = 64;
	w->texHeight = 64;
	if ((w->tex[3].img_ptr = mlx_xpm_file_to_image(w->mlx.mlx_ptr,
					"../textures/mossy.xpm",&w->texWidth, &w->texHeight))
			== NULL)
		return (-1);
	if ((w->tex[3].data_ptr = (char *)mlx_get_data_addr(w->tex[3].img_ptr,
					&w->tex[3].bpp, &w->tex[3].sl, &w->tex[3].endian)) == NULL)
		return (-1);
	return (0);
}

int			ft_load_txt_3(t_wolf *w)
{
	w->texWidth = 32;
	w->texHeight = 32;
	if ((w->tex[4].img_ptr = mlx_xpm_file_to_image(w->mlx.mlx_ptr, 
					"../textures/wood.xpm",&w->texWidth, &w->texHeight))
			== NULL)
		return (-1);
	if ((w->tex[4].data_ptr = (char *)mlx_get_data_addr(w->tex[4].img_ptr,
					&w->tex[4].bpp, &w->tex[4].sl, &w->tex[4].endian)) == NULL)
		return (-1);
	w->texWidth = 32;
	w->texHeight = 32;
	if ((w->tex[5].img_ptr = mlx_xpm_file_to_image(w->mlx.mlx_ptr,
					"../textures/metal.xpm",&w->texWidth, &w->texHeight))
			== NULL)
		return (-1);
	if ((w->tex[5].data_ptr = (char *)mlx_get_data_addr(w->tex[5].img_ptr,
					&w->tex[5].bpp, &w->tex[5].sl, &w->tex[5].endian)) == NULL)
		return (-1);
	return (0);
}
