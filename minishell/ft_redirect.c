/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirect.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmagikar <tmagikar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 12:46:37 by eshakita          #+#    #+#             */
/*   Updated: 2021/08/16 19:56:16 by tmagikar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

int	ft_syntax_red_err(t_list *list, int i)
{
	if (!list->arg[i + 1] || !ft_strcmp(list->arg[i + 1], ">")
		|| !ft_strcmp(list->arg[i + 1], ">>") || !ft_strcmp(list->arg[i
				+ 1], "<") || !ft_strcmp(list->arg[i + 1], "<<"))
		return (0);
	return (1);
}

int	ft_check_redirect(t_list *list, int i)
{
	if (!list->arg[i] || !ft_strcmp(list->arg[i], ">")
		|| !ft_strcmp(list->arg[i], ">>") || !ft_strcmp(list->arg[i], \
				"<") || !ft_strcmp(list->arg[i], "<<"))
		return (0);
	return (1);
}

int	ft_redirect_error(t_list *list, int i, int pp)
{
	if (!ft_syntax_red_err(list, i))
	{
		list->pp[pp] = -1;
		g_shell.code_return = 258;
		if (list->arg[i + 1])
			ft_putstr3("\nbash: syntax error near unexpected token \'",
				list->arg[i + 1], "\'\n");
		else
			ft_putstr("\nbash: syntax error near unexpected token \'newline\'\n");
		return (0);
	}
	return (1);
}

int	ft_redirect_output(t_list *list, int i)
{
	if (!ft_strcmp(list->arg[i], ">") && !g_shell.test_contr_c_sig)
	{
		if (list->redirect_out)
			close(list->pp[1]);
		list->redirect_out = 1;
		if (!ft_redirect_error(list, i, 1))
			return (0);
		list->pp[1] = open(list->arg[i + 1], O_CREAT | O_WRONLY | O_TRUNC,
				S_IRWXU);
	}
	else if (!ft_strcmp(list->arg[i], ">>") && !g_shell.test_contr_c_sig)
	{
		if (list->redirect_out)
			close(list->pp[1]);
		list->redirect_out = 1;
		if (!ft_redirect_error(list, i, 1))
			return (0);
		list->pp[1] = open(list->arg[i + 1], O_CREAT | O_WRONLY + O_APPEND,
				S_IRWXU);
	}
	return (1);
}
