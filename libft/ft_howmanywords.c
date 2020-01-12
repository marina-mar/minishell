/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_howmanywords.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 01:34:05 by mcouto            #+#    #+#             */
/*   Updated: 2019/05/06 16:14:53 by mcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int	ft_howmanywords(char const *s, char c)
{
	int i;
	int size_a;

	i = 0;
	size_a = 0;
	if (s[0] != c)
		size_a++;
	while (s[i] != '\0')
	{
		if ((s[i] == c) && (s[i + 1] != c) && (s[i + 1] != '\0'))
			size_a++;
		i++;
	}
	return (size_a);
}
