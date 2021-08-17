/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 17:48:34 by tmagikar          #+#    #+#             */
/*   Updated: 2021/04/02 15:39:53 by eshakita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned int i;

	i = 0;
	if (n == 0)
		return (0);
	while (i <= n - 1)
	{
		if (((unsigned char*)s1)[i] == ((unsigned char*)s2)[i])
			i++;
		else
			return (((unsigned char*)s1)[i] - ((unsigned char*)s2)[i]);
	}
	return (0);
}
