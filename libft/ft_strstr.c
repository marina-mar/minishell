/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 04:16:20 by mcouto            #+#    #+#             */
/*   Updated: 2019/05/14 21:43:35 by mcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	if (ft_strlen(needle) == 0)
		return ((char*)haystack);
	else
	{
		while ((haystack[j] != '\0'))
		{
			if (needle[i] == haystack[j])
			{
				if ((ft_strncmp(&haystack[j], needle, ft_strlen(needle))) == 0)
					return ((char*)&haystack[j]);
				else
				{
					i = 0;
				}
			}
			j++;
		}
		return (NULL);
	}
}
