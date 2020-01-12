/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_oct_prec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 05:33:42 by mcouto            #+#    #+#             */
/*   Updated: 2019/07/27 05:33:44 by mcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char		*prec_minus(char *final, char *txt, int size, int zeros)
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

static char		*fill_prec(char *final, char *txt, int width_size, int zeros)
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

char			*precision_oct(char *txt, t_token *lexeme, int size)
{
	char	*final;
	int		precision;
	int		zeros;
	int		width_size;
	char	*precision_str;

	final = ft_strnew(size);
	precision_str = (char*)PREC;
	precision = (int)ft_atoi(&precision_str[1]);
	zeros = precision - (int)ft_strlen(txt);
	width_size = WIDTH - precision;
	if (FLAGS != NULL && ft_strchr(FLAGS, '-') != NULL)
		final = prec_minus(final, txt, size, zeros);
	else
		final = fill_prec(final, txt, width_size, zeros);
	return (final);
}
