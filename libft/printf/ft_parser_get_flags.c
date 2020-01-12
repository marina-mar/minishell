/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_get_flags.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 11:31:50 by mcouto            #+#    #+#             */
/*   Updated: 2019/07/29 11:31:51 by mcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*organize_flags(char *str, int how_many_flags)
{
	char *flags;
	char *tmp;

	flags = ft_strnew(how_many_flags);
	tmp = flags;
	while (*str == '#' ||
			*str == '0' ||
			*str == '-' ||
			*str == ' ' ||
			*str == '+')
	{
		*flags = *str;
		flags++;
		str++;
	}
	return (tmp);
}

int		ft_is_flag(char *str)
{
	int how_many_flags;

	how_many_flags = 0;
	while (*str == '#' ||
			*str == '0' ||
			*str == '-' ||
			*str == ' ' ||
			*str == '+')
	{
		how_many_flags++;
		str++;
	}
	return (how_many_flags);
}

char	*get_flags(char *format, t_token *lexeme)
{
	int how_many;

	if ((how_many = ft_is_flag(format)) > 0)
	{
		lexeme->flags = organize_flags(format, how_many);
		format = format + how_many;
	}
	return (format);
}
