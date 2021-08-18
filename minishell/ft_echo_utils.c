/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakita <eshakita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 17:12:36 by eshakita          #+#    #+#             */
/*   Updated: 2021/08/12 17:42:04 by eshakita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

void	ft_init_echo_str_var(t_bild_var *echo_str, int code)
{
	if (code == 1)
	{
		echo_str->i = 1;
		echo_str->j = 0;
		echo_str->flag_n = 0;
	}
	else if (code == 2)
	{
		echo_str->flag_n = 1;
		echo_str->i++;
	}
}

int	ft_echo_str(t_list *list, char *buf)
{
	t_bild_var	echo_str;

	ft_init_echo_str_var(&echo_str, 1);
	while (list->arg[echo_str.i])
	{
		if (!ft_redirect_input(list, echo_str.i)
			|| !ft_redirect_output(list, echo_str.i))
			return (-2);
		if (!ft_check_redirect(list, echo_str.i))
			echo_str.i += 2;
		else if (!ft_memcmp(list->arg[echo_str.i], "-n", 2)
			&& (!echo_str.flag_n || echo_str.flag_n == 1))
			ft_init_echo_str_var(&echo_str, 2);
		else
		{
			if (echo_str.j != 0)
				buf[echo_str.j++] = ' ';
			echo_str.j += ft_strlcpy(&(buf[echo_str.j]), list->arg[echo_str.i],
					ft_strlen(list->arg[echo_str.i]) + 1);
			if (echo_str.flag_n == 1)
				echo_str.flag_n = -1;
			echo_str.i++;
		}
	}
	return (echo_str.flag_n);
}
