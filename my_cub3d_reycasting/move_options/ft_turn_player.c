/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_turn_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 13:41:44 by eshakita          #+#    #+#             */
/*   Updated: 2021/04/07 14:52:20 by eshakita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void		ft_turn_right(t_tar *tar, double old_dir_x, double old_plane_x)
{
	old_dir_x = tar->viev_x;
	old_plane_x = tar->plane_x;
	tar->viev_x = tar->viev_x * cos(25) - tar->viev_y * sin(25);
	tar->viev_y = old_dir_x * sin(25) + tar->viev_y * cos(25);
	tar->plane_x = tar->plane_x * cos(25) - tar->plane_y * sin(25);
	tar->plane_y = old_plane_x * sin(25) + tar->plane_y * cos(25);
}

void		ft_turn_left(t_tar *tar, double old_dir_x, double old_plane_x)
{
	old_dir_x = tar->viev_x;
	old_plane_x = tar->plane_x;
	tar->viev_x = tar->viev_x * cos(-25) - tar->viev_y * sin(-25);
	tar->viev_y = old_dir_x * sin(-25) + tar->viev_y * cos(-25);
	tar->plane_x = tar->plane_x * cos(-25) - tar->plane_y * sin(-25);
	tar->plane_y = old_plane_x * sin(-25) + tar->plane_y * cos(-25);
}
