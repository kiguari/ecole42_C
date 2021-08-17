/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_gen3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 15:14:40 by eshakita          #+#    #+#             */
/*   Updated: 2021/01/20 20:00:43 by eshakita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				ft_putnchar(char c, int i)
{
	while (i > 0)
	{
		write(1, &c, 1);
		i--;
	}
}

void				ft_putstr(char *str)
{
	int				i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}

int					ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (c);
	else
		return (0);
}

int					len_numb(const long long int d)
{
	int				i;
	long long int	n;

	i = 0;
	if (d == 0)
		return (1);
	if (d < 0)
		n = -d;
	else
		n = d;
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

int					len_numb_uns(unsigned int d)
{
	int				i;
	unsigned int	n;

	i = 0;
	if (d == 0)
		return (1);
	else
		n = d;
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}
