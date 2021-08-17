/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 13:44:08 by eshakita          #+#    #+#             */
/*   Updated: 2020/11/23 14:15:17 by eshakita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned int	i;
	unsigned int	c;
	unsigned int	j;

	i = 0;
	if (needle[0] == '\0')
		return ((char*)&haystack[0]);
	while (haystack[i])
	{
		c = i;
		j = 0;
		while (haystack[c] == needle[j] && c < len && needle[j])
		{
			c++;
			j++;
		}
		if (needle[j] == '\0')
			return ((char*)&haystack[i]);
		i++;
	}
	return (NULL);
}
