/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmagikar <tmagikar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 13:14:54 by eshakita          #+#    #+#             */
/*   Updated: 2021/08/16 19:59:36 by tmagikar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

void	ft_export_sort(char **my_envp, int count_envp)
{
	char	*tmp_line;
	int		i;
	int		j;
	int		k;

	i = -1;
	while (++i < count_envp)
	{
		j = -1;
		while (++j < count_envp - 1)
		{
			if (ft_strlen(my_envp[j]) > ft_strlen(my_envp[j + 1]))
				k = ft_strlen(my_envp[j]);
			else
				k = ft_strlen(my_envp[j + 1]);
			if (ft_strncmp(my_envp[j], my_envp[j + 1], k) > 0)
			{
				tmp_line = my_envp[j];
				my_envp[j] = my_envp[j + 1];
				my_envp[j + 1] = tmp_line;
			}
		}
	}
}

void	ft_export_print(char *str, int fd)
{
	int	i;

	i = 0;
	ft_putstr_fd("declare -x ", fd);
	while (str[i] && str[i] != '=')
		ft_putchar_fd(str[i++], fd);
	if (str[i] == '=')
	{
		ft_putchar_fd(str[i++], fd);
		ft_putchar_fd('\"', fd);
		ft_putstr_fd(&(str[i]), fd);
		ft_putchar_fd('\"', fd);
	}
}

void	ft_export_print1(char *str, int fd)
{
	if (!g_shell.firts_new_line)
		ft_putchar_fd('\n', fd);
	g_shell.firts_new_line = 0;
	ft_export_print(str, fd);
}

void	ft_export_print2(char *str, int fd)
{
	ft_export_print(str, fd);
	if (!g_shell.test_contr_c_sig)
		ft_putchar_fd('\n', fd);
}

int	ft_export_work1(t_list *list, char ***envp, int *j, int i)
{
	if (list->arg[i][0] == '=')
	{
		ft_putstr3("\nminigoose: export: \'", list->arg[i], \
				"\': not a valid identifier");
		return (-1);
	}
	*j = ft_isarg(*envp, list->arg[i]);
	if (*j != -1)
	{
		free((*envp)[*j]);
		(*envp)[*j] = ft_strdup(list->arg[i]);
	}
	else
		*envp = ft_realloc_more_line(envp, list->arg[i]);
	return (0);
}
