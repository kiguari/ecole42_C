/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_num_arg.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 12:09:35 by eshakita          #+#    #+#             */
/*   Updated: 2021/04/02 13:11:28 by eshakita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		ft_check_second_arg(char *argv, int i)
{
	while (argv[i])
	{
		if (argv[i] != '-')
			return (1);
		i++;
		if (argv[i] != '-')
			return (1);
		i++;
		if (argv[i] != 's')
			return (1);
		i++;
		if (argv[i] != 'a')
			return (1);
		i++;
		if (argv[i] != 'v')
			return (1);
		i++;
		if (argv[i] != 'e')
			return (1);
		i++;
		if (argv[i] != '\0')
			return (1);
		return (2);
	}
	return (1);
}

int		ft_check_first_arg(char *argv, int i)
{
	while (argv[i])
		i++;
	if (i < 4)
		return (0);
	i -= 4;
	if (argv[i] != '.')
		return (0);
	i++;
	if (argv[i] != 'c')
		return (0);
	i++;
	if (argv[i] != 'u')
		return (0);
	i++;
	if (argv[i] != 'b')
		return (0);
	return (1);
}

int		ft_check_num_arg(int argc, char **argv)
{
	int i;

	i = 0;
	if (argc < 2)
		return (0);
	if (ft_check_first_arg(argv[1], i) == 0)
		return (0);
	i = 0;
	if (argv[2])
	{
		if (ft_check_second_arg(argv[2], i) == 2)
			return (2);
	}
	return (1);
}
