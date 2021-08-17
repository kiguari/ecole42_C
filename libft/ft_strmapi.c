/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 16:05:09 by eshakita          #+#    #+#             */
/*   Updated: 2020/11/19 17:51:46 by eshakita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*string;
	unsigned int	j;

	j = 0;
	string = NULL;
	if (s && f)
	{
		string = (char*)malloc(sizeof(char) * (ft_strlen(s) + 1));
		if (!(string))
			return (NULL);
		while (s[j])
		{
			string[j] = f(j, (char)s[j]);
			j++;
		}
		string[j] = '\0';
	}
	return (string);
}
