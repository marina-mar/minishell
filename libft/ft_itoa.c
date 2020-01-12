/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 06:46:36 by mcouto            #+#    #+#             */
/*   Updated: 2019/07/11 19:24:30 by mcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#pragma clang diagnostic ignored "-Wimplicitly-unsigned-literal"

char	*ft_itoa(intmax_t n)
{
	char				*final;
	uintmax_t			nbr;
	unsigned long long	size;

	nbr = (uintmax_t)n;
	if (nbr == -9223372036854775808)
		return (ft_strdup("-9223372036854775808"));
	size = ft_howmanydig(n);
	if (!(final = ft_strnew(size)))
		return (NULL);
	if (n < 0)
	{
		n = n * (-1);
		final[0] = '-';
	}
	if (n == 0)
		return (ft_strcat(final, "0"));
	while (n != 0)
	{
		final[size - 1] = (n % 10) + '0';
		n = n / 10;
		size--;
	}
	return (final);
}
