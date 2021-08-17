/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 14:20:47 by eshakita          #+#    #+#             */
/*   Updated: 2020/11/20 18:11:27 by eshakita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*forlast(char const *s1, char const *set, char *a)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	while (s1[i])
	{
		j = 0;
		while (set[j])
		{
			if (s1[i] == set[j])
				break ;
			j++;
		}
		if (set[j] == '\0')
		{
			while (s1[i])
				a[k++] = s1[i++];
			a[k] = '\0';
			break ;
		}
		i++;
	}
	return (a);
}

static char		*forfirst(char const *set, char *a)
{
	int		k;
	int		j;

	k = 0;
	while (a[k])
		k++;
	k--;
	while (k > 0)
	{
		j = 0;
		while (set[j])
		{
			if (a[k] == set[j])
			{
				a[k] = '\0';
				break ;
			}
			j++;
		}
		if ((!set[j]))
			break ;
		k--;
	}
	return (a);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	char	*a;
	char	*b;

	if (!s1 || !set)
		return (NULL);
	a = (char*)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!(a))
		return (NULL);
	a = forlast(s1, set, a);
	a = forfirst(set, a);
	b = (char*)malloc(sizeof(char) * (ft_strlen(a) + 1));
	if (!(b))
		return (NULL);
	ft_memcpy(b, a, ft_strlen(a) + 1);
	free(a);
	return (b);
}
