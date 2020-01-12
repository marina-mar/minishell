/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 19:00:24 by mcouto            #+#    #+#             */
/*   Updated: 2019/05/30 22:36:44 by mcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_lastlines(char **remain, char **line, int ret)
{
	int		size;

	if (ret == -1)
		return (-1);
	if (**remain != '\0')
	{
		size = ft_strlen(*remain);
		*line = ft_strnew(size);
		*line = ft_strncpy(*line, *remain, (size));
		ft_strdel(remain);
		return (1);
	}
	*line = NULL;
	ft_strdel(remain);
	return (0);
}

static void	ft_organize(char **remain, char **line, int i)
{
	char		*tmp;

	tmp = *remain;
	*line = ft_strnew(i);
	*line = ft_strncpy(*line, *remain, (i));
	*remain = ft_strdup(&(*remain)[i + 1]);
	ft_strdel(&tmp);
}

static char	*ft_nonl(int *ret, char **remain, const int fd)
{
	char		*new;
	char		*tmp;

	tmp = *remain;
	if (!(new = ft_strnew(BUFF_SIZE)))
		return (NULL);
	*ret = read(fd, new, BUFF_SIZE);
	if (!(*remain = ft_strjoin(*remain, new)))
		return (NULL);
	ft_strdel(&new);
	ft_strdel(&tmp);
	return (*remain);
}

int			get_next_line(const int fd, char **line)
{
	static char	*remain[MAX_FD];
	int			i;
	int			ret;

	ret = 0;
	i = 0;
	if ((fd < 0 || fd >= MAX_FD) || !line)
		return (-1);
	if (remain[fd] == NULL)
		if (!(remain[fd] = ft_strnew(BUFF_SIZE)))
			return (-1);
	while (remain[fd][i] != '\n')
	{
		if (remain[fd][i] == '\0')
		{
			remain[fd] = ft_nonl(&ret, &remain[fd], fd);
			if (ret < 1)
				return (ft_lastlines(&remain[fd], line, ret));
			i = i - 1;
		}
		i++;
	}
	ft_organize(&remain[fd], line, i);
	return (1);
}
