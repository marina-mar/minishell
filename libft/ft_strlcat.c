/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 18:41:19 by mcouto            #+#    #+#             */
/*   Updated: 2019/05/15 21:54:14 by mcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include <stdio.h>
#include <string.h>

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t i;
	size_t j;
	size_t origindst;

	i = 0;
	j = ft_strlen(dst);
	origindst = ft_strlen(dst);
	if (dstsize <= (j))
		return ((ft_strlen(src)) + dstsize);
	else if (dstsize > (j + 1))
	{
		while ((j) < (dstsize - 1))
		{
			dst[j] = src[i];
			j++;
			i++;
		}
	}
	dst[j] = '\0';
	return ((origindst) + (ft_strlen(src)));
}
