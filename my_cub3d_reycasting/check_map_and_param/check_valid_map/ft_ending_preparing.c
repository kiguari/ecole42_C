/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ending_preparing.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 11:46:17 by eshakita          #+#    #+#             */
/*   Updated: 2021/04/06 14:57:36 by eshakita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

static void	free_int_map(t_tar *tar)
{
	int i;

	i = 0;
	if (tar->use_map_in_prog)
	{
		while (i < tar->hgt_map)
		{
			free(tar->use_map_in_prog[i]);
			i++;
		}
		free(tar->use_map_in_prog);
	}
}

void		check_flag(t_map_flag_args *map_flag_args,
			t_tar *tar, char **tmap)
{
	if (map_flag_args->resol != 1 || map_flag_args->north != 1 ||
	map_flag_args->south != 1 || map_flag_args->west != 1 ||
	map_flag_args->east != 1 || map_flag_args->south != 1 ||
	map_flag_args->cell != 1 || map_flag_args->floor != 1 ||
	tar->player_position != 1)
	{
		ft_close_not_valid_map_free(tar, tmap);
		free_int_map(tar);
		printf("Error - map not valid (check wall, sprite, player pos etc)\n");
		exit(-1);
	}
}

void		ft_free_tmp_variables(char **tmp_map)
{
	int		i;

	i = 0;
	if (tmp_map)
	{
		while (tmp_map[i])
		{
			free(tmp_map[i]);
			i++;
		}
		free(tmp_map);
	}
}
