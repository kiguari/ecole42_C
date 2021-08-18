/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell_loop.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmagikar <tmagikar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 17:47:03 by eshakita          #+#    #+#             */
/*   Updated: 2021/08/17 15:59:48 by tmagikar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

void	ft_shell_live(char *str, char *line_to_pars, t_init *init)
{
	while (strcmp(str, "\4"))
	{
		ft_make_loop_param(init);
		while (1)
		{
			if (!ft_minishell_heart(init, str, line_to_pars))
				break ;
		}
	}
}

int	ft_minishell_heart(t_init *init, char *str, char *line_to_pars)
{
	init->i = read(0, str, 100);
	if (init->i == -1)
		return (0);
	else
		str[init->i] = 0;
	if (!strncmp(str, "\n", 4) && g_shell.count_len >= 0
		&& ft_pars_00(line_to_pars, &init->my_envp))
		return (0);
	else if (!strcmp(str, "\t") || !strcmp(str, "\5"))
		return (1);
	else if (!strcmp(str, "\e[A") || !strcmp(str, "\e[B"))
		ft_history_updown_switch(init, str, line_to_pars);
	else if (!strcmp(str, "\177"))
		ft_delete_symbol();
	else if (strncmp(str, "\e", 1))
		if (!ft_make_line(str, init, line_to_pars))
			return (0);
	line_to_pars[g_shell.count_len + 1] = '\0';
	if (!strcmp(str, "\n"))
		return (0);
	return (1);
}

int	ft_make_line(char *str, t_init *init, char *line_to_pars)
{
	if (g_shell.echo_flag)
		write(1, str, init->i);
	else
		g_shell.echo_flag = 1;
	if (!strcmp(str, "\4") && g_shell.count_len == -1)
		return (0);
	if (!strcmp(str, "\n"))
		g_shell.tmp_count++;
	if (g_shell.tmp_count == 0)
		g_shell.count_len++;
	line_to_pars[g_shell.count_len] = *str;
	return (1);
}

void	ft_delete_symbol(void)
{
	if (g_shell.count_len >= 0)
	{
		tputs(cursor_left, 1, ft_putchar);
		tputs(tgetstr("dc", 0), 1, ft_putchar);
		g_shell.count_len--;
	}
}

void	ft_make_loop_param(t_init *init)
{
	ft_set_term(1);
	signal(SIGINT, for_signal);
	signal(SIGQUIT, &sig_quit);
	ft_putstr("\e[32mminishell$ \e[0m");
	g_shell.flag_bildin = 0;
	g_shell.tmp_count = 0;
	g_shell.count_len = -1;
	g_shell.test_contr_c_sig = 0;
	g_shell.flag_redir = 0;
	g_shell.firts_new_line = 0;
	tputs(save_cursor, 1, ft_putchar);
	init->new_pos_tmp = g_shell.pos_hist;
}
