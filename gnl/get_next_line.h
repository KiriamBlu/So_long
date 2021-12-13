/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanfeli <jsanfeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 13:05:47 by jsanfeli          #+#    #+#             */
/*   Updated: 2021/12/13 15:53:07 by jsanfeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1

char	*get_next_line(int fd);
char	*ft_strjoinconst(char const *s1, char const *s2);
ssize_t	ft_strle(const char *c);
char	*ft_beforejump(const char *aux);
char	*ft_strc(const char *s, int c);
char	*ft_substrcon(const char *s, unsigned int start, size_t len);

# endif
#endif