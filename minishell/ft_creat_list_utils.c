/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_creat_list_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmagikar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 19:11:58 by tmagikar          #+#    #+#             */
/*   Updated: 2021/08/16 19:11:59 by tmagikar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

int	ft_one_line_pipe_1(char *line, char *buf, int j)
{
	int	i;

	i = 0;
	while (line[j])
	{
		if (line[j] == '|')
		{
			j++;
			break ;
		}
		else if (line[j] == '\'')
		{
			i += ft_comma_buf_cmp(line, &(buf[i]), &j, '\'');
			buf[i++] = line[j++];
		}
		else if (line[j] == '\"')
		{
			i += ft_comma_buf_cmp(line, &(buf[i]), &j, '\"');
			buf[i++] = line[j++];
		}
		else
			buf[i++] = line[j++];
	}
	buf[i] = '\0';
	return (j);
}

int	ft_isredirect(char c)
{
	if (c == '<' || c == '>')
		return (0);
	return (1);
}

int	ft_symb_redir_cmp(char *str, char *buf, int *j, char symb)
{
	int	i;

	i = 0;
	buf[i++] = str[(*j)++];
	if (str[*j] == symb)
		buf[i++] = str[(*j)++];
	return (i);
}

int	ft_one_arg_1(char *str, char *buf, int j, int i)
{
	j = skip_space(str, j);
	if (!ft_isredirect(str[j]))
		i += ft_symb_redir_cmp(str, &(buf[i]), &j, str[j]);
	else
	{
		while (str[j] && str[j] != ' ')
		{
			if (str[j] == '\'')
			{
				i += ft_comma_buf_cmp(str, &(buf[i]), &j, '\'');
				buf[i++] = str[j++];
			}
			else if (str[j] == '\"')
			{
				i += ft_comma_buf_cmp(str, &(buf[i]), &j, '\"');
				buf[i++] = str[j++];
			}
			else
				buf[i++] = str[j++];
		}
	}
	buf[i] = '\0';
	return (j);
}

/*
** строка бьется на меньшии по пробелам
*/
char	**ft_split_arg_1(char *str)
{
	int		i;
	int		j;
	int		num;
	char	buf[1000];
	char	**arg;

	ft_num_arg(str, &num);
	arg = (char **)malloc(sizeof(char *) * (num + 1));
	arg[num] = NULL;
	i = 0;
	j = 0;
	while (i < num)
	{
		j = ft_one_arg_1(str, buf, j, 0);
		arg[i++] = ft_strdup(buf);
	}
	return (arg);
}
