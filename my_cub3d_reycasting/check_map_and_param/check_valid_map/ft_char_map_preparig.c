/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_map_preparig.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 11:36:18 by eshakita          #+#    #+#             */
/*   Updated: 2021/04/06 13:08:07 by eshakita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void		ft_check_map_len(t_tar *tar, char **tmp_map,
			int *i, int *max_map_len)
{
	*i = 0;
	while (tmp_map[*i])
	{
		if (*max_map_len < (int)ft_strlen(tmp_map[*i]))
			*max_map_len = ft_strlen(tmp_map[*i]);
		*i += 1;
	}
	tar->hgt_map = *i;
	tar->wdt_map = *max_map_len;
}
