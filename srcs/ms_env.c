/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 15:22:06 by mcouto            #+#    #+#             */
/*   Updated: 2019/09/28 15:22:08 by mcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ms_env(t_command *command)
{
	char	**env_var;
	int		i;

	i = 0;
	env_var = command->all_env;
	while (env_var[i] != NULL)
	{
		ft_printf("%B|%E %s\n", env_var[i]);
		i++;
	}
}
