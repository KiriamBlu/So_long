/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanfeli <jsanfeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 17:28:20 by jsanfeli          #+#    #+#             */
/*   Updated: 2021/12/09 13:06:05 by jsanfeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void ft_error(char *str, int c, t_map *map)
{
	printf("%s\n", str);
	if(c == 1)
		freemap(map);
	exit(0);
}

static void checkextention(char const *berhopefully, t_map *map)
{
	char	*ber;
	char	*aux;
	int		len;
	int		i;

	i = -1;
	ber = ".ber";
	len = ft_strlen(berhopefully);
	while(berhopefully[len] != '.')
		len--;
	aux = ft_substr(berhopefully, len, ft_strlen(berhopefully));
	while(++i < 4)
		if(aux[i] != ber[i])
		{
			free(aux);
			ft_error("Bro what is this that you are trying to feed me", 0, map);
		}
	free(aux);
}

static void allperfect(t_map *map)
{
	if(map->p != 1 | map->c < 1 | map->e < 1)
		ft_error("THIS MAP IS CLEARLY NOT VALID", 1, map);
}

static void lesthavealook(t_map *map)
{
	size_t i;
	size_t j;

	i = -1;
	while(++i <= map->y)
	{
		j = -1;
		while(++j <= map->x)
		{
			if(i == 0 | i == map->y)
				if(map->map[i][j] != '1')
					ft_error("THIS MAP IS NOT CLOSED", 1, map);	
			if(j == 0 | j == map->x)
				if(map->map[i][j] != '1')
					ft_error("THIS MAP IS NOT CLOSED", 1, map);
			if(map->map[i][j] == 'C')
				map->c += 1;
			else if(map->map[i][j] == 'P')
			{
				map->p += 1;
				map->px = j;
				map->py = i;
			}
			else if(map->map[i][j] == 'E')
				map->e += 1;
			else if(map->map[i][j] != '0' && map->map[i][j] != '1')
				ft_error("I DONT LIKE THAT U TRYED TO CHEAT", 1, map);				
		}
	}
	allperfect(map);
}

void checkmap(t_map *map)
{
	size_t i;

	i = 0;
	map->x = ft_strlen(map->map[0]) - 1;
	while(i < map->y)
	{
		if(map->x != ft_strlen(map->map[i]) - 1)
			ft_error("This map is irregular", 1, map);
		i++;
	}
	lesthavealook(map);
}

static char **mountmap(int fd, t_map *map)
{
	char *spliter;
	char *aux;
	char *tmp;

	spliter = ft_calloc(sizeof(char), 1);
	aux = get_next_line(fd);
	while(aux != NULL)
	{
		map->y += 1;
		tmp = ft_strdup(spliter);
		free(spliter);
		spliter = ft_strjoin(tmp, aux);
		free(tmp);
		free(aux);
		aux = get_next_line(fd);
	}
	return (ft_split(spliter,'\n'));
}

void parser(int argc, char const **argv, t_map *map)
{
	int	fd;

	if (argc > 2)
		ft_error("Error too much text", 0, map);
	else if (argc < 2)
		ft_error("Error what you want me to open dude", 0, map);
	checkextention(argv[1], map);
	fd = open(argv[1], O_RDONLY);
	if(fd == -1)
		ft_error("Error wyd u entered a wrong file directory", 0, map);
	map->map = mountmap(fd, map);
	close(fd);
	map->y -= 1;
	checkmap(map);
}

