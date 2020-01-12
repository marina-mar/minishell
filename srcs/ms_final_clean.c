/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_final_clean.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 19:23:41 by mcouto            #+#    #+#             */
/*   Updated: 2019/10/01 19:23:42 by mcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ms_clean(t_command *command)
{
	command->command_btin = 0;
	if (command->command_env != NULL)
		ft_strdel(&(command->command_env));
	if (command->flags != NULL)
		ft_strdel(&(command->flags));
	if (command->argv != NULL)
		ft_strdel(&(command->argv));
	if (command->env_path != NULL)
		ft_strdel(&(command->env_path));
}

void	ms_final_clean(t_command *command)
{
	ms_clean(command);
	if (command->env_home != NULL)
		ft_strdel(&(command->env_home));
	if (command->env_tmp != NULL)
		ft_strdel(&(command->env_tmp));
	if (command->pwd != NULL)
		ft_strdel(&(command->pwd));
	if (command->oldpwd != NULL)
		ft_strdel(&(command->oldpwd));
	if (command->all_env != NULL)
		ft_table_del(&(command->all_env));
}
