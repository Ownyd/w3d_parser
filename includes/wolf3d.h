/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlux <tlux@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 03:41:26 by tlux              #+#    #+#             */
/*   Updated: 2018/03/30 07:14:08 by tlux             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "mlx.h"
#include "math.h"
#define WIDTH 512
#define HEIGHT 384

typedef struct s_mlx
{
	void *mlx_ptr;
	void *win_ptr;
	void *img_ptr;
	void *data_ptr;
/*Image call */
	int endian;
	int sl;
	int bpp;


}				t_mlx;

typedef struct s_wolf
{
	t_mlx	mlx;
/*Parsing*/
	t_coords	*map;
	int			read_x;
	int			read_y;
	int			map_width;
	int			map_height;
/*Textures */
	int texWidth;
	int texHeight;
	int texX;
	int texY;
	int texNum;
	t_mlx	tex[6];
/*Algoritm*/
	double posX;
	double posY;
	int mapX;
	int mapY;
		double dirX;
		double dirY;
	double planeX;
	double planeY;
		double cameraX;
		double camPosX;
		double camPosY;
	double rayDirX;
	double rayDirY;
		double sideDistX;
		double sideDistY;
	double deltaDistX;
	double deltaDistY;
	double perpWallDist;
		int stepX;
		int setpY;
		int hit;
		int side;
/*Ray*/
}				t_wolf;

void			ft_sky(t_wolf *w);
void		ft_init_ray(t_wolf *w, int x);
int			ft_load_txt_3(t_wolf *w);
int			ft_load_txt_2(t_wolf *w);
int			ft_load_txt_1(t_wolf *w);

