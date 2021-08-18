/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmagikar <tmagikar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 15:06:36 by eshakita          #+#    #+#             */
/*   Updated: 2021/08/10 15:33:20 by tmagikar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (s)
	{
		while (*s)
			ft_putchar_fd(*s++, fd);
	}
}

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (s)
	{
		while (*s)
			i += ft_putchar(*s++);
	}
	return (i);
}

int	ft_putstr3(char *s1, char *s2, char *s3)
{
	int	i;

	i = 0;
	i += ft_putstr(s1);
	i += ft_putstr(s2);
	i += ft_putstr(s3);
	return (i);
}
