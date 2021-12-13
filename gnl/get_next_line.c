/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanfeli <jsanfeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 13:01:54 by jsanfeli          #+#    #+#             */
/*   Updated: 2021/12/13 15:40:26 by jsanfeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	firstenty(int fd, char **save)
{
	char	*aux;
	ssize_t	num;

	aux = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	num = read(fd, aux, BUFFER_SIZE);
	if (num <= 0)
	{
		free(aux);
		return ;
	}
	aux[num] = '\0';
	*save = ft_substrcon(aux, 0, num);
	free(aux);
}

char	*doafterjump(char **sa)
{
	char	*a;
	char	*ai;

	a = ft_beforejump(*sa);
	ai = ft_substrcon(ft_strc(*sa, '\n'), 0, ft_strle(ft_strc(*sa, '\n')));
	free(*sa);
	*sa = ft_substrcon(ai, 0, ft_strle(ai));
	free(ai);
	return (a);
}

void	middlepart(int fd, char **save)
{
	char	*aux;
	ssize_t	num;
	char	*check;

	check = NULL;
	while (!ft_strc(*save, '\n'))
	{
		aux = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
		num = read(fd, aux, BUFFER_SIZE);
		aux[num] = '\0';
		*save = ft_strjoinconst(*save, aux);
		free(aux);
		if (!read(fd, check, BUFFER_SIZE))
			return ;
	}
}

char	*ft_getline(int fd, char **save)
{
	char	*aux;

	if (!*save)
		firstenty(fd, &(*save));
	if (!*save)
		return (NULL);
	middlepart(fd, &(*save));
	if (ft_strc(*save, '\n'))
		aux = doafterjump(&(*save));
	else if (ft_strle(*save) > 0)
	{
		aux = ft_substrcon(*save, 0, ft_strle(*save));
		free(*save);
		*save = NULL;
	}
	else
		return (NULL);
	return (aux);
}

char	*get_next_line(int fd)
{
	static char	*save[4096];
	char		*a;

	if (fd < 0 || fd > 4096 || BUFFER_SIZE <= 0)
		return (NULL);
	a = ft_getline(fd, &(*save));
	if (!a)
	{
		free(*save);
		return (NULL);
	}
	return (a);
}
