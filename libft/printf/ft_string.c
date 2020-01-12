/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 04:08:48 by mcouto            #+#    #+#             */
/*   Updated: 2019/08/03 19:41:30 by mcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char		*aply_precision(char *text, int precision)
{
	char *final;

	final = ft_strnew(precision);
	final = ft_strncpy(final, text, (size_t)precision);
	return (final);
}

int			clean_precision(const char *precision)
{
	int final;

	if (precision != NULL)
	{
		precision = precision + 1;
		final = ft_atoi((char *)precision);
	}
	else
		final = -1;
	return (final);
}

const char	*string(t_token *lexeme, va_list arguments)
{
	char	*text;
	char	*string;
	int		size;
	int		precision;
	int		has_to_clean;

	has_to_clean = 0;
	text = va_arg(arguments, char *);
	if (text == NULL)
		text = "(null)";
	precision = clean_precision(lexeme->precision);
	if (precision >= 0 && precision <= (int)ft_strlen(text))
	{
		text = aply_precision(text, precision);
		has_to_clean = 1;
	}
	if (lexeme->width > (int)ft_strlen(text) && lexeme->width > 0)
	{
		size = (lexeme->width);
		string = width_string(text, lexeme, size);
	}
	else
		string = ft_strdup(text);
	(has_to_clean == 1 ? ft_strdel(&text) : text);
	return (string);
}
