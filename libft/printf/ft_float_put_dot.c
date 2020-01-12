/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_dot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 02:43:03 by mcouto            #+#    #+#             */
/*   Updated: 2019/08/01 02:43:39 by mcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char		*ft_width_minus(char *after_dot, LEXEME, char *before_dot)
{
	char	*final;
	char	*spaces;
	int		size;
	int		i;

	spaces = NULL;
	final = NULL;
	i = 0;
	size = ft_strlen(after_dot) + ft_strlen(before_dot);
	spaces = ft_strnew(WIDTH - size);
	while (i < (WIDTH - size))
	{
		spaces[i] = ' ';
		i++;
	}
	final = ft_strjoin(after_dot, spaces);
	ft_strdel(&after_dot);
	ft_strdel(&spaces);
	return (final);
}

char			*check_after_dot(char *after_dot, int fsize)
{
	int i;

	i = 0;
	while (i < fsize)
	{
		if ((char)after_dot[i] == '\0')
			after_dot[i] = '0';
		i++;
	}
	return (after_dot);
}

static int		float_size(char *precision)
{
	int fsize;

	if (precision != NULL)
	{
		precision = (char*)precision;
		fsize = ft_atoi(&precision[1]);
	}
	else
		fsize = 6;
	return (fsize);
}

char			*put_dot(const char *text, t_token *lexeme, double nbr)
{
	int		isize;
	int		fsize;
	char	*before_dot;
	char	*after_dot;
	char	*final;

	after_dot = NULL;
	final = NULL;
	isize = ft_howmanydig(nbr);
	before_dot = ft_before_dot(lexeme, isize, (char*)text);
	fsize = float_size((char*)PREC);
	if (fsize <= 0 && (FLAGS == NULL || ft_strchr(FLAGS, '#') == NULL))
		return (before_dot);
	after_dot = ft_strnew(fsize);
	after_dot = ft_strcpy(after_dot, (char*)&text[isize]);
	if (WIDTH > (int)(ft_strlen(after_dot) + ft_strlen(before_dot)) &&
		FLAGS != NULL && ft_strchr(FLAGS, '-') != NULL)
		after_dot = ft_width_minus(after_dot, lexeme, before_dot);
	after_dot = check_after_dot((char*)after_dot, fsize);
	final = ft_strjoin(before_dot, after_dot);
	ft_strdel(&before_dot);
	ft_strdel(&after_dot);
	return (final);
}
