/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_gen2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 15:14:11 by eshakita          #+#    #+#             */
/*   Updated: 2021/01/20 15:31:32 by eshakita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_len2(size_t n)
{
	int			len;

	len = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n = n / 16;
		len++;
	}
	return (len);
}

static void		*ft_memcpyy(void *dst, const void *src, size_t n)
{
	void		*a;

	a = dst;
	if (!n || (char *)dst == (char *)src)
		return (dst);
	while (n--)
	{
		*((char *)dst) = *((char *)src);
		dst++;
		src++;
	}
	return (a);
}

char			*ft_itoa_16h_x(int n, char *point)
{
	char		*str;
	int			len;
	size_t		b;
	char		set[17];

	b = (unsigned int)n;
	len = ft_len2(b);
	if (!(str = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	if (*point == 'X')
		ft_memcpyy(set, "0123456789ABCDEF", 17);
	if (*point == 'x')
		ft_memcpyy(set, "0123456789abcdef", 17);
	str[len--] = '\0';
	if (b == 0)
	{
		str[0] = '0';
		return (str);
	}
	while (b > 0)
	{
		str[len--] = set[b % 16];
		b = b / 16;
	}
	return (str);
}

char			*ft_itoa_16h_p(size_t *n)
{
	char		*str;
	int			len;
	size_t		b;
	char		set[17];

	b = (size_t)n;
	len = ft_len2(b);
	if (!(str = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	ft_memcpyy(set, "0123456789abcdef", 17);
	str[len--] = '\0';
	if (b == 0)
	{
		str[0] = '0';
		return (str);
	}
	while (b > 0)
	{
		str[len--] = set[b % 16];
		b = b / 16;
	}
	return (str);
}

int				ft_putstr_2(char *str)
{
	int			i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}
