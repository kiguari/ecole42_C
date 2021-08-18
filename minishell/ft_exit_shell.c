/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_shell.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmagikar <tmagikar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 18:43:30 by tmagikar          #+#    #+#             */
/*   Updated: 2021/08/17 16:45:30 by tmagikar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

void	ft_exit_shell1(t_list *list)
{
	int	i;

	i = 0;
	while (list->arg[1][i])
	{
		if ((i == 0) && (list->arg[1][0] == '-' || list->arg[1][0] == '+'))
			i++;
		if (!ft_isdigit(list->arg[1][i++]))
			ft_exit("goose: exit:", list->arg[1], \
			": numeric argument required\n", 255);
	}
}

int	ft_exit_shell(t_list *list)
{
	int				i;

	i = 0;
	if (list->arg[1])
	{
		g_shell.code_return = (unsigned char)ft_atoi(list->arg[1]);
		ft_exit_shell1(list);
		if (list->arg[2])
		{
			ft_putstr("\nexit\ngoose: exit: too many arguments");
			g_shell.code_return = 1;
			return (1);
		}
	}
	else
		g_shell.code_return = 0;
	ft_putstr("\nexit\n");
	exit(g_shell.code_return);
}

void	ft_exit(char *str1, char *str2, char *str3, int code)
{
	ft_putstr("\nexit\n");
	ft_putstr(str1);
	if (str2)
		ft_putstr(str2);
	if (str3)
		ft_putstr(str3);
	exit(code);
}
