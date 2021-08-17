/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_for_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 17:19:42 by eshakita          #+#    #+#             */
/*   Updated: 2021/01/20 20:01:41 by eshakita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_nm_u(t_flag *znak, int n, int u, int size_of_u)
{
	if (!znak->tochka)
		return (ft_nm_u_nt(znak, n, u, size_of_u));
	else
		return (ft_nm_u_tc(znak, n, u, size_of_u));
}

int		ft_nm_u_tc(t_flag *znak, int n, int u, int size_of_u)
{
	if (znak->nool && znak->tochnost != 0)
	{
		while (n < znak->d_shiri)
		{
			ft_putchar('0');
			n++;
		}
		ft_putnbr_uns_u(u, znak);
		return (n);
	}
	while (znak->d_shiri > size_of_u && znak->d_shiri > znak->d_tochn)
	{
		ft_putchar(' ');
		n++;
		znak->d_shiri--;
	}
	while (size_of_u < znak->d_tochn)
	{
		ft_putchar('0');
		n++;
		znak->d_tochn--;
	}
	ft_putnbr_uns_u(u, znak);
	return (n);
}

int		ft_nm_u_nt(t_flag *znak, int n, int u, int size_of_u)
{
	if (znak->nool)
	{
		while (n < znak->d_shiri)
		{
			ft_putchar('0');
			n++;
		}
		ft_putnbr_uns_u(u, znak);
	}
	else
	{
		while (size_of_u < znak->d_shiri)
		{
			ft_putchar(' ');
			n++;
			znak->d_shiri--;
		}
		ft_putnbr_uns_u(u, znak);
	}
	return (n);
}
