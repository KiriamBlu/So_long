/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanfeli <jsanfeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 16:27:35 by jsanfeli          #+#    #+#             */
/*   Updated: 2021/12/08 04:37:18 by jsanfeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void initiator(t_map *map)
{
	map->map = NULL;
	map->mlx = NULL;
	map->win = NULL;
	map->x = 0;
	map->y = 0;
	map->c = 0;
	map->p = 0;
	map->e = 0;
}

int main(int argc, char const **argv)
{
	t_map map;
	size_t resx;
	size_t resy;


	initiator(&map);
	parser(argc, argv, &map);
	resx = (map.x + 1) * 32;
	resy = (map.y + 1) * 32;
	map.mlx = mlx_init();
	map.win = mlx_new_window(map.mlx, resx, resy, "so_long");
	drawmap(&map);
	mlx_loop(map.mlx);
	return (0);
}
