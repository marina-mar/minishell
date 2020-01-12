/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_function_box.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 18:21:22 by mcouto            #+#    #+#             */
/*   Updated: 2019/09/27 18:21:23 by mcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#define FUNC command->command_btin

static void	executer(t_command *command)
{
	char *const *argv;

	if ((argv = (char *const*)ft_strsplit(command->argv, ' ')) == NULL)
		exit(EXIT_FAILURE);
	if (execve(command->env_path, argv, command->all_env) == -1)
		ft_printf("%B|%E %R%s%E\n", strerror(errno));
	else
		exit(EXIT_SUCCESS);
	ft_table_del((char***)&argv);
}

static void	env_prog(t_command *command)
{
	int pid;
	int status;

	pid = fork();
	if (pid < 0)
	{
		ft_printf("%B|%E %R%s%E\n", strerror(errno));
		return ;
	}
	else if (pid == 0)
		executer(command);
	else
	{
		if (waitpid(pid, &status, 0) == -1)
		{
			ft_printf("%B|%E %R%s%E\n", strerror(errno));
			return ;
		}
		if (WIFSIGNALED(status) || WEXITSTATUS(status))
			return ;
	}
}

static void	btin_funcs(t_command *command)
{
	if ((FUNC & ECHO) == ECHO)
		ms_echo(command);
	else if ((FUNC & CD) == CD)
		ms_cd(command);
	else if ((FUNC & SETENV) == SETENV)
		ms_setenv(command);
	else if ((FUNC & UNSETENV) == UNSETENV)
		ms_unsetenv(command);
	else if ((FUNC & ENV) == ENV)
		ms_env(command);
	else if ((FUNC & LOZENGE) == LOZENGE)
		ft_printf("%B|%E %Y  ◊  %E\n%B|%E %Y◊   ◊%E\n%B|%E %Y  ◊  %E\n");
	else if ((FUNC & EIGHT) == EIGHT)
		ms_random_8();
}

int			ms_function_box(t_command *command)
{
	uint8_t function;

	function = command->command_btin;
	if (function != 0)
		btin_funcs(command);
	else
		env_prog(command);
	return (0);
}
