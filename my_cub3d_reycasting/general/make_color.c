/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 18:46:33 by eshakita          #+#    #+#             */
/*   Updated: 2021/04/06 18:57:24 by eshakita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_make_super_color(void *color)
{
	unsigned char *tmp;

	tmp = (unsigned char *)color;
	tmp[0] /= 2;
	tmp[1] /= 2;
	tmp[2] /= 2;
}

void	ft_fill_wall_color_path_one(t_make *make, t_tar *tar, t_data *data)
{
	int color;

	color = 0;
	if (make->move_map_y > 0)
	{
		color = tar->texture[2][64 * make->pix_tex_y + make->pix_tex_x];
		if (make->player_dist_to_wall > 12)
			ft_make_super_color(&color);
		my_mlx_pixel_put(data, make->each_ray, make->start_fill_pos,
		color);
	}
	if (make->move_map_y < 0)
	{
		color = tar->texture[3][64 * make->pix_tex_y + make->pix_tex_x];
		if (make->player_dist_to_wall > 12)
			ft_make_super_color(&color);
		my_mlx_pixel_put(data, make->each_ray, make->start_fill_pos,
		color);
	}
}

void	ft_fill_wall_color_path_two(t_make *make, t_tar *tar, t_data *data)
{
	int color;

	color = 0;
	if (make->move_map_x > 0)
	{
		color = tar->texture[0][64 * make->pix_tex_y + make->pix_tex_x];
		if (make->player_dist_to_wall > 12)
			ft_make_super_color(&color);
		my_mlx_pixel_put(data, make->each_ray, make->start_fill_pos,
		color);
	}
	if (make->move_map_x < 0)
	{
		color = tar->texture[1][64 * make->pix_tex_y + make->pix_tex_x];
		if (make->player_dist_to_wall > 12)
			ft_make_super_color(&color);
		my_mlx_pixel_put(data, make->each_ray, make->start_fill_pos,
		color);
	}
}
