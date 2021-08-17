/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d_i.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 17:38:24 by eshakita          #+#    #+#             */
/*   Updated: 2021/01/20 20:02:50 by eshakita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_zero_d_sh(t_flag *znak, int n)
{
	n = znak->shirina;
	while (znak->shirina)
	{
		ft_putchar(' ');
		znak->shirina--;
	}
	return (n);
}

static int	ft_zero_d(t_flag *znak, int n)
{
	n = znak->shirina;
	while (znak->shirina)
	{
		ft_putchar('0');
		znak->shirina--;
	}
	return (n);
}

static int	ft_m_d(t_flag *znak, int d, int n, int size_of_d_i)
{
	n += sign(d, znak);
	if (!znak->tochka)
	{
		if (d < 0 || znak->plus || znak->space)
			znak->d_tochn--;
		ft_putnbr(d);
		while (n < znak->d_tochn)
		{
			ft_putchar('0');
			n++;
		}
		while (n < znak->d_shiri)
		{
			ft_putchar(' ');
			n++;
		}
		return (n);
	}
	else
		return (ft_m_d_tc(znak, d, n, size_of_d_i));
}

static int	ft_nm_d_nt(t_flag *znak, int d, int n, int size_of_d_i)
{
	if (!znak->tochka)
	{
		if (znak->nool)
		{
			n += sign(d, znak);
			while (n < znak->d_shiri)
			{
				ft_putchar('0');
				n++;
			}
			ft_putnbr(d);
		}
		else
			n = ft_nm_d_nt_dop(znak, d, n, size_of_d_i);
		return (n);
	}
	else
		return (ft_nm_d_tc(znak, d, n, size_of_d_i));
}

int			print_d_i(const int d, t_flag *znak)
{
	int		size_of_d_i;
	int		n;

	size_of_d_i = len_numb(d);
	n = size_of_d_i;
	if ((znak->d_shiri = znak->shirina) < size_of_d_i)
		znak->d_shiri = size_of_d_i;
	if ((znak->d_tochn = znak->tochnost) < size_of_d_i)
		znak->d_tochn = size_of_d_i;
	if ((znak->d_tochn = znak->tochnost) < 0)
		znak->d_tochn = 0;
	if (d == 0 && znak->tochnost == 0 && znak->tochka && znak->shirina > 0)
		return (ft_zero_d_sh(znak, n));
	if (d == 0 && znak->tochnost == 0 && znak->tochka)
		return (ft_zero_d(znak, n));
	if (znak->minus)
		return (ft_m_d(znak, d, n, size_of_d_i));
	else
		return (ft_nm_d_nt(znak, d, n, size_of_d_i));
}
