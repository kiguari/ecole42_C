/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 15:14:28 by eshakita          #+#    #+#             */
/*   Updated: 2021/06/08 11:41:06 by eshakita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	j;

	j = n;
	if (n < 0)
	{
		j = -n;
		ft_putchar_fd('-', fd);
	}
	if (j >= 10)
		ft_putnbr_fd(j / 10, fd);
	ft_putchar_fd((char)(j % 10 + 48), fd);
}
