/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uns_dec_int_width.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 04:21:37 by mcouto            #+#    #+#             */
/*   Updated: 2019/07/27 04:21:39 by mcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char		*fill_width_minus(char *txt, char *final, LEXEME)
{
	int i;

	i = 0;
	while (*txt)
	{
		final[i] = *txt;
		txt++;
		i++;
	}
	while (i < WIDTH)
	{
		final[i] = ' ';
		i++;
	}
	return (final);
}

static char		*fill_width(char *final, LEXEME, char *txt, int size)
{
	int i;

	i = 0;
	while (i < size && WIDTH > 0)
	{
		if (FLAGS != NULL && ft_strchr(FLAGS, '0') != NULL && PREC == NULL)
			final[i] = '0';
		else
			final[i] = ' ';
		i++;
	}
	while (i < WIDTH || (size > WIDTH && i < size))
	{
		final[i] = *txt;
		txt++;
		i++;
	}
	return (final);
}

char			*width_uns_int(char *txt, LEXEME, int size)
{
	char *final;

	final = ft_strnew(size);
	if (FLAGS != NULL && ft_strchr(FLAGS, '-') != NULL)
		final = fill_width_minus(txt, final, lexeme);
	else if (WIDTH > 0)
	{
		size = size - (int)ft_strlen(txt);
		final = fill_width(final, lexeme, txt, size);
	}
	else
	{
		final = fill_width(final, lexeme, txt, size);
		return (final);
	}
	return (final);
}
