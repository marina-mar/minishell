/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 06:40:49 by mcouto            #+#    #+#             */
/*   Updated: 2019/07/05 06:26:32 by mcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char *join;

	if (!s1 || !s2)
		return (NULL);
	if (!(join = ft_strnew((ft_strlen(s1)) + (ft_strlen(s2)))))
		return (NULL);
	join = ft_strcat(join, s1);
	join = ft_strcat(join, s2);
	return (join);
}
