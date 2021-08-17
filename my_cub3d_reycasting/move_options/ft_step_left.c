/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_step_left.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 14:31:40 by eshakita          #+#    #+#             */
/*   Updated: 2021/04/07 14:48:33 by eshakita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void		ft_step_forward_tmp(t_tar *tar)
{
	if (tar->use_map_in_prog[(int)(tar->player_pos_x + tar->viev_x / 5)]
	[(int)(tar->player_pos_y)] == 0 || tar->use_map_in_prog[(int)
	(tar->player_pos_x + tar->viev_x / 5)][(int)(tar->player_pos_y)] == 2)
		tar->player_pos_x += tar->viev_x / 10;
	if (tar->use_map_in_prog[(int)(tar->player_pos_x)]
	[(int)(tar->player_pos_y + tar->viev_y / 5)] == 0 ||
	tar->use_map_in_prog[(int)
	(tar->player_pos_x)][(int)(tar->player_pos_y + tar->viev_y / 5)] == 2)
		tar->player_pos_y += tar->viev_y / 10;
}

void			ft_step_left(t_tar *tar)
{
	double		old_dir_x;
	double		old_plane_x;
	int			turn;

	old_dir_x = tar->viev_x;
	old_plane_x = tar->plane_x;
	turn = 0;
	while (turn < 12)
	{
		ft_turn_left(tar, old_dir_x, old_plane_x);
		turn++;
	}
	turn = 0;
	if (tar->button_d != tar->button_a)
		ft_step_forward_tmp(tar);
	while (turn < 12)
	{
		ft_turn_right(tar, old_dir_x, old_plane_x);
		turn++;
	}
}
