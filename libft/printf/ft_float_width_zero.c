/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float_width_zero.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 02:31:49 by mcouto            #+#    #+#             */
/*   Updated: 2019/08/01 02:31:52 by mcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char	*fill_spaces(t_token *lexeme, char *space, int how_many_spaces)
{
	char *tmp;

	tmp = space;
	if (FLAGS != NULL && ft_strchr(FLAGS, '0') != NULL)
		while (how_many_spaces-- > 0)
			*(space++) = '0';
	else
		while (how_many_spaces-- > 0)
			*(space++) = ' ';
	return (tmp);
}

static int	check_spaces(t_token *lexeme, char *before_dot)
{
	char	*precision;
	int		prec;
	int		how_many_spaces;

	how_many_spaces = 0;
	precision = NULL;
	if (PREC != NULL)
	{
		precision = (char*)PREC;
		prec = ft_atoi(&precision[1]);
		if (WIDTH > (int)(prec + ft_strlen(before_dot)))
			how_many_spaces = WIDTH - (prec + ft_strlen(before_dot));
	}
	else if (WIDTH > (int)(6 + ft_strlen(before_dot)))
		how_many_spaces = WIDTH - (6 + ft_strlen(before_dot));
	return (how_many_spaces);
}

static char	*put_zero_dot(void)
{
	char *before_dot;

	before_dot = ft_strnew(2);
	before_dot[0] = '0';
	before_dot[1] = '.';
	return (before_dot);
}

char		*ft_width_in_zero(t_token *lexeme, char *before_dot)
{
	char	*space;
	char	*tmp;
	char	*final;
	int		how_many_spaces;

	space = NULL;
	final = NULL;
	if (before_dot == NULL)
		before_dot = put_zero_dot();
	how_many_spaces = check_spaces(lexeme, before_dot);
	space = ft_strnew(how_many_spaces);
	if (space != NULL)
	{
		space = fill_spaces(lexeme, space, how_many_spaces);
		tmp = before_dot;
		final = ft_strjoin(space, before_dot);
		ft_strdel(&space);
		ft_strdel(&tmp);
		return (final);
	}
	return (before_dot);
}
