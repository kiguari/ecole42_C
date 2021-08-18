/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 13:05:13 by eshakita          #+#    #+#             */
/*   Updated: 2021/06/08 11:42:47 by eshakita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	a;
	size_t	b;

	i = 0;
	a = ft_strlen(dst);
	b = ft_strlen((char *)src);
	if (dstsize == 0)
		return (b);
	if (a > dstsize)
		return (b + dstsize);
	b += a;
	while (a < dstsize - 1 && src[i])
		dst[a++] = src[i++];
	dst[a] = '\0';
	return (b);
}
