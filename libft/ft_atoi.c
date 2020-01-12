/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 10:16:26 by mcouto            #+#    #+#             */
/*   Updated: 2019/06/28 01:55:53 by mcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int	ft_atoi(char *str)
{
	long long	final;
	long long	k;
	long long	i;

	i = 0;
	k = 1;
	final = 0;
	while ((ft_isblancsp(str[i]) == 1) && !ft_isdigit(str[i]))
		i++;
	if (str[i] == '-')
	{
		k = k * -1;
		i++;
	}
	if (str[i] == '+' && (str[i - 1] != '-'))
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		final = (final * 10) + (str[i] - 48);
		i++;
	}
	final = final * k;
	return (final);
}
