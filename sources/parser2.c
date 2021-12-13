/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanfeli <jsanfeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 13:33:45 by jsanfeli          #+#    #+#             */
/*   Updated: 2021/12/13 14:35:05 by jsanfeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	initiator(t_map *map)
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

void	ft_error(char *str, int c, t_map *map)
{
	printf("%s\n", str);
	if (c == 1)
		freemap(map);
	exit(0);
}

char	**mountmap(int fd, t_map *map)
{
	char	*spliter;
	char	*aux;
	char	*tmp;

	spliter = ft_calloc(sizeof(char), 1);
	aux = get_next_line(fd);
	while (aux != NULL)
	{
		map->y += 1;
		tmp = ft_strdup(spliter);
		free(spliter);
		spliter = ft_strjoin(tmp, aux);
		free(tmp);
		free(aux);
		aux = get_next_line(fd);
	}
	return (ft_split(spliter, '\n'));
}
