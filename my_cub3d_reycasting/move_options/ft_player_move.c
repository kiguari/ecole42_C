/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player_move.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 13:14:14 by eshakita          #+#    #+#             */
/*   Updated: 2021/04/07 14:56:44 by eshakita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void			ft_step_forward_back(t_tar *tar)
{
	if (tar->button_w)
	{
		if (tar->use_map_in_prog[(int)(tar->player_pos_x + tar->viev_x / 5)]
		[(int)(tar->player_pos_y)] == 0 || tar->use_map_in_prog[(int)
		(tar->player_pos_x + tar->viev_x / 5)][(int)(tar->player_pos_y)] == 2)
			tar->player_pos_x += tar->viev_x / 10;
		if (tar->use_map_in_prog[(int)(tar->player_pos_x)]
		[(int)(tar->player_pos_y + tar->viev_y / 5)] == 0 ||
		tar->use_map_in_prog[(int)(tar->player_pos_x)][(int)
		(tar->player_pos_y + tar->viev_y / 5)] == 2)
			tar->player_pos_y += tar->viev_y / 10;
	}
	if (tar->button_s)
	{
		if (tar->use_map_in_prog[(int)(tar->player_pos_x - tar->viev_x / 5)]
		[(int)(tar->player_pos_y)] == 0 || tar->use_map_in_prog[(int)
		(tar->player_pos_x - tar->viev_x / 5)][(int)(tar->player_pos_y)] == 2)
			tar->player_pos_x -= tar->viev_x / 20;
		if (tar->use_map_in_prog[(int)(tar->player_pos_x)]
		[(int)(tar->player_pos_y - tar->viev_y / 5)] == 0 ||
		tar->use_map_in_prog[(int)(tar->player_pos_x)][(int)
		(tar->player_pos_y - tar->viev_y / 5)] == 2)
			tar->player_pos_y -= tar->viev_y / 20;
	}
}

void			ft_player_move(t_tar *tar)
{
	double		old_dir_x;
	double		old_plane_x;

	old_dir_x = tar->viev_x;
	old_plane_x = tar->plane_x;
	if (tar->button_w || tar->button_s)
		ft_step_forward_back(tar);
	if (tar->button_e && (tar->button_e != tar->button_q))
	{
		tar->viev_x = tar->viev_x * cos(-0.04) - tar->viev_y * sin(-0.04);
		tar->viev_y = old_dir_x * sin(-0.04) + tar->viev_y * cos(-0.04);
		tar->plane_x = tar->plane_x * cos(-0.04) - tar->plane_y * sin(-0.04);
		tar->plane_y = old_plane_x * sin(-0.04) + tar->plane_y * cos(-0.04);
	}
	if (tar->button_q && (tar->button_e != tar->button_q))
	{
		tar->viev_x = tar->viev_x * cos(0.04) - tar->viev_y * sin(0.04);
		tar->viev_y = old_dir_x * sin(0.04) + tar->viev_y * cos(0.04);
		tar->plane_x = tar->plane_x * cos(0.04) - tar->plane_y * sin(0.04);
		tar->plane_y = old_plane_x * sin(0.04) + tar->plane_y * cos(0.04);
	}
	if (tar->button_a)
		ft_step_left(tar);
	if (tar->button_d)
		ft_step_right(tar);
}
