/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirect_pipe_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmagikar <tmagikar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 13:09:20 by eshakita          #+#    #+#             */
/*   Updated: 2021/08/16 19:56:36 by tmagikar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

static int	ft_input_error(t_list *list, int i, int fd)
{
	if (fd == -1)
	{
		if (!ft_stat_file(list->arg[i + 1]))
		{
			g_shell.code_return = 1;
			return (0);
		}
	}
	return (1);
}

static int	ft_red_in_utils(t_list *list, int *fd, int i)
{
	list->redirect_in = 1;
	if (!ft_redirect_error(list, i, 0))
		return (-3);
	*fd = open(list->arg[i + 1], O_RDONLY);
	if (!ft_input_error(list, i, *fd))
		return (-3);
	ft_free_arg_redirect(list, i);
	return (0);
}

int	ft_red_in(t_list *list, int i)
{
	int	fd;

	fd = 0;
	if (list->arg[i] && !ft_strcmp(list->arg[i], "<"))
	{
		if (ft_red_in_utils(list, &fd, i) == -3)
			return (-3);
	}
	else if (list->arg[i] && !ft_strcmp(list->arg[i], "<<"))
	{
		list->redirect_in = 1;
		if (!ft_redirect_error(list, i, 0))
			return (0);
		fd = ft_redirect_in(list, list->arg[i + 1]);
		close(fd);
		ft_free_arg_redirect(list, i);
		fd = open("tmp_text_redirect.ggwp", O_RDONLY);
	}
	else
		return (-2);
	return (fd);
}
