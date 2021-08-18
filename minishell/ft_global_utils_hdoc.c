/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_global_utils_hdoc.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmagikar <tmagikar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 17:25:51 by eshakita          #+#    #+#             */
/*   Updated: 2021/08/17 16:38:40 by tmagikar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

void	ft_hdoc_utils(t_hdoc *hdoc, int code)
{
	if (code == 1)
	{
		hdoc->i = 1;
		g_shell.firts_new_line = 1;
		g_shell.flag_redir = 1;
		hdoc->pid = fork();
	}
	else if (code == 2)
	{
		hdoc->fd_her = open("tmp_text_redirect.ggwp",
				O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
		signal(SIGINT, for_signal_her);
		signal(SIGQUIT, for_signal_her);
		ft_putstr_fd("\n> ", 1);
	}
	else if (code == 3)
	{
		if (g_shell.test_contr_c_sig)
			hdoc->fd_her = -1;
		else
			hdoc->fd_her = open("tmp_text_redirect.ggwp", O_RDONLY);
		g_shell.ret_code = 1;
	}
}

void	ft_hdoc_print_or_exit(t_hdoc *hdoc, int code)
{
	if (code == 1)
	{
		close(hdoc->fd_her);
		exit(1);
	}
	else if (code == 2)
	{
		ft_putstr_fd(hdoc->buf, hdoc->fd_her);
		if (hdoc->i > 0)
			ft_putstr_fd("> ", 1);
	}
}

int	ft_redirect_in(t_list *list, char *stop)
{
	t_hdoc	hdoc;

	list->norma_besit = -999;
	ft_hdoc_utils(&hdoc, 1);
	if (hdoc.pid < 0)
		exit(0);
	else if (hdoc.pid == 0)
	{
		ft_hdoc_utils(&hdoc, 2);
		while (hdoc.i)
		{
			hdoc.i = read(0, hdoc.buf, 100);
			hdoc.buf[hdoc.i] = '\0';
			if (!strcmp(hdoc.buf, "\4") || g_shell.test_contr_c_sig
				|| (!ft_memcmp(hdoc.buf, stop, ft_strlen(stop))
					&& hdoc.i - 1 == (int)ft_strlen(stop)))
				ft_hdoc_print_or_exit(&hdoc, 1);
			ft_hdoc_print_or_exit(&hdoc, 2);
		}
		exit(1);
	}
	else
		waitpid(hdoc.pid, &hdoc.status, 0);
	ft_hdoc_utils(&hdoc, 3);
	return (hdoc.fd_her);
}
