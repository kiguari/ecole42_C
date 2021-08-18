/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmagikar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 19:06:14 by tmagikar          #+#    #+#             */
/*   Updated: 2021/08/16 19:06:16 by tmagikar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

int	ft_iscomma(char c)
{
	if (c == '\'' || c == '\"')
		return (0);
	return (1);
}

int	ft_comma_buf_cmp(char *line, char *buf, int *i, char comma)
{
	int	j;

	j = 0;
	buf[j++] = line[(*i)++];
	while (line[*i] != comma)
		buf[j++] = line[(*i)++];
	return (j);
}

void	ft_check_arg_zero_comma(char *line, char *buf, int *i, int *j)
{
	if (line[*i] == '\'')
		*j += ft_comma_buf_cmp(line, &(buf[*j]), i, '\'');
	else if (line[*i] == '\"')
		*j += ft_comma_buf_cmp(line, &(buf[*j]), i, '\"');
}

void	ft_check_arg_zero1(char *line, char *buf, int *i, int *j)
{
	if (line[*i] == ' ')
	{
		buf[(*j)++] = ' ';
		*i = skip_space(line, *i);
	}
	else
		buf[(*j)++] = line[(*i)++];
}

void	ft_check_arg_zero2(char ***envp, char *line, int *i)
{
	if (ft_dollar(envp, &(line[*i])) == -1)
		while (!ft_isspec_sym(line[*i]))
			(*i)++;
}
