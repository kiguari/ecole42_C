/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprite_preparig.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 11:37:30 by eshakita          #+#    #+#             */
/*   Updated: 2021/04/07 10:52:20 by eshakita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

static void		ft_close(t_tar *tar, char **tmp_map, char *tmp_buf)
{
	int j;

	j = 0;
	if (tmp_buf)
		free(tmp_buf);
	if (tmp_map)
	{
		while (j < tar->hgt_map)
		{
			free(tmp_map[j]);
			j++;
		}
		free(tmp_map);
	}
}

static void		ft_free_sprite(t_tar *tar, int *i)
{
	int j;

	j = 0;
	if (0 < tar->numsprites)
	{
		while (j < *i)
		{
			free(tar->sprite[*i]);
			j++;
		}
		free(tar->sprite);
	}
}

static void		ft_sprite_malloc(t_tar *tar, int *i, char **tmp_map,
				char *tmp_buf)
{
	if (!(tar->sprite = (double**)malloc(sizeof(double*) *
	(tar->numsprites + 1))))
	{
		ft_close(tar, tmp_map, tmp_buf);
		printf("Error - memory error - sprite \n");
		exit(-1);
	}
	while (*i < tar->numsprites)
	{
		if (!(tar->sprite[*i] = (double*)malloc(sizeof(double) * (2))))
		{
			ft_close(tar, tmp_map, tmp_buf);
			ft_free_sprite(tar, i);
			printf("Error - memory error - sprite \n");
			exit(-1);
		}
		*i += 1;
	}
}

void			make_sprite_number(t_tar *tar, char **tmp_map, char *tmp_buf)
{
	int		i;
	int		j;

	i = 0;
	while (tmp_map[i])
	{
		j = 0;
		while (tmp_map[i][j])
		{
			if (tmp_map[i][j] == '2')
				tar->numsprites += 1;
			j++;
		}
		i++;
	}
	i = 0;
	if (tar->numsprites > 0)
		ft_sprite_malloc(tar, &i, tmp_map, tmp_buf);
}
