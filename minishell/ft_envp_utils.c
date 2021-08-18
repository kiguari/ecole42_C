/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_envp_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmagikar <tmagikar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 13:18:57 by eshakita          #+#    #+#             */
/*   Updated: 2021/08/16 15:34:09 by tmagikar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

char	**ft_realloc_envp(char **en, int new_size, int del_str)
{
	int		i;
	char	**new;

	i = 0;
	if (del_str != -1)
		delete_one_envp(en, del_str);
	new = (char **)malloc(sizeof(char *) * (new_size + 1));
	while (en[i] && i < new_size)
	{
		new[i] = ft_strdup(en[i]);
		if (!(new[i]))
			ft_gg_wp_the_end();
		free(en[i]);
		i++;
	}
	while (i <= new_size)
		new[i++] = NULL;
	free(en);
	return (new);
}

/*
**	Удаляет 1 строку
*/

void	delete_one_envp(char **en, int i)
{
	free(en[i]);
	while (en[i + 1])
	{
		en[i] = en[i + 1];
		i++;
	}
	en[i] = NULL;
}

char	**ft_my_envp(char **envp)
{
	int		i;
	char	**tmp;

	i = num_size(envp);
	tmp = (char **)malloc(sizeof(char *) * (i + 1));
	if (!tmp)
		ft_gg_wp_the_end();
	i = 0;
	while (envp[i])
	{
		tmp[i] = ft_strdup(envp[i]);
		if (!tmp[i])
			ft_gg_wp_the_end();
		i++;
	}
	tmp[i] = NULL;
	return (tmp);
}

char	*ft_revers_one_dir(char *line, int len)
{
	char	*tmp;

	tmp = (char *)malloc(sizeof(char) * (len + 1));
	ft_strlcpy(tmp, line, len + 1);
	return (tmp);
}

/*
** Находит '=' в переменной окружения
*/

int	ft_check_ravno(char *arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		if (arg[i] == '=')
			return (1);
		i++;
	}
	return (0);
}
