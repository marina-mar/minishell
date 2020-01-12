/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uns_dec_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 22:36:54 by mcouto            #+#    #+#             */
/*   Updated: 2019/07/22 23:15:44 by mcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int			deal_with_size(char *txt, t_token *lexeme)
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
	else
		size = txt_size;
	return (size);
}

static uintmax_t	deal_with_type(uintmax_t nbr, LEXEME)
{
	if (TYPE != NULL)
	{
		if (ft_strcmp(TYPE, "hh") == 0)
			nbr = (unsigned char)nbr;
		if (ft_strcmp(TYPE, "h") == 0)
			nbr = (unsigned short int)nbr;
		if (ft_strcmp(TYPE, "ll") == 0)
			nbr = (unsigned long long int)nbr;
		if (ft_strcmp(TYPE, "l") == 0)
			nbr = (unsigned long int)nbr;
	}
	else
		nbr = (unsigned int)nbr;
	return (nbr);
}

static void			ft_prec_zero(char **txt, LEXEME)
{
	if (*txt[0] == '0' && WIDTH > 0)
		*txt[0] = ' ';
	if (*txt[0] == '0' && WIDTH == 0)
		*txt[0] = '\0';
}

static int			check_precision(LEXEME, char **txt)
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

const char			*uns_dec_i(LEXEME, va_list arguments)
{
	uintmax_t	nbr;
	char		*txt;
	char		*final;
	int			size;
	int			precision;

	nbr = va_arg(arguments, uintmax_t);
	nbr = deal_with_type(nbr, lexeme);
	txt = ft_itoabsu(nbr, 10, 'l');
	size = deal_with_size(txt, lexeme);
	precision = check_precision(lexeme, &txt);
	if (PREC != NULL && precision > (int)ft_strlen(txt))
		final = precision_u_int(txt, lexeme, size);
	else if (FLAGS != NULL || WIDTH == size)
		final = width_uns_int(txt, lexeme, size);
	else
		final = txt;
	return (final);
}
