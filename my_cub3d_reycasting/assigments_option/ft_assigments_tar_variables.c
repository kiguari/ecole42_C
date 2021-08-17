/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_assigments_tar_variables.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 13:07:50 by eshakita          #+#    #+#             */
/*   Updated: 2021/04/06 13:04:53 by eshakita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	ft_assigment_use_press_key(t_tar *tar)
{
	tar->button_esk = 0;
	tar->button_w = 0;
	tar->button_a = 0;
	tar->button_s = 0;
	tar->button_e = 0;
	tar->button_d = 0;
	tar->button_q = 0;
}

void		ft_assigment_tar_variables(t_tar *tar)
{
	tar->img.line_length = 0;
	tar->img.img = NULL;
	tar->mlx = NULL;
	tar->img.img_width = 0;
	tar->img.img_height = 0;
	tar->img.adres = NULL;
	tar->img.pix_bit = 0;
	tar->img.line_length = 0;
	tar->img.endian = 0;
	tar->hgt_win = 0;
	tar->wdt_win = 0;
	tar->numsprites = 0;
	tar->screen = 0;
	tar->fd = 0;
	tar->sprite = NULL;
	tar->array_wall_dist = NULL;
	ft_assigment_use_press_key(tar);
}
