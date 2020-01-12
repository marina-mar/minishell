/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 15:52:00 by mcouto            #+#    #+#             */
/*   Updated: 2019/09/28 15:52:03 by mcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	get_index(char **env_var, char *name)
{
	int i;
	int has_name;
	int size;

	i = 0;
	size = ft_strlen(name);
	has_name = -1;
	while (env_var[i] != NULL)
	{
		if (ft_strncmp(name, env_var[i], size) == 0)
			has_name = i;
		i++;
	}
	return (has_name);
}

static char	**copy_without(char **env_var, int has_name, char **new)
{
	int		i;
	char	**tmp;

	i = 0;
	tmp = new;
	while (env_var[i] != NULL)
	{
		if (i != has_name)
		{
			*new = ft_strdup(env_var[i]);
			new++;
		}
		i++;
	}
	return (tmp);
}

char		**check_for_name(char *name, char **env_var)
{
	char	**new;
	int		has_name;
	int		i;

	i = 0;
	has_name = get_index(env_var, name);
	if (has_name > -1)
		new = ft_memalloc((sizeof(char*)) * (get_table_len(env_var)));
	else
	{
		ft_printf("%B|%E %RNo Enviromment Variable named%E: %R%s%E\n", name);
		return (env_var);
	}
	new = copy_without(env_var, has_name, new);
	ft_table_del(&env_var);
	return (new);
}

void		ms_unsetenv(t_command *command)
{
	char	**env_var;
	char	**name;
	char	**new;
	int		i;

	i = 0;
	env_var = command->all_env;
	name = ft_strsplit(command->flags, ' ');
	if (get_table_len(name) != 1)
	{
		ft_printf("%B|%E %RUSAGE%E: %Cunsetenv%E %Bname%E %Yvalue%E\n");
		return ;
	}
	while (name[0][i] != '\0')
	{
		name[0][i] = ft_toupper(name[0][i]);
		i++;
	}
	new = check_for_name(name[0], env_var);
	command->all_env = new;
	ft_table_del(&name);
}
