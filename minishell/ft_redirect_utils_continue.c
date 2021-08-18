/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirect_utils_continue.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmagikar <tmagikar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 12:48:36 by eshakita          #+#    #+#             */
/*   Updated: 2021/08/17 16:29:02 by tmagikar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

static int	ft_input_error(t_list *list, int i)
{
	if (list->pp[0] == -1)
	{
		if (!ft_stat_file(list->arg[i + 1]))
		{
			g_shell.code_return = 1;
			return (0);
		}
	}
	return (1);
}

int	ft_redirect_input(t_list *list, int i)
{
	if (!ft_strcmp(list->arg[i], "<"))
	{
		if (list->redirect_in)
			close(list->pp[0]);
		list->redirect_in = 1;
		if (!ft_redirect_error(list, i, 0))
			return (0);
		list->pp[0] = open(list->arg[i + 1], O_RDONLY);
		if (!ft_input_error(list, i))
			return (0);
		close(list->pp[0]);
	}
	else if (!ft_strcmp(list->arg[i], "<<"))
	{
		if (list->redirect_in)
			close(list->pp[0]);
		list->redirect_in = 1;
		if (!ft_redirect_error(list, i, 0))
			return (0);
		list->pp[0] = ft_redirect_in(list, list->arg[i + 1]);
		close (list->pp[0]);
	}
	return (1);
}

int	ft_system_redirect(t_list *list, int *fdre0, int *fdre1)
{
	int	i;

	i = 1;
	while (list->arg[i])
	{
		if (!ft_check_red_in(list->arg[i]))
		{
			*fdre0 = ft_red_in(list, i);
			if (*fdre0 == -1 && !list->next)
				return (-1);
			if (*fdre0 == -3)
				break ;
		}
		else if (!ft_check_red_out(list->arg[i]))
		{
			*fdre1 = ft_red_out(list, i);
			if (*fdre1 == 0)
				return (-1);
		}
		else
			i++;
	}
	return (0);
}

int	ft_open_zero_redirect1(t_list *list)
{
	int	code;

	code = ft_open_zero_redirect(list);
	ft_cd_unset_fork(list);
	return (code);
}

int	ft_zero_fork(t_list *list)
{
	g_shell.code_return = 0;
	ft_cd_unset_fork(list);
	return (0);
}
