/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 18:24:11 by eshakita          #+#    #+#             */
/*   Updated: 2021/04/02 15:39:58 by eshakita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char		*ft_strdup(const char *s1)
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
