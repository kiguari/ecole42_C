/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_player_position.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 11:43:34 by eshakita          #+#    #+#             */
/*   Updated: 2021/04/02 12:19:00 by eshakita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void		ft_make_player_pos(t_tar *tar, char **tmp_map, int x, int y)
{
	if (tmp_map[x][y] == 'N' || tmp_map[x][y] == 'S' || tmp_map[x][y] == 'W' ||
	tmp_map[x][y] == 'E')
		if (check_direction_view(tar, tmp_map[x][y]))
		{
			tar->player_pos_x = (double)x + 0.5;
			tar->player_pos_y = (double)y + 0.5;
			tmp_map[x][y] = '0';
		}
}
