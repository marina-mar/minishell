/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_howmanydig.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 07:02:17 by mcouto            #+#    #+#             */
/*   Updated: 2019/07/05 04:40:02 by mcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int	ft_howmanydig(intmax_t n)
{
	long int size;

	size = 0;
	if (n < 0)
	{
		n = n * (-1);
		size++;
	}
	if (n == 0)
		size = 1;
	while (n > 0)
	{
		n = n / 10;
		size++;
	}
	return (size);
}
