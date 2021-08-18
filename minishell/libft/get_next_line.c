/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmagikar <tmagikar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 15:35:34 by tmagikar          #+#    #+#             */
/*   Updated: 2021/08/09 15:58:36 by tmagikar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup_gnl(char *s)
{
	char			*dest;
	unsigned int	i;

	i = 0;
	dest = NULL;
	dest = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!(dest))
		return (NULL);
	while (s[i])
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	s[0] = '\0';
	return (dest);
}

static int	ft_gnl_help_check_buf(char *buf, char **line, char **point)
{
	*point = ft_strchr(buf, '\n');
	if (*point)
	{
		**point = '\0';
		*line = ft_strdup_gnl(buf);
		if (!(*line))
			return (0);
		ft_memmove(buf, (*point + 1), GNL_BUFFER_SIZE - (*point - buf));
	}
	else
	{
		*line = ft_strdup_gnl(buf);
		if (!(*line))
			return (0);
	}
	return (1);
}

static char	*ft_gnl_check_buf(char *buf, char **line)
{
	char	*point_n;

	point_n = NULL;
	if (buf[0])
	{
		if (!ft_gnl_help_check_buf(buf, line, &point_n))
			return (NULL);
	}
	else
	{
		*line = (char *)malloc(1);
		if (!(*line))
			return (NULL);
		*line[0] = '\0';
	}
	return (point_n);
}

static char	*ft_gnl_buf_read(char *buf, char **line)
{
	char	*point_n;
	char	*tmp;

	point_n = NULL;
	point_n = ft_strchr(buf, '\n');
	if (point_n)
	{
		*point_n = '\0';
		tmp = *line;
		*line = ft_strjoin(*line, buf);
		if (!(*line))
			return (NULL);
		free(tmp);
		ft_memmove(buf, (point_n + 1), GNL_BUFFER_SIZE - (point_n - buf));
	}
	else
	{
		tmp = *line;
		*line = ft_strjoin(*line, buf);
		if (!(*line))
			return (NULL);
		free(tmp);
		buf[0] = '\0';
	}
	return (point_n);
}

int	get_next_line(int fd, char **line)
{
	int			byte;
	char		*point;
	static char	buf[GNL_BUFFER_SIZE + 1];

	point = NULL;
	if (GNL_BUFFER_SIZE < 1 || read(fd, buf, 0) == -1 || line == NULL)
		return (-1);
	point = ft_gnl_check_buf(buf, line);
	if (line == NULL)
		return (-1);
	byte = -1;
	while (!point && byte)
	{
		byte = read(fd, buf, GNL_BUFFER_SIZE);
		buf[byte] = '\0';
		point = ft_gnl_buf_read(buf, line);
		if (line == NULL)
			return (-1);
	}
	if (!point && !byte)
		return (0);
	return (1);
}
