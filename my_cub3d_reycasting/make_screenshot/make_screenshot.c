/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_screenshot.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 13:22:48 by eshakita          #+#    #+#             */
/*   Updated: 2021/04/15 15:33:09 by eshakita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	ft_free_variables(t_tar *tar)
{
	int i;

	i = 0;
	if (tar->array_wall_dist)
		free(tar->array_wall_dist);
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

static void	ft_close_screen(t_tar *tar, int arg)
{
	mlx_destroy_image(tar->mlx, tar->img.img);
	mlx_destroy_window(tar->mlx, tar->win);
	if (arg == 1)
	{
		ft_free_variables(tar);
		printf("Error - can't do screenshot \n");
	}
	if (arg == 2)
	{
		ft_free_variables(tar);
		printf("Screenshot ready \n");
	}
}

static void	ft_creat_head(t_tar *tar, unsigned char *bmp_data,
			int bmp_data_size)
{
	bmp_data[0] = (unsigned char)'B';
	bmp_data[1] = (unsigned char)'M';
	bmp_data[2] = (unsigned char)bmp_data_size;
	bmp_data[3] = (unsigned char)(bmp_data_size >> 8);
	bmp_data[4] = (unsigned char)(bmp_data_size >> 16);
	bmp_data[5] = (unsigned char)(bmp_data_size >> 24);
	bmp_data[10] = (unsigned char)54;
	bmp_data[14] = (unsigned char)40;
	bmp_data[18] = (unsigned char)tar->wdt_win;
	bmp_data[19] = (unsigned char)(tar->wdt_win >> 8);
	bmp_data[20] = (unsigned char)(tar->wdt_win >> 16);
	bmp_data[21] = (unsigned char)(tar->wdt_win >> 24);
	bmp_data[22] = (unsigned char)tar->hgt_win;
	bmp_data[23] = (unsigned char)(tar->hgt_win >> 8);
	bmp_data[24] = (unsigned char)(tar->hgt_win >> 16);
	bmp_data[25] = (unsigned char)(tar->hgt_win >> 24);
	bmp_data[26] = (unsigned char)1;
	bmp_data[28] = (unsigned char)24;
}

static void	ft_creat_screenshot_img(t_tar *tar)
{
	int		x;
	int		y;
	char	*color;
	int		tmp_calc;

	y = tar->hgt_win - 1;
	while (y >= 0)
	{
		x = 0;
		while (x < tar->wdt_win)
		{
			tmp_calc = y * tar->img.line_length + x * (tar->img.pix_bit / 8);
			color = (char*)tar->img.adres + tmp_calc;
			write(tar->fd, color, 3);
			x++;
		}
		y--;
	}
}

int			make_screenshot(t_tar *tar)
{
	int		count;

	count = 0;
	while (count < 54)
		tar->bmp_data[count++] = (char)0;
	if (tar->wdt_win % 4)
		tar->wdt_win -= (tar->wdt_win % 4);
	tar->bmp_data_size = tar->wdt_win * tar->hgt_win + 54;
	tar->fd = open("Screenshoot.bmp", O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
	if (tar->fd <= 0)
	{
		ft_close_screen(tar, 1);
		exit(-1);
	}
	ft_creat_head(tar, tar->bmp_data, tar->bmp_data_size);
	write(tar->fd, tar->bmp_data, 54);
	ft_creat_screenshot_img(tar);
	close(tar->fd);
	ft_close_screen(tar, 2);
	exit(0);
}
