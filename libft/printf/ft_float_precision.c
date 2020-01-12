/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float_precision.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 02:54:23 by mcouto            #+#    #+#             */
/*   Updated: 2019/08/01 02:54:26 by mcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char	*before_dot_prec(int isize, t_token *lexeme, char *text)
{
	char	*before_dot;
	char	*precision;
	int		prec;

	precision = (char*)PREC;
	prec = ft_atoi(&precision[1]);
	if (prec <= 0 && (FLAGS == NULL || ft_strchr(FLAGS, '#') == NULL))
	{
		before_dot = ft_strnew(isize);
		before_dot = ft_strncpy(before_dot, (char*)text, (isize));
	}
	else
	{
		before_dot = ft_strnew(isize + 1);
		before_dot = ft_strncpy(before_dot, (char*)text, isize);
		before_dot[isize] = '.';
	}
	return (before_dot);
}

char		*ft_precision(t_token *lexeme, int isize, char *text)
{
	char	*before_dot;
	char	*tmp;
	char	*space;

	before_dot = NULL;
	tmp = NULL;
	space = NULL;
	before_dot = before_dot_prec(isize, lexeme, text);
	if (FLAGS != NULL && ft_strchr(FLAGS, ' ') != NULL)
	{
		tmp = before_dot;
		space = ft_strnew(1);
		space[0] = ' ';
		before_dot = ft_strjoin(space, before_dot);
		ft_strdel(&tmp);
		ft_strdel(&space);
	}
	return (before_dot);
}
