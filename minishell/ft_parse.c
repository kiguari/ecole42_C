/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmagikar <tmagikar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 12:38:13 by eshakita          #+#    #+#             */
/*   Updated: 2021/08/17 16:41:43 by tmagikar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

void	ft_pars_wait(t_list *list)
{
	if (list->arg)
		waitpid(list->pid, &list->res, 0);
	if (!g_shell.flag_bildin)
	{
		if (WIFEXITED(list->res))
			list->res = WEXITSTATUS(list->res);
		g_shell.code_return = list->res;
	}
	if (g_shell.ret_code == 1 && g_shell.code_return != 2)
		g_shell.code_return = 1;
	else if (g_shell.ret_code == 130)
		g_shell.code_return = 130;
	else if (g_shell.ret_code == 131)
		g_shell.code_return = 131;
}

void	ft_run_cmd(t_list *list, char ***envp, int *code)
{
	if (!list->arg[0])
		ft_zero_fork(list);
	else if (!ft_strcmp(list->arg[0], "pwd"))
		*code = ft_pwd(envp, list);
	else if (!ft_strcmp(list->arg[0], "unset"))
		*code = ft_unset(envp, list);
	else if (!ft_strcmp(list->arg[0], "cd"))
		*code = ft_cd(envp, list);
	else if (!ft_strcmp(list->arg[0], "echo"))
		*code = ft_echo(list);
	else if (!ft_strcmp(list->arg[0], "export"))
		*code = ft_export(envp, list);
	else if (!ft_strcmp(list->arg[0], "env"))
		*code = ft_env(envp, list);
	else if (!ft_strcmp(list->arg[0], "exit"))
		ft_exit_shell(list);
	else if (list->arg[0] == NULL)
		ft_putstr("\ngoose: : command not found\n");
	else if (!ft_check_redirect(list, 0))
		*code = ft_open_zero_redirect1(list);
	else
		*code = ft_execve_call(list, envp);
}

void	ft_parse_loop(t_list **p_list, t_list **tmps, char ***envp, int *code)
{
	t_list	*list;

	list = *p_list;
	while (list)
	{
		g_shell.flag_bildin = 1;
		ft_donald_baks(*envp, list);
		if (list->arg[0] && !ft_check_redirect(list, 0))
			ft_redirect_sort(list);
		signal(SIGINT, for_signal);
		ft_run_cmd(list, envp, code);
		*tmps = list;
		list = list->next;
		if (*code == -1)
			break ;
	}
}

int	ft_init_pars_var(t_list **list, t_list **tmps, char *line_to_pars)
{
	ft_write_hist(line_to_pars);
	g_shell.ret_code = 0;
	g_shell.test_contr_c_sig = 0;
	*list = ft_choto_list_1(line_to_pars, 0, 0);
	if (!list)
		return (-1);
	*tmps = *list;
	return (0);
}

int	ft_pars_00(char *line_to_pars, char ***envp)
{
	int		code;
	t_list	*list;
	t_list	*tmps;

	if (ft_init_pars_var(&list, &tmps, line_to_pars) == -1)
		return (-1);
	code = ft_num_pipe(line_to_pars, 0, 0);
	ft_set_term(2);
	ft_parse_loop(&list, &tmps, envp, &code);
	g_shell.flag_redir = 0;
	list = tmps;
	while (list)
	{
		ft_pars_wait(list);
		tmps = list;
		list = list->prev;
	}
	unlink("tmp_text_redirect.ggwp");
	ft_all_list_free(tmps);
	g_shell.child = 0;
	return (code);
}
