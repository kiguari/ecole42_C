/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmagikar <tmagikar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 15:32:09 by tmagikar          #+#    #+#             */
/*   Updated: 2021/08/17 16:40:29 by tmagikar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

void	ft_pwd_print1(t_list *list, char *pwd)
{
	if (!g_shell.flag_redir)
		write(1, "\n", 1);
	if (!g_shell.test_contr_c_sig)
		ft_putstr_fd(pwd, list->pp[1]);
	if (!list->next || list->prev || !g_shell.test_contr_c_sig)
		write(1, "\n", 1);
}

void	ft_pwd_print2(t_list *list, char *pwd)
{
	ft_putendl_fd(pwd, list->pp[1]);
	if (!list->type)
		ft_putchar('\n');
}

void	ft_pwd_print_fork(t_list *list, char *pwd)
{
	if (pipe(list->pp) < 0)
		exit (1);
	list->pid = fork();
	if (list->pid < 0)
		exit (1);
	else if (list->pid == 0)
	{
		ft_fork_bildin(list);
		if (!list->redirect_out || list->pp[0] == -1)
			ft_putendl_fd(pwd, list->pp[1]);
		exit (0);
	}
	else
		ft_fork_bildin2(list);
}

int	ft_pwd(char ***envp, t_list *list)
{
	int		i;
	char	pwd[500];

	i = 1;
	list->pp[1] = 1;
	list->redirect_out = 0;
	g_shell.flag_bildin = 1;
	g_shell.code_return = 0;
	getcwd(pwd, 500);
	while (list->arg[i] && *envp)
	{
		if (!ft_redirect_input(list, i) || !ft_redirect_output(list, i))
			break ;
		i++;
	}
	if (list->redirect_out == 1 && list->pp[1] != -1 && list->pp[0] != -1)
		ft_pwd_print2(list, pwd);
	else if (list->pp[1] == 1 && !list->type && list->pp[0] != -1)
		ft_pwd_print1(list, pwd);
	if (list->type && list->next)
		ft_pwd_print_fork(list, pwd);
	if (g_shell.test_contr_c_sig)
		ft_putchar('\n');
	return (i);
}
