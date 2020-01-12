/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_up_prec.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 02:15:53 by mcouto            #+#    #+#             */
/*   Updated: 2019/07/28 02:15:56 by mcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

#define CHECK_FIRST_CHAR text[0] != '\0' && text[0] != ' ' && text[0] != '0'

static char			*fill_prec_minus(char *text, int size, LEXEME, int zeros)
{
	int		i;
	char	*final;

	i = 0;
	final = ft_strnew(size);
	if ((CHECK_FIRST_CHAR) && FLAGS != NULL && IS_HASHTAG)
	{
		final[i] = '0';
		final[i + 1] = 'X';
		i = i + 2;
	}
	while (zeros > 0)
	{
		final[i++] = '0';
		zeros--;
	}
	while (*text)
		final[i++] = *(text++);
	while (i < size)
		final[i++] = ' ';
	return (final);
}

static char			*fill_precision(char *final, char *text, int zeros, LEXEME)
{
	int i;
	int how_many_width;

	i = 0;
	how_many_width = WIDTH - how_much_precision(lexeme);
	if ((CHECK_FIRST_CHAR) && FLAGS != NULL && IS_HASHTAG)
		how_many_width = how_many_width - 2;
	while (i < how_many_width)
		final[i++] = ' ';
	if ((CHECK_FIRST_CHAR) && FLAGS != NULL && IS_HASHTAG)
	{
		final[i] = '0';
		final[i + 1] = 'X';
		i = i + 2;
	}
	while (zeros > 0)
	{
		final[i++] = '0';
		zeros--;
	}
	while (*text)
		final[i++] = *(text++);
	return (final);
}

char				*precision_hex_u(char *text, t_token *lexeme, int size)
{
	char	*final;
	char	*tmp;
	int		precision;
	int		zeros;
	int		text_size;

	final = ft_strnew(size);
	text_size = (int)ft_strlen(text);
	precision = how_much_precision(lexeme);
	zeros = precision - text_size;
	if (lexeme->flags != NULL && ft_strchr(lexeme->flags, '-') != NULL)
	{
		tmp = final;
		final = fill_prec_minus(text, size, lexeme, zeros);
		ft_strdel(&tmp);
	}
	else
		final = fill_precision(final, text, zeros, lexeme);
	return (final);
}
