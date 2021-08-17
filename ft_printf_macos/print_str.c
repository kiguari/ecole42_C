/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 19:42:38 by eshakita          #+#    #+#             */
/*   Updated: 2021/01/20 19:42:39 by eshakita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_str_fl(const char *s, t_flag *znak, int wid, int acc)
{
	int i;

	i = wid - acc;
	if (!znak->minus)
	{
		if (znak->nool)
			ft_putnchar('0', i);
		else
			ft_putnchar(' ', i);
		write(1, s, acc);
	}
	else
	{
		write(1, s, acc);
		ft_putnchar(' ', i);
	}
	return (wid);
}

int			print_str(const char *s, t_flag *znak)
{
	int		acc;
	int		wid;

	acc = 0;
	wid = 0;
	if (s == NULL)
		s = "(null)";
	acc = ft_strlen(s);
	if (znak->tochnost < 0)
		znak->tochnost = acc;
	if (znak->shirina == 0 && znak->tochnost < 0)
	{
		write(1, s, acc);
		return (acc);
	}
	if (znak->tochka)
		if (acc >= znak->tochnost)
			acc = znak->tochnost;
	if ((wid = acc) <= znak->shirina)
		wid = znak->shirina;
	if ((wid - acc) > 0)
		return (print_str_fl(s, znak, wid, acc));
	else
		write(1, s, acc);
	return (acc);
}
