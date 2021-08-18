/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 15:59:44 by eshakita          #+#    #+#             */
/*   Updated: 2021/06/08 11:24:48 by eshakita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned int	i;
	unsigned char	*m;

	i = 0;
	m = (unsigned char *)s;
	while (++i <= n)
	{
		if (*(m++) == (unsigned char)c)
			return ((void *)--m);
	}
	return (NULL);
}
