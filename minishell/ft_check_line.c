/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmagikar <tmagikar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 18:23:03 by tmagikar          #+#    #+#             */
/*   Updated: 2021/08/16 19:18:32 by tmagikar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

/*
** ну тут всё ясно понятно
*/
int	ft_check_valid_comma1(char *line, char comma, int *i)
{
	(*i)++;
	while (line[*i] != comma)
	{
		if (!line[*i])
		{
			ft_putstr("\nNo valid str\n");
			return (-1);
		}
		(*i)++;
	}
	return (0);
}

int	ft_check_valid_comma(char *line, int *i)
{
	if (line[*i] == '\'')
	{
		if (ft_check_valid_comma1(line, '\'', i))
			return (-1);
	}
	else if (line[*i] == '\"')
	{
		if (ft_check_valid_comma1(line, '\"', i))
			return (-1);
	}
	return (0);
}

int	ft_check_valid_pipe(char *line, int *i, int error)
{
	if (*i == error)
	{
		ft_putstr("\ngoose: syntax error near unexpected token `|'\n");
		return (-1);
	}
	(*i)++;
	while (line[*i] == ' ')
		(*i)++;
	if (!line[*i] || line[*i] == '|' || line[0] == '|')
	{
		ft_putstr("\ngoose: syntax error near unexpected token `|'\n");
		return (-1);
	}
	return (0);
}

/*
** чекает кол-во пайпов и валидность их положений
*/
int	ft_num_pipe(char *line, int i, int count)
{
	int		space_if_pipe_first_on_line;

	space_if_pipe_first_on_line = 0;
	while (line[space_if_pipe_first_on_line] == ' ')
		space_if_pipe_first_on_line++;
	while (line[i])
	{
		if (!ft_iscomma(line[i]))
		{
			if (ft_check_valid_comma(line, &i))
				return (-1);
		}
		else if (line[i] == '|')
		{
			if (ft_check_valid_pipe(line, &i, space_if_pipe_first_on_line))
				return (-1);
			count++;
			continue ;
		}
		i++;
	}
	return (count);
}

char	**ft_split_line(char ***envp, char *line)
{
	int		i;
	int		j;
	char	buf[1000];
	char	**split_line;

	i = ft_num_pipe(line, 0, 0) + 1;
	if (!i)
		return (NULL);
	split_line = (char **)malloc(sizeof(char *) * (i + 1));
	split_line[i] = NULL;
	i = 0;
	j = 0;
	while (line[i])
	{
		i += ft_check_arg_zero(envp, &(line[i]), buf);
		split_line[j++] = ft_strdup(buf);
	}
	return (split_line);
}
