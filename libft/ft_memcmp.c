/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 03:16:26 by mcouto            #+#    #+#             */
/*   Updated: 2019/05/14 15:55:17 by mcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*str;
	unsigned char	*str1;
	int				i;

	str = (unsigned char*)s1;
	str1 = (unsigned char*)s2;
	i = 0;
	if (n == 0)
		return (0);
	while ((str[i] == str1[i]) && (i < (int)(n - 1)))
		i++;
	if (str[i] != str1[i])
	{
		return (str[i] - str1[i]);
	}
	return (0);
}
