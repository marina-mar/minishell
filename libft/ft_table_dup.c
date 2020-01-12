/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_table_dup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 16:44:21 by mcouto            #+#    #+#             */
/*   Updated: 2019/09/28 16:44:24 by mcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	**ft_table_dup(char **original)
{
	char	**new;
	int		i;

	i = 0;
	new = ft_memalloc(sizeof(char*) * (get_table_len(original) + 1));
	while (original[i] != NULL)
	{
		new[i] = ft_strdup(original[i]);
		i++;
	}
	new[i] = NULL;
	return (new);
}
