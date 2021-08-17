/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 17:37:56 by eshakita          #+#    #+#             */
/*   Updated: 2021/01/19 17:39:50 by eshakita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_nm_x(t_flag *znak, char *line, int n, int size_x)
{
	if (!znak->tochka)
		return (ft_nm_nt_x(znak, line, n, size_x));
	else
		return (ft_nm_t_x(znak, line, n, size_x));
}

int				print_x(int x, t_flag *znak, char *point)
{
	int			size_x;
	char		*line;
	int			test;

	test = 0;
	if (znak->tochnost == 0 && x == 0 && znak->tochka)
	{
		line = "";
		size_x = 0;
		test = 1;
	}
	else
	{
		line = ft_itoa_16h_x(x, point);
		size_x = ft_strlen(line);
	}
	return (ft_x(znak, size_x, line, test));
}

int				ft_x(t_flag *znak, int size_x, char *line, int test)
{
	int rt;
	int n;

	rt = 0;
	n = size_x;
	if (znak->nool && znak->tochnost > 0)
		znak->nool = 0;
	if (znak->shirina < size_x)
		znak->shirina = size_x;
	if (znak->minus)
	{
		if (!znak->tochka)
			rt += ft_m_nt_x(znak, line, n, size_x);
		else
			rt += ft_m_t_x(znak, line, n, size_x);
	}
	else
		rt += ft_nm_x(znak, line, n, size_x);
	if (test == 0)
		free(line);
	return (rt);
}
