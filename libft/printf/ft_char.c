/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 00:27:40 by mcouto            #+#    #+#             */
/*   Updated: 2019/07/22 20:54:53 by mcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char		*fill_width_minus(char *final, int width, int text)
{
	int	i;

	i = 1;
	final[0] = text;
	while (i < width)
	{
		final[i] = ' ';
		i++;
	}
	return (final);
}

char		*fill_width(char *final, int width, int text)
{
	int	i;

	i = 0;
	while (i < (width - 1))
	{
		final[i] = ' ';
		i++;
	}
	final[i] = text;
	return (final);
}

const char	*charac(t_token *lexeme, va_list arguments)
{
	const char	*final;
	char		text;
	int			size;

	size = 0;
	text = va_arg(arguments, unsigned int);
	if (text == 0)
	{
		lexeme->is_null = 1;
		text = '\0';
	}
	if (lexeme->width > 0)
		size = (lexeme->width);
	if (lexeme->width == 0)
		size = 1;
	final = ft_strnew(size);
	if (lexeme->width >= 0)
	{
		if (lexeme->flags != NULL && ft_strchr(lexeme->flags, '-') != NULL)
			final = fill_width_minus((char*)final, lexeme->width, text);
		else
			final = fill_width((char*)final, lexeme->width, text);
	}
	return (final);
}
