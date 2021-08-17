/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 17:38:18 by eshakita          #+#    #+#             */
/*   Updated: 2021/01/19 17:39:01 by eshakita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_minus_p(char *pointer, t_flag *znak, size_t *p)
{
	int n;
	int size_p;

	n = 0;
	if (p == NULL)
		return (ft_m_p_a(znak, n));
	else
	{
		size_p = ft_strlen(pointer);
		n += ft_putstr_2("0x");
		while (znak->tochnost > size_p)
		{
			ft_putchar('0');
			n++;
			znak->tochnost--;
		}
		n += ft_putstr_2(pointer);
		while (n < znak->shirina)
		{
			ft_putchar(' ');
			n++;
		}
	}
	return (n);
}

static int	ft_nm_p_a(t_flag *znak, int n)
{
	while ((znak->shirina > znak->tochnost + 2 && znak->tochka)
	|| (znak->shirina > znak->tochnost + 3 && !znak->tochka))
	{
		ft_putchar(' ');
		n++;
		znak->shirina--;
	}
	if (!znak->tochka)
		n += ft_putstr_2("0x0");
	if (znak->tochka)
		n += ft_putstr_2("0x");
	while (znak->tochnost)
	{
		ft_putchar('0');
		n++;
		znak->tochnost--;
	}
	return (n);
}

static int	ft_nm_p_b(t_flag *znak, int n, char *pointer, int size_p_2)
{
	if (znak->tochnost == 1 || znak->tochnost == 2)
		znak->tochnost = 3;
	while ((znak->shirina > znak->tochnost + 2 + size_p_2
	&& znak->tochka && !znak->tochnost) ||
	(znak->shirina > znak->tochnost + 2 + size_p_2 && !znak->tochka
	&& !znak->tochnost)
	|| (znak->shirina > znak->tochnost + 2 && znak->tochka
	&& znak->tochnost && size_p_2 != 12) || (znak->shirina > znak->tochnost + 2
	&& znak->tochka && znak->tochnost && size_p_2 != 12))
	{
		ft_putchar(' ');
		znak->shirina--;
		n++;
	}
	n += ft_putstr_2("0x");
	while (znak->tochnost > size_p_2)
	{
		ft_putchar('0');
		n++;
		znak->tochnost--;
	}
	ft_putstr(pointer);
	n += size_p_2;
	return (n);
}

static int	print_no_minus_p(char *pointer, t_flag *znak, size_t *p)
{
	int n;
	int size_p_2;

	n = 0;
	size_p_2 = ft_strlen(pointer);
	if (p == NULL)
		return (ft_nm_p_a(znak, n));
	else
		return (ft_nm_p_b(znak, n, pointer, size_p_2));
}

int			print_p(size_t *p, t_flag *znak)
{
	int		i;
	char	*pointer;

	i = 0;
	pointer = ft_adress(p);
	if (znak->tochnost < 0)
		znak->tochnost = 1;
	if (znak->minus)
		i = print_minus_p(pointer, znak, p);
	else
		i = print_no_minus_p(pointer, znak, p);
	free(pointer);
	return (i);
}
