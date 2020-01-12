/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 04:31:45 by mcouto            #+#    #+#             */
/*   Updated: 2019/05/11 07:46:57 by mcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strncpy(char *dst, char *src, size_t len)
{
	size_t i;

	i = 0;
	ft_bzero(dst, len);
	while (i < len && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	return (dst);
}
