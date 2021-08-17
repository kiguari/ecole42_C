/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_image_calk.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 18:25:47 by eshakita          #+#    #+#             */
/*   Updated: 2021/04/06 18:59:39 by eshakita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void		ft_make_move_map_x_for_dda(t_make *make, t_tar *tar)
{
	if (make->each_ray_pos_x < 0)
	{
		make->move_map_x = -1;
		make->dist_to_side_x = (tar->player_pos_x - make->tmp_pos_x) *
		make->mod_ray_dist_x;
	}
	if (make->each_ray_pos_y < 0)
	{
		make->move_map_y = -1;
		make->dist_to_side_y = (tar->player_pos_y - make->tmp_pos_y) *
		make->mod_ray_dist_y;
	}
}

void		ft_get_wall_side_and_player_dist_to_wall(t_make *make, t_tar *tar)
{
	while (make->ray_wall_hit == 0)
	{
		if (make->dist_to_side_x < make->dist_to_side_y)
		{
			make->dist_to_side_x += make->mod_ray_dist_x;
			make->tmp_pos_x += make->move_map_x;
			make->wall_side = 0;
		}
		else
		{
			make->dist_to_side_y += make->mod_ray_dist_y;
			make->tmp_pos_y += make->move_map_y;
			make->wall_side = 1;
		}
		if (tar->use_map_in_prog[make->tmp_pos_x][make->tmp_pos_y] == 1)
			make->ray_wall_hit = 1;
	}
	if (make->wall_side == 0)
		make->player_dist_to_wall = (make->tmp_pos_x - tar->player_pos_x +
		(1 - make->move_map_x) / 2) / make->each_ray_pos_x;
	else
		make->player_dist_to_wall = (make->tmp_pos_y - tar->player_pos_y +
		(1 - make->move_map_y) / 2) / make->each_ray_pos_y;
}

void		ft_get_fill_param(t_make *make, t_tar *tar)
{
	make->len_make_line = (int)(tar->hgt_win / make->player_dist_to_wall);
	make->start_fill_pos = -make->len_make_line / 2 + tar->hgt_win / 2;
	if (make->start_fill_pos < 0)
		make->start_fill_pos = 0;
	make->end_fill_pos = make->len_make_line / 2 + tar->hgt_win / 2;
	if (make->end_fill_pos >= tar->hgt_win)
		make->end_fill_pos = tar->hgt_win + 1;
	if (make->wall_side == 0)
		make->ray_wall_hit_pos = tar->player_pos_y + make->player_dist_to_wall *
		make->each_ray_pos_y;
	else
		make->ray_wall_hit_pos = tar->player_pos_x + make->player_dist_to_wall *
		make->each_ray_pos_x;
	make->ray_wall_hit_pos -= floor(make->ray_wall_hit_pos);
}

void		ft_get_fill_pix_param(t_make *make, t_tar *tar)
{
	make->pix_tex_x = (int)(make->ray_wall_hit_pos * (double)64);
	if ((make->wall_side == 0 && make->each_ray_pos_x > 0) ||
	(make->wall_side == 1 && make->each_ray_pos_y < 0))
		make->pix_tex_x = 64 - make->pix_tex_x - 1;
	make->step = 1.0 * 64 / make->len_make_line;
	make->pix_tex_pos = (make->start_fill_pos - tar->hgt_win / 2 +
	make->len_make_line / 2) * make->step;
	make->pix_tex_y = (int)make->pix_tex_pos % (64 - 1);
	make->pix_tex_pos += make->step;
	if (tar->numsprites > 0)
		tar->array_wall_dist[make->each_ray] = make->player_dist_to_wall;
}

void		ft_image_calk(t_make *make, t_tar *tar)
{
	ft_assigment_ray_variables(make);
	ft_make_values_ray_variable(make, tar);
	ft_make_move_map_x_for_dda(make, tar);
	ft_get_wall_side_and_player_dist_to_wall(make, tar);
	ft_get_fill_param(make, tar);
	ft_get_fill_pix_param(make, tar);
}
