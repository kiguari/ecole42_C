/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_int_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 11:47:58 by eshakita          #+#    #+#             */
/*   Updated: 2021/04/08 14:59:38 by eshakita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

static void			ft_free_int_map(t_tar *tar, int *i)
{
	int j;

	j = 0;
	if (tar->use_map_in_prog)
	{
		while (j < *i)
		{
			free(tar->use_map_in_prog[*i]);
			j++;
		}
		free(tar->use_map_in_prog);
	}
}

void				ft_map_malloc(t_tar *tar, int *i, int max_map_len,
					char **tmap)
{
	int j;

	j = 0;
	if (!(tar->use_map_in_prog = (int**)malloc(sizeof(int*) * (*i + 1))))
	{
		ft_close_not_valid_map_free(tar, tmap);
		printf("Error - memory error - int_map \n");
		exit(-1);
	}
	while (j < *i)
	{
		if (!(tar->use_map_in_prog[j] = (int*)malloc(sizeof(int) *
		(max_map_len))))
		{
			ft_close_not_valid_map_free(tar, tmap);
			ft_free_int_map(tar, &j);
			printf("Error - memory error - int_map \n");
			exit(-1);
		}
		j++;
	}
}

void				ft_make_int_map(t_tar *tar, char **tmp_map)
{
	int				i;
	int				j;

	i = 0;
	while (i < tar->hgt_map)
	{
		j = 0;
		while (tmp_map[i][j])
		{
			tar->use_map_in_prog[i][j] = (int)(tmp_map[i][j]) - '0';
			j++;
		}
		i++;
	}
}
