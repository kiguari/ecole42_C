/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_history.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmagikar <tmagikar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 16:33:48 by eshakita          #+#    #+#             */
/*   Updated: 2021/08/16 19:58:31 by tmagikar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

void	ft_history_up(t_init *init, char *line, int fd)
{
	init->new_pos = 1;
	if (init->new_pos_tmp > 0)
	{
		while (init->new_pos < init->new_pos_tmp)
		{
			get_next_line(fd, &init->line_to_pars2);
			free(init->line_to_pars2);
			init->new_pos++;
		}
		get_next_line(fd, &init->line_to_pars2);
	}
	if (init->new_pos_tmp > 0)
		init->new_pos_tmp--;
	ft_strlcpy(line, init->line_to_pars2, ft_strlen(init->line_to_pars2) + 1);
	g_shell.count_len += ft_putstr(init->line_to_pars2);
	if (init->new_pos_tmp > 0)
		free(init->line_to_pars2);
}

void	ft_history_down(t_init *init, char *line, int fd)
{
	init->new_pos = 1;
	if (init->new_pos_tmp <= g_shell.pos_hist)
	{
		while (init->new_pos_tmp <= g_shell.pos_hist && init->new_pos <= \
			init->new_pos_tmp)
		{
			get_next_line(fd, &init->line_to_pars2);
			free(init->line_to_pars2);
			init->new_pos++;
		}
		get_next_line(fd, &init->line_to_pars2);
		free(init->line_to_pars2);
		get_next_line(fd, &init->line_to_pars2);
	}
	if (init->new_pos_tmp < g_shell.pos_hist)
		init->new_pos_tmp++;
	ft_strlcpy(line, init->line_to_pars2, ft_strlen(init->line_to_pars2) + 1);
	g_shell.count_len += ft_putstr(init->line_to_pars2);
	if (init->new_pos_tmp <= g_shell.pos_hist)
		free(init->line_to_pars2);
}

void	ft_history_updown_switch(t_init *init, char *str, char *line_to_pars)
{
	int	fd;

	g_shell.count_len = -1;
	tputs(restore_cursor, 1, ft_putchar);
	tputs(tigetstr("ed"), 1, ft_putchar);
	fd = open(g_shell.name_hist, O_RDONLY);
	if (fd == -1)
	{
		fd = open(g_shell.name_hist, O_CREAT | O_APPEND, S_IRWXU);
		g_shell.pos_hist = 0;
	}
	if (!strcmp(str, "\e[A"))
		ft_history_up(init, line_to_pars, fd);
	else if (!strcmp(str, "\e[B"))
		ft_history_down(init, line_to_pars, fd);
	close(fd);
}

void	ft_write_hist(char *line)
{
	int	fd;

	fd = open(g_shell.name_hist, O_WRONLY + O_APPEND);
	if (fd == -1)
	{
		fd = open(g_shell.name_hist, O_CREAT | O_APPEND, S_IRWXU);
		g_shell.pos_hist = 0;
	}
	ft_putendl_fd(line, fd);
	close(fd);
	g_shell.pos_hist++;
}
