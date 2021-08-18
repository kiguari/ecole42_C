/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_dollar_utils2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmagikar <tmagikar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 19:05:58 by tmagikar          #+#    #+#             */
/*   Updated: 2021/08/17 16:44:38 by tmagikar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

/*
** $ в кавычках: "$var"  "$мусор"
*/
int	ft_two_comma_cmp_1(char **envp, char *arg, char *buf, int *i)
{
	int		j;
	char	tmp[500];

	j = 0;
	while (arg[*i] != '\"' && arg[*i] != '\'' && arg[*i] != '$')
		tmp[j++] = arg[(*i)++];
	tmp[j] = 0;
	j = ft_search_var(envp, tmp);
	if (j != -1)
		ft_envpcpy(buf, envp[j]);
	j = ft_strlen(buf);
	(*i)--;
	return (j);
}

/*
** $ в кавычках: "$"  "$?"  "$var"  "$мусор"
*/
int	ft_two_comma_cmp(char **envp, char *arg, char *buf, int *i)
{
	int	j;

	j = 0;
	while (arg[++(*i)] != '\"')
	{
		if (arg[*i] == '$')
		{
			if (arg[++(*i)] == '?')
				ft_dollar_exit_status_cmp(buf, &j);
			else if (arg[*i] == '\"' || arg[*i] == ' ')
			{
				buf[j++] = '$';
				if (arg[*i] == ' ')
					(*i)--;
				else
					break ;
			}
			else
				j += ft_two_comma_cmp_1(envp, arg, &(buf[j]), i);
		}
		else
			buf[j++] = arg[*i];
	}
	(*i)++;
	return (j);
}

/*
** $var $мусор
*/
int	ft_dollar_cmp_1(char **envp, char *arg, char *buf, int *i)
{
	int		j;
	char	tmp[500];

	j = 0;
	while (arg[*i] != 0 && arg[*i] != '\"' && arg[*i] != '\'' && arg[*i] != '$')
		tmp[j++] = arg[(*i)++];
	tmp[j] = 0;
	j = ft_search_var(envp, tmp);
	if (j != -1)
		ft_envpcpy(buf, envp[j]);
	j = ft_strlen(buf);
	buf[j] = 0;
	return (j);
}

/*
** на случай: $  $?  $var $мусор
*/
int	ft_dollar_cmp(char **envp, char *arg, char *buf, int *i)
{
	int	j;

	j = 0;
	if (arg[++(*i)] == '?')
	{
		ft_dollar_exit_status_cmp(buf, &j);
		(*i)++;
	}
	else if (!arg[*i])
	{
		buf[j++] = '$';
		return (-6000);
	}
	else
		j += ft_dollar_cmp_1(envp, arg, &(buf[j]), i);
	return (j);
}
