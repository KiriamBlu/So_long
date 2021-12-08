/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanfeli <jsanfeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 00:34:57 by jsanfeli          #+#    #+#             */
/*   Updated: 2021/12/08 04:17:44 by jsanfeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void drawblock(t_map *map, size_t a, size_t b, char *imgname)
{
	void	*img;
	size_t	x;
	size_t y;
	int res;

	res = 32;
	x = (res * a);
	y = (res * b);
	img = mlx_xpm_file_to_image(map->mlx, imgname, &res, &res);
	mlx_put_image_to_window(map->mlx, map->win, img, y, x);
	mlx_destroy_image(map->mlx, img);
}

void drawmap(t_map *map)
{
	size_t i;
	size_t k;

	i = -1;
	while (++i <= map->y)
	{
		k = -1;
		while (++k <= map->x)
		{
			if (map->map[i][k] == '1')
				drawblock(map, i, k, "./sprites/bloque.XPM");
			if (map->map[i][k] == '0')
				drawblock(map, i, k, "./sprites/fondo.XPM");
			if (map->map[i][k] == 'P')
				drawblock(map, i, k, "./sprites/personaje1.XPM");
			if (map->map[i][k] == 'C')
				drawblock(map, i, k, "./sprites/pineaple.XPM");
			if (map->map[i][k] == 'E')
				drawblock(map, i, k, "./sprites/puerta1.XPM");
		}
	}
}