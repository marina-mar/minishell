/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 05:27:37 by mcouto            #+#    #+#             */
/*   Updated: 2019/05/14 21:57:08 by mcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static void		ft_increase(int *size, int *i)
{
	*size += 1;
	*i += 1;
}

char			**ft_strsplit(const char *s, char c)
{
	char	**final;
	int		i;
	int		j;
	int		size;

	i = 0;
	j = 0;
	if (!s || !c || !(final = ft_table(ft_howmanywords(s, c))))
		return (NULL);
	while (s[i] != '\0')
	{
		size = 0;
		while (s[i] == c)
			i++;
		while ((s[i] != c) && (s[i] != '\0'))
			ft_increase(&size, &i);
		if (size > 0)
		{
			final[j] = ft_strnew(size);
			final[j] = ft_strncpy(final[j], (char*)&s[i - size], (size));
			j++;
		}
	}
	return (final);
}
