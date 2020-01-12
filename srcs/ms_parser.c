/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 19:59:12 by mcouto            #+#    #+#             */
/*   Updated: 2019/09/25 19:59:14 by mcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#define BTIN command->command_btin
#define ALL_ENV command->all_env
#define CF command->flags

int			check_env_func(char *function, char **environ, t_command *command)
{
	int		size;
	char	**table;

	size = ft_strlen(function);
	while (*environ != '\0')
	{
		if (ft_strncmp(*environ, "PATH", 4) == 0)
			break ;
		environ++;
	}
	table = ft_strsplit(*environ, '=');
	if ((command->env_path = ms_check_path(function, table[1])) == NULL)
	{
		ft_table_del(&table);
		return (1);
	}
	else if (ft_strcmp(command->env_path, "1") == 0)
	{
		command->env_path = NULL;
		ft_table_del(&table);
		return (2);
	}
	ft_table_del(&table);
	return (0);
}

uint8_t		check_btin_func(char *function, uint8_t builtin)
{
	if (ft_strcmp(function, "echo") == 0)
		builtin = (builtin | ECHO);
	else if (ft_strcmp(function, "cd") == 0)
		builtin = (builtin | CD);
	else if (ft_strcmp(function, "setenv") == 0)
		builtin = (builtin | SETENV);
	else if (ft_strcmp(function, "unsetenv") == 0)
		builtin = (builtin | UNSETENV);
	else if (ft_strcmp(function, "env") == 0)
		builtin = (builtin | ENV);
	else if (ft_strcmp(function, "exit") == 0)
		builtin = (builtin | EXIT);
	else if (ft_strcmp(function, "lozenge") == 0)
		builtin = (builtin | LOZENGE);
	else if (ft_strcmp(function, "8") == 0)
		builtin = (builtin | EIGHT);
	return (builtin);
}

static int	enviroment_funcs(char *all_args, char **environ, t_command *command)
{
	int	okay;

	okay = check_env_func(all_args, environ, command);
	if (okay == 1)
	{
		ft_printf("%B|%E %Rminishell%E: %Rcommand" \
		" not found%E: %R%s%E\n", all_args);
		return (1);
	}
	else if (okay == 2)
		return (1);
	return (0);
}

int			ms_parser(char *input, t_command *command, char **environ)
{
	char	**all_args;
	char	**tmp;
	char	*clean_input;

	clean_input = ms_clean_input(input);
	all_args = ft_strsplit(clean_input, ' ');
	tmp = all_args;
	if (get_table_len(all_args) == 0)
	{
		ft_strdel(&clean_input);
		ft_table_del(&all_args);
		return (1);
	}
	if ((command->command_btin = check_btin_func(all_args[0], BTIN)) == 0)
		if (enviroment_funcs(all_args[0], environ, command) == 1)
		{
			ft_strdel(&clean_input);
			ft_table_del(&tmp);
			return (1);
		}
	CF = ms_lastquotmarks(remain_input(all_args, clean_input, ALL_ENV));
	ft_strdel(&clean_input);
	ft_table_del(&tmp);
	return (0);
}
