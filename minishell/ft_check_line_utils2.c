/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_line_utils2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmagikar <tmagikar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 19:06:22 by tmagikar          #+#    #+#             */
/*   Updated: 2021/08/17 16:42:35 by tmagikar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

int	ft_check_arg_zero(char ***envp, char *line, char *buf)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (line[i])
	{
		if (line[i] == '|')
		{
			i++;
			break ;
		}
		if (line[i] == '$' && !ft_isspec_sym(line[i + 1]))
			ft_check_arg_zero2(envp, line, &i);
		else if (!ft_iscomma(line[i]))
			ft_check_arg_zero_comma(line, buf, &i, &j);
		else
			ft_check_arg_zero1(line, buf, &i, &j);
	}
	buf[j] = '\0';
	return (i);
}
