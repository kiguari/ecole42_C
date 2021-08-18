/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirect_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmagikar <tmagikar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 12:46:18 by eshakita          #+#    #+#             */
/*   Updated: 2021/08/16 19:56:23 by tmagikar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

void	ft_free_arg_redirect(t_list *list, int i)
{
	int		j;
	int		k;
	char	**new;

	j = 1;
	while (list->arg[j])
		j++;
	new = (char **)malloc(sizeof(char *) * (j - 1));
	j = 0;
	k = 0;
	while (list->arg[j])
	{
		if (j == i)
			j += 2;
		else
			new[k++] = ft_strdup(list->arg[j++]);
	}
	new[k] = NULL;
	j = 0;
	ft_free_dou_array(list->arg);
	list->arg = new;
}

int	ft_open_zero_redirect(t_list *list)
{
	int	i;

	i = 0;
	while (list->arg[i])
	{
		if (!ft_redirect_input(list, i) || !ft_redirect_output(list, i))
		{
			if (list->arg[i + 1])
				ft_putstr3("\nbash: syntax error near unexpected token \'", \
					list->arg[i + 1], "\'\n");
			else
				ft_putstr
				("\nbash: syntax error near unexpected token \'newline\'\n");
			g_shell.code_return = 258;
			return (-1);
		}
		i++;
	}
	return (0);
}

static int	ft_redirect_sort_check_red(t_list *list)
{
	int	i;

	i = 0;
	while (list->arg[i])
	{
		if (!ft_check_redirect(list, i) && !ft_syntax_red_err(list, i))
			break ;
		else if (!ft_check_redirect(list, i))
			i += 2;
		else
			break ;
	}
	return (i);
}

static char	**ft_redirect_sort_1(char *tmp, int *i, int *j)
{
	char	**new;

	new = (char **)malloc(sizeof(char *) * (*j + 1));
	new[0] = ft_strdup(tmp);
	*i = 0;
	*j = 1;
	return (new);
}

void	ft_redirect_sort(t_list *list)
{
	int		i;
	int		j;
	char	*tmp;
	char	**new;

	i = ft_redirect_sort_check_red(list);
	if (i == 0 || !list->arg[i])
		return ;
	tmp = list->arg[i];
	j = 0;
	while (list->arg[j])
		j++;
	new = ft_redirect_sort_1(tmp, &i, &j);
	while (list->arg[i])
	{
		if (list->arg[i] != tmp)
			new[j++] = ft_strdup(list->arg[i++]);
		else
			i++;
	}
	new[j] = NULL;
	ft_free_dou_array(list->arg);
	list->arg = new;
}
