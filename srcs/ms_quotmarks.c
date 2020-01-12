/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_quotmarks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 21:07:52 by mcouto            #+#    #+#             */
/*   Updated: 2019/09/27 21:07:54 by mcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static char	*redo_quotes(char *final, char **clean, int how_many)
{
	int i;

	i = 0;
	while (final[i] != '\0')
	{
		if (final[i] == '\\' && final[i + 1] == '\"' &&
		(i < (int)(ft_strlen(final) - how_many)))
		{
			clean[j] = '\"';
			j++;
			i++;
		}
		else if ((i == 0 && final[i] != '\"') ||
		(i > 0 && final[i - 1] != '\\' && final[i] != '\"'))
		{
			clean[j] = final[i];
			j++;
		}
		i++;
	}
}

static char	*get_string_no_quotes(char *final, int how_many)
{
	char	*tmp;
	char	*clean;
	int		i;
	int		j;

	tmp = final;
	i = 0;
	j = 0;
	clean = ft_strnew(ft_strlen(final) - how_many);
	ft_strdel(&tmp);
	return (clean);
}

char		*ms_lastquotmarks(char *final)
{
	int	i;
	int	size;
	int	has;

	i = 0;
	has = 0;
	size = 0;
	while (final[size] != '\0')
	{
		if (size == 0 && final[size] == '\"')
			has++;
		if (size > 0 && final[size - 1] != '\\' && final[size] == '\"')
			has++;
		size++;
	}
	if (has % 2 == 0)
		return (final = get_string_no_quotes(final, has));
	return (final);
}

char		*ms_quotmarks(char *extra_input)
{
	int		how_long;
	char	*tmp;
	char	*final;

	tmp = extra_input;
	how_long = ft_strlen(extra_input);
	if (extra_input[0] == '\"' && extra_input[how_long - 1] == '\"')
	{
		extra_input++;
		extra_input[how_long - 2] = '\0';
	}
	final = ft_strdup(extra_input);
	ft_strdel(&tmp);
	return (final);
}
