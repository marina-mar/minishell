/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 04:10:26 by mcouto            #+#    #+#             */
/*   Updated: 2019/05/15 01:44:14 by mcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*s;
	unsigned char	*d;
	unsigned char	k;
	size_t			i;

	d = (unsigned char*)dst;
	s = (unsigned char*)src;
	k = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		if (s[i] == k)
			return (&d[i + 1]);
		i++;
	}
	return (NULL);
}
