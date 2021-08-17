/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_east_path_check.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 10:52:36 by eshakita          #+#    #+#             */
/*   Updated: 2021/04/06 14:53:34 by eshakita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	ft_close(char *buf)
{
	if (buf)
		free(buf);
	printf("Error - uncorrect texture path \n");
	exit(-1);
}

void		ft_east_path_check(t_tar *tar, int *i, char *buf,
			t_map_flag_args *map_flag_args)
{
	int u;

	u = 0;
	*i += 3;
	while (buf[*i] == ' ' || buf[*i] == '\t')
		*i += 1;
	while (buf[*i] != ' ' && buf[*i] != '\n' && buf[*i] != '\t')
	{
		tar->texture_path[3][u] = buf[*i];
		u++;
		*i += 1;
	}
	tar->texture_path[3][u] = '\0';
	while (buf[*i] == ' ' || buf[*i] == '\t')
		*i += 1;
	if (buf[*i] != '\n')
		ft_close(buf);
	if (map_flag_args->east == 1)
	{
		if (buf)
			free(buf);
		printf("Error - doblicate texture path \n");
		exit(-1);
	}
	map_flag_args->east = 1;
}
