/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_preparing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 13:39:26 by eshakita          #+#    #+#             */
/*   Updated: 2021/04/06 16:05:35 by eshakita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	ft_free_variables(t_tar *tar)
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
	i = 0;
	if (tar->numsprites > 0)
	{
		while (i < tar->numsprites)
		{
			free(tar->sprite[i]);
			i++;
		}
		free(tar->sprite);
	}
}

static void	ft_close(t_tar *tar, int arg)
{
	ft_free_variables(tar);
	if (tar->array_wall_dist)
		free(tar->array_wall_dist);
	if (arg == 1)
	{
		printf("Error - texture, check path, texture is reality etc \n");
		exit(-1);
	}
	if (arg == 2)
	{
		printf("Error - wrong texture size (need 64x64) \n");
		exit(-1);
	}
}

void		textre_color_preparing(t_tar *tar, int *texture, char *path,
			t_data *img)
{
	int wdt;
	int hgt;

	if (!(img->img = mlx_xpm_file_to_image(tar->mlx, path, &img->img_width,
	&img->img_height)))
		ft_close(tar, 1);
	if (img->img_width != 64 || img->img_height != 64)
		ft_close(tar, 2);
	img->adres = (int*)mlx_get_data_addr(img->img, &img->pix_bit,
	&img->line_length, &img->endian);
	hgt = 0;
	while (hgt < img->img_height)
	{
		wdt = 0;
		while (wdt < img->img_width)
		{
			texture[img->img_width * hgt + wdt] =
			img->adres[img->img_width * hgt + wdt];
			wdt++;
		}
		hgt++;
	}
	mlx_destroy_image(tar->mlx, img->img);
}

void		texture_init(t_tar *tar)
{
	t_data	img;

	textre_color_preparing(tar, tar->texture[0], tar->texture_path[0], &img);
	textre_color_preparing(tar, tar->texture[1], tar->texture_path[1], &img);
	textre_color_preparing(tar, tar->texture[2], tar->texture_path[2], &img);
	textre_color_preparing(tar, tar->texture[3], tar->texture_path[3], &img);
	textre_color_preparing(tar, tar->texture[4], tar->texture_path[4], &img);
}

void		ft_sprite_arrey_malloc(t_tar *tar)
{
	if (tar->numsprites > 0)
	{
		if (!(tar->array_wall_dist = malloc(sizeof(float *) * tar->wdt_win)))
		{
			ft_free_variables(tar);
			printf("Error - memory error - array_wall_dist \n");
			exit(-1);
		}
	}
}
