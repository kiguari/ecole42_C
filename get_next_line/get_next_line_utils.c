/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 18:17:24 by eshakita          #+#    #+#             */
/*   Updated: 2020/12/21 15:48:49 by eshakita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t				ft_strlen(const char *s)
{
	int				i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char				*ft_strdup(const char *s1)
{
	char			*dst;
	unsigned int	i;

	i = 0;
	dst = NULL;
	dst = (char*)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!(dst))
		return (NULL);
	while (s1[i])
	{
		dst[i] = ((char*)s1)[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char				*ft_strjoin(char const *s1, char const *s2)
{
	int				i;
	int				j;
	char			*b;

	if (!s1 || !s2)
		return (NULL);
	j = ft_strlen((char*)s1) + ft_strlen((char*)s2);
	b = (char*)malloc(sizeof(char) * (j + 1));
	if (!(b))
		return (NULL);
	i = 0;
	j = 0;
	while (((char*)s1)[i])
		b[j++] = ((char*)s1)[i++];
	i = 0;
	while (((char*)s2)[i])
		b[j++] = ((char*)s2)[i++];
	b[j] = '\0';
	return (b);
}

char				*ft_strcpy(char *dst, const char *src)
{
	int				i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char				*ft_strchr(const char *s, int c)
{
	while (*((char *)s) != (char)c && *((char *)s) != '\0')
		s++;
	if (*((char *)s) == '\0' && (char)c != '\0')
		return (NULL);
	else
		return ((char *)s);
}
