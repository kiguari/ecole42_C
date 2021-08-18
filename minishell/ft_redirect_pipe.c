/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirect_pipe.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakita <eshakita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 13:02:42 by eshakita          #+#    #+#             */
/*   Updated: 2021/08/16 13:09:18 by eshakita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

int	ft_red_out(t_list *list, int i)
{
	int	fd;

	fd = 0;
	if (list->arg[i] && !ft_strcmp(list->arg[i], ">"))
	{
		list->redirect_out = 1;
		if (!ft_redirect_error(list, i, 1))
			return (0);
		fd = open(list->arg[i + 1], O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
		ft_free_arg_redirect(list, i);
	}
	else if (list->arg[i] && !ft_strcmp(list->arg[i], ">>"))
	{
		list->redirect_out = 1;
		if (!ft_redirect_error(list, i, 1))
			return (0);
		fd = open(list->arg[i + 1], O_CREAT | O_WRONLY | O_APPEND, S_IRWXU);
		ft_free_arg_redirect(list, i);
	}
	else
		return (-2);
	return (fd);
}

int	ft_check_red_in(char *arg)
{
	if (arg && (!ft_strcmp(arg, "<") || !ft_strcmp(arg, "<<")))
		return (0);
	return (1);
}

int	ft_check_red_out(char *arg)
{
	if (arg && (!ft_strcmp(arg, ">") || !ft_strcmp(arg, ">>")))
		return (0);
	return (1);
}

int	ft_fork_zero(t_list *list)
{
	if (pipe(list->pp) < 0)
		exit (1);
	list->pid = fork();
	if (list->pid < 0)
		exit (1);
	else if (list->pid == 0)
	{
		ft_fork_bildin(list);
		exit (0);
	}
	else
		ft_fork_bildin2(list);
	return (1);
}
