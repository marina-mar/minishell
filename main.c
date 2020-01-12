/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 17:02:06 by mcouto            #+#    #+#             */
/*   Updated: 2019/09/25 17:02:08 by mcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

static char	*put_in_struct(char *environ)
{
	char	**path;
	char	*place;

	path = ft_strsplit((const char*)environ, '=');
	place = ft_strdup(path[1]);
	ft_table_del(&path);
	return (place);
}

static void	get_home_tmp_pwd(char **environ, t_command *command)
{
	int		gotit;

	gotit = 0;
	while (*environ != '\0' && gotit < 3)
	{
		if (ft_strncmp(*environ, "HOME", 4) == 0)
		{
			command->env_home = put_in_struct(*environ);
			gotit++;
		}
		else if (ft_strncmp(*environ, "TMP", 3) == 0)
		{
			command->env_tmp = put_in_struct(*environ);
			gotit++;
		}
		else if (ft_strncmp(*environ, "OLDPWD", 6) == 0)
		{
			command->oldpwd = put_in_struct(*environ);
			gotit++;
		}
		environ++;
	}
}

static void	read_line(t_command *command, char *input)
{
	int ret;

	ret = 0;
	while (get_next_line(0, &input) != 0)
	{
		ret = ms_parser(input, command, command->all_env);
		if (ret == 0)
		{
			command->argv = ft_strdup(input);
			if ((command->command_btin & EXIT) == EXIT)
			{
				ms_final_clean(command);
				break ;
			}
			ms_function_box(command);
		}
		if (input != NULL)
			ft_strdel(&input);
		ms_clean(command);
		whereami(command);
	}
	if (input != NULL)
		ft_strdel(&input);
}

int			main(void)
{
	int			i;
	char		*input;
	t_command	command;
	extern char	**environ;

	i = 0;
	input = NULL;
	initialize(&command);
	command.all_env = ft_memalloc(sizeof(char*) * (get_table_len(environ) + 1));
	while (environ[i] != NULL)
	{
		(command.all_env)[i] = ft_strdup(environ[i]);
		i++;
	}
	get_home_tmp_pwd(environ, &command);
	read_line(&command, input);
	ms_final_clean(&command);
}
