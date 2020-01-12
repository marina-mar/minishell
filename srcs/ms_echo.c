/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 18:35:16 by mcouto            #+#    #+#             */
/*   Updated: 2019/09/27 18:35:18 by mcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int		check_empty_string(char *extra)
{
	if (extra == NULL || ft_strcmp(extra, "") == 0)
	{
		ft_printf("\n");
		return (1);
	}
	return (0);
}

static	void	print(char **extra_input)
{
	if (extra_input[0][0] == '-' && extra_input[0][1] == 'n')
	{
		extra_input++;
		while (*extra_input != NULL)
		{
			ft_printf("%s%I%c%E ", *extra_input, '%');
			extra_input++;
		}
	}
	else
	{
		while (*extra_input != NULL)
		{
			ft_printf("%s ", *extra_input);
			extra_input++;
		}
	}
}

void			ms_echo(t_command *command)
{
	char **extra_input;
	char **tmp;

	if (check_empty_string(command->flags) == 1)
		return ;
	extra_input = ft_strsplit(command->flags, ' ');
	tmp = extra_input;
	ft_printf("%B|%E ");
	print(extra_input);
	ft_printf("\n");
	ft_table_del(&tmp);
}
