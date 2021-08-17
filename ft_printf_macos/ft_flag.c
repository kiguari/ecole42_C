/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 15:02:01 by eshakita          #+#    #+#             */
/*   Updated: 2021/01/20 18:07:42 by eshakita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_flag_null(t_flag *znak)
{
	znak->space = 0;
	znak->minus = 0;
	znak->plus = 0;
	znak->nool = 0;
	znak->tochka = 0;
	znak->shirina = 0;
	znak->tochnost = 0;
	znak->tk = 0;
	znak->d_shiri = 0;
	znak->d_tochn = 0;
	znak->shiri_u = 0;
	znak->tochn_u = 0;
}

char		*ft_flag(char *point, t_flag *znak)
{
	while (ft_check_flag(*point))
	{
		if (*point == '-')
			znak->minus = 1;
		else if (*point == '+')
			znak->plus = 1;
		else if (*point == '0')
			znak->nool = 1;
		else if (*point == ' ')
			znak->space = 1;
		point++;
	}
	return (point);
}

int			ft_check_flag(int point)
{
	if ((point == '-') || (point == '0') || (point == '+') || (point == ' '))
		return (1);
	else
		return (0);
}
