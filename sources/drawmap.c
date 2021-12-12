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
			drawblock(map, i, k, "./sprites/BRIK.xpm");
			if (map->map[i][k] == '1')
				drawblock(map, i, k, "./sprites/WHOALL.xpm");
			if (map->map[i][k] == '0')
				drawblock(map, i, k, "./sprites/BRIK.xpm");
			if (map->map[i][k] == 'P')
				drawblock(map, i, k, "./sprites/ANIM1F_2.xpm");
			if (map->map[i][k] == 'X')
				drawblock(map, i, k, "./sprites/ANIM1F_11.xpm");
			if (map->map[i][k] == 'C')
				drawblock(map, i, k, "./sprites/collectionable.xpm");
			if (map->map[i][k] == 'E' && map->c != 0)
				drawblock(map, i, k, "./sprites/puerta1.xpm");
		}
	}
}

void xmoves(int keycode, t_map *map)
{
	drawblock(map, map->py, map->px, "./sprites/BRIK.xpm");
	if (keycode == 13)
	{
		map->py -= 1;
		if(map->c != 0)
			if(map->map[map->py][map->px] == 'E')
				map->py += 1;
	}
	else if (keycode == 1)
	{
		map->py += 1;
		if(map->c != 0)
			if(map->map[map->py][map->px] == 'E')
				map->py -= 1;
	}
	if(map->count % 2 == 0 && keycode == 13)
		drawblock(map, map->py, map->px, "./sprites/ANIM1F_6.xpm");
	else if(keycode == 13)
		drawblock(map, map->py, map->px, "./sprites/ANIM1F_9.xpm");
	else if(map->count % 2 == 0 && keycode == 1)
		drawblock(map, map->py, map->px, "./sprites/ANIM1F_1.xpm");
	else if(keycode == 1)
		drawblock(map, map->py, map->px, "./sprites/ANIM1F_3.xpm");
	map->map[map->py][map->px] = 'P';
}

void ymoves(int keycode, t_map *map)
{
	drawblock(map, map->py, map->px, "./sprites/BRIK.xpm");
	if (keycode == 0)
	{
		map->px -= 1;
		if(map->c != 0)
			if(map->map[map->py][map->px] == 'E')
				map->px += 1;
	}
	else if (keycode == 2)
	{
		map->px += 1;
		if(map->c != 0)
			if(map->map[map->py][map->px] == 'E')
				map->px -= 1;
	}
	if(map->count % 2 == 0 && keycode == 0)
		drawblock(map, map->py, map->px, "./sprites/ANIM1F_4.xpm");
	else if(keycode == 0)
		drawblock(map, map->py, map->px, "./sprites/ANIM1F_7.xpm");
	else if(map->count % 2 == 0 && keycode == 2)
		drawblock(map, map->py, map->px, "./sprites/ANIM1F_8.xpm");
	else if(keycode == 2)
		drawblock(map, map->py, map->px, "./sprites/ANIM1F_5.xpm");
	map->map[map->py][map->px] = 'P';
}

int moves(int keycode, t_map *map)
{
	map->map[map->py][map->px] = '0';
	if ((keycode == 13 && map->map[map->py - 1][map->px] != '1' &&
		map->map[map->py - 1][map->px] != 'X')| (keycode == 1
			&& map->map[map->py + 1][map->px] != '1' &&
			map->map[map->py + 1][map->px] != 'X'))
	{
		xmoves(keycode, map);
		return(1);
	}
	if ((keycode == 0 && map->map[map->py][map->px - 1] != '1' &&
		map->map[map->py][map->px - 1] != 'X')| (keycode == 2
			&& map->map[map->py][map->px + 1] != '1' &&
			map->map[map->py][map->px + 1] != 'X'))
	{
		ymoves(keycode, map);
		return(1);
	}
	return(0);
}
