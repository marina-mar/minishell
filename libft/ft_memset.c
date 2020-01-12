/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 23:36:28 by mcouto            #+#    #+#             */
/*   Updated: 2019/05/01 01:55:28 by mcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char *str;

	str = (char*)b;
	while (len > 0)
	{
		str[0] = (unsigned char)c;
		str++;
		len--;
	}
	return (b);
}
