/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat_wnull.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 00:53:34 by mcouto            #+#    #+#             */
/*   Updated: 2019/07/26 00:53:38 by mcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strncat_wnull(char *s1, const char *s2, size_t n)
{
	size_t i;
	size_t j;

	i = ft_strlen(s1);
	j = 0;
	while (j < n)
	{
		s1[i] = s2[j];
		j++;
		i++;
	}
	return (s1);
}
