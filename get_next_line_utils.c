/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsimon <nsimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 12:18:39 by nsimon            #+#    #+#             */
/*   Updated: 2020/01/17 13:07:51 by nsimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	if (dst == 0 || src == 0)
		return (0);
	if (dstsize == 0)
		return (ft_strlen(src));
	i = -1;
	while (++i < dstsize - 1 && src[i] != '\0')
		dst[i] = src[i];
	dst[i] = '\0';
	return (ft_strlen(src));
}

char	*ft_strdup(const char *s1)
{
	size_t	size;
	char	*copy;

	size = ft_strlen(s1) + 1;
	if ((copy = malloc(sizeof(*s1) * size)) == NULL)
		return (NULL);
	ft_strlcpy(copy, s1, size);
	return (copy);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	len;
	size_t	i;
	size_t	len_dst;
	char	*newstr;

	if (s1 == 0 || s2 == 0)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2) + 2;
	if ((newstr = malloc(sizeof(*newstr) * len)) == NULL)
		return (NULL);
	ft_strlcpy(newstr, s1, len);
	i = 0;
	len_dst = ft_strlen(newstr);
	while (s2[i] != '\0' && (len_dst + i + 1) < len)
	{
		newstr[len_dst + i] = s2[i];
		i++;
	}
	newstr[len_dst + i] = '\0';
	return (newstr);
}

int		ft_stop(char **buff, char **prev, char **next, int res)
{
	if (buff)
		if (*buff)
		{
			free(*buff);
			*buff = NULL;
		}
	if (prev)
		if (*prev)
		{
			free(*prev);
			*prev = NULL;
		}
	if (next)
		if (*next)
		{
			free(*next);
			*next = NULL;
		}
	return (res);
}
