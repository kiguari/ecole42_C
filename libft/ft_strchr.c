/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 13:32:04 by eshakita          #+#    #+#             */
/*   Updated: 2020/11/08 13:35:42 by eshakita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*((char *)s) != (char)c && *((char *)s) != '\0')
		s++;
	if (*((char *)s) == '\0' && (char)c != '\0')
		return (NULL);
	else
		return ((char *)s);
}