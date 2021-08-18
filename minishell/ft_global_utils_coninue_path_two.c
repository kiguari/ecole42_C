/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_global_utils_coninue_path_two.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmagikar <tmagikar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 17:30:47 by eshakita          #+#    #+#             */
/*   Updated: 2021/08/17 16:34:20 by tmagikar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

void	ft_history_init(char **tmp)
{
	int		fd_hist;
	char	path[200];

	getcwd(path, 200);
	*tmp = ft_strjoin(path, "/.minishell_history");
	ft_strcpy(g_shell.name_hist, *tmp);
	free(*tmp);
	fd_hist = open(g_shell.name_hist, O_CREAT | O_APPEND, S_IRWXU);
	close(fd_hist);
	fd_hist = open(g_shell.name_hist, O_RDONLY);
	while (get_next_line(fd_hist, tmp) > 0)
	{
		g_shell.pos_hist++;
		free(*tmp);
	}
	free(*tmp);
	close(fd_hist);
}

int	ft_isarg(char **arg, char *line)
{
	int	i;
	int	num;

	num = 0;
	while (arg[num])
	{
		i = 0;
		while (arg[num][i] && line[i] && arg[num][i] == line[i])
		{
			if ((arg[num][i + 1] == '=' || !arg[num][i + 1])
					&& (line[i + 1] == '=' || !line[i + 1]))
				return (num);
			i++;
		}
		num++;
	}
	return (-1);
}

int	ft_search_var(char **envp, char *var)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(var);
	while (envp[i])
	{
		if (!ft_memcmp(envp[i], var, len) && envp[i][len] == '=')
			return (i);
		i++;
	}
	return (-1);
}

void	ft_shlvl(char **envp)
{
	int		i;
	int		j;
	int		num;
	char	*tmp;

	num = 0;
	j = 6;
	i = ft_search_var(envp, "SHLVL");
	while (envp[i][j])
	{
		num = num * 10 + envp[i][j] - '0';
		j++;
	}
	num++;
	tmp = ft_itoa(num);
	free(envp[i]);
	envp[i] = ft_strjoin("SHLVL=", tmp);
	free(tmp);
}

int	ft_search_slash(char *arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		if (arg[i] == '/')
			break ;
		i++;
	}
	if (!arg[i])
		return (1);
	return (0);
}
