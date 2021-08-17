/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 13:50:38 by eshakita          #+#    #+#             */
/*   Updated: 2021/04/08 15:16:26 by eshakita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_free_main_variables(t_tar *tar)
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

int			ft_close_program(t_tar *tar)
{
	return (ft_correct_exit_program(tar, 2));
}

static void	ft_error_exit_program(void)
{
	printf("Error - wrong quantity arguments (need map_file) \n");
	exit(-1);
}

int			ft_correct_exit_program(t_tar *tar, int arg)
{
	int i;

	i = 0;
	mlx_destroy_image(tar->mlx, tar->img.img);
	mlx_destroy_window(tar->mlx, tar->win);
	ft_free_main_variables(tar);
	if (arg == 1)
		printf("game over - esc\n");
	else if (arg == 2)
		printf("game over - red_x\n");
	exit(0);
}

int			main(int argc, char **argv)
{
	t_tar	tar;
	int		flag_args_num;

	ft_assigment_tar_variables(&tar);
	flag_args_num = ft_check_num_arg(argc, argv);
	if ((tar.fd = open(argv[1], O_RDONLY) <= 0) || (flag_args_num == 0))
		ft_error_exit_program();
	ft_check_initial_map_make_map(argv[1], &tar);
	tar.mlx = mlx_init();
	ft_sprite_arrey_malloc(&tar);
	texture_init(&tar);
	ft_check_resol(&tar);
	tar.win = mlx_new_window(tar.mlx, tar.wdt_win, tar.hgt_win, "My cub3d");
	tar.img.img = mlx_new_image(tar.mlx, tar.wdt_win, tar.hgt_win);
	tar.img.adres = (int *)mlx_get_data_addr(tar.img.img, &tar.img.pix_bit,
	&tar.img.line_length, &tar.img.endian);
	ft_make_image_on_screen(&tar);
	if (flag_args_num == 2)
		make_screenshot(&tar);
	mlx_hook(tar.win, 2, 0, &use_button_keep, &tar);
	mlx_hook(tar.win, 3, 0, &use_button_let_go, &tar);
	mlx_hook(tar.win, 17, 0, &ft_close_program, &tar);
	mlx_loop_hook(tar.mlx, &ft_make_next_frame, &tar);
	mlx_put_image_to_window(tar.mlx, tar.win, tar.img.img, 0, 0);
	mlx_loop(tar.mlx);
}
