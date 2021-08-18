/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_creat_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmagikar <tmagikar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 18:39:15 by tmagikar          #+#    #+#             */
/*   Updated: 2021/08/17 16:43:19 by tmagikar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

/*
** изначальная строка бьется на меньшии по пайпам
*/
char	**ft_split_pipe_1(char *line, int num)
{
	int		i;
	int		j;
	char	buf[2000];
	char	**new;

	i = 0;
	j = 0;
	new = (char **)malloc(sizeof(char *) * (num + 1));
	new[num] = NULL;
	while (i < num)
	{
		j = ft_one_line_pipe_1(line, buf, j);
		new[i++] = ft_strdup(buf);
	}
	return (new);
}

void	ft_list_init(t_list **list, t_list **tmp, int *i, int *num)
{
	*list = NULL;
	*tmp = NULL;
	*i = 0;
	*num = 0;
}

/*
** Создать листы, возвращает указатель на первый лист
*/
t_list	*ft_choto_list_1(char *line, int i, int num)
{
	char	**str;
	t_list	*list;
	t_list	*tmp;

	ft_list_init(&list, &tmp, &i, &num);
	num = ft_num_pipe(line, 0, 0) + 1;
	str = ft_split_pipe_1(line, num);
	while (str[i])
	{
		tmp = ft_create_list(tmp, str[i]);
		if (!list)
			list = tmp;
		i++;
		if (i < num)
			tmp->type = 1;
		else
			tmp->type = 0;
	}
	ft_free_dou_array(str);
	return (list);
}

t_list	*ft_create_list(t_list *tmp, char *str)
{
	int		i;
	t_list	*new;

	i = 0;
	new = (t_list *)malloc(sizeof(t_list));
	new->redirect_in = 0;
	new->redirect_out = 0;
	new->pp[0] = 0;
	new->pp[1] = 0;
	new->next = NULL;
	if (tmp)
		tmp->next = new;
	new->prev = tmp;
	new->arg = ft_split_arg_1(str);
	return (new);
}

void	ft_all_list_free(t_list *list)
{
	t_list	*tmp;

	while (list)
	{
		tmp = list;
		list = list->next;
		ft_free_dou_array(tmp->arg);
		free(tmp);
	}
}
