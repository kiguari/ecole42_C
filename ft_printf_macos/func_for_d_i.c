/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_for_d_i.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 15:49:40 by eshakita          #+#    #+#             */
/*   Updated: 2021/01/20 19:52:21 by eshakita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		sign(const int d, t_flag *znak)
{
	if (znak->plus && d >= 0)
		ft_putchar('+');
	else if (d < 0)
		ft_putchar('-');
	else if (znak->space && d >= 0)
		ft_putchar(' ');
	return ((znak->plus && d >= 0) || d < 0 || (znak->space && d >= 0)) ? 1 : 0;
}

int		ft_m_d_tc(t_flag *znak, int d, int n, int size_of_d_i)
{
	if (d < 0 || znak->plus || znak->space)
		znak->d_shiri--;
	while (znak->d_tochn > size_of_d_i)
	{
		size_of_d_i++;
		ft_putchar('0');
		n++;
	}
	ft_putnbr(d);
	while (znak->d_shiri > size_of_d_i)
	{
		ft_putchar(' ');
		n++;
		size_of_d_i++;
	}
	return (n);
}

int		ft_nm_d_n_tochn(t_flag *znak, int d, int n)
{
	n += sign(d, znak);
	while (n < znak->d_shiri)
	{
		ft_putchar('0');
		n++;
	}
	ft_putnbr(d);
	return (n);
}

int		ft_nm_d_tc(t_flag *znak, int d, int n, int size_of_d_i)
{
	if (znak->tochnost >= 0)
		znak->nool = 0;
	if (znak->nool && znak->tochnost < 0)
		return (ft_nm_d_n_tochn(znak, d, n));
	if (d < 0 || znak->plus || znak->space)
		znak->d_shiri--;
	while (znak->d_shiri > size_of_d_i && znak->shirina > znak->tochnost
	&& (znak->d_shiri - znak->tochnost) > 0)
	{
		ft_putchar(' ');
		n++;
		znak->d_shiri--;
	}
	if (!znak->nool)
		n += sign(d, znak);
	while (size_of_d_i < znak->d_tochn)
	{
		ft_putchar('0');
		n++;
		znak->d_tochn--;
	}
	ft_putnbr(d);
	return (n);
}

int		ft_nm_d_nt_dop(t_flag *znak, int d, int n, int size_of_d_i)
{
	if (d < 0 || znak->plus || znak->space)
		znak->d_shiri--;
	while (size_of_d_i < znak->d_shiri)
	{
		ft_putchar(' ');
		n++;
		znak->d_shiri--;
	}
	n += sign(d, znak);
	ft_putnbr(d);
	return (n);
}
