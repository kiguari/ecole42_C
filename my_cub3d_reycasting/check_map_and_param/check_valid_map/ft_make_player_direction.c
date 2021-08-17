/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_player_direction.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 11:44:04 by eshakita          #+#    #+#             */
/*   Updated: 2021/04/05 09:52:13 by eshakita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

static int		ft_north_player_view(t_tar *tar)
{
	tar->viev_x = -1;
	tar->viev_y = 0.0;
	tar->plane_x = 0;
	tar->plane_y = 0.66;
	tar->player_position += 1;
	return (1);
}

static int		ft_west_player_view(t_tar *tar)
{
	tar->viev_x = 0.0;
	tar->viev_y = -1.0;
	tar->plane_x = -0.66;
	tar->plane_y = 0.0;
	tar->player_position += 1;
	return (1);
}

static int		ft_south_player_view(t_tar *tar)
{
	tar->viev_x = 1;
	tar->viev_y = 0.0;
	tar->plane_x = 0;
	tar->plane_y = -0.66;
	tar->player_position += 1;
	return (1);
}

static int		ft_east_player_view(t_tar *tar)
{
	tar->viev_x = 0.0;
	tar->viev_y = 1.0;
	tar->plane_x = 0.66;
	tar->plane_y = 0.0;
	tar->player_position += 1;
	return (1);
}

int				check_direction_view(t_tar *tar, char tmp_map)
{
	if (tmp_map == 'N')
		return (ft_north_player_view(tar));
	else if (tmp_map == 'W')
		return (ft_west_player_view(tar));
	else if (tmp_map == 'S')
		return (ft_south_player_view(tar));
	else if (tmp_map == 'E')
		return (ft_east_player_view(tar));
	return (0);
}
