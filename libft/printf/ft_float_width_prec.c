/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float_width_prec.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 02:56:42 by mcouto            #+#    #+#             */
/*   Updated: 2019/08/01 02:56:46 by mcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char	*int_size_prec(int prec, int width, char *before_dot, int *isize)
{
	char *spaces;

	*isize = ft_strlen(before_dot);
	spaces = ft_strnew(width - (prec + *isize));
	return (spaces);
}

static char	*int_size(int width, int nbr, int *isize)
{
	char *spaces;

	*isize = nbr;
	spaces = ft_strnew(width - (6 + *isize));
	return (spaces);
}

char		*ft_w_p(char *before_dot, int p, t_token *lexeme, int nbr)
{
	char	*final;
	char	*spaces;
	int		isize;
	int		i;

	i = -1;
	final = NULL;
	spaces = NULL;
	if (p > 0)
		spaces = int_size_prec(p, WIDTH, before_dot, &isize);
	else
		spaces = int_size(WIDTH, nbr, &isize);
	if (FLAGS != NULL && ft_strchr(FLAGS, '0') != NULL)
	{
		while (++i < (WIDTH - (p + isize)))
			spaces[i] = '0';
	}
	else
	{
		while (++i < (WIDTH - (p + isize)))
			spaces[i] = ' ';
	}
	final = ft_strjoin(spaces, before_dot);
	ft_strdel(&before_dot);
	return (final);
}
