/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_global_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakita <eshakita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 13:35:18 by eshakita          #+#    #+#             */
/*   Updated: 2021/08/16 17:31:12 by eshakita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

void	ft_fork_bildin(t_list *list)
{
	if (list->type)
	{
		dup2(list->pp[1], 1);
		close(list->pp[0]);
	}
	if (list->prev && list->prev->type)
	{
		dup2(list->prev->pp[0], 0);
		close(list->pp[1]);
	}
}

void	ft_fork_bildin2(t_list *list)
{
	if (list->type)
	{
		close(list->pp[1]);
		if (!list->next)
			close(list->pp[0]);
	}
	if (list->prev && list->prev->type)
		close(list->prev->pp[0]);
}

int	ft_stat_file(char *file)
{
	char		buf[500];
	char		*tmp;
	char		*tmp2;
	struct stat	buff[1111];

	getcwd(buf, 500);
	tmp = ft_strjoin(buf, "/");
	tmp2 = ft_strjoin(tmp, file);
	free(tmp);
	if (stat(tmp2, buff))
	{
		ft_putstr3("\nminigoose: ", file, ": No such file or directory\n");
		free(tmp2);
		return (0);
	}
	free(tmp2);
	return (1);
}
