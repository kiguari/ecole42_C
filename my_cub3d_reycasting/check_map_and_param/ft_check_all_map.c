/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_all_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 13:17:03 by eshakita          #+#    #+#             */
/*   Updated: 2021/04/07 16:56:36 by eshakita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void		ft_close(char *buf, char **char_map, int arg)
{
	int j;

	j = 0;
	if (arg == 1)
	{
		if (char_map)
		{
			while (char_map[j])
			{
				free(char_map[j]);
				j++;
			}
			free(char_map);
		}
		printf("Error - map no valid (check wall, spr, player pos etc)\n");
	}
	if (buf)
		free(buf);
	if (arg != 1)
		printf("Error - wrong map file \n");
	exit(-1);
}

static char		**ft_make_map(char *buf, int *i)
{
	char	**char_map;

	while (buf[*i] != '\n')
		*i -= 1;
	char_map = ft_split(&buf[*i], '\n');
	if (char_map == NULL)
	{
		if (buf)
			free(buf);
		printf("Error - memory error ft_make_map \n");
		exit(-1);
	}
	while (buf[*i])
	{
		if (!ft_memcmp(&(buf[*i]), "\n\n", 2))
			ft_close(buf, char_map, 1);
		*i += 1;
	}
	return (char_map);
}

static int		ft_space(char *buf, int i)
{
	while (buf[i] == ' ' || buf[i] == '\t' || buf[i] == '\n')
		i++;
	return (i);
}

static void		ft_check_map_param(t_tar *tar, int *i, char *buf,
				t_map_flag_args *map_flag_args)
{
	if (!ft_memcmp(&(buf[*i]), "R ", 2))
		ft_resol_check(tar, i, buf, map_flag_args);
	else if (!ft_memcmp(&(buf[*i]), "NO ", 3))
		ft_north_path_check(tar, i, buf, map_flag_args);
	else if (!ft_memcmp(&(buf[*i]), "SO ", 3))
		ft_south_path_check(tar, i, buf, map_flag_args);
	else if (!ft_memcmp(&(buf[*i]), "WE ", 3))
		ft_west_path_check(tar, i, buf, map_flag_args);
	else if (!ft_memcmp(&(buf[*i]), "EA ", 3))
		ft_east_path_check(tar, i, buf, map_flag_args);
	else if (!ft_memcmp(&(buf[*i]), "S ", 2))
		ft_sprite_path_check(tar, i, buf, map_flag_args);
	else if (!ft_memcmp(&(buf[*i]), "F ", 2))
		ft_floor_color_check(tar, i, buf, map_flag_args);
	else if (!ft_memcmp(&(buf[*i]), "C ", 2))
		ft_celling_color_check(tar, i, buf, map_flag_args);
}

char			**ft_check_all_map(t_tar *tar, char *buf,
				t_map_flag_args *map_flag_args)
{
	int		i;
	char	**char_map;

	i = 0;
	char_map = NULL;
	while (buf[i])
	{
		i = ft_space(&(buf[0]), i);
		ft_check_map_param(tar, &i, buf, map_flag_args);
		if (ft_isdigit(buf[i]))
		{
			char_map = ft_make_map(buf, &i);
			break ;
		}
		else if (buf[i] != '\n')
			ft_close(buf, char_map, 1);
		i++;
	}
	if (char_map == NULL)
		ft_close(buf, char_map, 0);
	return (char_map);
}
