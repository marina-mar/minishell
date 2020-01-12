/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_get_width.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 11:31:03 by mcouto            #+#    #+#             */
/*   Updated: 2019/07/29 11:31:04 by mcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_is_width(char *format)
{
	int how_many_digits;

	how_many_digits = 0;
	if (*format == '*')
		return (1);
	while (ft_isdigit((int)*format) == 1)
	{
		how_many_digits++;
		format++;
	}
	return (how_many_digits);
}

int		organize_width(char *format, int how_many_dig, va_list arg)
{
	char	*num;
	char	*tmp;
	int		final;

	num = ft_strnew(how_many_dig);
	tmp = num;
	if (*format == '*')
	{
		ft_strdel(&tmp);
		return (va_arg(arg, int));
	}
	while (ft_isdigit((int)*format) == 1)
	{
		*num = *format;
		num++;
		format++;
	}
	final = (int)ft_atoi(tmp);
	ft_strdel(&tmp);
	return (final);
}

char	*get_width(char *format, t_token *lexeme, va_list arg)
{
	int how_many;

	if ((how_many = ft_is_width(format)) > 0)
	{
		lexeme->width = organize_width(format, how_many, arg);
		format = format + how_many;
	}
	return (format);
}
