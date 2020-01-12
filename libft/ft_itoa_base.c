/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 03:58:20 by mcouto            #+#    #+#             */
/*   Updated: 2019/07/22 23:10:25 by mcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static int	check_size(long long nbr, int base)
{
	int	size;

	size = 0;
	if (nbr == 0)
		return (1);
	if (nbr < 0)
	{
		size = 1;
		nbr = nbr * -1;
	}
	while (nbr > 0)
	{
		nbr = nbr / base;
		size++;
	}
	return (size);
}

void		check_if_neg(long long nbr, char **final)
{
	if (nbr < 0)
	{
		nbr = nbr * -1;
		*final[0] = '-';
	}
}

char		*ft_itoa_base(long long nbr, int base, char u_or_l)
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
