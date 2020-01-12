/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_get_prec.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 11:31:15 by mcouto            #+#    #+#             */
/*   Updated: 2019/07/29 11:31:17 by mcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*organize_precision(char *format, int how_many_precision, va_list arg)
{
	char *precision;
	char *tmp;
	char *txt;

	precision = ft_strnew(how_many_precision);
	tmp = precision;
	if (*format == '.')
	{
		*precision = *format;
		precision++;
		format++;
	}
	if (*format == '*')
	{
		ft_strdel(&tmp);
		txt = ft_itoa(va_arg(arg, int));
		return (ft_strjoin(".", txt));
	}
	while (ft_isdigit((int)*format) == 1)
	{
		*precision = *format;
		precision++;
		format++;
	}
	return (tmp);
}

int		ft_is_precision(char *format)
{
	int how_many_precision;

	how_many_precision = 0;
	if (*format == '.')
	{
		how_many_precision++;
		format++;
	}
	else
		return (0);
	if (*format == '*')
		return (2);
	while (ft_isdigit((int)*format) == 1)
	{
		how_many_precision++;
		format++;
	}
	return (how_many_precision);
}

char	*get_prec(char *format, t_token *lexeme, va_list arg)
{
	int how_many;

	if ((how_many = ft_is_precision(format)) > 0)
	{
		lexeme->precision = organize_precision(format, how_many, arg);
		format = format + how_many;
	}
	return (format);
}
