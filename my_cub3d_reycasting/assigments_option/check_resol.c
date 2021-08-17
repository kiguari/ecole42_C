/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_resol.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 13:56:40 by eshakita          #+#    #+#             */
/*   Updated: 2021/04/02 13:57:12 by eshakita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void		ft_check_resol(t_tar *tar)
{
	int		wdt;
	int		hgt;

	mlx_get_screen_size(&wdt, &hgt);
	if (wdt < tar->wdt_win)
		tar->wdt_win = wdt;
	if (hgt < tar->hgt_win)
		tar->hgt_win = hgt;
}
