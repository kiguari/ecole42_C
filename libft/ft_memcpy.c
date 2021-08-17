/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 15:48:56 by eshakita          #+#    #+#             */
/*   Updated: 2020/11/23 18:56:22 by eshakita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	void	*a;

	a = dst;
	if (!n || (char *)dst == (char *)src)
		return (dst);
	while (n--)
	{
		*((char *)dst) = *((char *)src);
		dst++;
		src++;
	}
	return (a);
}
