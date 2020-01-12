/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilitarium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 01:51:42 by mcouto            #+#    #+#             */
/*   Updated: 2019/07/28 01:51:48 by mcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		how_much_precision(t_token *lexeme)
{
	int		precision;
	char	*precision_str;

	if (PREC != NULL)
	{
		precision_str = (char*)PREC;
		precision = (int)ft_atoi(&precision_str[1]);
	}
	else
		precision = -1;
	return (precision);
}
