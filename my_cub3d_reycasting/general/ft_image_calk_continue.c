/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_image_calk_continue.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 18:31:32 by eshakita          #+#    #+#             */
/*   Updated: 2021/04/02 19:02:41 by eshakita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void		ft_assigment_ray_variables(t_make *make)
{
	make->x_pos_on_screen = 0.0;
	make->each_ray_pos_x = 0.0;
	make->each_ray_pos_y = 0.0;
	make->tmp_pos_x = 0;
	make->tmp_pos_y = 0;
	make->dist_to_side_x = 0.0;
	make->dist_to_side_y = 0.0;
	make->mod_ray_dist_x = 0.0;
	make->mod_ray_dist_y = 0.0;
	make->player_dist_to_wall = 0.0;
	make->move_map_x = 0;
	make->move_map_y = 0;
	make->ray_wall_hit = 0;
	make->wall_side = 0;
	make->len_make_line = 0;
	make->start_fill_pos = 0;
	make->end_fill_pos = 0;
	make->ray_wall_hit_pos = 0.0;
	make->pix_tex_x = 0;
	make->step = 0.0;
	make->pix_tex_pos = 0.0;
	make->pix_tex_y = 0;
}

void		ft_make_values_ray_variable(t_make *make, t_tar *tar)
{
	make->x_pos_on_screen = 2 * make->each_ray / (double)tar->wdt_win - 1;
	make->each_ray_pos_x = tar->viev_x + tar->plane_x * make->x_pos_on_screen;
	make->each_ray_pos_y = tar->viev_y + tar->plane_y * make->x_pos_on_screen;
	make->tmp_pos_x = (int)tar->player_pos_x;
	make->tmp_pos_y = (int)tar->player_pos_y;
	make->mod_ray_dist_x = fabs(1 / make->each_ray_pos_x);
	make->mod_ray_dist_y = fabs(1 / make->each_ray_pos_y);
	make->move_map_x = 1;
	make->dist_to_side_x = (make->tmp_pos_x + 1.0 - tar->player_pos_x) *
	make->mod_ray_dist_x;
	make->move_map_y = 1;
	make->dist_to_side_y = (make->tmp_pos_y + 1.0 - tar->player_pos_y) *
	make->mod_ray_dist_y;
}
