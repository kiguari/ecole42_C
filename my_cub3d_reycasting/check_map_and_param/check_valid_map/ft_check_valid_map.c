/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_valid_map.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 11:38:43 by eshakita          #+#    #+#             */
/*   Updated: 2021/04/08 15:16:00 by eshakita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void			ft_close_not_valid_map_free(t_tar *tar, char **tmap)
{
	int i;

	i = 0;
	if (tmap)
	{
		while (i < tar->hgt_map)
		{
			free(tmap[i]);
			i++;
		}
		free(tmap);
	}
	i = 0;
	if (0 < tar->numsprites)
	{
		while (i < tar->numsprites)
		{
			free(tar->sprite[i]);
			i++;
		}
		free(tar->sprite);
	}
	printf("Error - map not valid (check wall, sprite, player pos etc)\n");
	exit(-1);
}

static int		ft_check_symbol(char symbol)
{
	if (symbol == '0')
		return (1);
	else if (symbol == '1')
		return (1);
	else if (symbol == '2')
		return (1);
	else if (symbol == 'N')
		return (1);
	else if (symbol == 'W')
		return (1);
	else if (symbol == 'S')
		return (1);
	else if (symbol == 'E')
		return (1);
	else
		return (0);
}

static int		ft_check_symbol_outside_map(int x, int y, char **tmp_map,
				t_map_xy *map_xy)
{
	if (map_xy->x_i == 0 || map_xy->x_i == y)
		return (0);
	else if (map_xy->y_j == 0 || map_xy->y_j == x)
		return (0);
	else if (ft_check_symbol(tmp_map[map_xy->x_i][map_xy->y_j - 1]) == 0)
		return (0);
	else if (ft_check_symbol(tmp_map[map_xy->x_i][map_xy->y_j + 1]) == 0)
		return (0);
	else if (ft_check_symbol(tmp_map[map_xy->x_i - 1][map_xy->y_j]) == 0)
		return (0);
	else if (!(tmp_map[map_xy->x_i + 1]))
		return (0);
	else if (!(tmp_map[map_xy->x_i - 1]))
		return (0);
	if (ft_strlen_mod(tmp_map[map_xy->x_i + 1]) < map_xy->y_j)
		return (0);
	if (ft_strlen_mod(tmp_map[map_xy->x_i - 1]) < map_xy->y_j)
		return (0);
	else if (ft_check_symbol(tmp_map[map_xy->x_i + 1][map_xy->y_j]) == 0)
		return (0);
	else if (ft_check_symbol(tmp_map[map_xy->x_i - 1][map_xy->y_j]) == 0)
		return (0);
	return (1);
}

static int		ft_chk_symbol_insid_map(char symbol)
{
	if (symbol == '0')
		return (1);
	else if (symbol == '2')
		return (1);
	else if (symbol == 'W')
		return (1);
	else if (symbol == 'N')
		return (1);
	else if (symbol == 'S')
		return (1);
	else if (symbol == 'E')
		return (1);
	else
		return (0);
}

void			check_valid_map(t_tar *tar, char **tmap, int x, int y)
{
	int			sprite_num;
	t_map_xy	map_xy;

	map_xy.x_i = 0;
	ft_zero_sprite(tar, &sprite_num);
	while (tmap[map_xy.x_i])
	{
		map_xy.y_j = 0;
		while (tmap[map_xy.x_i][map_xy.y_j])
		{
			if (ft_chk_symbol_insid_map(tmap[map_xy.x_i][map_xy.y_j]) == 1)
			{
				if ((ft_check_symbol_outside_map(x, y, tmap, &map_xy) == 0))
					ft_close_not_valid_map_free(tar, tmap);
				if (tmap[map_xy.x_i][map_xy.y_j] == '2')
					ft_make_spr_pos(tar, map_xy.x_i, map_xy.y_j, &sprite_num);
				ft_make_player_pos(tar, tmap, map_xy.x_i, map_xy.y_j);
			}
			else if (tmap[map_xy.x_i][map_xy.y_j] != '1' && tmap[map_xy.x_i]
			[map_xy.y_j] != ' ' && tmap[map_xy.x_i][map_xy.y_j] != '\t')
				ft_close_not_valid_map_free(tar, tmap);
			map_xy.y_j++;
		}
		map_xy.x_i++;
	}
}
