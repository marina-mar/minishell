/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_get_type.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 11:30:53 by mcouto            #+#    #+#             */
/*   Updated: 2019/07/29 11:30:55 by mcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*organize_type(char *format, int how_many_type)
{
	char *type;
	char *tmp;

	type = ft_strnew(how_many_type);
	tmp = type;
	while (*format)
	{
		if (*format == 'h')
			*(type++) = *format;
		if (*format == 'l')
			*(type++) = *format;
		if (*format == 'L')
			*(type++) = *format;
		format++;
	}
	return (tmp);
}

int		ft_is_type(char *format)
{
	int type;

	type = 0;
	while (*format)
	{
		if (*format == 'h')
			type++;
		if (*format == 'l')
			type++;
		if (*format == 'L')
			type++;
		format++;
	}
	return (type);
}

char	*get_type(char *format, t_token *lexeme)
{
	int how_many;

	if ((how_many = ft_is_type(format)) > 0)
	{
		lexeme->type = organize_type(format, how_many);
		format = format + how_many;
	}
	return (format);
}
