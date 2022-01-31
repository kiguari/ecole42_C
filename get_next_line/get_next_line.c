/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 18:17:17 by eshakita          #+#    #+#             */
/*   Updated: 2020/12/21 16:12:26 by eshakita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char			*check_reminder(char *reminder, char **line)
{
	char			*place_n;

	place_n = NULL;
	if (reminder)
	{
		if ((place_n = ft_strchr(reminder, '\n')))
		{
			*place_n = '\0';
			*line = ft_strdup(reminder);
			place_n++;
			ft_strcpy(reminder, place_n);
		}
		else
		{
			*line = ft_strdup(reminder);
		}
	}
	else
		*line = ft_strdup("");
	return (place_n);
}

static int			ft_clear_and_line(char *baffer, char **line)
{
	char			*place_n;
	char			*free_leaks_in_line;

	place_n = NULL;
	free_leaks_in_line = *line;
	if (!(*line = ft_strjoin(*line, baffer)))
		return (0);
	free(free_leaks_in_line);
	return (1);
}

static int			ft_ost(char *place_n, int byte, char **reminder)
{
	if (!place_n && !byte)
	{
		free(*reminder);
		*reminder = NULL;
		return (0);
	}
	return (1);
}

static int			ft_gnl(int fd, char **line, char *baffer, char *place_n)
{
	int				byte;
	static char		*reminder;

	if (fd < 0 || !line || BUFFER_SIZE <= 0 || read(fd, baffer, 0) == -1
	|| (!(baffer = (char *)malloc(BUFFER_SIZE + 1))))
		return (-1);
	place_n = check_reminder(reminder, line);
	if (!line)
		return (-1);
	while (!place_n && (byte = read(fd, baffer, BUFFER_SIZE)))
	{
		baffer[byte] = '\0';
		if ((place_n = ft_strchr(baffer, '\n')))
		{
			free(reminder);
			*place_n = '\0';
			if (!(reminder = ft_strdup(++place_n)))
				return (-1);
		}
		if (!(ft_clear_and_line(baffer, line)))
			return (-1);
	}
	free(baffer);
	return (ft_ost(place_n, byte, &reminder));
}

int					get_next_line(int fd, char **line)
{
	char			*baffer;
	char			*place_n;

	place_n = NULL;
	baffer = NULL;
	return (ft_gnl(fd, line, baffer, place_n));
}
