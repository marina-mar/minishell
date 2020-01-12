/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 22:06:39 by mcouto            #+#    #+#             */
/*   Updated: 2019/07/22 20:13:27 by mcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	arguments;
	t_token lexeme;
	char	*buffer;
	int		how_many_prints;

	buffer = ft_strnew(BUFFER_SIZE);
	va_start(arguments, format);
	ft_bzero(&lexeme, sizeof(t_token));
	lexeme.is_null = 0;
	how_many_prints = ft_buf((char*)format, &lexeme, arguments, buffer);
	write(1, buffer, how_many_prints);
	ft_strdel(&buffer);
	return (how_many_prints);
}
