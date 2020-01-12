/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_uns.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 23:07:25 by mcouto            #+#    #+#             */
/*   Updated: 2019/07/22 23:16:38 by mcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static int	check_size(uintmax_t nbr, int base)
{
	int size;

	size = 0;
	if (nbr == 0)
		return (1);
	while (nbr > 0)
	{
		nbr = nbr / base;
		size++;
	}
	return (size);
}

char		*ft_itoabsu(unsigned long long nbr, int base, char u_or_l)
{
	char	*final;
	int		size;

	size = check_size(nbr, base);
	final = ft_strnew(size);
	if (base > 0 && base <= 16)
	{
		if (nbr == 0)
			final[0] = '0';
		while (nbr > 0)
		{
			if (u_or_l == 'l')
				final[size - 1] = ITOA_B_L[nbr % base];
			else if (u_or_l == 'u')
				final[size - 1] = ITOA_B_U[nbr % base];
			else
				return (NULL);
			nbr = nbr / base;
			size--;
		}
		return (final);
	}
	return (NULL);
}
