/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_image_on_screen.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 18:06:29 by eshakita          #+#    #+#             */
/*   Updated: 2021/04/02 11:21:50 by eshakita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void		ft_sprite_entry_value(int *spr_ord, double *dist_to_spr,
				t_tar *tar, t_make *make)
{
	double		tmp_calculation_f;
	double		tmp_calculation_s;
	double		tmp_calc_first;
	double		tmp_calc_second;

	while (make->i < tar->numsprites)
	{
		spr_ord[make->i] = make->i;
		tmp_calc_first = tar->player_pos_x - tar->sprite[make->i][0];
		tmp_calc_second = tar->player_pos_x - tar->sprite[make->i][0];
		tmp_calculation_f = tmp_calc_first * tmp_calc_second;
		tmp_calc_first = tar->player_pos_y - tar->sprite[make->i][1];
		tmp_calc_second = tar->player_pos_y - tar->sprite[make->i][1];
		tmp_calculation_s = tmp_calc_first * tmp_calc_second;
		dist_to_spr[make->i] = tmp_calculation_f + tmp_calculation_s;
		make->i++;
	}
}

int				ft_make_image_on_screen(t_tar *tar)
{
	t_make		make;
	int			spr_ord[tar->numsprites];
	double		dist_to_spr[tar->numsprites];

	make.each_ray = 0;
	make.i = 0;
	while (make.each_ray < tar->wdt_win)
	{
		ft_image_calk(&make, tar);
		make_line(&tar->img, tar, &make);
		make.each_ray++;
	}
	ft_sprite_entry_value(spr_ord, dist_to_spr, tar, &make);
	if (tar->numsprites > 1)
		ft_my_sprite_quicksort(spr_ord, dist_to_spr, tar->numsprites);
	if (tar->numsprites > 0)
		ft_spr_calk_and_make(&make, tar, spr_ord);
	return (0);
}
