/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 08:38:01 by mcouto            #+#    #+#             */
/*   Updated: 2019/05/15 22:44:18 by mcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strtrim(char const *s)
{
	const char	*strt;
	const char	*end;
	char		*ret;

	if (!s)
		return (NULL);
	strt = s;
	end = &s[ft_strlen(s) - 1];
	while ((*strt == ' ' || *strt == '\n' || *strt == '\t') && *strt != '\0')
		strt++;
	while (((*end == ' ') || (*end == '\n') || (*end == '\t')) && *end >= 0)
		end--;
	if (strt >= end)
	{
		return (ft_strdup(""));
	}
	else
	{
		if (!(ret = ft_strsub(strt, 0, ((end - strt + 1)))))
			return (NULL);
	}
	return (ret);
}
