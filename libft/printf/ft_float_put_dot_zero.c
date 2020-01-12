/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float_put_dot_zero.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 02:06:41 by mcouto            #+#    #+#             */
/*   Updated: 2019/08/01 02:06:42 by mcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char		*fill_zero_dot(t_token *lexeme, int isize)
{
	char *before_dot;

	before_dot = NULL;
	if (FLAGS != NULL && ft_strchr(FLAGS, ' ') != NULL)
	{
		before_dot = ft_strnew(isize + 2);
		before_dot[0] = ' ';
		before_dot[1] = '0';
		before_dot[2] = '.';
	}
	else
	{
		before_dot = ft_strnew(isize + 1);
		before_dot[0] = '0';
		before_dot[isize] = '.';
	}
	return (before_dot);
}

char			*ft_before_dot_zero(t_token *lexeme, double nbr)
{
	char	*before_dot;
	int		isize;

	isize = ft_howmanydig((int)nbr);
	before_dot = NULL;
	if (PREC != NULL)
		before_dot = ft_precision_zero(lexeme, isize);
	if (WIDTH > 0)
		before_dot = ft_width_in_zero(lexeme, before_dot);
	if (before_dot == NULL)
		before_dot = fill_zero_dot(lexeme, isize);
	return (before_dot);
}

static char		*do_after_dot(int fsize, char *text)
{
	char *after_dot;

	after_dot = ft_strnew(fsize);
	after_dot = ft_strcpy(after_dot, (char*)text);
	after_dot = check_after_dot((char*)after_dot, fsize);
	return (after_dot);
}

char			*put_dot_0(const char *text, t_token *lexeme, double nbr)
{
	int		fsize;
	char	*precision;
	char	*before_dot;
	char	*after_dot;
	char	*final;

	before_dot = ft_before_dot_zero(lexeme, nbr);
	precision = NULL;
	after_dot = NULL;
	final = NULL;
	if (PREC != NULL)
	{
		precision = (char*)PREC;
		fsize = ft_atoi(&precision[1]);
	}
	else
		fsize = 6;
	if (fsize <= 0 && (FLAGS == NULL || ft_strchr(FLAGS, '#') == NULL))
		return (before_dot);
	after_dot = do_after_dot(fsize, (char*)text);
	final = ft_strjoin(before_dot, after_dot);
	ft_strdel(&before_dot);
	ft_strdel(&after_dot);
	return (final);
}
