/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 13:19:20 by eshakita          #+#    #+#             */
/*   Updated: 2021/06/08 11:25:15 by eshakita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned int	j;

	j = 0;
	if (n == 0)
		return (0);
	while (j <= n - 1)
	{
		if (((unsigned char *)s1)[j] == ((unsigned char *)s2)[j])
			j++;
		else
			return (((unsigned char *)s1)[j] - ((unsigned char *)s2)[j]);
	}
	return (0);
}
