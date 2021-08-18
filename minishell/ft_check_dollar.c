/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_dollar.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmagikar <tmagikar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 16:29:03 by tmagikar          #+#    #+#             */
/*   Updated: 2021/08/16 19:00:45 by tmagikar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

void	ft_gg_norma_init_dollar(int *a, int *b, int *c)
{
	*a = 0;
	*b = 0;
	*c = 0;
}

int	ft_search_dollar_1(char **envp, char *arg, char *buf)
{
	int	i;
	int	j;
	int	ret;

	ft_gg_norma_init_dollar(&i, &j, &ret);
	while (arg[i])
	{
		if (arg[i] == '\'')
			ret = ft_one_comma_cmp(arg, buf, &i, &j);
		else if (arg[i] == '\"')
		{
			j += ft_two_comma_cmp(envp, arg, &(buf[j]), &i);
			ret = 1;
		}
		else if (arg[i] == '$')
		{
			j += ft_dollar_cmp(envp, arg, &(buf[j]), &i);
			if (j < 0)
				break ;
		}
		else
			buf[j++] = arg[i++];
	}
	buf[j] = 0;
	return (ret);
}

void	ft_donald_baks(char **envp, t_list *list)
{
	int		i;
	int		j;
	char	buf[1000];

	i = 0;
	j = 0;
	ft_fullzero(buf);
	while (list->arg[i])
	{
		if (!ft_search_dollar_1(envp, list->arg[i], buf))
		{
			if (buf[0] == '\0')
			{
				list->arg = ft_del_arg_list(list, i);
				continue ;
			}
		}
		free(list->arg[i]);
		list->arg[i] = ft_strdup(buf);
		i++;
	}
}
