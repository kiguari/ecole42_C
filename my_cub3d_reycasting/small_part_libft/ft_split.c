/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 18:51:11 by eshakita          #+#    #+#             */
/*   Updated: 2021/04/02 15:39:56 by eshakita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int		checkwords(char const *s, char c)
{
	int i;
	int j;

	i = 0;
	j = 1;
	while (*s)
	{
		if (*s == c)
			j = 1;
		else if (*s != c && j == 1 && *s)
		{
			i++;
			j = 0;
		}
		s++;
	}
	return (i);
}

static int		checknumword(char const *s, char c, int start)
{
	int i;

	i = 0;
	while (s[start] && s[start] != c)
	{
		i++;
		start++;
	}
	return (i);
}

static char		**ft_free(char **str)
{
	while (*str)
		free(*str++);
	free(str);
	return (NULL);
}

char			**ft_split(char const *s, char c)
{
	char	**str;
	int		start;
	int		i;
	int		j;

	start = 0;
	i = 0;
	if (!(s))
		return (NULL);
	j = checkwords(s, c);
	str = (char**)malloc(sizeof(*str) * (j + 1));
	if (!str)
		return (NULL);
	while (j > 0)
	{
		while (s[start] == c && s[start])
			start++;
		str[i++] = ft_substr(s, start, checknumword(s, c, start));
		if (!(str[i - 1]))
			return (ft_free(str));
		start += checknumword(s, c, start);
		j--;
	}
	str[i] = NULL;
	return (str);
}
