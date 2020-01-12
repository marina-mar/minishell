/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_up_width.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 02:11:33 by mcouto            #+#    #+#             */
/*   Updated: 2019/07/28 02:11:34 by mcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

#define CHECK_FIRST_CHAR text[0] != '\0' && text[0] != ' ' && text[0] != '0'

static char			*fill_width_minus(char *text, char *final, LEXEME)
{
	int i;

	i = 0;
	if ((CHECK_FIRST_CHAR) && FLAGS != NULL && IS_HASHTAG)
	{
		final[i] = '0';
		final[i + 1] = 'X';
		i = i + 2;
	}
	while (*text)
	{
		final[i] = *text;
		text++;
		i++;
	}
	while (i < WIDTH)
	{
		final[i] = ' ';
		i++;
	}
	return (final);
}

static int			deal_with_hashtag(char **final, LEXEME, int size)
{
	int i;

	i = 0;
	if (FLAGS != NULL && IS_ZERO_FLAG)
	{
		final[0][i] = '0';
		final[0][i + 1] = 'X';
		i = i + 2;
		while (i < size && WIDTH > 0)
			final[0][i++] = '0';
	}
	else
	{
		while (i < (size - 2) && WIDTH > 0)
		{
			final[0][i] = ' ';
			i++;
		}
		final[0][i] = '0';
		final[0][i + 1] = 'X';
		i = i + 2;
	}
	return (i);
}

static char			*fill_width(char *final, LEXEME, char *text, int size)
{
	int i;

	i = 0;
	if ((CHECK_FIRST_CHAR) && FLAGS != NULL && IS_HASHTAG)
		i = deal_with_hashtag(&final, lexeme, size);
	else
	{
		while (i < size && WIDTH > 0)
		{
			if (FLAGS != NULL && IS_ZERO_FLAG && PREC == NULL)
				final[i] = '0';
			else
				final[i] = ' ';
			i++;
		}
	}
	while (i < WIDTH || (size > WIDTH && i < size))
	{
		final[i] = *text;
		text++;
		i++;
	}
	return (final);
}

char				*width_hex_u(char *text, LEXEME, int size)
{
	char *final;

	final = ft_strnew(size);
	if (lexeme->flags != NULL && ft_strchr(lexeme->flags, '-') != NULL)
		final = fill_width_minus(text, final, lexeme);
	else if (WIDTH > 0)
	{
		size = size - (int)ft_strlen(text);
		final = fill_width(final, lexeme, text, size);
	}
	else
	{
		final = fill_width(final, lexeme, text, size);
		return (final);
	}
	return (final);
}
