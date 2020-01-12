/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 04:36:04 by mcouto            #+#    #+#             */
/*   Updated: 2019/05/14 21:36:51 by mcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t		i;
	char		*str;

	i = 0;
	if (!s || !f || !(str = ft_strnew(ft_strlen(s))))
		return (NULL);
	while (i < ft_strlen(s))
	{
		str[i] = f(s[i]);
		i++;
	}
	return (str);
}
