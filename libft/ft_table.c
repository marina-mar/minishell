/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_table.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 02:21:53 by mcouto            #+#    #+#             */
/*   Updated: 2019/05/05 07:16:25 by mcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	**ft_table(size_t size)
{
	char **new;

	new = (char**)malloc(sizeof(char*) * (size + 1));
	if (!new)
		return (NULL);
	ft_bzero(new, sizeof(char*) * (size + 1));
	return (new);
}
