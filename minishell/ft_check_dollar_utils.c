/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_dollar_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmagikar <tmagikar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 19:05:48 by tmagikar          #+#    #+#             */
/*   Updated: 2021/08/17 16:44:11 by tmagikar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

/*
** копирует содержимое переменной окружения в буфер
*/
void	ft_envpcpy(char *buf, char *en)
{
	int	i;

	i = 0;
	while (en[i] != '=')
		i++;
	ft_strcpy(buf, &(en[i + 1]));
}

int	ft_cpy_code_ret(char *buf, t_shell *shell)
{
	int		i;
	char	*tmp;

	tmp = ft_itoa(shell->code_return);
	i = ft_strlen(tmp);
	ft_strcpy(buf, tmp);
	free(tmp);
	return (i);
}

/*
** удаляет 1 аргумент в list->arg например:
** ls $мусор (NULL) превращает в ls (NULL)
*/
char	**ft_del_arg_list(t_list *list, int del)
{
	int		i;
	int		j;
	char	**new_arg;

	i = 0;
	while (list->arg[i])
		i++;
	new_arg = (char **)malloc(sizeof(char *) * i);
	new_arg[i - 1] = NULL;
	i = 0;
	j = 0;
	while (list->arg[i])
	{
		if (i == del)
		{
			i++;
			continue ;
		}
		new_arg[j++] = ft_strdup(list->arg[i++]);
	}
	i = 0;
	ft_free_dou_array(list->arg);
	return (new_arg);
}

/*
** стр в кавычках переписывает без кавычек
*/
int	ft_one_comma_cmp(char *arg, char *buf, int *i, int *j)
{
	while (arg[++(*i)] != '\'')
		buf[(*j)++] = arg[*i];
	(*i)++;
	return (1);
}

/*
** $? в кавычках:   "$?"  
*/
void	ft_dollar_exit_status_cmp(char *buf, int *j)
{
	int		k;
	char	*tmp;

	k = 0;
	tmp = ft_itoa(g_shell.code_return);
	while (tmp[k])
		buf[(*j)++] = tmp[k++];
	free(tmp);
}
