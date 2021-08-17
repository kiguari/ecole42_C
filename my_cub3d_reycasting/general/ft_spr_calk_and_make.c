/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spr_calk_and_make.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 16:24:20 by eshakita          #+#    #+#             */
/*   Updated: 2021/04/07 10:12:56 by eshakita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void		ft_assigment_sprite_variables(t_make *make)
{
	make->multiply_factor = 0.0;
	make->factor_spr_wdt = 0.0;
	make->factor_spr_hgt = 0.0;
	make->spr_cam_place = 0;
	make->spr_hgt = 0;
	make->start_fill_spr_y = 0;
	make->end_fill_spr_y = 0;
	make->spr_wdt = 0;
	make->start_fill_spr_x = 0;
	make->end_fill_spr_x = 0;
	make->fill_x = 0;
	make->pix_tex_x = 0;
	make->fill_y = 0;
	make->corret_tex_spr_pos = 0;
	make->pix_tex_y = 0;
	make->color = 0;
}

void		ft_make_values_spr_variables(t_make *make, t_tar *tar)
{
	make->multiply_factor = 1.0 / (tar->plane_x * tar->viev_y -
	tar->viev_x * tar->plane_y);
	make->factor_spr_wdt = make->multiply_factor * (tar->viev_y *
	make->spr_cam_pos_x - tar->viev_x * make->spr_cam_pos_y);
	make->factor_spr_hgt = make->multiply_factor * (tar->plane_x *
	make->spr_cam_pos_y - tar->plane_y * make->spr_cam_pos_x);
	make->spr_cam_place = (int)((tar->wdt_win / 2) *
	(1 + make->factor_spr_wdt / make->factor_spr_hgt));
	make->spr_hgt = (int)fabs(tar->hgt_win / make->factor_spr_hgt);
	make->start_fill_spr_y = -make->spr_hgt / 2 + tar->hgt_win / 2;
	make->end_fill_spr_y = make->spr_hgt / 2 + tar->hgt_win / 2;
	make->spr_wdt = (int)fabs(tar->hgt_win / make->factor_spr_hgt);
	make->start_fill_spr_x = -make->spr_wdt / 2 + make->spr_cam_place;
	make->end_fill_spr_x = make->spr_wdt / 2 + make->spr_cam_place;
}

void		ft_make_start_end_spr_pos(t_make *make, t_tar *tar)
{
	if (make->start_fill_spr_y < 0)
		make->start_fill_spr_y = 0;
	if (make->end_fill_spr_y >= tar->hgt_win)
		make->end_fill_spr_y = tar->hgt_win - 1;
	if (make->start_fill_spr_x < 0)
		make->start_fill_spr_x = 0;
	if (make->end_fill_spr_x >= tar->wdt_win)
		make->end_fill_spr_x = tar->wdt_win - 1;
	make->fill_x = make->start_fill_spr_x;
}

void		ft_make_sprite_on_screen(t_make *make, t_tar *tar)
{
	while (make->fill_x < make->end_fill_spr_x)
	{
		make->pix_tex_x = (int)((256 * (make->fill_x -
		(-make->spr_wdt / 2 + make->spr_cam_place)) *
		64 / make->spr_wdt) / 256);
		if (make->factor_spr_hgt > 0 && make->factor_spr_hgt <
		tar->array_wall_dist[make->fill_x])
		{
			make->fill_y = make->start_fill_spr_y;
			while (make->fill_y < make->end_fill_spr_y)
			{
				make->corret_tex_spr_pos = (make->fill_y) *
				256 - tar->hgt_win * 128 + make->spr_hgt * 128;
				make->pix_tex_y = ((make->corret_tex_spr_pos * 64) /
				make->spr_hgt) / 256;
				make->color = tar->texture[4][64 * make->pix_tex_y +
				make->pix_tex_x];
				if (make->color != 000000)
					my_mlx_pixel_put(&tar->img, make->fill_x,
					make->fill_y, make->color);
				make->fill_y++;
			}
		}
		make->fill_x++;
	}
}

void		ft_spr_calk_and_make(t_make *make, t_tar *tar, int *spr_ord)
{
	make->each_spr = 0;
	while (make->each_spr < tar->numsprites)
	{
		ft_assigment_sprite_variables(make);
		make->spr_cam_pos_x = tar->sprite[spr_ord[make->each_spr]][0] -
		tar->player_pos_x;
		make->spr_cam_pos_y = tar->sprite[spr_ord[make->each_spr]][1] -
		tar->player_pos_y;
		ft_make_values_spr_variables(make, tar);
		ft_make_start_end_spr_pos(make, tar);
		ft_make_sprite_on_screen(make, tar);
		make->each_spr++;
	}
}
