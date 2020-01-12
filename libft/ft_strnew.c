/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 01:17:16 by mcouto            #+#    #+#             */
/*   Updated: 2019/07/22 20:04:23 by mcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strnew(size_t size)
{
	char *new;

	new = (char*)malloc(sizeof(char) * (size + 1));
	if (!new)
		return (NULL);
	ft_bzero(new, size + 1);
	return (new);
}
