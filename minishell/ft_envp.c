/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_envp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmagikar <tmagikar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 17:14:05 by tmagikar          #+#    #+#             */
/*   Updated: 2021/08/16 20:00:46 by tmagikar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

void	ft_print_env1(char **envp, int fd)
{
	int	i;

	i = 0;
	while (envp[i] && !g_shell.test_contr_c_sig)
	{
		if (ft_check_ravno(envp[i]))
		{
			ft_putstr_fd(envp[i], fd);
			ft_putchar_fd('\n', fd);
		}
		i++;
	}
}

void	ft_print_env2(char **envp, int fd)
{
	int	i;

	i = 0;
	while (envp[i] && !g_shell.test_contr_c_sig)
	{
		if (ft_check_ravno(envp[i]))
		{
			if (!g_shell.firts_new_line)
				ft_putchar_fd('\n', fd);
			g_shell.firts_new_line = 0;
			ft_putstr_fd(envp[i], fd);
		}
		i++;
	}
}

void	ft_env_fork(t_list *list, char ***envp)
{
	if (pipe(list->pp) < 0)
		exit (1);
	list->pid = fork();
	if (list->pid < 0)
		exit (1);
	else if (list->pid == 0)
	{
		ft_fork_bildin(list);
		if (!list->redirect_out)
			ft_print_env1(*envp, list->pp[1]);
		exit (0);
	}
	else
		ft_fork_bildin2(list);
}

int	ft_env_check_red(t_list *list)
{
	int	i;

	i = 1;
	while (list->arg[i])
	{
		if (!ft_redirect_input(list, i) || !ft_redirect_output(list, i))
			return (-1);
		if (!ft_check_redirect(list, i))
			i += 2;
		else
			i++;
	}
	return (0);
}

int	ft_env(char ***envp, t_list *list)
{
	int	i;

	list->pp[1] = 1;
	list->redirect_out = 0;
	if (ft_env_check_red(list))
		return (-1);
	i = 0;
	if (list->redirect_out && list->pp[1] != -1)
		ft_print_env1(*envp, list->pp[1]);
	else if (!list->redirect_out && !list->type)
		ft_print_env2(*envp, list->pp[1]);
	if (list->type && list->next)
		ft_env_fork(list, envp);
	return (0);
}
