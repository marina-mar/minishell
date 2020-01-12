/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer_prec.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 03:54:05 by mcouto            #+#    #+#             */
/*   Updated: 2019/07/28 03:54:57 by mcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char	*deal_with_precision(char *text, t_token *lexeme, int precision)
{
	char	*new;
	char	*tmp;
	int		size;
	int		i;

	size = (int)ft_strlen(text);
	i = 0;
	if (precision > 0 && precision > WIDTH)
	{
		new = ft_strnew(precision - size);
		while (i < (precision - size))
		{
			new[i] = '0';
			i++;
		}
		tmp = new;
		new = ft_strjoin(new, text);
		ft_strdel(&tmp);
		ft_strdel(&text);
		return (new);
	}
	return (text);
}

static char	*precision_for_zero(char *text, int precision)
{
	char	*new;
	char	*tmp;
	int		i;

	i = 0;
	tmp = text;
	if (precision == 0)
		text[0] = '\0';
	if (precision > 0)
	{
		new = ft_strnew(precision);
		while (i < precision)
		{
			new[i] = '0';
			i++;
		}
		text = new;
		ft_strdel(&tmp);
	}
	return (text);
}

char		*precision_pointer(char *text, t_token *lexeme)
{
	int precision;

	if (PREC != NULL)
	{
		precision = how_much_precision(lexeme);
		if (text[0] == '0')
			text = precision_for_zero(text, precision);
		else
			text = deal_with_precision(text, lexeme, precision);
	}
	return (text);
}
