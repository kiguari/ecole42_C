/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmagikar <tmagikar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 18:24:13 by tmagikar          #+#    #+#             */
/*   Updated: 2021/08/17 16:39:12 by tmagikar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

int	ft_export_work(char ***envp, t_list *list)
{
	int	i;
	int	j;

	i = 1;
	j = -2;
	while (list->arg[i])
	{
		if (!ft_redirect_input(list, i) || !ft_redirect_output(list, i))
			return (-3);
		if (!ft_check_redirect(list, i))
			i++;
		else if (!list->type)
			if (ft_export_work1(list, envp, &j, i))
				break ;
		i++;
	}
	return (j);
}

int	ft_export_init(t_list *list, char ***envp, char ***tmp, int *j)
{
	int	i;

	*tmp = ft_my_envp(*envp);
	i = num_size(*tmp);
	ft_export_sort(*tmp, i);
	list->pp[1] = 1;
	list->tmp_i = 0;
	list->redirect_out = 0;
	*j = ft_export_work(envp, list);
	if (*j == -3)
		return (-1);
	return (0);
}

void	ft_export_fork(t_list *list, char **tmp)
{
	int	i;

	if (pipe(list->pp) < 0)
		exit (1);
	list->pid = fork();
	if (list->pid < 0)
		exit (1);
	else if (list->pid == 0)
	{
		ft_fork_bildin(list);
		if (!list->tmp_i && !list->redirect_out)
		{
			i = 0;
			while (tmp[i])
				ft_export_print2(tmp[i++], list->pp[1]);
		}
		exit (0);
	}
	else
		ft_fork_bildin2(list);
}

int	ft_export(char ***envp, t_list *list)
{
	int		i;
	int		j;
	char	**tmp;

	if (ft_export_init(list, envp, &tmp, &j))
		return (-1);
	i = 0;
	if (list->redirect_out && list->pp[1] != -1 && j == -2)
	{
		i = 0;
		while (tmp[i] && !g_shell.test_contr_c_sig)
			ft_export_print2(tmp[i++], list->pp[1]);
	}
	if (list->type && list->next && j == -2)
		ft_export_fork(list, tmp);
	else if (!list->redirect_out && !list->type && !list->tmp_i && j == -2)
	{
		i = 0;
		while (tmp[i] && !g_shell.test_contr_c_sig)
			ft_export_print1(tmp[i++], list->pp[1]);
	}
	ft_free_dou_array(tmp);
	return (0);
}
