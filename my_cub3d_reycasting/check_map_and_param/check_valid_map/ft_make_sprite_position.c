/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_sprite_position.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 11:41:43 by eshakita          #+#    #+#             */
/*   Updated: 2021/04/06 13:21:40 by eshakita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void				ft_zero_sprite(t_tar *tar, int *sprite_num)
{
	*sprite_num = 0;
	if (tar->numsprites > 0)
	{
		tar->sprite[*sprite_num][0] = 0;
		tar->sprite[*sprite_num][1] = 0;
	}
}

void				ft_make_spr_pos(t_tar *tar, int i, int j, int *sprite_num)
{
	tar->sprite[*sprite_num][0] = i + 0.5;
	tar->sprite[*sprite_num][1] = j + 0.5;
	*sprite_num += 1;
}
