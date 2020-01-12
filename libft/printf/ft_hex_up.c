/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_up.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 20:38:49 by mcouto            #+#    #+#             */
/*   Updated: 2019/08/01 04:28:29 by mcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int			deal_with_size(char *text, t_token *lexeme)
{
	int		size;
	int		txt;
	int		precision;
	char	*precision_str;

	precision_str = (char*)PREC;
	txt = (int)ft_strlen(text);
	precision = 0;
	if (PREC != NULL)
		precision = (int)ft_atoi(&precision_str[1]);
	if (WIDTH > precision && WIDTH > txt)
		size = WIDTH;
	else if (PREC != NULL && precision > WIDTH && precision > txt)
		size = precision;
	else
		size = txt;
	if ((text[0] != '0' && text[0] != ' ' && text[0] != '\0') &&
		FLAGS != NULL && ft_strchr(FLAGS, '#') != NULL && WIDTH < (txt + 2))
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

const char			*hex_up(t_token *lexeme, va_list arg)
{
	uintmax_t	nbr;
	char		*text;
	char		*final;
	int			size;
	int			precision;

	precision = how_much_precision(lexeme);
	nbr = deal_with_type(arg, lexeme);
	text = ft_itoabsu(nbr, 16, 'u');
	size = deal_with_size(text, lexeme);
	if (PREC != NULL && precision == 0)
		text = prec_zero(text, lexeme);
	if (PREC != NULL && precision > (int)ft_strlen(text))
		final = precision_hex_u(text, lexeme, size);
	else if (FLAGS != NULL || WIDTH == size)
		final = width_hex_u(text, lexeme, size);
	else
		final = ft_strdup(text);
	ft_strdel(&text);
	return (final);
}
