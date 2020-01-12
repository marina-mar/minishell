/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 18:19:34 by mcouto            #+#    #+#             */
/*   Updated: 2019/07/22 21:53:01 by mcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../includes/conversions.h"

static char		*ft_width(char *final, t_token *lexeme)
{
	int i;

	i = 0;
	if (lexeme->flags != NULL && ft_strchr(lexeme->flags, '0') != NULL)
	{
		while (i < (lexeme->width - 1))
		{
			final[i] = '0';
			i++;
		}
		final[lexeme->width - 1] = '%';
	}
	else
	{
		while (i < (lexeme->width - 1))
		{
			final[i] = ' ';
			i++;
		}
		final[lexeme->width - 1] = '%';
	}
	return (final);
}

static char		*ft_width_minus(char *final, t_token *lexeme)
{
	int i;

	i = 1;
	final[0] = '%';
	while (i < lexeme->width)
	{
		final[i] = ' ';
		i++;
	}
	return (final);
}

const char		*porcentage(t_token *lexeme)
{
	char	*final;
	int		size;

	size = 1;
	if (lexeme->width > 0)
	{
		size = lexeme->width;
		final = ft_strnew(size);
		if (lexeme->flags == NULL || ft_strchr(lexeme->flags, '-') == NULL)
			final = ft_width(final, lexeme);
		else
			final = ft_width_minus(final, lexeme);
	}
	else
	{
		final = ft_strnew(size);
		final[0] = '%';
	}
	return (final);
}

const char		*ft_format(t_token *lexeme, va_list arguments)
{
	int						i;
	const char				*final;

	final = NULL;
	i = -1;
	while (++i < 11)
		if (CONV[i] == lexeme->conversion)
			final = g_convert[i](lexeme, arguments);
	if (CONVERSION == 'B' || CONVERSION == 'M' || CONVERSION == 'E' ||
		CONVERSION == 'Y' || CONVERSION == 'R' || CONVERSION == 'G' ||
		CONVERSION == 'I' || CONVERSION == 'C')
		final = print_colors(CONVERSION);
	return (lexeme->conversion == '%' ? porcentage(lexeme) : final);
}
