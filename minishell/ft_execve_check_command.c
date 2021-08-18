/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execve_check_command.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmagikar <tmagikar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 18:31:14 by tmagikar          #+#    #+#             */
/*   Updated: 2021/08/17 16:42:13 by tmagikar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

int	ft_sys_check_command_1(t_list *list, char **path, struct stat *bufst)
{
	char		buf[1000];

	if (!stat(list->arg[0], bufst))
	{
		*path = ft_strdup(list->arg[0]);
		getcwd(buf, 500);
		if (!chdir(*path))
			return (ft_sys_check_command_2_1(list, buf, path));
	}
	else
	{
		if (ft_sys_pipe(list))
			return (-1);
		if (!list->prev)
			ft_putchar('\n');
		ft_putstr3("minigoose: ", list->arg[0], ": No such file or directory\n");
		g_shell.code_return = 127;
		return (1);
	}
	return (0);
}

int	ft_sys_check_command_2(t_list *list, char **path)
{
	char		buf[1000];
	char		*tmp;
	struct stat	bufst[1111];

	getcwd(buf, 500);
	tmp = ft_strjoin(buf, "/");
	*path = ft_strjoin(tmp, list->arg[0]);
	free(tmp);
	if (stat(*path, bufst))
	{
		free(*path);
		if (ft_sys_pipe(list))
			return (-1);
		if (!list->prev)
			ft_putchar('\n');
		ft_putstr3("minigoose: ", list->arg[0], ": No such file or directory\n");
		g_shell.code_return = 127;
		return (1);
	}
	getcwd(buf, 500);
	if (!chdir(*path))
		return (ft_sys_check_command_2_1(list, buf, path));
	return (0);
}

int	ft_sys_check_command_3_1(t_list *list, char **tmp_path)
{
	int			i;
	char		*tmp;
	struct stat	bufst[1111];

	i = 0;
	while (tmp_path[i])
	{
		tmp = tmp_path[i];
		tmp_path[i] = ft_strjoin(tmp_path[i], "/");
		free(tmp);
		tmp = tmp_path[i];
		tmp_path[i] = ft_strjoin(tmp_path[i], list->arg[0]);
		free(tmp);
		if (!stat(tmp_path[i], bufst))
			break ;
		i++;
	}
	return (i);
}

int	ft_sys_check_command_3(t_list *list, char **envp, char **path, int i)
{
	char		**tmp_path;

	tmp_path = ft_split(envp[i] + 5, ':');
	i = ft_sys_check_command_3_1(list, tmp_path);
	if (!tmp_path[i])
	{
		g_shell.code_return = 127;
		if (ft_sys_pipe(list))
			return (-1);
		if (!list->prev)
			ft_putchar('\n');
		ft_putstr3("minigoose: ", list->arg[0], ": command not found\n");
		ft_free_dou_array(tmp_path);
		return (1);
	}
	else
		*path = ft_strdup(tmp_path[i]);
	ft_free_dou_array(tmp_path);
	return (0);
}

int	ft_sys_check_command(t_list *list, char **envp, char **path, \
						struct stat *bufst)
{
	int	i;
	int	flag_unset_path;

	i = ft_search_var(envp, "PATH");
	if (i != -1)
		flag_unset_path = 1;
	if (list->arg[0][0] == '/' || i == -1)
		return (ft_sys_check_command_1(list, path, bufst));
	else if (!ft_search_slash(list->arg[0]))
		return (ft_sys_check_command_2(list, path));
	else if (flag_unset_path == 1)
		return (ft_sys_check_command_3(list, envp, path, i));
	return (0);
}
