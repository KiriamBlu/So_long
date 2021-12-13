/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanfeli <jsanfeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 13:01:54 by jsanfeli          #+#    #+#             */
/*   Updated: 2021/12/13 15:40:31 by jsanfeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

ssize_t	ft_strle(const char *c)
{
	unsigned int	i;

	i = 0;
	if (!c)
		return (0);
	while (c[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoinconst(const char *s1, const char *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	str = (char *)malloc((ft_strle(s1) + ft_strle(s2) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (*(s1 + i) != '\0')
	{
		*(str + i) = *(s1 + i);
		i++;
	}
	j = 0;
	while (*(s2 + j) != '\0')
	{
		*(str + i + j) = *(s2 + j);
		j++;
	}
	str[i + j] = '\0';
	free((void *)s1);
	return (str);
}

char	*ft_beforejump(const char *save)
{
	char	*beforebuff;
	char	*aux;
	ssize_t	i;
	ssize_t	j;
	ssize_t	len;

	i = 0;
	j = 0;
	aux = (char *)save;
	if (!aux)
		return (NULL);
	len = ft_strle(aux);
	while (i < len)
	{	
		if (aux[i] == '\n')
		{
			beforebuff = ft_substrcon(aux, 0, i + 1);
			return (beforebuff);
		}
		i++;
	}
	return (NULL);
}

char	*ft_substrcon(const char *s, unsigned int start, size_t len)
{
	char	*a;
	size_t	i;
	size_t	lens;

	i = 0;
	lens = ft_strle(s);
	if (!s)
		return (NULL);
	if (start >= lens)
		len = 0;
	if (len > lens)
		len = lens;
	a = (char *)malloc((len + 1) * sizeof(char));
	if (!a)
		return (NULL);
	while (i < len && s[start + i])
	{
		a[i] = s[start + i];
		i++;
	}
	a[i] = '\0';
	return (a);
}

char	*ft_strc(const char *s, int c)
{
	ssize_t	i;
	ssize_t	j;
	char	*a;

	i = 0;
	j = ft_strle(s);
	a = (char *)s;
	if (!s)
		return (NULL);
	while (i < j)
	{
		if (s[i] == (char)c)
			return (&a[i + 1]);
		i++;
	}
	return (NULL);
}
