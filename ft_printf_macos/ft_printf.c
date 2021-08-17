/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 15:41:18 by eshakita          #+#    #+#             */
/*   Updated: 2021/01/20 19:41:48 by eshakita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_spr_2(t_sprs *spr, t_flag *znak, char *point, va_list *name)
{
	int n;

	n = 0;
	if (*point == 'x' || *point == 'X')
	{
		spr->x = va_arg(*name, int);
		n += print_x(spr->x, znak, point);
	}
	else if (*point == 'c')
	{
		spr->c = va_arg(*name, int);
		n += print_c(spr->c, znak);
	}
	else if (*point == 'p')
	{
		spr->p = va_arg(*name, size_t*);
		n += print_p(spr->p, znak);
	}
	else if (*point == '%')
		n += print_percent('%', znak);
	else
		n += print_c2(*point, znak);
	return (n);
}

static int	ft_spr(t_sprs *spr, t_flag *znak, char *point, va_list *name)
{
	int n;

	n = 0;
	if (*point == 'd' || *point == 'i')
	{
		spr->d = va_arg(*name, long int);
		n += print_d_i(spr->d, znak);
	}
	else if (*point == 's')
	{
		spr->s = va_arg(*name, char*);
		n += print_str(spr->s, znak);
	}
	else if (*point == 'u')
	{
		spr->u = va_arg(*name, int);
		n += print_u(spr->u, znak);
	}
	else
		n = ft_spr_2(spr, znak, point, name);
	return (n);
}

int			ft_printf(const char *points, ...)
{
	char	*point;
	int		n;
	t_flag	znak;
	t_sprs	spr;
	va_list	name;

	va_start(name, points);
	point = (char*)points;
	n = 0;
	while (*point != '\0')
	{
		if (*point != '%')
		{
			ft_putchar(*point++);
			n++;
			continue ;
		}
		ft_flag_null(&znak);
		point = ft_pars(++point, &znak, &name);
		n += ft_spr(&spr, &znak, point, &name);
		if (*point)
			point++;
	}
	va_end(name);
	return (n);
}
