/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_width.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 02:39:01 by mcouto            #+#    #+#             */
/*   Updated: 2019/07/28 02:39:03 by mcouto           ###   ########.fr       */
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

char		*width_string(char *text, t_token *lexeme, int size)
{
	char *final;

	final = ft_strnew(size);
	if (lexeme->flags != NULL && ft_strchr(lexeme->flags, '-') != NULL)
		final = fill_width_minus(final, lexeme->width, text);
	else
		final = fill_width(final, lexeme->width, text);
	return (final);
}
