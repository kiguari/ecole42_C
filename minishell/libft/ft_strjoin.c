/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 17:47:23 by eshakita          #+#    #+#             */
/*   Updated: 2021/06/08 10:56:05 by eshakita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*b;

	if (!s1 || !s2)
		return (NULL);
	j = ft_strlen((char *)s1) + ft_strlen((char *)s2);
	b = (char *)malloc(sizeof(char) * (j + 1));
	if (!(b))
		return (NULL);
	i = 0;
	j = 0;
	while (((char *)s1)[i])
		b[j++] = ((char *)s1)[i++];
	i = 0;
	while (((char *)s2)[i])
		b[j++] = ((char *)s2)[i++];
	b[j] = '\0';
	return (b);
}
