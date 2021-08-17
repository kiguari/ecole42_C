/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 13:37:18 by eshakita          #+#    #+#             */
/*   Updated: 2020/11/18 15:36:55 by eshakita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char *a;

	a = NULL;
	while (*((char *)s) != '\0')
	{
		if (*((char *)s) == (char)c)
			a = (char*)s;
		s++;
	}
	if (a == NULL && (char)c == '\0')
		return ((char*)s);
	return (a);
}
