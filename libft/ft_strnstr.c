/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 05:59:30 by mcouto            #+#    #+#             */
/*   Updated: 2019/05/15 22:44:01 by mcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include <stdio.h>
#include <string.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	const char *start;
	const char *end;

	start = haystack;
	if (len >= ft_strlen(needle))
		end = &haystack[len - ft_strlen(needle) + 1];
	if (len < ft_strlen(needle))
		end = &haystack[ft_strlen(needle) - len + 1];
	if (ft_strlen(needle) == 0)
		return ((char*)haystack);
	else if ((*start != '\0') && ft_strlen(needle) <= len)
	{
		while ((*start != '\0') && (start != end))
		{
			if (*start == needle[0])
			{
				if (ft_strncmp(start, needle, ft_strlen(needle)) == 0)
					return ((char*)start);
			}
			start++;
		}
	}
	return (NULL);
}
