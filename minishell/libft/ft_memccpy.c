/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 14:58:35 by eshakita          #+#    #+#             */
/*   Updated: 2021/06/08 11:24:34 by eshakita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned int	i;
	unsigned char	*mem_dst;
	unsigned char	*mem_src;

	i = 0;
	mem_dst = (unsigned char *)dst;
	mem_src = (unsigned char *)src;
	while (i < n)
	{
		mem_dst[i] = mem_src[i];
		if (mem_dst[i] == (unsigned char)c)
			return ((void *)(dst + i + 1));
		i++;
	}
	return (NULL);
}
