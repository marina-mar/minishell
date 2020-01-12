/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 19:23:19 by mcouto            #+#    #+#             */
/*   Updated: 2019/07/22 19:58:34 by mcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

const char				*deal_with_plus(char *text)
{
	int		i;
	char	*plus;
	char	*tmp;

	i = 0;
	plus = NULL;
	while (ft_isdigit(text[i]) == 0)
		i++;
	if (i == 0)
	{
		plus = ft_strnew(1);
		plus[0] = '+';
		tmp = text;
		text = ft_strjoin(plus, text);
		ft_strdel(&tmp);
		ft_strdel(&plus);
	}
	if (text[i - 1] == ' ')
		text[i - 1] = '+';
	return (text);
}

const char				*floating(t_token *lexeme, va_list arguments)
{
	long double	nbr;
	const char	*text;
	const char	*tmp;

	text = NULL;
	if (TYPE != NULL && ft_strcmp(TYPE, "L") == 0)
		nbr = va_arg(arguments, long double);
	else
		nbr = (long double)va_arg(arguments, double);
	text = get_decimals(lexeme, nbr);
	tmp = text;
	if ((int)nbr != 0)
		text = put_dot(text, lexeme, nbr);
	else
		text = put_dot_0(text, lexeme, nbr);
	if (nbr >= 0 && FLAGS != NULL && ft_strchr(FLAGS, '+') != NULL)
		text = deal_with_plus((char*)text);
	text = check_round_up((char*)text, nbr);
	ft_strdel((char**)&tmp);
	return (text);
}
