/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 03:13:05 by mcouto            #+#    #+#             */
/*   Updated: 2019/05/14 21:41:29 by mcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	int				i;

	i = 0;
	str = (unsigned char*)s;
	while (n > 0)
	{
		if (str[i] == (unsigned char)c)
		{
			return (&str[i]);
		}
		n--;
		i++;
	}
	return (NULL);
}
