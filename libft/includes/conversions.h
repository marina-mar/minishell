/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 15:41:34 by mcouto            #+#    #+#             */
/*   Updated: 2019/09/03 21:12:12 by mcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERSIONS_H
# define CONVERSIONS_H

typedef const char		*t_conversions(t_token *lexeme, va_list arguments);

static t_conversions	*g_convert[] = {charac, string, pointer, sig_dec_i,
	sig_dec_i, uns_dec_i, oct, hex_low, hex_up, floating, binary, NULL};
const char				*ft_format(t_token *lexeme, va_list arguments);
#endif
