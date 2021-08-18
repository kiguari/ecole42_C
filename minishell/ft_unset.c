/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmagikar <tmagikar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 15:33:09 by tmagikar          #+#    #+#             */
/*   Updated: 2021/08/17 16:16:53 by tmagikar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

int	ft_unset_check_red(t_list *list)
{
	int	i;

	i = 1;
	while (list->arg[i])
	{
		if (!ft_redirect_input(list, i) || !ft_redirect_output(list, i))
			return (-1);
		if (!ft_check_redirect(list, i))
			i++;
		i++;
	}
	return (i);
}

void	ft_unset_realloc(t_list *list, char ***envp, int j)
{
	int	i;

	i = 0;
	while ((*envp)[i])
	{
		if (!ft_memcmp((*envp)[i], list->arg[j],
			ft_strlen_ravno((*envp)[i], list->arg[j])))
		{
			*envp = ft_realloc_envp(*envp, num_size(*envp), i);
			break ;
		}
		i++;
	}
}

int	ft_unset(char ***envp, t_list *list)
{
	int		j;

	j = 1;
	if (ft_unset_check_red(list) == -1)
		return (-1);
	j = 1;
	while (list->arg[j] && !g_shell.test_contr_c_sig)
	{
		ft_unset_realloc(list, envp, j);
		j++;
	}
	if ((list->prev && !list->next) || (!list->next && !list->prev))
		ft_putchar('\n');
	else if (list->type)
		ft_cd_unset_fork(list);
	return (j);
}
