/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_gen.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 22:17:32 by eshakita          #+#    #+#             */
/*   Updated: 2021/01/20 20:02:12 by eshakita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t				ft_strlen(const char *s)
{
	int				i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void				ft_putnbr(int nb)
{
	long int		a;
	char			c;

	a = nb;
	if (a < 0)
		a *= -1;
	if (a != 0)
	{
		if (a / 10)
			ft_putnbr(a / 10);
		c = '0' + (a % 10);
		write(1, &c, 1);
	}
	else
		write(1, "0", 1);
}

int					ft_putnbr_uns(unsigned int nb)
{
	unsigned int	a;
	char			c;
	int				i;

	a = nb;
	if (nb == 0)
	{
		i = 0;
		return (i);
	}
	if (a != 0)
	{
		if (a / 10)
			ft_putnbr_uns(a / 10);
		c = '0' + (a % 10);
		write(1, &c, 1);
	}
	else
		write(1, "0", 1);
	i = len_numb_uns(a);
	return (i);
}

int					ft_putnbr_uns_u(unsigned int nb, t_flag *znak)
{
	unsigned int	a;
	char			c;
	int				i;

	a = nb;
	if (nb == 0 && znak->tochn_u == 0 && znak->tk)
	{
		i = 0;
		return (i);
	}
	if (a != 0)
	{
		if (a / 10)
			ft_putnbr_uns(a / 10);
		c = '0' + (a % 10);
		write(1, &c, 1);
	}
	else
		write(1, "0", 1);
	i = len_numb_uns(a);
	return (i);
}

void				ft_putchar(char c)
{
	write(1, &c, 1);
}
