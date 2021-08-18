/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dollar.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmagikar <tmagikar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 18:50:02 by tmagikar          #+#    #+#             */
/*   Updated: 2021/08/12 18:57:40 by tmagikar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

int	ft_strlen_ravno(char *env, char *buf)
{
	int	i;

	i = 0;
	while ((env[i] && env[i] != '=') || buf[i])
		i++;
	return (i);
}

static int	ft_dollar_check_line(char *line, char *buf)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (!ft_issym(line[i]))
		buf[j++] = line[i++];
	buf[j] = '\0';
	return (j);
}

static int	ft_dollar_search_env_ravno(char **envp, char *buf)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (!ft_memcmp(envp[i], buf, ft_strlen_ravno(envp[i], buf)))
			break ;
		i++;
	}
	return (i);
}

int	ft_dollar(char ***envp, char *line)
{
	int		i;
	int		j;
	int		k;
	char	buf[1000];

	if (!ft_dollar_check_line(line, buf))
		return (0);
	k = ft_dollar_search_env_ravno(*envp, buf);
	if (!(*envp)[k])
		return (-1);
	ft_strcpy(buf, line);
	j = 0;
	while ((*envp)[k][j] != '=')
		j++;
	j++;
	i = 0;
	while ((*envp)[k][j])
		line[i++] = (*envp)[k][j++];
	j = 0;
	while (buf[j])
		line[i++] = buf[j++];
	line[i] = '\0';
	return (i);
}

int	ft_check_dollar(char ***envp, char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '$')
			ft_dollar(envp, &(line[i]));
		i++;
	}
	return (0);
}
