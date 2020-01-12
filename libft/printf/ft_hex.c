/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 23:40:22 by mcouto            #+#    #+#             */
/*   Updated: 2019/07/23 00:36:46 by mcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int			deal_with_size(char *text, t_token *lexeme)
{
	int		size;
	int		text_size;
	int		precision;
	char	*precision_str;

	precision_str = (char*)PREC;
	text_size = (int)ft_strlen(text);
	precision = 0;
	if (PREC != NULL)
		precision = (int)ft_atoi(&precision_str[1]);
	if (WIDTH > precision && WIDTH > text_size)
		size = WIDTH;
	else if (PREC != NULL && precision > WIDTH && precision > text_size)
		size = precision;
	else
		size = text_size;
	if ((text[0] != '0' && text[0] != ' ' && text[0] != '\0') &&
	FLAGS != NULL && ft_strchr(FLAGS, '#') != NULL && WIDTH < (text_size + 2))
		size = size + 2;
	return (size);
}

static uintmax_t	deal_with_type(va_list arguments, t_token *lexeme)
{
	long long int nbr;

	if (lexeme->type != NULL)
	{
		if (ft_strcmp(lexeme->type, "hh") == 0)
		{
			nbr = va_arg(arguments, uintmax_t);
			nbr = (unsigned char)nbr;
		}
		if (ft_strcmp(lexeme->type, "h") == 0)
		{
			nbr = va_arg(arguments, uintmax_t);
			nbr = (unsigned short int)nbr;
		}
		if (ft_strcmp(lexeme->type, "ll") == 0)
			nbr = va_arg(arguments, unsigned long long int);
		if (ft_strcmp(lexeme->type, "l") == 0)
			nbr = va_arg(arguments, unsigned long int);
	}
	else
		nbr = va_arg(arguments, unsigned int);
	return (nbr);
}

static char			*prec_zero(char *text, t_token *lexeme)
{
	if (text[0] == '0' && WIDTH > 0)
		text[0] = ' ';
	if (text[0] == '0' && WIDTH == 0)
		text[0] = '\0';
	return (text);
}

const char			*hex_low(t_token *lexeme, va_list arguments)
{
	uintmax_t	nbr;
	char		*text;
	char		*final;
	int			size;
	int			precision;

	precision = how_much_precision(lexeme);
	nbr = deal_with_type(arguments, lexeme);
	text = ft_itoabsu(nbr, 16, 'l');
	size = deal_with_size(text, lexeme);
	if (PREC != NULL && precision == 0)
		text = prec_zero(text, lexeme);
	if (PREC != NULL && precision > (int)ft_strlen(text))
		final = precision_hex(text, lexeme, size);
	else if (FLAGS != NULL || WIDTH == size)
		final = width_hex(text, lexeme, size);
	else
		final = ft_strdup(text);
	ft_strdel(&text);
	return (final);
}
