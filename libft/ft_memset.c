/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 13:11:42 by eshakita          #+#    #+#             */
/*   Updated: 2020/11/23 13:49:45 by eshakita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char *a;

	a = (unsigned char *)b;
	while (len--)
	{
		*(a++) = (unsigned char)c;
	}
	return ((void*)b);
}
