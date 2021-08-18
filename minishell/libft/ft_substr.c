/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 18:06:56 by eshakita          #+#    #+#             */
/*   Updated: 2021/06/08 11:45:00 by eshakita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*a;
	char			*b;

	b = NULL;
	i = 0;
	if (!s)
		return (0);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s + start))
		a = (char *)malloc(sizeof(char) * (ft_strlen(s + start) + 1));
	else
		a = (char *)malloc(sizeof(char) * (len + 1));
	if (!(a))
		return (NULL);
	b = a;
	while (((char *)s)[i] && i < len)
	{
		a[i] = ((char *)s)[start];
		i++;
		start++;
	}
	a[i] = '\0';
	return (b);
}
