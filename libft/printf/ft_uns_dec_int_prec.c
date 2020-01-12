/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uns_dec_int_prec.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 04:32:54 by mcouto            #+#    #+#             */
/*   Updated: 2019/07/27 04:33:13 by mcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char	*p_minus(char *final, char *txt, int size, int zeros)
{
	int i;

	i = 0;
	while (zeros > 0)
	{
		final[i] = '0';
		i++;
		zeros--;
	}
	while (*txt)
	{
		final[i] = *txt;
		txt++;
		i++;
	}
	while (i < size)
	{
		final[i] = ' ';
		i++;
	}
	return (final);
}

static char	*prec(char *final, char *txt, int width_size, int zeros)
{
	int i;

	i = 0;
	while (i < width_size)
	{
		final[i] = ' ';
		i++;
	}
	while (zeros > 0)
	{
		final[i] = '0';
		zeros--;
		i++;
	}
	while (*txt)
	{
		final[i] = *txt;
		txt++;
		i++;
	}
	return (final);
}

static int	get_precision(t_token *lexeme)
{
	char	*precision_str;
	int		precision;

	precision = -1;
	if (PREC != NULL)
	{
		precision_str = (char*)PREC;
		precision = (int)ft_atoi(&precision_str[1]);
	}
	return (precision);
}

char		*precision_u_int(char *txt, LEXEME, int size)
{
	char	*final;
	int		precision;
	int		zeros;
	int		width_size;
	int		txt_size;

	final = ft_strnew(size);
	txt_size = (int)ft_strlen(txt);
	precision = get_precision(lexeme);
	zeros = precision - txt_size;
	width_size = WIDTH - precision;
	if (FLAGS != NULL && ft_strchr(FLAGS, '-') != NULL)
		final = p_minus(final, txt, size, zeros);
	else
		final = prec(final, txt, width_size, zeros);
	return (final);
}
