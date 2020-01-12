/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 18:49:58 by mcouto            #+#    #+#             */
/*   Updated: 2019/05/11 10:04:24 by mcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strdup(char *str1)
{
	char *str2;

	if (!(str2 = ft_strnew(ft_strlen(str1))))
	{
		return (NULL);
	}
	str2 = ft_strcpy(str2, str1);
	return (str2);
}
