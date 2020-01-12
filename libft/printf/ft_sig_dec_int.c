/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sig_dec_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 04:18:38 by mcouto            #+#    #+#             */
/*   Updated: 2019/07/23 02:11:56 by mcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int				size_plus_spc(int size, LEXEME, char *txt)
{
	if (txt[0] != '-' && FLAGS != NULL)
	{
		if (ft_strchr(FLAGS, '+') != NULL && ft_strchr(FLAGS, ' ') == NULL)
			size++;
		if (ft_strchr(FLAGS, ' ') != NULL)
			size++;
	}
	return (size);
}

int				deal_with_size(char *txt, t_token *lexeme)
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
	{
		size = precision;
		if (txt[0] == '-')
			size = size + 1;
	}
	else
		size = txt_size;
	if ((PREC != NULL && precision > WIDTH) || size == txt_size)
		size = size_plus_spc(size, lexeme, txt);
	return (size);
}

static intmax_t	deal_with_type(LEXEME, va_list arguments)
{
	signed long long nbr;

	if (TYPE != NULL)
	{
		if (ft_strcmp(TYPE, "hh") == 0)
		{
			nbr = va_arg(arguments, int);
			nbr = (char)nbr;
		}
		if (ft_strcmp(TYPE, "h") == 0)
		{
			nbr = va_arg(arguments, int);
			nbr = (short int)nbr;
		}
		if (ft_strcmp(TYPE, "ll") == 0)
			nbr = va_arg(arguments, long long int);
		if (ft_strcmp(TYPE, "l") == 0)
			nbr = va_arg(arguments, long int);
	}
	else
		nbr = va_arg(arguments, int);
	return (nbr);
}

static int		check_precision(LEXEME, char *txt)
{
	int		precision;
	char	*precision_str;

	if (PREC != NULL)
	{
		precision_str = (char*)PREC;
		precision = (int)ft_atoi(&precision_str[1]);
		if (precision == 0)
		{
			if (txt[0] == '0' && WIDTH > 0)
				txt[0] = ' ';
			if (txt[0] == '0' && WIDTH == 0)
				txt[0] = '\0';
		}
	}
	else
		precision = -1;
	return (precision);
}

const char		*sig_dec_i(LEXEME, va_list arguments)
{
	signed long long	nbr;
	char				*txt;
	char				*final;
	int					size;
	int					prec;

	if (TYPE != NULL && ft_strcmp(TYPE, "L") == 0)
		return (NULL);
	nbr = deal_with_type(lexeme, arguments);
	txt = ft_itoa(nbr);
	size = deal_with_size(txt, lexeme);
	prec = check_precision(lexeme, txt);
	if (PREC != NULL && ((txt[0] == '-' &&
	prec > ((int)ft_strlen(txt) - 1)) || (prec > ((int)ft_strlen(txt)))))
		final = precision_sig_int(txt, lexeme, size);
	else if (FLAGS != NULL || WIDTH == size)
		final = width_sig_int(txt, lexeme, size);
	else
		final = ft_strdup(txt);
	ft_strdel(&txt);
	return (final);
}
