/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 15:52:59 by eshakita          #+#    #+#             */
/*   Updated: 2021/06/08 12:13:09 by eshakita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_part(unsigned int *i, size_t *len,
	unsigned char *mdst, unsigned char *msrc)
{
	while (*i <= *len)
	{
		mdst[*len - *i] = msrc[*len - *i];
		*i += 1;
	}
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned int	i;
	unsigned char	*mdst;
	unsigned char	*msrc;

	i = 1;
	mdst = (unsigned char *)dst;
	msrc = (unsigned char *)src;
	if (mdst == NULL && msrc == NULL)
		return (NULL);
	if (mdst > msrc)
		ft_part(&i, &len, mdst, msrc);
	else
	{
		while (len > 0)
		{
			*mdst = *msrc;
			mdst++;
			msrc++;
			len--;
		}
	}
	return (dst);
}
