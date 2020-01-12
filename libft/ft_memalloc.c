/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 00:56:49 by mcouto            #+#    #+#             */
/*   Updated: 2019/05/04 10:10:04 by mcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memalloc(size_t size)
{
	void *mem;

	mem = malloc(size);
	if (!mem)
		return (NULL);
	ft_bzero(mem, size);
	return (mem);
}
