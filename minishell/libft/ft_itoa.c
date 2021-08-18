/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 14:09:52 by eshakita          #+#    #+#             */
/*   Updated: 2021/06/08 12:13:03 by eshakita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(long int n)
{
	long int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n = n * -1;
		len++;
	}
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static void	ft_part(char *str, long *b)
{
	str[0] = '-';
	*b = *b * -1;
}

char	*ft_itoa(int n)
{
	char		*str;
	int			len;
	long		b;

	b = (long)n;
	len = ft_len(b);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (b == 0)
	{
		str[0] = '0';
		return (str);
	}
	if (b < 0)
		ft_part(str, &b);
	while (b > 0)
	{
		str[--len] = 48 + (b % 10);
		b = b / 10;
	}
	return (str);
}
