/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanfeli <jsanfeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 16:13:57 by jsanfeli          #+#    #+#             */
/*   Updated: 2021/12/13 14:35:15 by jsanfeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

//Header files
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include "../mlx/mlx.h"
# include "../gnl/get_next_line.h"
# include "../libft/libft.h"

typedef struct s_map
{
	char	**map;
	void	*mlx;
	void	*win;
	size_t	y;
	size_t	x;
	size_t	c;
	size_t	p;
	int 	px;
	int		py;
	size_t	e;
	int		count;
	
}	t_map;

void	parser(int argc, char const **argv, t_map *map);
void	drawmap(t_map *map);
void	freemap(t_map *map);
int		moves(int keycode, t_map *map);
void	drawblock(t_map *map, size_t a, size_t b, char *imgname);
void	enemymoves(t_map *map);
char	**mountmap(int fd, t_map *map);
void	ft_error(char *str, int c, t_map *map);
void	initiator(t_map *map);

#endif