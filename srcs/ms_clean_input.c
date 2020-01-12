/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_clean_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 17:06:03 by mcouto            #+#    #+#             */
/*   Updated: 2019/10/01 17:06:05 by mcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*ms_clean_input(char *input)
{
	int		i;
	int		j;
	char	*clean;

	j = 0;
	i = 0;
	clean = ft_strnew(ft_strlen(input));
	while (ft_isblancsp(*input) == 1)
		input++;
	while (input[i] != '\0')
	{
		while ((input[i + 1] != '\0') && (ft_isblancsp(input[i]) == 1) &&
		(ft_isblancsp(input[i + 1]) == 1))
			i++;
		clean[j] = input[i];
		j++;
		i++;
	}
	return (clean);
}
