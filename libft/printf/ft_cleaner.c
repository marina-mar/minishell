/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cleaner.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 21:10:55 by mcouto            #+#    #+#             */
/*   Updated: 2019/07/22 19:58:23 by mcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_clean_struct(t_token *lexeme)
{
	if (lexeme->flags != NULL)
		ft_strdel((char**)&lexeme->flags);
	if (lexeme->type != NULL)
		ft_strdel((char **)&lexeme->type);
	if (lexeme->precision != NULL)
		ft_strdel((char **)&lexeme->precision);
	ft_bzero(lexeme, sizeof(t_token));
}
