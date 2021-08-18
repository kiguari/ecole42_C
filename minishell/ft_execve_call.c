/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execve_call.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmagikar <tmagikar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 18:22:12 by tmagikar          #+#    #+#             */
/*   Updated: 2021/08/17 16:40:57 by tmagikar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

int	ft_sys_check_command_2_1(t_list *list, char *buf, char **path)
{
	chdir(buf);
	if (ft_sys_pipe(list))
		return (-1);
	if (!list->prev)
		ft_putchar('\n');
	ft_putstr3("minigoose: ", list->arg[0], ": is a directory\n");
	free(*path);
	g_shell.code_return = 126;
	return (1);
}

void	ft_sys_waitpid(t_list *list, int fdre0, int fdre1, int status)
{
	if (WIFEXITED(status))
		list->res = WIFEXITED(status);
	if (list->redirect_out)
		close(fdre1);
	if (list->redirect_in)
		close(fdre0);
	if (list->type)
	{
		close(list->pp[1]);
		if (!list->next)
			close(list->pp[0]);
	}
	if (list->prev && list->prev->type)
		close(list->prev->pp[0]);
	close(fdre0);
}

void	ft_sys_call_utils(t_list *list, char *tmp_path)
{
	if (list->prev)
	{
		list->pp[0] = list->prev->pp[0];
		list->pp[1] = list->prev->pp[1];
	}
	if (list->type && list->next)
	{
		if (pipe(list->pp) < 0)
			exit (1);
	}
	if (ft_check_minishell(tmp_path))
		g_shell.child = 1;
	signal(SIGINT, for_signal_fork);
	g_shell.flag_bildin = 0;
	list->pid = fork();
}

void	ft_execve_call_init(int *fd_res_status)
{
	fd_res_status[0] = -2;
	fd_res_status[1] = -2;
	fd_res_status[2] = 0;
	fd_res_status[3] = 0;
	fd_res_status[4] = 0;
	g_shell.flag_bildin = 2;
}

/*
** fd_res_status[5]:
** [0] ==  fdre0;	[1] == fdre1; [2] == exit перед execve
** [3] == (res) отвечает за выход из систем_колл при неверном пути
** [4] == status - нужен в waitpid
*/
int	ft_execve_call(t_list *list, char ***envp)
{
	int			fd_res_status[5];
	char		*tmp_path;
	struct stat	bufst[1111];

	ft_execve_call_init(fd_res_status);
	fd_res_status[3] = ft_sys_check_command(list, *envp, &tmp_path, bufst);
	if (fd_res_status[3])
		return (fd_res_status[3]);
	if (ft_system_redirect(list, &fd_res_status[0], &fd_res_status[1]))
		return (-1);
	if (fd_res_status[0] == -3)
		return (ft_fork_zero(list));
	fd_res_status[2] = list->pp[0];
	ft_sys_call_utils(list, tmp_path);
	if (list->pid < 0)
		exit (1);
	else if (list->pid == 0)
		ft_execve_pid_null(list, *envp, fd_res_status, tmp_path);
	else
		ft_sys_waitpid(list, fd_res_status[0], fd_res_status[1], \
				fd_res_status[4]);
	free(tmp_path);
	return (list->res);
}
