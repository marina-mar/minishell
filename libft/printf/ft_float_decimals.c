/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_decimals_float.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 01:53:32 by mcouto            #+#    #+#             */
/*   Updated: 2019/08/01 01:53:33 by mcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static long double	ft_decimals_simple(long double nbr, int after_dot)
{
	int mult;

	mult = 0;
	while (mult < after_dot)
	{
		nbr = nbr * 10;
		mult++;
	}
	return (nbr);
}

static const char	*ft_decimals(long double n, int size)
{
	char			*final;
	int				i;
	int				val;
	int				how_many_int;
	long double		divider;

	i = 0;
	divider = 1;
	final = NULL;
	how_many_int = ft_howmanydig((intmax_t)n);
	while (i++ < (how_many_int - 1))
		divider = (divider == 0) ? 1 : divider * 10;
	i = 0;
	if (n == 0)
		return (ft_strdup("0"));
	if (!(final = ft_strnew(size)))
		return (NULL);
	while (i < size)
	{
		val = n / divider;
		final[i++] = val + '0';
		n = n - (val * divider);
		divider = divider / 10;
	}
	return (final);
}

const char			*get_decimals(t_token *lexeme, long double nbr)
{
	char	*precision;
	int		after_dot;

	precision = (char*)PREC;
	if (PREC != NULL)
		after_dot = ft_atoi(&precision[1]);
	else
		after_dot = 6;
	if (after_dot > 15)
		return (ft_decimals(nbr, after_dot));
	else
		return (ft_itoa(ft_decimals_simple(nbr, after_dot)));
}

char				*round_it_up(char *text)
{
	int i;

	i = 0;
	while (text[i] != '\0')
	{
		if (text[i] == '9')
		{
			if (text[i - 1] >= '0' && text[i - 1] <= '8')
				text[i - 1] = text[i - 1] + 1;
			if (text[i - 1] == '9')
				text[i - 1] = '0';
		}
		i++;
	}
	if (text[i] == '\0')
	{
		if (text[i - 1] >= '0' && text[i - 1] <= '8')
			text[i - 1] = text[i - 1] + 1;
		if (text[i - 1] == '9')
			text[i - 1] = '0';
	}
	return (text);
}

const char			*check_round_up(char *text, long double nbr)
{
	char	*num;
	int		i;
	int		is_equal;
	int		size_text;

	num = NULL;
	i = 0;
	is_equal = 0;
	size_text = ft_strlen(text);
	if (size_text + 6 > 15)
		num = (char*)ft_decimals(nbr, (size_text + 6));
	else
		num = ft_itoa(ft_decimals_simple(nbr, (size_text + 6)));
	while (text[i++] != '\0')
		if (text[i] == '.')
			break ;
	i = i + 1;
	while (num[i++] != '\0' && is_equal < 6)
		if (num[i] == '9' && num[i] == num[i - 1])
			is_equal++;
	if (is_equal >= 6)
		text = round_it_up(text);
	ft_strdel(&num);
	return (text);
}
