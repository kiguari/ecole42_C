/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmagikar <tmagikar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 19:14:45 by tmagikar          #+#    #+#             */
/*   Updated: 2021/08/12 19:16:33 by tmagikar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

static int	ft_isredirect(char c)
{
	if (c == '>' || c == '<')
		return (0);
	return (1);
}

static int	ft_skip_red(char *line, int i)
{
	if (line[i] == '<')
	{
		i++;
		if (line[i] == '<')
			i++;
	}
	else if (line[i] == '>')
	{
		i++;
		if (line[i] == '>')
			i++;
	}
	return (i);
}

static int	ft_num_arg_1(char *line, int i)
{
	while (line[i] && line[i] != ' ' && line[i] != '|' && line[i] != '<' \
			&& line[i] != '>')
	{
		if (line[i] == '\'')
		{
			i++;
			while (line[i] != '\'')
				i++;
		}
		else if (line[i] == '\"')
		{
			i++;
			while (line[i] != '\"')
				i++;
		}
		i++;
	}
	return (i);
}

int	ft_num_arg(char *line, int *count)
{
	int		i;

	i = 0;
	*count = 0;
	while (line[i] == ' ')
		i++;
	while (line[i] && line[i] != '|')
	{
		*count += 1;
		if (!ft_isredirect(line[i]))
			i = ft_skip_red(line, i);
		else
			i = ft_num_arg_1(line, i);
		while (line[i] == ' ')
			i++;
	}
	return (i);
}
