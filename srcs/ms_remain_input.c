/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_organize_arguments.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 22:45:32 by mcouto            #+#    #+#             */
/*   Updated: 2019/10/03 22:45:34 by mcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	len_before_char(char *string, char delimiter)
{
	int i;

	i = 0;
	while (string[i] != delimiter)
		i++;
	return (i);
}

static char	*check_for_dolar(char *string, char **all_env)
{
	char	*clean;
	char	*tmp;
	char	*final;
	int		where;

	clean = &string[1];
	tmp = string;
	while (*all_env != NULL)
	{
		where = len_before_char(*all_env, '=');
		if (ft_strncmp(*all_env, clean, where) == 0)
		{
			ft_strdel(&tmp);
			final = *all_env;
			return (ft_strdup(&(final[where + 1])));
		}
		all_env++;
	}
	return (ft_strdup(""));
}

char		*remain_input(char **all_args, char *input, char **all_env)
{
	int		size;
	int		i;
	char	*extra;

	size = ft_strlen(input) - ft_strlen(all_args[0]);
	i = 0;
	extra = ft_strnew(size);
	size = 1;
	while (all_args[i] != NULL)
		i++;
	while (size < i)
	{
		all_args[size] = ms_quotmarks(all_args[size]);
		if (all_args[size][0] == '$')
			all_args[size] = check_for_dolar(all_args[size], all_env);
		extra = ft_strcat(extra, all_args[size]);
		if (size < (i - 1))
			extra = ft_strcat(extra, " ");
		size++;
	}
	extra = ms_quotmarks(extra);
	return (extra);
}
