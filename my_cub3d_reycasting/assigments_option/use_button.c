/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   use_button.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 13:16:18 by eshakita          #+#    #+#             */
/*   Updated: 2021/04/07 14:21:37 by eshakita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		use_button_keep(int button, t_tar *tar)
{
	if (button == 53)
		ft_correct_exit_program(tar, 1);
	else if (button == 13)
		tar->button_w = 1;
	else if (button == 0)
		tar->button_a = 1;
	else if (button == 1)
		tar->button_s = 1;
	else if (button == 2)
		tar->button_d = 1;
	else if (button == 124)
		tar->button_e = 1;
	else if (button == 123)
		tar->button_q = 1;
	return (0);
}

int		use_button_let_go(int button, t_tar *tar)
{
	if (button == 13)
		tar->button_w = 0;
	else if (button == 0)
		tar->button_a = 0;
	else if (button == 1)
		tar->button_s = 0;
	else if (button == 2)
		tar->button_d = 0;
	else if (button == 124)
		tar->button_e = 0;
	else if (button == 123)
		tar->button_q = 0;
	return (0);
}
