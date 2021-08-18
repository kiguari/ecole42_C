/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmagikar <tmagikar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 11:16:21 by eshakita          #+#    #+#             */
/*   Updated: 2021/08/17 16:49:42 by tmagikar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

void	ft_first_cd_utils(t_bild_var *cd, t_list *list, char ***envp)
{
	list->norma_besit = -666;
	cd->tmp = (*envp)[cd->i];
	(*envp)[cd->i] = ft_strjoin("PWD=", cd->tmp2);
	cd->i = ft_search_var(*envp, "OLDPWD");
	if (!(*envp)[cd->i])
	{
		cd->tmp2 = ft_strjoin("OLDPWD=", cd->tmp);
		*envp = ft_realloc_more_line(envp, cd->tmp2);
	}
	else
	{
		cd->tmp2 = (*envp)[cd->i];
		(*envp)[cd->i] = ft_strjoin("OLDPWD=", cd->tmp + 4);
	}
	free(cd->tmp2);
	free(cd->tmp);
	cd->i = ft_search_var(*envp, "PWD");
	if (!g_shell.test_contr_c_sig)
		chdir((*envp)[cd->i] + 4);
	getcwd(cd->buf, 500);
	cd->tmp = (*envp)[cd->i];
	(*envp)[cd->i] = ft_strjoin("PWD=", cd->buf);
	free(cd->tmp);
}

void	ft_second_cd_utils_patt_two(t_bild_var *cd, t_list *list, char ***envp)
{
	free((*envp)[cd->j]);
	(*envp)[cd->j] = ft_strjoin("PWD=", cd->tmp2);
	printf("\ncd: %s: No such file or directory\n", list->arg[cd->i]);
	free(cd->tmp2);
}

int	ft_second_cd_utils(t_bild_var *cd, t_list *list, char ***envp)
{
	if (chdir((*envp)[cd->j] + 4))
	{
		ft_second_cd_utils_patt_two(cd, list, envp);
		return (1);
	}
	free((*envp)[cd->j]);
	getcwd(cd->buf, 500);
	(*envp)[cd->j] = ft_strjoin("PWD=", cd->buf);
	cd->i = 0;
	cd->i = ft_search_var(*envp, "OLDPWD");
	if (cd->i != -1)
	{
		free((*envp)[cd->i]);
		(*envp)[cd->i] = ft_strjoin("OLDPWD=", cd->tmp2);
	}
	else
	{
		cd->tmp = ft_strjoin("OLDPWD=", cd->tmp2);
		*envp = ft_realloc_more_line(envp, cd->tmp);
		free(cd->tmp);
	}
	free(cd->tmp2);
	return (0);
}

void	ft_cd_unset_fork(t_list *list)
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
}
