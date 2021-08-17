/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 13:42:11 by eshakita          #+#    #+#             */
/*   Updated: 2021/04/06 18:55:24 by eshakita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void		my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = (char *)data->adres + (y * data->line_length + x *
	(data->pix_bit / 8));
	*(unsigned int*)dst = color;
}

static void	ft_fill_ceiling(t_make *make, t_tar *tar, t_data *data, int *start)
{
	int color;

	color = 0;
	while (*start < make->start_fill_pos)
	{
		color = tar->floor;
		if (*start > tar->hgt_win * 0.457)
			ft_make_super_color(&color);
		my_mlx_pixel_put(data, make->each_ray, *start, color);
		*start += 1;
	}
}

static void	ft_fill_wall(t_make *make, t_tar *tar, t_data *data)
{
	while (make->start_fill_pos < make->end_fill_pos - 1)
	{
		make->pix_tex_pos += make->step;
		make->pix_tex_y = (int)make->pix_tex_pos & (64 - 1);
		if (make->wall_side == 1)
			ft_fill_wall_color_path_one(make, tar, data);
		if (make->wall_side == 0)
			ft_fill_wall_color_path_two(make, tar, data);
		make->start_fill_pos++;
	}
}

static void	ft_fill_floor(t_make *make, t_tar *tar, t_data *data)
{
	int color;

	color = 0;
	while (make->start_fill_pos < tar->hgt_win)
	{
		color = tar->ceilling;
		if (make->start_fill_pos < tar->hgt_win * 0.54)
			ft_make_super_color(&color);
		my_mlx_pixel_put(data, make->each_ray, make->start_fill_pos,
		color);
		make->start_fill_pos++;
	}
}

void		make_line(t_data *data, t_tar *tar, t_make *make)
{
	int		start;

	start = 0;
	ft_fill_ceiling(make, tar, data, &start);
	ft_fill_wall(make, tar, data);
	ft_fill_floor(make, tar, data);
}
