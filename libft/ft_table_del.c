/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_table_del.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 19:07:09 by mcouto            #+#    #+#             */
/*   Updated: 2019/10/01 19:07:12 by mcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_table_del(char ***table)
{
	int		i;
	char	**tbl;

	i = 0;
	if (table && *table)
		tbl = *table;
	else
		return ;
	while (tbl[i] != '\0')
	{
		ft_strdel(&tbl[i]);
		i++;
	}
	free(*table);
	*table = NULL;
}
