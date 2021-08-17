/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_next_frame.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 13:43:42 by eshakita          #+#    #+#             */
/*   Updated: 2021/04/02 16:10:10 by eshakita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int			ft_make_next_frame(t_tar *tar)
{
	t_data	img_buff;

	ft_player_move(tar);
	img_buff.img = mlx_new_image(tar->mlx, tar->wdt_win, tar->hgt_win);
	img_buff.adres = (int *)mlx_get_data_addr(img_buff.img,
	&(img_buff.pix_bit), &(img_buff.line_length), &(img_buff.endian));
	mlx_clear_window(tar->mlx, tar->win);
	mlx_destroy_image(tar->mlx, tar->img.img);
	tar->img = img_buff;
	ft_make_image_on_screen(tar);
	mlx_put_image_to_window(tar->mlx, tar->win, tar->img.img, 0, 0);
	return (0);
}
