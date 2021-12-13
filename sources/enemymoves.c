/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemymoves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanfeli <jsanfeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 12:30:23 by jsanfeli          #+#    #+#             */
/*   Updated: 2021/12/13 14:47:50 by jsanfeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ycalculator(int s, int l, t_map *map)
{
	if (s <= map->py)
	{
		if (map->map[s + 1][l] == '0' | map->map[s + 1][l] == 'P')
		{
			s += 1;
			if (map->count % 2 == 0)
				drawblock(map, s, l, "./sprites/ANIM1F_10.xpm");
			else
				drawblock(map, s, l, "./sprites/ANIM1F_12.xpm");
		}
		else
			drawblock(map, s, l, "./sprites/ANIM1F_11.xpm");
	}
	else
	{
		if (map->map[s - 1][l] == '0' | map->map[s - 1][l] == 'P')
		{
			s -= 1;
			if (map->count % 2 == 0)
				drawblock(map, s, l, "./sprites/ANIM1F_15.xpm");
			else
				drawblock(map, s, l, "./sprites/ANIM1F_18.xpm");
		}
		else
			drawblock(map, s, l, "./sprites/ANIM1F_11.xpm");
	}
	return (s);
}

void	movecalculator(int l, int s, t_map *map)
{	
	if (l != map->px)
	{
		if (l <= map->px)
		{
			if (map->map[s][l + 1] == '0' | map->map[s][l + 1] == 'P')
			{
				l += 1;
				if (map->count % 2 == 0)
					drawblock(map, s, l, "./sprites/ANIM1F_17.xpm");
				else
					drawblock(map, s, l, "./sprites/ANIM1F_14.xpm");
			}
			else
				s = ycalculator(s, l, map);
		}
		else
		{
			if (map->map[s][l - 1] == '0' | map->map[s][l - 1] == 'P')
			{
				l -= 1;
				if (map->count % 2 == 0)
					drawblock(map, s, l, "./sprites/ANIM1F_13.xpm");
				else
					drawblock(map, s, l, "./sprites/ANIM1F_16.xpm");
			}
			else
				s = ycalculator(s, l, map);
		}
	}
	else
		s = ycalculator(s, l, map);
	map->map[s][l] = 'X';
}

void	enemymoves(t_map *map)
{
	size_t	i;
	size_t	j;
	int		l;
	int		s;

	s = 0;
	i = -1;
	while (++i < map->y)
	{
		j = -1;
		l = 0;
		while (++j < map->x)
		{
			if (map->map[i][j] == 'X')
			{
				map->map[i][j] = '0';
				drawblock(map, i, j, "./sprites/BRIK.xpm");
				movecalculator(l, s, map);
				return ;
			}
			l++;
		}
		s++;
	}
}
