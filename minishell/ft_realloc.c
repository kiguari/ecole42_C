/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmagikar <tmagikar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 19:16:52 by tmagikar          #+#    #+#             */
/*   Updated: 2021/08/16 15:36:53 by tmagikar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

void	ft_free_en(char ***en)
{
	int	i;

	i = 0;
	while ((*en)[i])
		free((*en)[i++]);
	free(*en);
}

char	**ft_realloc_more_line(char ***envp, char *new_line)
{
	int		i;
	char	**new;

	i = num_size(*envp);
	new = (char **)malloc(sizeof(char *) * (i + 2));
	i = 0;
	while ((*envp)[i])
	{
		new[i] = ft_strdup((*envp)[i]);
		i++;
	}
	new[i++] = ft_strdup(new_line);
	new[i] = NULL;
	ft_free_en(envp);
	return (new);
}

char	**ft_realloc_del_one_line(char ***envp, int del)
{
	int		i;
	int		j;
	char	**new;

	i = num_size(*envp);
	new = (char **)malloc(sizeof(char *) * (i));
	i = 0;
	j = 0;
	while ((*envp)[i])
	{
		if (i == del)
			i++;
		else
			new[j++] = ft_strdup((*envp)[i++]);
	}
	new[j] = NULL;
	ft_free_en(envp);
	return (new);
}
