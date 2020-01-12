/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sig_dec_int_prec.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 05:15:17 by mcouto            #+#    #+#             */
/*   Updated: 2019/08/03 19:38:31 by mcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int		deal_with_spc_plus(char **final, LEXEME, char *txt)
{
	int i;

	i = 0;
	if (txt[0] == '-' && ft_strchr(FLAGS, '-') != NULL)
	{
		*final[0] = '-';
		return (1);
	}
	if (ft_strchr(FLAGS, ' ') != NULL && ft_strchr(FLAGS, '+') == NULL &&
	(txt[0] != '-' || ft_strchr(FLAGS, '-') == NULL))
	{
		*final[i] = ' ';
		return (1);
	}
	if (ft_strchr(FLAGS, '+') != NULL && (txt[0] != '-' ||
		ft_strchr(FLAGS, '-') == NULL))
	{
		*final[i] = '+';
		return (1);
	}
	return (0);
}

static char		*fill_prec_minus(char *final, LEXEME, char *txt, int size)
{
	int i;
	int how_many_zeros;
	int txt_size;
	int precision;

	i = 0;
	precision = how_much_precision(lexeme);
	txt_size = ft_strlen(txt);
	if (txt[0] == '-')
		how_many_zeros = precision - (txt_size - 1);
	else
		how_many_zeros = precision - txt_size;
	if (FLAGS != NULL)
		i = deal_with_spc_plus(&final, lexeme, txt);
	while (how_many_zeros > 0)
	{
		final[i++] = '0';
		how_many_zeros--;
	}
	(txt[0] == '-') ? txt++ : txt;
	while (*txt)
		final[i++] = *(txt++);
	while (i < size)
		final[i++] = ' ';
	return (final);
}

static int		put_zeros(char **txt, char **final, int how_many_zeros, int i)
{
	while (how_many_zeros > 0)
	{
		if (*txt[0] == '-')
		{
			how_many_zeros = how_many_zeros - 1;
			final[0][i] = '-';
			txt[0][0] = '0';
			i++;
		}
		else
		{
			final[0][i] = '0';
			how_many_zeros--;
			i++;
		}
	}
	return (i);
}

static char		*fill_prec(char *final, LEXEME, char *txt, int how_many_width)
{
	int		i;
	int		how_many_zeros;
	char	*tmp;

	i = 0;
	if (txt[0] == '-')
		how_many_zeros = how_much_precision(lexeme) - (ft_strlen(txt) - 1);
	else
		how_many_zeros = how_much_precision(lexeme) - ft_strlen(txt);
	while (i < how_many_width)
		final[i++] = ' ';
	if (txt[0] != '-' && FLAGS != NULL &&
		(ft_strchr(FLAGS, ' ') || ft_strchr(FLAGS, '+')))
	{
		if (how_many_width > 0 && ft_strlen(txt) >= 1)
			i = i - 1;
		tmp = &final[i];
		if ((deal_with_spc_plus(&tmp, lexeme, txt)) == 1)
			i++;
	}
	i = put_zeros(&txt, &final, how_many_zeros, i);
	while (*txt)
		final[i++] = *(txt++);
	return (final);
}

char			*precision_sig_int(char *txt, LEXEME, int size)
{
	char	*final;
	int		precision;
	int		how_many_width;

	final = ft_strnew(size);
	precision = how_much_precision(lexeme);
	if (txt[0] == '-')
		how_many_width = WIDTH - (precision + 1);
	else
		how_many_width = WIDTH - precision;
	if ((txt[0] != '-' || WIDTH > precision) &&
		FLAGS != NULL && ft_strchr(FLAGS, '-') != NULL)
		final = fill_prec_minus(final, lexeme, txt, size);
	else
		final = fill_prec(final, lexeme, txt, how_many_width);
	return (final);
}
