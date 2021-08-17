/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_for_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 22:05:05 by eshakita          #+#    #+#             */
/*   Updated: 2021/01/19 17:37:59 by eshakita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_m_nt_x(t_flag *znak, char *line, int n, int size_x)
{
	if (znak->plus || znak->space)
		znak->tochnost--;
	ft_putstr(line);
	while (n < znak->tochnost)
	{
		ft_putchar('0');
		n++;
	}
	while (size_x < znak->shirina)
	{
		ft_putchar(' ');
		n++;
		znak->shirina--;
	}
	return (n);
}

int		ft_m_t_x(t_flag *znak, char *line, int n, int size_x)
{
	if (znak->plus || znak->space)
		znak->shirina--;
	while (znak->tochnost > size_x)
	{
		size_x++;
		ft_putchar('0');
		n++;
	}
	ft_putstr(line);
	while (znak->shirina > size_x)
	{
		ft_putchar(' ');
		n++;
		size_x++;
	}
	return (n);
}

int		ft_nm_nt_x(t_flag *znak, char *line, int n, int size_x)
{
	if (znak->nool)
	{
		while (n < znak->shirina)
		{
			ft_putchar('0');
			n++;
		}
		ft_putstr(line);
	}
	else
	{
		if (znak->plus || znak->space)
			znak->shirina--;
		while (size_x < znak->shirina)
		{
			ft_putchar(' ');
			n++;
			znak->shirina--;
		}
		ft_putstr(line);
	}
	return (n);
}

int		ft_nm_t_x_a(t_flag *znak, int n, char *line)
{
	while (n < znak->shirina && znak->tochnost != 0)
	{
		ft_putchar('0');
		n++;
	}
	ft_putstr(line);
	return (n);
}

int		ft_nm_t_x(t_flag *znak, char *line, int n, int size_x)
{
	if (znak->plus || znak->space)
		znak->shirina--;
	if (znak->nool && znak->tochnost != 0)
		return (ft_nm_t_x_a(znak, n, line));
	while (znak->shirina > size_x && znak->shirina > znak->tochnost)
	{
		ft_putchar(' ');
		n++;
		znak->shirina--;
	}
	while (size_x < znak->tochnost)
	{
		ft_putchar('0');
		n++;
		znak->tochnost--;
	}
	ft_putstr(line);
	return (n);
}
