/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_type_perm.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 21:33:10 by mcouto            #+#    #+#             */
/*   Updated: 2019/10/03 21:33:14 by mcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int			check_type_perm(char *function, char *where)
{
	struct stat	filestat;
	int			okay;
	char		*path;
	char		*tmp;

	path = ft_strjoin(where, "/");
	tmp = path;
	okay = 0;
	path = ft_strjoin(path, (const char*)function);
	ft_strdel(&tmp);
	if (lstat((const char*)path, &filestat) == -1)
	{
		ft_printf("%B|%E %R%s%E\n", strerror(errno));
		exit(EXIT_FAILURE);
	}
	ft_strdel(&path);
	if (S_ISREG(filestat.st_mode) || S_ISLNK(filestat.st_mode))
		okay++;
	if (!(filestat.st_mode & S_IXOTH) && !(filestat.st_mode & S_IXGRP) &&
		!(filestat.st_mode & S_IXUSR))
		okay++;
	if (okay == 0)
		return (1);
	return ((okay == 1) ? 0 : 2);
}
