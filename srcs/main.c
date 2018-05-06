/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlux <tlux@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 03:38:04 by tlux              #+#    #+#             */
/*   Updated: 2018/03/30 06:56:16 by tlux             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

static void print_map(t_wolf *w)
{
	t_coords *tmp;

	tmp = w->map;
	while(tmp)
	{
		printf("%d ", tmp->v);
		if ((!tmp->next || (tmp->next->y == tmp->y + 1)))
			printf("\n");
		tmp = tmp->next;
	}
}

static int convert_line(t_wolf *w, char *line)
{
	char **tmp;
	int i;

	i = -1;
	tmp = ft_strsplit(line, " ");
	w->read_x = 0;
	while(tmp[++i])
	{
		if (!ft_isstrdigit(tmp[i]) || ft_atoll(tmp[i]) == 9999999999)
			return (printf("Wrong value format in the map"));
		ft_coordsadd(&(w->map), ft_coordsnew(w->read_x, w->read_y,
					(int)ft_atoll(tmp[i])));
		w->read_x += 1;
	}
	if (w->read_x > w->map_width)
		w->map_width = w->read_x;
	w->read_y += 1;
	ft_tabfree(tmp);
	return (0);
}

static void	adjust_coords(t_wolf *w)
{
	t_coords	*tmp;
	int			i;

	tmp = w->map;
	while (tmp)
	{
		if ((!tmp->next || (tmp->next->y == tmp->y + 1))
				&& tmp->x != w->map_width - 1 && (i = 0) == 0)
			while(++i <= w->map_width - 1 - tmp->x)
				ft_coordsplace(&(w->map), ft_coordsnew(tmp->x + i, tmp->y,
							(tmp->y == 0 || tmp->y == w->map_height - 1
							 || tmp->x + i == w->map_width - 1 ? 1 : 0)));
		tmp = tmp->next;
	}
	print_map(w);
}

static int parse_map(char *path, t_wolf *w)
{
	int fd;
	char *line;

	if (ft_strlen(path) <= 3 || 
			!(ft_strstr(path + ft_strlen(path) - 4, ".w3d")))
		return(printf("Not a .w3d file"));
	if ((fd = open(path, O_RDONLY)) == -1)
		return(printf("Failed to open map"));
	while(get_next_line(fd, &line) == 1)
		if (!ft_isstrblank(line) && convert_line(w, line))
			return (1);
	w->map_height = w->read_y;
	printf("HEIGHT :%d\nWIDTH :%d\n", w->map_height, w->map_width);
	adjust_coords(w);
	return (0);
}

static int init_struct(char *path, t_wolf *w)
{
	w->map = NULL;
	w->read_x = 0;
	w->read_y = 0;
	w->map_width = 0;
	if (parse_map(path, w))
		return (1);
	w->posX = w->map_height - 2;
	w->posY = (int)w->map_width / 2;
	w->dirX = 1;
	w->dirY = 1;
	ft_load_txt_1(w);
	ft_load_txt_2(w);
	ft_load_txt_3(w);
	return (0);
}

static void init_image(t_wolf *w)
{
	w->mlx.mlx_ptr = mlx_init();
	w->mlx.win_ptr = mlx_new_window(w->mlx.mlx_ptr, WIDTH, HEIGHT,
			"Wolfenstein 3D");
	w->mlx.img_ptr = mlx_new_image(w->mlx.mlx_ptr, WIDTH, HEIGHT);
	w->mlx.data_ptr = mlx_get_data_addr(w->mlx.img_ptr, &w->mlx.bpp,
			&w->mlx.sl, &w->mlx.endian);
}

int	main(int ac, char **av)
{
	t_wolf w;
	if (ac != 2)
		return(printf("usage : ./wolf3d [map.w3d]\n"));
	if (init_struct(av[1], &w))
		return (0);
	init_image(&w);

	return(0);
}
