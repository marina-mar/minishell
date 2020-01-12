/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 20:20:31 by mcouto            #+#    #+#             */
/*   Updated: 2019/10/03 20:20:32 by mcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	whereami(t_command *command)
{
	char	s[100];
	char	**all;
	char	*tmp;
	int		i;

	i = 0;
	getcwd(s, 100);
	tmp = NULL;
	if (command->pwd != NULL)
		tmp = command->pwd;
	command->pwd = ft_strdup(s);
	if (tmp)
		ft_strdel(&tmp);
	if (ft_strcmp(s, "/") == 0)
	{
		ft_printf("%B (%E%M%s%E%B)%E%Y --> %E", s);
		return ;
	}
	all = ft_strsplit(s, '/');
	while (all[i] != NULL)
		i++;
	ft_printf("%B (%E%M%s%E%B)%E%Y --> %E", all[i - 1]);
	ft_table_del(&all);
}

void	initialize(t_command *command)
{
	command->command_btin = 0;
	command->command_env = NULL;
	command->flags = NULL;
	command->all_env = NULL;
	command->argv = NULL;
	command->env_path = NULL;
	command->env_home = NULL;
	command->env_tmp = NULL;
	command->pwd = NULL;
	command->oldpwd = NULL;
	ft_printf("%B ______________");
	ft_printf("_______________/\\_____________________________\n%E");
	ft_printf("%B                        %Y.%E");
	ft_printf(" minishell %Y.%E                       \n%E");
	ft_printf("%B ====================");
	ft_printf("========================================\n%E");
	ft_printf("%B ◊◊◊◊◊◊◊◊◊◊◊◊◊◊◊◊◊◊◊◊◊◊◊");
	ft_printf("◊◊◊◊◊◊◊◊◊◊◊◊◊◊◊◊◊◊◊◊◊◊◊◊◊◊◊◊◊◊◊◊◊◊◊◊◊\n%E");
	whereami(command);
}
