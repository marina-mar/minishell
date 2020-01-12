/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sig_dec_int_width.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 05:18:58 by mcouto            #+#    #+#             */
/*   Updated: 2019/08/09 18:07:45 by mcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int		s_p(char *final, LEXEME)
{
	int i;

	i = 0;
	if (ft_strchr(FLAGS, '-') == NULL && final[i] == ' ')
	{
		while (final[i] == ' ')
			i++;
		i = i - 1;
	}
	if (ft_strchr(FLAGS, ' ') != NULL && ft_strchr(FLAGS, '+') == NULL)
	{
		final[i] = ' ';
		return (1);
	}
	if (ft_strchr(FLAGS, '+') != NULL)
	{
		final[i] = '+';
		return (1);
	}
	return (0);
}

static char		*fill_width_minus(char *txt, char *final, LEXEME)
{
	int i;

	i = 0;
	if (FLAGS != NULL && txt[0] != '-')
		i = s_p(final, lexeme);
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
	int		i;
	char	*tmp;

	i = 0;
	tmp = txt;
	while (i < size && WIDTH >= size)
	{
		if (FLAGS != NULL && ft_strchr(FLAGS, '0') != NULL && PREC == NULL)
		{
			if (txt[0] == '-')
			{
				final[i++] = '-';
				txt[0] = '0';
			}
			else
				final[i++] = '0';
		}
		else
			final[i++] = ' ';
	}
	while (i < WIDTH || (size > WIDTH && i < size))
		final[i++] = *(txt++);
	((FLAGS != NULL && tmp[0] != '-' &&
	final[0] != '-') ? s_p(final, lexeme) : 1);
	return (final);
}

char			*width_sig_int(char *txt, LEXEME, int size)
{
	char *final;

	final = ft_strnew(size);
	if (FLAGS != NULL && ft_strchr(FLAGS, '-') != NULL)
		final = fill_width_minus(txt, final, lexeme);
	else if (WIDTH > 0 && WIDTH >= size)
	{
		size = size - (int)ft_strlen(txt);
		final = fill_width(final, lexeme, txt, size);
	}
	else
		final = fill_width_minus(txt, final, lexeme);
	return (final);
}
