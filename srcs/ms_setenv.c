/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 22:11:27 by mcouto            #+#    #+#             */
/*   Updated: 2019/09/27 22:11:29 by mcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	has_name(char **all_env, char **arguments)
{
	int here;
	int i;

	here = -1;
	i = 0;
	while (all_env[i] != NULL)
	{
		if (ft_strncmp(all_env[i], arguments[0], ft_strlen(arguments[0])) == 0)
			return (i);
		i++;
	}
	return (here);
}

static char	*change_value(char *original, char *new_val)
{
	char	*new;
	char	*tmp;
	char	**split;

	split = ft_strsplit(original, '=');
	tmp = split[1];
	split[1] = ft_strdup(new_val);
	ft_strdel(&tmp);
	new = ft_strjoin(split[0], "=");
	tmp = new;
	new = ft_strjoin(new, split[1]);
	ft_strdel(&tmp);
	ft_table_del(&split);
	return (new);
}

static char	*build_it(char *new, char **arguments)
{
	char *tmp;

	new = ft_strjoin(arguments[0], "=");
	tmp = new;
	new = ft_strjoin(new, arguments[1]);
	ft_strdel(&tmp);
	return (new);
}

static char	**new_env(char **all_env, char **arguments)
{
	char	**new;
	int		i;
	int		here;

	i = 0;
	here = has_name(all_env, arguments);
	if (here == -1)
		new = ft_memalloc((sizeof(char*)) * (get_table_len(all_env) + 2));
	else
		new = ft_memalloc((sizeof(char*)) * (get_table_len(all_env) + 1));
	while (all_env[i] != NULL)
	{
		if (i == here)
			new[i] = change_value(all_env[i], arguments[1]);
		else
			new[i] = ft_strdup(all_env[i]);
		i++;
	}
	if (here == -1)
		new[i] = build_it(new[i], arguments);
	ft_table_del(&all_env);
	return (new);
}

void		ms_setenv(t_command *command)
{
	char	**all_env;
	char	**arguments;
	int		size;
	int		i;

	i = 0;
	size = 0;
	all_env = command->all_env;
	arguments = ft_strsplit(command->flags, ' ');
	size = get_table_len(arguments);
	if (command->flags == NULL || size != 2)
	{
		ft_table_del(&arguments);
		ft_printf("%B|%E %RUSAGE%E: %Csetenv%E %Bname%E %Yvalue%E\n");
		return ;
	}
	while (arguments[0][i] != '\0')
	{
		arguments[0][i] = ft_toupper(arguments[0][i]);
		i++;
	}
	command->all_env = new_env(all_env, arguments);
	ft_table_del(&arguments);
}
