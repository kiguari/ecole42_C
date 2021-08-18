/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_global_utils_continue.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmagikar <tmagikar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 17:28:10 by eshakita          #+#    #+#             */
/*   Updated: 2021/08/16 19:59:05 by tmagikar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

int	ft_isspec_sym(char c)
{
	if (c == ' ' || c == '\\' || c == '>' || c == '<' || c == '|'
		|| c == ';' || c == '\n' || c == '\0')
		return (1);
	return (0);
}

int	ft_issym(char c)
{
	if (c == '\\' || c == '>' || c == '<' || c == '|'
		|| c == ';' || c == '\0')
		return (1);
	return (0);
}

int	skip_space(char *buf, int i)
{
	while (buf[i] == ' ' || buf[i] == '\t')
		i++;
	return (i);
}

void	ft_global_var_init(void)
{
	g_shell.pos_hist = 0;
	g_shell.code_return = 0;
	g_shell.echo_flag = 1;
}

void	ft_global_var_new_cycle(void)
{
	g_shell.flag_bildin = 0;
	g_shell.tmp_count = 0;
	g_shell.count_len = -1;
	g_shell.test_contr_c_sig = 0;
	g_shell.flag_redir = 0;
}
