/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_get_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 18:01:52 by mcouto            #+#    #+#             */
/*   Updated: 2019/09/27 18:01:54 by mcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static char	*build_path(char *function, char *where)
{
	char *tmp;

	where = ft_strjoin(where, "/");
	tmp = where;
	where = ft_strjoin(where, function);
	ft_strdel(&tmp);
	return (where);
}

static int	check_name(char *function)
{
	struct stat filestat;

	if (lstat((const char*)function, &filestat) == -1)
		return (-1);
	if (S_ISREG(filestat.st_mode))
		return (0);
	else if (S_ISLNK(filestat.st_mode))
		return (0);
	else
		return (1);
}

char		*verify_exec(char **where, char *place, DIR *directory, char *func)
{
	struct dirent	*read_dir;

	while ((read_dir = readdir(directory)))
	{
		if (ft_strcmp(read_dir->d_name, func) == 0)
		{
			if (check_type_perm(func, *where) == 0)
			{
				if (place != NULL)
					ft_strdel(&place);
				place = build_path(func, *where);
			}
			else
			{
				ft_printf("%B|%E %RPermission denied%E\n");
				closedir(directory);
				return ("1");
			}
		}
	}
	return (place);
}

char		*find_in_dir(char **where, char *function)
{
	DIR		*directory;
	char	*place;
	int		found;

	place = NULL;
	found = 0;
	while (*where != '\0')
	{
		directory = opendir(*where);
		if (directory != NULL)
		{
			place = verify_exec(where, place, directory, function);
			closedir(directory);
		}
		where++;
	}
	return (place);
}

char		*ms_check_path(char *function, char *paths)
{
	char *place;
	char **where;

	place = NULL;
	if (check_name(function) == 0)
		return (ft_strdup(function));
	where = ft_strsplit(paths, ':');
	place = find_in_dir(where, function);
	ft_table_del(&where);
	return (place);
}
