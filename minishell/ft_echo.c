/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmagikar <tmagikar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 17:06:09 by eshakita          #+#    #+#             */
/*   Updated: 2021/08/16 20:01:03 by tmagikar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

void	ft_init_echo_var(t_bild_var *echo, t_list *list)
{
	echo->i = 1;
	echo->j = 0;
	list->pp[1] = 1;
	list->tmp_i = 0;
	ft_fullzero(echo->buf);
	echo->flag_n = ft_echo_str(list, echo->buf);
}

int	ft_check_flag_n(t_bild_var *echo, t_list *list)
{
	if (echo->flag_n)
		g_shell.echo_flag = 0;
	else if (echo->flag_n == -2)
		return (-1);
	echo->not_print_pipe = list->pp[0];
	return (0);
}

void	ft_check_cd_redir(t_bild_var *echo, t_list *list)
{
	if (list->redirect_out && list->pp[0] != -1)
	{
		g_shell.code_return = 0;
		if (echo->flag_n != 0)
			ft_putstr_fd(echo->buf, list->pp[1]);
		else
			ft_putendl_fd(echo->buf, list->pp[1]);
	}
	else if (!list->redirect_out && !list->type && list->pp[0] != -1)
	{
		g_shell.code_return = 0;
		ft_putchar_fd('\n', list->pp[1]);
		ft_putstr_fd(echo->buf, list->pp[1]);
	}
}

int	ft_pipe_in_cd(t_bild_var *echo, t_list *list)
{
	if (list->type && list->next && list->pp[0] != -1)
	{
		g_shell.code_return = 0;
		if (pipe(list->pp) < 0)
			exit (1);
		list->pid = fork();
		if (list->pid < 0)
			exit (1);
		else if (list->pid == 0)
		{
			ft_fork_bildin(list);
			if (!list->tmp_i && echo->not_print_pipe != -1)
			{
				ft_putstr_fd(echo->buf, list->pp[1]);
			}
			exit (0);
		}
		else
			ft_fork_bildin2(list);
	}
	return (0);
}

int	ft_echo(t_list *list)
{
	t_bild_var	echo;

	ft_init_echo_var(&echo, list);
	if (ft_check_flag_n(&echo, list) == -1)
		return (-1);
	ft_check_cd_redir(&echo, list);
	ft_pipe_in_cd(&echo, list);
	if (list->pp[0] == -1)
		return (-1);
	return (0);
}
