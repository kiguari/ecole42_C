/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_for_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 22:12:59 by eshakita          #+#    #+#             */
/*   Updated: 2021/01/20 15:11:39 by eshakita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_m_p_a(t_flag *znak, int n)
{
	if ((!znak->tochka) || (!znak->shirina && !znak->tochka && !znak->tochnost))
		n += ft_putstr_2("0x0");
	else
		n += ft_putstr_2("0x");
	while (znak->tochnost)
	{
		ft_putchar('0');
		n++;
		znak->tochnost--;
	}
	while (n < znak->shirina)
	{
		ft_putchar(' ');
		n++;
	}
	return (n);
}

char		*ft_adress(size_t *adr)
{
	size_t	*p;
	char	*test;

	p = adr;
	test = ft_itoa_16h_p(p);
	return (test);
}
