/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 20:41:06 by mcouto            #+#    #+#             */
/*   Updated: 2019/05/14 21:32:51 by mcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strsep(char **stringp, const char *delim)
{
	char	*temp;
	int		i;

	i = 0;
	if (stringp == NULL)
		return (NULL);
	temp = *stringp;
	while (*stringp[i] != delim[0])
		i++;
	if (*stringp[i] == delim[0])
	{
		*stringp[i] = '\0';
		i++;
	}
	stringp = &stringp[i];
	return (temp);
}
