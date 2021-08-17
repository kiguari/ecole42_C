/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 17:38:03 by eshakita          #+#    #+#             */
/*   Updated: 2021/01/20 20:03:32 by eshakita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_m_u_tc(t_flag *znak, int n, int u, int size_of_u)
{
	if (znak->plus || znak->space)
		znak->d_shiri--;
	while (znak->d_tochn > n)
	{
		ft_putchar('0');
		n++;
	}
	size_of_u = ft_putnbr_uns_u(u, znak);
	while (znak->d_shiri > n)
	{
		ft_putchar(' ');
		n++;
	}
	return (n);
}

static int	ft_m_u_nt(t_flag *znak, int n, int u, int size_of_u)
{
	if (znak->plus || znak->space)
		znak->d_tochn--;
	ft_putnbr_uns_u(u, znak);
	while (n < znak->d_tochn)
	{
		ft_putchar('0');
		n++;
	}
	while (size_of_u < znak->d_shiri)
	{
		ft_putchar(' ');
		n++;
		znak->d_shiri--;
	}
	return (n);
}

static int	ft_m_u(t_flag *znak, int n, int u, int size_of_u)
{
	if (!znak->tochka)
		return (ft_m_u_nt(znak, n, u, size_of_u));
	else
		return (ft_m_u_tc(znak, n, u, size_of_u));
}

int			print_u(int u, t_flag *znak)
{
	int size_of_u;
	int n;

	size_of_u = len_numb_uns(u);
	n = size_of_u;
	znak->shiri_u = znak->shirina;
	znak->tochn_u = znak->tochnost;
	znak->tk = znak->tochka;
	if (znak->tochnost == 0 && u == 0 && znak->tochka)
	{
		n = 0;
		size_of_u = 0;
	}
	if (znak->nool && znak->tochnost > 0)
		znak->nool = 0;
	if ((znak->d_shiri = znak->shirina) < size_of_u)
		znak->d_shiri = size_of_u;
	if ((znak->d_tochn = znak->tochnost) < size_of_u)
		znak->d_tochn = size_of_u;
	if (znak->minus)
		return (ft_m_u(znak, n, u, size_of_u));
	else
		return (ft_nm_u(znak, n, u, size_of_u));
}
