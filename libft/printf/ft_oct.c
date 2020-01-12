/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_oct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 20:01:10 by mcouto            #+#    #+#             */
/*   Updated: 2019/07/23 02:55:54 by mcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int		deal_with_size(char *txt, t_token *lexeme)
{
	int		size;
	int		txt_size;
	int		precision;
	char	*precision_str;

	precision_str = (char*)PREC;
	txt_size = (int)ft_strlen(txt);
	precision = 0;
	if (PREC != NULL)
		precision = (int)ft_atoi(&precision_str[1]);
	if (WIDTH > precision && WIDTH > txt_size)
		size = WIDTH;
	else if (PREC != NULL && precision > WIDTH && precision > txt_size)
		size = precision;
	else if (lexeme->flags != NULL &&
			ft_strchr(FLAGS, '#') != NULL && NOT_ZERO_FLAG &&
			WIDTH == 0 && txt[0] != '0')
		size = txt_size + 1;
	else
		size = txt_size;
	return (size);
}

static intmax_t	deal_with_type(va_list arguments, t_token *lexeme)
{
	uintmax_t nbr;

	nbr = 0;
	if (TYPE != NULL)
	{
		if (ft_strcmp(TYPE, "hh") == 0)
		{
			nbr = va_arg(arguments, uintmax_t);
			nbr = (unsigned char)nbr;
		}
		if (ft_strcmp(TYPE, "h") == 0)
		{
			nbr = va_arg(arguments, uintmax_t);
			nbr = (unsigned short int)nbr;
		}
		if (ft_strcmp(TYPE, "ll") == 0)
			nbr = va_arg(arguments, unsigned long long int);
		if (ft_strcmp(TYPE, "l") == 0)
			nbr = va_arg(arguments, unsigned long int);
	}
	else
		nbr = va_arg(arguments, unsigned int);
	return (nbr);
}

static void		ft_prec_zero(char **txt, t_token *lexeme)
{
	if (*txt[0] == '0' && WIDTH > 0)
		*txt[0] = ' ';
	if (*txt[0] == '0' && WIDTH == 0)
		*txt[0] = '\0';
}

static int		check_precision(t_token *lexeme, char **txt)
{
	int		precision;
	char	*precision_str;

	if (PREC != NULL)
	{
		precision_str = (char*)PREC;
		precision = (int)ft_atoi(&precision_str[1]);
		if (precision == 0)
		{
			ft_prec_zero(txt, lexeme);
		}
	}
	else
		precision = -1;
	return (precision);
}

const char		*oct(t_token *lexeme, va_list arguments)
{
	uintmax_t	nbr;
	char		*txt;
	char		*final;
	int			size;
	int			precision;

	nbr = deal_with_type(arguments, lexeme);
	txt = ft_itoabsu(nbr, 8, 'l');
	size = deal_with_size(txt, lexeme);
	precision = check_precision(lexeme, &txt);
	if (PREC != NULL && precision > (int)ft_strlen(txt))
		final = precision_oct(txt, lexeme, size);
	else if (FLAGS != NULL || WIDTH == size)
		final = width_oct(txt, lexeme, size);
	else
		final = ft_strdup(txt);
	ft_strdel(&txt);
	return (final);
}
