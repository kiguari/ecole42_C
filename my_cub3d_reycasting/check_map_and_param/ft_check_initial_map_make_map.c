/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_initial_map_make_map.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 12:43:56 by eshakita          #+#    #+#             */
/*   Updated: 2021/04/08 15:16:16 by eshakita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void				ft_check_initial_map_make_map(char *initial_map, t_tar *tar)
{
	char			*tmp_buf;
	char			**tmp_map;
	int				i;
	int				max_map_len;
	t_map_flag_args	map_flag_args;

	ft_assigment_map_flags_args(&map_flag_args, tar);
	tmp_buf = ft_buff_prepering(initial_map);
	tmp_map = ft_check_all_map(tar, tmp_buf, &map_flag_args);
	max_map_len = 0;
	ft_check_map_len(tar, tmp_map, &i, &max_map_len);
	make_sprite_number(tar, tmp_map, tmp_buf);
	if (tmp_buf)
		free(tmp_buf);
	check_valid_map(tar, tmp_map, max_map_len, i);
	ft_map_malloc(tar, &i, max_map_len, tmp_map);
	check_flag(&map_flag_args, tar, tmp_map);
	ft_make_int_map(tar, tmp_map);
	ft_free_tmp_variables(tmp_map);
}
