/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pars.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 15:01:40 by eshakita          #+#    #+#             */
/*   Updated: 2021/01/20 18:40:06 by eshakita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_ck_shirina_else(char *point, t_flag *znak)
{
	znak->shirina = 0;
	while (ft_isdigit(*point))
	{
		znak->shirina *= 10;
		znak->shirina += *point - '0';
		point++;
	}
	return (point);
}

static char	*ft_check_shirina(char *point, t_flag *znak, va_list *name)
{
	while (ft_check_flag(*point) || ft_isdigit(*point) ||
			*point == '*')
	{
		point = ft_flag(point, znak);
		if (*point == '*')
		{
			znak->shirina = va_arg(*name, int);
			if (znak->shirina < 0)
			{
				znak->minus = 1;
				znak->shirina *= -1;
			}
			point++;
		}
		if (ft_isdigit(*point))
			point = ft_ck_shirina_else(point, znak);
	}
	return (point);
}

static char	*ft_ck_toch_else(char *point, t_flag *znak)
{
	znak->tochnost = 0;
	while (ft_isdigit(*point))
	{
		znak->tochnost *= 10;
		znak->tochnost += *point - '0';
		point++;
	}
	return (point);
}

static char	*ft_check_tochnost(char *point, t_flag *znak, va_list *name)
{
	while (*point == '.')
	{
		znak->tochka = 1;
		point++;
		while (ft_check_flag(*point) || ft_isdigit(*point)
		|| *point == '*')
		{
			if (*point == '*')
			{
				znak->tochnost = va_arg(*name, int);
				point++;
			}
			else if (ft_isdigit(*point))
				point = ft_ck_toch_else(point, znak);
			if (ft_check_flag(*point) || ft_isdigit(*point)
			|| *point == '*')
				point = ft_check_shirina(point, znak, name);
		}
	}
	return (point);
}

char		*ft_pars(char *point, t_flag *znak, va_list *name)
{
	point = ft_check_shirina(point, znak, name);
	point = ft_check_tochnost(point, znak, name);
	return (point);
}
