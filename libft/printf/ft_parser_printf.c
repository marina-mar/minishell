/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_printf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 22:31:29 by mcouto            #+#    #+#             */
/*   Updated: 2019/07/22 21:41:11 by mcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	ft_is_conv(char *format)
{
	while (*format)
	{
		if (*format == 'c' || *format == 's' || *format == 'p')
			return (*format);
		if (*format == 'd' || *format == 'i' || *format == '%')
			return (*format);
		if (*format == 'o' || *format == 'u' || *format == 'B')
			return (*format);
		if (*format == 'x' || *format == 'X' || *format == 'M')
			return (*format);
		if (*format == 'f' || *format == '%' || *format == 'Y')
			return (*format);
		if (*format == 'G' || *format == 'R' || *format == 'b')
			return (*format);
		if (*format == 'E' || *format == 'I' || *format == 'C')
			return (*format);
		format++;
	}
	return (0);
}

char	*make_format(char *original, char conversion)
{
	int		i;
	int		j;
	char	*final;

	j = 0;
	i = 0;
	while (original[i] != conversion)
		i++;
	if (i == 0)
		final = ft_strnew(1);
	else
		final = ft_strnew(i + 1);
	while (j <= i)
	{
		final[j] = original[j];
		j++;
	}
	return (final);
}

int		ft_checker(t_token *lexeme, char *format, va_list arg)
{
	int okay;

	okay = 0;
	while (*format != lexeme->conversion)
	{
		format = get_flags(format, lexeme);
		format = get_width(format, lexeme, arg);
		format = get_prec(format, lexeme, arg);
		format = get_type(format, lexeme);
		if (*format != lexeme->conversion)
		{
			okay = 1;
			break ;
		}
	}
	return (okay);
}

int		ft_parser_pf(char *original, t_token *lexeme, va_list arg)
{
	int		okay;
	char	*format;

	okay = 0;
	if (!(lexeme->conversion = ft_is_conv(original)))
		return (0);
	if (lexeme->conversion == 'B' || lexeme->conversion == 'M' ||
		lexeme->conversion == 'Y' || lexeme->conversion == 'R' ||
		lexeme->conversion == 'G' || lexeme->conversion == 'E' ||
		lexeme->conversion == 'I' || lexeme->conversion == 'C')
		return (1);
	format = make_format(original, lexeme->conversion);
	okay = ft_checker(lexeme, format, arg);
	ft_strdel(&format);
	if (okay == 1)
		return (0);
	return (1);
}
