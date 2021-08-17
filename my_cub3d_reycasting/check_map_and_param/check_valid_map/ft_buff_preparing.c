/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buff_preparing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 11:31:05 by eshakita          #+#    #+#             */
/*   Updated: 2021/04/06 14:52:30 by eshakita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

static void			ft_close_map(char *tmp_buf)
{
	if (tmp_buf)
		free(tmp_buf);
	printf("Error - wrong map file\n");
	exit(-1);
}

void				ft_assigment_map_flags_args(t_map_flag_args *map_flag_args,
					t_tar *tar)
{
	map_flag_args->resol = 0;
	map_flag_args->north = 0;
	map_flag_args->south = 0;
	map_flag_args->west = 0;
	map_flag_args->east = 0;
	map_flag_args->spr = 0;
	map_flag_args->cell = 0;
	map_flag_args->floor = 0;
	tar->floor = 0;
	tar->ceilling = 0;
	tar->player_position = 0;
}

char				*ft_buff_prepering(char *initial_map)
{
	int				fd;
	int				size;
	char			tmp_static_buf[201];
	char			*tmp_buf;

	if (!(tmp_buf = malloc(1)))
	{
		printf("Error - memory error - tmp_buf \n");
		exit(-1);
	}
	tmp_buf[0] = '\0';
	fd = open(initial_map, O_RDONLY);
	if (fd < 0)
		ft_close_map(tmp_buf);
	while ((size = read(fd, tmp_static_buf, 200)))
	{
		if (size < 0)
			ft_close_map(tmp_buf);
		tmp_static_buf[size] = '\0';
		tmp_buf = ft_strjoin(tmp_buf, tmp_static_buf);
	}
	if (!*tmp_buf)
		ft_close_map(tmp_buf);
	close(fd);
	return (tmp_buf);
}
