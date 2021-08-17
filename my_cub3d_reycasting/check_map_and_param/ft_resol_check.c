/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resol_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 10:09:23 by eshakita          #+#    #+#             */
/*   Updated: 2021/04/08 10:42:59 by eshakita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void		ft_close(char *buf, int flag)
{
	if (buf)
		free(buf);
	if (flag == 1)
		printf("Error - doblicate screen size \n");
	if (flag == 2)
		printf("Error - wrong screen size \n");
	exit(-1);
}

static void		ft_copy_resol_in_tmp(char *tmp_value, char *buf, int *i)
{
	int			u;

	u = 0;
	while (buf[*i] == '0')
		*i += 1;
	while (ft_isdigit(buf[*i]))
	{
		tmp_value[u] = buf[*i];
		*i += 1;
		u++;
	}
	if (u > 8)
		tmp_value[7] = '\0';
	else
		tmp_value[u] = '\0';
}

void			ft_resol_check(t_tar *tar, int *i, char *buf,
				t_map_flag_args *map_flag_args)
{
	char		tmp_screen_width[100];
	char		tmp_screen_hight[100];

	*i += 2;
	while (buf[*i] == ' ' || buf[*i] == '\t')
		*i += 1;
	ft_copy_resol_in_tmp(tmp_screen_width, buf, i);
	tar->wdt_win = ft_atoi(tmp_screen_width);
	while (buf[*i] == ' ' || buf[*i] == '\t')
		*i += 1;
	ft_copy_resol_in_tmp(tmp_screen_hight, buf, i);
	tar->hgt_win = ft_atoi(tmp_screen_hight);
	if (map_flag_args->resol == 1)
		ft_close(buf, 1);
	map_flag_args->resol = 1;
	while (buf[*i] == ' ' || buf[*i] == '\t')
		*i += 1;
	if (buf[*i] != '\n' || tar->hgt_win <= 0 || tar->wdt_win <= 0)
		ft_close(buf, 2);
}
