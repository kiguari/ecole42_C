/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_celling_color_check.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 11:28:05 by eshakita          #+#    #+#             */
/*   Updated: 2021/04/06 14:53:11 by eshakita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void		ft_free_close(char *buf)
{
	if (buf)
		free(buf);
	printf("Error - uncorrect ceilling color \n");
	exit(-1);
}

static void		ft_digit_color_pars(t_tar *tar, char *buf, int *i, int flag)
{
	int		u;
	char	tmp_color[100];
	int		int_tmp_color;

	u = 0;
	int_tmp_color = 0;
	tmp_color[u] = '\0';
	while (ft_isdigit(buf[*i]))
	{
		tmp_color[u] = buf[*i];
		u++;
		*i += 1;
	}
	if (ft_strlen(tmp_color) == 0)
		ft_free_close(buf);
	tmp_color[u] = '\0';
	int_tmp_color = ft_atoi(tmp_color);
	if (int_tmp_color < 0 || int_tmp_color > 255)
		ft_free_close(buf);
	if (flag == 1)
		tar->ceilling = tar->ceilling | (int_tmp_color << 16);
	if (flag == 2)
		tar->ceilling = tar->ceilling | (int_tmp_color << 8);
	if (flag == 3)
		tar->ceilling = tar->ceilling | int_tmp_color;
}

static void		ft_check_comma(char *buf, int *i)
{
	if (buf[*i] != ',')
		ft_free_close(buf);
	*i += 1;
}

static void		ft_space(char *buf, int *i)
{
	while (buf[*i] == ' ' || buf[*i] == '\t')
		*i += 1;
}

void			ft_celling_color_check(t_tar *tar, int *i, char *buf,
				t_map_flag_args *map_flag_args)
{
	*i += 2;
	ft_space(buf, i);
	ft_digit_color_pars(tar, buf, i, 1);
	ft_space(buf, i);
	ft_check_comma(buf, i);
	ft_space(buf, i);
	ft_digit_color_pars(tar, buf, i, 2);
	ft_space(buf, i);
	ft_check_comma(buf, i);
	ft_space(buf, i);
	ft_digit_color_pars(tar, buf, i, 3);
	ft_space(buf, i);
	if (buf[*i] != '\n')
		ft_free_close(buf);
	if (map_flag_args->cell == 1)
		ft_free_close(buf);
	map_flag_args->cell = 1;
}
