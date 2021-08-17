/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_percent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 14:13:08 by eshakita          #+#    #+#             */
/*   Updated: 2021/01/19 18:02:56 by eshakita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_nm_cp(t_flag *znak, int size_of_c, int n, int c)
{
	if (znak->nool)
	{
		while (znak->shirina > size_of_c)
		{
			ft_putchar('0');
			n++;
			znak->shirina--;
		}
	}
	while (znak->shirina > size_of_c)
	{
		ft_putchar(' ');
		n++;
		znak->shirina--;
	}
	ft_putchar(c);
	return (n);
}

int			print_percent(int c, t_flag *znak)
{
	int		size_of_c;
	int		n;

	n = 1;
	size_of_c = 1;
	if (znak->shirina < size_of_c)
		znak->shirina = size_of_c;
	if (znak->minus)
	{
		ft_putchar(c);
		while (znak->shirina > size_of_c)
		{
			ft_putchar(' ');
			n++;
			znak->shirina--;
		}
	}
	else
		n = (ft_nm_cp(znak, size_of_c, n, c));
	return (n);
}
