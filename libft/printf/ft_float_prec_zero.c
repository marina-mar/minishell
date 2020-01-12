/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float_prec_zero.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 02:27:19 by mcouto            #+#    #+#             */
/*   Updated: 2019/08/01 02:27:22 by mcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char	*flag_space(int isize)
{
	char *before_dot;

	before_dot = ft_strnew(isize + 2);
	before_dot[0] = ' ';
	before_dot[1] = '0';
	before_dot[2] = '.';
	return (before_dot);
}

static char	*zero_no_flags(t_token *lexeme, int isize)
{
	char *before_dot;

	before_dot = NULL;
	if (FLAGS != NULL && ft_strchr(FLAGS, ' ') != NULL)
	{
		before_dot = ft_strnew(isize + 1);
		before_dot[0] = ' ';
		before_dot[1] = '0';
	}
	else
	{
		before_dot = ft_strnew(isize);
		before_dot[0] = '0';
	}
	return (before_dot);
}

char		*ft_precision_zero(t_token *lexeme, int isize)
{
	char	*precision;
	char	*before_dot;
	int		prec;

	precision = NULL;
	if (PREC != NULL)
	{
		precision = (char*)PREC;
		prec = ft_atoi(&precision[1]);
	}
	if (PREC != NULL && prec <= 0 && (FLAGS == NULL ||
		ft_strchr(FLAGS, '#') == NULL))
		before_dot = zero_no_flags(lexeme, isize);
	else
	{
		if (FLAGS != NULL && ft_strchr(FLAGS, ' ') != NULL)
			before_dot = flag_space(isize);
		else
		{
			before_dot = ft_strnew(isize + 1);
			before_dot[0] = '0';
			before_dot[isize] = '.';
		}
	}
	return (before_dot);
}
