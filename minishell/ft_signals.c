/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signals.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmagikar <tmagikar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 12:23:36 by eshakita          #+#    #+#             */
/*   Updated: 2021/08/17 16:48:56 by tmagikar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

int	ft_check_minishell(char *command)
{
	int	i;

	i = ft_strlen(command) - 10;
	if (i >= 0)
		if (!ft_memcmp(&(command[i]), "/minishell", 10))
			return (1);
	return (0);
}

void	sig_quit(int code)
{
	if (g_shell.child == 0)
	{
		if (code == SIGQUIT && !g_shell.flag_redir)
		{
			if (waitpid(-1, NULL, WNOHANG) == -1)
				printf("  \b\b");
			else
				printf("Quit: 3\n");
			g_shell.ret_code = 131;
		}
	}
}

void	for_signal(int sig)
{
	int	norma_besit;

	norma_besit = sig;
	if (g_shell.child == 0)
	{
		if (!g_shell.flag_redir)
			ft_putstr_fd("\e[32m\nminishell$ \e[0m", 1);
		g_shell.tmp_count = 0;
		g_shell.count_len = -1;
		tputs(save_cursor, 1, ft_putchar);
		g_shell.test_contr_c_sig = 1;
	}
}

void	for_signal_fork(int sig)
{
	int	norma_besit;

	norma_besit = sig;
	if (g_shell.child == 0)
	{
		if (!g_shell.flag_redir)
		{
			ft_putstr_fd("\n", 1);
			tputs(save_cursor, 1, ft_putchar);
			g_shell.test_contr_c_sig = 1;
		}
		g_shell.ret_code = 130;
	}
}

void	for_signal_her(int sig)
{
	g_shell.flag_redir = 1;
	if (sig == SIGINT)
	{
		tputs(cursor_left, 1, ft_putchar);
		tputs(tgetstr("dc", 0), 1, ft_putchar);
		tputs(cursor_left, 1, ft_putchar);
		tputs(tgetstr("dc", 0), 1, ft_putchar);
		if (!g_shell.flag_bildin)
			ft_putstr_fd("\n", 1);
		else if (g_shell.flag_bildin == 2)
			ft_putstr_fd("\n", 1);
		exit(1);
	}
	else if (sig == SIGQUIT)
	{
		tputs(cursor_left, 1, ft_putchar);
		tputs(tgetstr("dc", 0), 1, ft_putchar);
		tputs(cursor_left, 1, ft_putchar);
		tputs(tgetstr("dc", 0), 1, ft_putchar);
	}
}
