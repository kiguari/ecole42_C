/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmagikar <tmagikar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 11:14:36 by eshakita          #+#    #+#             */
/*   Updated: 2021/08/17 15:37:27 by tmagikar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

int	ft_check_redir_cd(t_bild_var *cd, t_list *list)
{
	cd->i = 1;
	while (list->arg[cd->i])
	{
		if (!ft_redirect_input(list, cd->i) || !ft_redirect_output(list, cd->i))
			return (-1);
		cd->i++;
	}
	return (0);
}

void	ft_some_cd_while(t_bild_var *cd, t_list *list)
{
	cd->i = 1;
	while (list->arg[cd->i])
	{
		if (ft_strcmp(list->arg[cd->i], ">"))
			if (ft_strcmp(list->arg[cd->i], ">>"))
				if (ft_strcmp(list->arg[cd->i], "<"))
					if (ft_strcmp(list->arg[cd->i], "<<"))
						break ;
		cd->i += 2;
	}
}

int	ft_only_cd_and_no_pipe(t_bild_var *cd, t_list *list, char ***envp)
{
	cd->i = 0;
	cd->i = ft_search_var(*envp, "HOME");
	if (cd->i != -1)
		cd->tmp2 = (*envp)[cd->i] + 5;
	else
	{
		ft_putstr("\nminig: cd: HOME not set");
		return (1);
	}
	cd->i = 0;
	cd->i = ft_search_var(*envp, "PWD");
	if (cd->i == -1)
	{
		*envp = ft_realloc_more_line(envp, "PWD=");
		cd->i = ft_search_var(*envp, "PWD");
	}
	ft_first_cd_utils(cd, list, envp);
	return (0);
}

int	ft_cd_pipe(t_bild_var *cd, t_list *list, char ***envp)
{
	cd->j = 0;
	cd->j = ft_search_var(*envp, "PWD");
	cd->tmp2 = ft_strdup((*envp)[cd->j] + 4);
	if (list->arg[cd->i][0] == '/')
	{
		free((*envp)[cd->j]);
		(*envp)[cd->j] = ft_strjoin("PWD=", list->arg[cd->i]);
	}
	else
	{
		cd->tmp = (*envp)[cd->j];
		(*envp)[cd->j] = ft_strjoin((*envp)[cd->j], "/");
		free(cd->tmp);
		cd->tmp = (*envp)[cd->j];
		(*envp)[cd->j] = ft_strjoin((*envp)[cd->j], list->arg[cd->i]);
		free(cd->tmp);
	}
	if (ft_second_cd_utils(cd, list, envp) == 1)
		return (1);
	return (0);
}

int	ft_cd(char ***envp, t_list *list)
{
	t_bild_var	cd;

	if (ft_check_redir_cd(&cd, list) == -1)
		return (-1);
	ft_some_cd_while(&cd, list);
	if (!list->arg[cd.i] && !list->type)
	{
		if (ft_only_cd_and_no_pipe(&cd, list, envp) == 1)
			return (1);
	}
	else if (!list->type)
	{
		if (ft_cd_pipe(&cd, list, envp) == 1)
			return (1);
	}
	else if (list->type)
		ft_cd_unset_fork(list);
	return (0);
}
