/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 19:22:28 by mcouto            #+#    #+#             */
/*   Updated: 2019/10/03 19:22:29 by mcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char		*two_bit(char conv)
{
	char *final;

	final = ft_strnew(8);
	if (conv == 'M')
		final = ft_strcat(final, "\033[0;35m");
	else if (conv == 'B')
		final = ft_strcat(final, "\033[1;34m");
	else if (conv == 'C')
		final = ft_strcat(final, "\033[0;36m");
	else if (conv == 'Y')
		final = ft_strcat(final, "\033[0;33m");
	else if (conv == 'G')
		final = ft_strcat(final, "\033[1;32m");
	return (final);
}

char			*print_colors(char conv)
{
	char *final;

	if (conv == 'M' || conv == 'B' || conv == 'Y' || conv == 'G' ||
		conv == 'C' || conv == 'I')
		final = two_bit(conv);
	else if (conv == 'R')
		final = ft_strnew(14);
	else
		final = ft_strnew(6);
	if (conv == 'R')
		final = ft_strcat(final, "\033[4;38;5;168m");
	else if (conv == 'I')
		final = ft_strcat(final, "\033[7;m");
	else if (conv == 'E')
		final = ft_strcat(final, "\033[0m");
	return (final);
}
