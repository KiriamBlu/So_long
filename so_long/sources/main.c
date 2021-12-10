/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanfeli <jsanfeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 16:27:35 by jsanfeli          #+#    #+#             */
/*   Updated: 2021/12/09 15:05:13 by jsanfeli         ###   ########.fr       */
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
	map->px = 0;
	map->py = 0;
	map->count = 0;
}

void freemap(t_map *map)
{
	int i;

	i = -1;
	if(map->map)
	{
		while(map->map[++i])
			free(map->map[i]);
		free(map->map);
	}
	if(map->mlx && map->win)
	{
		mlx_clear_window(map->mlx, map->win);
		mlx_destroy_window(map->mlx, map->win);
	}
}

int closewin(t_map *map)
{
	freemap(map);
	printf("Done!\n");
	exit(0);
	return(0);
}

int key_pressed (int keycode, t_map *map)
{
	int i;

	i = 0;
	if (keycode == 53)
	{
		printf("Done!\n");
		freemap(map);
		exit(0);
	}
	if(keycode == 13 | keycode == 0 | keycode == 1 | keycode == 2)
	{
		i = moves(keycode, map);
		if(map->map[map->py][map->px] == 'E')
			closewin(map);
		if(map->map[map->py][map->px] == 'C')
		{
			map->c -= 1;
			map->map[map->py][map->px] = '0';
		}
		if(i == 1)
		{
			map->count += 1;
			printf("Moves: %d\n", map->count);
		}
	}
	return(0);
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
	mlx_hook(map.win, 17, 1L << 17, closewin, &map);
	mlx_key_hook(map.win, key_pressed, &map);
	mlx_loop(map.mlx);
	return (0);
}
