/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 01:08:35 by mcouto            #+#    #+#             */
/*   Updated: 2019/08/03 19:37:28 by mcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

#define IS_NULL lexeme->is_null

static int	ft_evaluator(const char *format, LEXEME, va_list arg)
{
	int i;

	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			if (ft_parser_pf((char*)&format[i + 1], lexeme, arg) == 0)
				return (1);
			break ;
		}
		i++;
	}
	return (0);
}

static int	fill_regular_buffer(char *buf, char *format, int j)
{
	buf[j] = *format;
	return (1);
}

static int	fill_buffer(char *buf, char *txt, t_token *lexeme, int j)
{
	int moves;
	int i;

	i = 0;
	moves = 0;
	if (txt != NULL)
	{
		moves = ft_strlen(txt) + IS_NULL;
		while (i < moves)
			buf[j++] = txt[i++];
		ft_strdel((char **)&txt);
	}
	else if (lexeme->conversion == '\0')
		buf = NULL;
	else
	{
		buf = ft_strcat(&buf[j], "(null)");
		moves = 6;
	}
	return (moves);
}

int			ft_buf(char *form, LEXEME, va_list arg, char *buf)
{
	char	*txt;
	int		j;

	txt = NULL;
	j = 0;
	while (*form)
	{
		if (*form == '%')
		{
			if (ft_evaluator(form, lexeme, arg) == 0)
				txt = (char*)ft_format(lexeme, arg);
			j = j + fill_buffer(buf, txt, lexeme, j);
			(lexeme->conversion == '%' ? form++ : form);
			while (lexeme->conversion != '\0' && *form != lexeme->conversion)
				form++;
			ft_clean_struct(lexeme);
		}
		else
			j = j + fill_regular_buffer(buf, form, j);
		form++;
	}
	return (j);
}
