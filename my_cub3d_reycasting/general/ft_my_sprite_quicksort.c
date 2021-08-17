/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_my_sprite_quicksort.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 12:57:36 by eshakita          #+#    #+#             */
/*   Updated: 2021/04/28 17:50:04 by eshakita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void		ft_swap(double *dist, int *order, int i, int j)
{
	double	gap_dist;
	int		gap_ordinal_point;

	gap_dist = 0;
	gap_ordinal_point = 0;
	gap_dist = dist[i];
	gap_ordinal_point = order[i];
	dist[i] = dist[j];
	order[i] = order[j];
	dist[j] = gap_dist;
	order[j] = gap_ordinal_point;
}

void		ft_body_quicksort(double *dist, int *order, int left, int right)
{
	int		i;
	int		j;
	double	middle_dist;

	i = left;
	j = right;
	middle_dist = dist[(left + right) / 2];
	while (i <= j)
	{
		while ((dist[i] > middle_dist) && (i < right))
			i++;
		while ((middle_dist > dist[j]) && (j > left))
			j--;
		if (i <= j)
		{
			ft_swap(dist, order, i, j);
			i++;
			j--;
		}
	}
	if (left < j)
		ft_body_quicksort(dist, order, left, j);
	if (i < right)
		ft_body_quicksort(dist, order, i, right);
}

void		ft_my_sprite_quicksort(int *order, double *dist, int amount)
{
	int		left;
	int		right;

	right = amount - 1;
	left = 0;
	ft_body_quicksort(dist, order, left, right);
}
