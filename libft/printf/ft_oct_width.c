/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_oct_width.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 05:39:23 by mcouto            #+#    #+#             */
/*   Updated: 2019/07/27 05:39:25 by mcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char		*fill_width_minus(char *txt, char *final, t_token *lexeme)
{
	int i;

	i = 0;
	if (FLAGS != NULL && IS_HASHTAG)
	{
		final[i] = '0';
		i++;
	}
	while (*txt)
	{
		final[i] = *txt;
		txt++;
		i++;
	}
	while (i < WIDTH)
	{
		final[i] = ' ';
		i++;
	}
	return (final);
}

static char		*fill_width(char *final, t_token *lexeme, char *txt, int size)
{
	int i;
	int are_zeros;

	i = -1;
	are_zeros = 0;
	while (++i < size && WIDTH >= size)
	{
		if (FLAGS != NULL && ft_strchr(FLAGS, '0') != NULL && PREC == NULL)
		{
			final[i] = '0';
			are_zeros = 1;
		}
		else
			final[i] = ' ';
	}
	if (are_zeros == 0 && FLAGS != NULL && IS_HASHTAG && txt[0] != '0')
	{
		if (i > 0)
			i = i - 1;
		final[i++] = '0';
	}
	while ((i < WIDTH || (size > WIDTH && i < size)))
		final[i++] = *(txt++);
	return (final);
}

char			*width_oct(char *txt, t_token *lexeme, int size)
{
	char *final;

	final = ft_strnew(size);
	if (FLAGS != NULL && IS_HASHTAG && WIDTH == (size + 1))
		size = size - 1;
	if (FLAGS != NULL && ft_strchr(FLAGS, '-') != NULL)
		final = fill_width_minus(txt, final, lexeme);
	else if (WIDTH > 0)
	{
		size = size - (int)ft_strlen(txt);
		final = fill_width(final, lexeme, txt, size);
	}
	else
	{
		final = fill_width(final, lexeme, txt, size);
		return (final);
	}
	return (final);
}
