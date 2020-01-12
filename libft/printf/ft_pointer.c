/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 22:23:12 by mcouto            #+#    #+#             */
/*   Updated: 2019/07/22 19:59:38 by mcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char	*fill_width_minus(char *final, int width, char *text)
{
	int i;

	i = 0;
	while (*text)
	{
		final[i] = *text;
		text++;
		i++;
	}
	while (i < width)
	{
		final[i] = ' ';
		i++;
	}
	return (final);
}

static char	*fill_width(char *final, int width, char *text)
{
	int size;
	int i;

	i = 0;
	size = width - ft_strlen(text);
	while (i < size)
	{
		final[i] = ' ';
		i++;
	}
	while (i < width)
	{
		final[i] = *text;
		text++;
		i++;
	}
	return (final);
}

static char	*width_pointer(char *text, t_token *lexeme, int size)
{
	char *final;

	final = ft_strnew(size);
	if (FLAGS != NULL && ft_strchr(FLAGS, '-') != NULL)
		final = fill_width_minus(final, WIDTH, text);
	else
		final = fill_width(final, WIDTH, text);
	return (final);
}

char		*putzerox(char *text)
{
	char *zerox;
	char *final;

	zerox = "0x";
	final = ft_strjoin(zerox, text);
	ft_strdel(&text);
	return (final);
}

const char	*pointer(t_token *lexeme, va_list arguments)
{
	intmax_t	address_int;
	char		*text;
	char		*final;
	int			size;

	address_int = va_arg(arguments, intmax_t);
	text = ft_itoa_base(address_int, 16, 'l');
	text = precision_pointer(text, lexeme);
	text = putzerox(text);
	if (WIDTH > (int)ft_strlen(text)
		&& WIDTH > 0 && WIDTH > how_much_precision(lexeme))
	{
		size = WIDTH;
		final = width_pointer(text, lexeme, size);
	}
	else
		final = text;
	return (final);
}
