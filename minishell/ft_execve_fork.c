/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execve_fork.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmagikar <tmagikar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 19:07:00 by tmagikar          #+#    #+#             */
/*   Updated: 2021/08/16 20:00:03 by tmagikar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

int	ft_sys_pipe(t_list *list)
{
	if (ft_open_zero_redirect(list))
		return (-1);
	if (list->type && list->next)
	{
		if (pipe(list->pp) < 0)
			exit (1);
	}
	return (0);
}

static void	ft_sys_fork_1(t_list *list, int fdre0, int fdre1)
{
	if (!g_shell.flag_redir && !list->next)
		ft_putstr("\n");
	if (list->type)
	{
		if (!list->redirect_out)
			dup2(list->pp[1], 1);
		else
			dup2(fdre1, 1);
		if (list->redirect_in)
			dup2(fdre0, 0);
		close(list->pp[0]);
	}
}

static void	ft_sys_fork_2(t_list *list, int fdre0, int fdre1)
{
	if (list->prev && list->prev->type)
	{
		if (!list->redirect_in)
			dup2(list->prev->pp[0], 0);
		else
			dup2(fdre0, 0);
		if (list->redirect_out)
			dup2(fdre1, 1);
		close(list->pp[1]);
	}
	if (!list->type && !list->next && (list->redirect_out || list->redirect_in))
	{
		if (!list->redirect_out)
			dup2(list->pp[1], 1);
		if (list->redirect_out)
			dup2(fdre1, 1);
		if (!list->redirect_in)
			dup2(list->pp[0], 0);
		else
			dup2(fdre0, 0);
		close(fdre0);
	}
}

/*
** в execve если команда не найдена
*/
void	ft_execve_cnf(t_list *list)
{
	if (!g_shell.flag_redir)
		g_shell.code_return = 1;
	if (!list->prev)
		ft_putchar('\n');
	ft_putstr3("minigoose: ", list->arg[0], ": command not found\n");
}

void	ft_execve_pid_null(t_list *list, char **envp, int *fd, char *path)
{
	if (!g_shell.test_contr_c_sig)
	{
		ft_sys_fork_1(list, fd[0], fd[1]);
		ft_sys_fork_2(list, fd[0], fd[1]);
		if (fd[2] == -1)
			exit (0);
		list->res = execve(path, list->arg, envp);
		if (list->res < 0)
			ft_execve_cnf(list);
	}
	exit (0);
}
