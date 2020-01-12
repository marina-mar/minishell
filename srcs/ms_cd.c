/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 20:24:58 by mcouto            #+#    #+#             */
/*   Updated: 2019/09/27 20:25:00 by mcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#define PWD command->pwd

static int	change_dir(char *where, t_command *command)
{
	int done;

	done = 0;
	if (ft_strlen(where) > 1 && where[0] == '/')
	{
		if (chdir("/") != 0)
		{
			ft_printf("%B|%E %Rcd%E: %R%s%E: %R%s%E\n", strerror(errno), where);
			ft_strdel(&where);
			return (1);
		}
		where = ft_strdup(&(where[1]));
		done = 1;
	}
	if (chdir(where) != 0)
	{
		if ((done == 1) && (chdir(command->pwd) != 0))
			ft_printf("%B|%E cd: %R%s%E: %R%s%E\n", strerror(errno), PWD);
		ft_printf("%B|%E cd: %R%s%E: %R%s%E\n", strerror(errno), where);
		ft_strdel(&where);
		return (1);
	}
	if (done == 1)
		ft_strdel(&where);
	return (0);
}

static void	change_pwd(char **all_env, char *old_pwd, t_command *command)
{
	char	*tmp;
	char	new[100];

	getcwd(new, 100);
	while (*all_env != NULL)
	{
		if (ft_strncmp("PWD", *all_env, 3) == 0)
		{
			tmp = *all_env;
			*all_env = ft_strjoin("PWD=", new);
			ft_strdel(&tmp);
			command->pwd = ft_strdup(new);
		}
		else if (ft_strncmp("OLDPWD", *all_env, 6) == 0)
		{
			tmp = *all_env;
			*all_env = ft_strjoin("OLDPWD=", old_pwd);
			ft_strdel(&tmp);
			tmp = command->oldpwd;
			command->oldpwd = ft_strdup(old_pwd);
			ft_strdel(&tmp);
			ft_strdel(&old_pwd);
		}
		all_env++;
	}
}

static char	*change_path(char *new, char *old, int cut_here)
{
	char	*where;

	where = ft_strjoin(new, &old[cut_here]);
	ft_strdel(&old);
	return (where);
}

static char	*cd_parser(char *where, t_command *command)
{
	char	*tmp;
	int		clean;

	clean = 0;
	if (where[0] == '-' && ft_strlen(where) == 1)
	{
		tmp = where;
		where = ft_strdup(command->oldpwd);
		clean = 1;
		ft_printf("%B|%E %s\n", command->oldpwd);
	}
	else if (where == NULL || ft_strcmp("", where) == 0)
	{
		tmp = where;
		where = ft_strdup("~");
		clean = 1;
	}
	if (ft_strncmp(where, "~", 1) == 0)
		where = change_path(command->env_home, where, 1);
	else if (ft_strncmp("/tmp", where, 4) == 0)
		where = change_path("/private/tmp/", where, 5);
	if (clean == 1)
		ft_strdel(&tmp);
	return (where);
}

void		ms_cd(t_command *command)
{
	char	*where;
	char	**all_env;

	all_env = command->all_env;
	where = ft_strdup(command->flags);
	if (ft_howmanywords(where, ' ') != 1)
	{
		ft_strdel(&where);
		ft_printf("%B|%E %RUSAGE%E: %Ccd%E %Ypath%E\n");
		return ;
	}
	where = cd_parser(where, command);
	if (change_dir(where, command) == 1)
		return ;
	ft_strdel(&where);
	change_pwd(all_env, command->pwd, command);
}
