/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float_before_dot.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 02:49:27 by mcouto            #+#    #+#             */
/*   Updated: 2019/08/01 02:52:13 by mcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char	*ft_width_no_prec(char *before_dot, t_token *lexeme, int isize)
{
	char	*final;
	char	*spaces;
	int		i;

	final = NULL;
	spaces = NULL;
	i = 0;
	spaces = ft_strnew(WIDTH - (6 + isize + 1));
	if (FLAGS != NULL && ft_strchr(FLAGS, '0') != NULL)
	{
		while (i < (WIDTH - (6 + isize + 1)))
			spaces[i++] = '0';
	}
	else
	{
		while (i < (WIDTH - (6 + isize + 1)))
			spaces[i++] = ' ';
	}
	final = ft_strjoin(spaces, before_dot);
	ft_strdel(&spaces);
	return (final);
}

static char	*no_width_or_prec(t_token *lexeme, int isize, char *text)
{
	char *before_dot;
	char *temp;
	char *space;

	before_dot = ft_strnew(isize + 1);
	before_dot = ft_strncpy(before_dot, (char*)text, isize);
	before_dot[isize] = '.';
	if (text[0] != '-' && FLAGS != NULL && ft_strchr(FLAGS, ' ') != NULL)
	{
		space = ft_strnew(1);
		space[0] = ' ';
		temp = before_dot;
		before_dot = ft_strjoin(space, before_dot);
		ft_strdel(&temp);
		ft_strdel(&space);
	}
	return (before_dot);
}

static char	*check_for_prec(t_token *lexeme, int isize, char *text)
{
	char	*precision;
	int		prec;
	int		size;
	char	*before_dot;

	precision = (char*)PREC;
	prec = ft_atoi(&precision[1]);
	before_dot = ft_precision(lexeme, isize, text);
	size = prec + isize;
	if (WIDTH > size && (FLAGS == NULL || ft_strchr(FLAGS, '-') == NULL))
		before_dot = ft_w_p(before_dot, prec, lexeme, isize);
	return (before_dot);
}

char		*ft_before_dot(t_token *lexeme, int isize, char *text)
{
	char	*before_dot;
	char	*temp;

	before_dot = NULL;
	temp = NULL;
	if (PREC != NULL)
		before_dot = check_for_prec(lexeme, isize, text);
	else if (WIDTH > (6 + isize) &&
		(FLAGS == NULL || ft_strchr(FLAGS, '-') == NULL))
	{
		before_dot = ft_strnew(isize + 1);
		before_dot = ft_strncpy(before_dot, (char*)text, isize);
		before_dot[isize] = '.';
		temp = before_dot;
		before_dot = ft_width_no_prec(before_dot, lexeme, isize);
		ft_strdel(&temp);
	}
	else
		before_dot = no_width_or_prec(lexeme, isize, text);
	return (before_dot);
}
