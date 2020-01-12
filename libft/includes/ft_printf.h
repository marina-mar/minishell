/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 23:08:18 by mcouto            #+#    #+#             */
/*   Updated: 2019/07/22 20:07:00 by mcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <limits.h>
# include <float.h>
# include "libft.h"
# include "binary_tree.h"
# include "get_next_line.h"

# define BUFFER_SIZE 10000
# define NOT_ZERO_FLAG ft_strchr(FLAGS, '0') == NULL
# define IS_HASHTAG ft_strchr(lexeme->flags, '#') != NULL
# define IS_ZERO_FLAG ft_strchr(lexeme->flags, '0') != NULL
# define CONV "cspdiuoxXfb"
# define LEXEME t_token *lexeme
# define FLAGS lexeme->flags
# define TYPE lexeme->type
# define PREC lexeme->precision
# define CONVERSION lexeme->conversion
# define WIDTH lexeme->width

typedef struct		s_token
{
	const char		*flags;
	const char		*type;
	const char		*precision;
	char			conversion;
	int				width;
	int				is_null;
}					t_token;

typedef const char	*t_conversions(t_token *lexeme, va_list arguments);

int					ft_printf(const char *format, ...);
int					ft_buf(char *form, t_token *lexeme, va_list arg, char *buf);
int					ft_parser_pf(char *original, t_token *lexeme, va_list arg);
int					how_much_precision(t_token *lexeme);
void				ft_clean_struct(t_token *lexeme);
char				*width_sig_int(char *txt, t_token *lexeme, int size);
char				*precision_sig_int(char *txt, t_token *lexeme, int size);
char				*width_string(char *text, t_token *lexeme, int size);
char				*precision_pointer(char *text, t_token *lexeme);
char				*width_uns_int(char *txt, t_token *lexeme, int size);
char				*precision_u_int(char *txt, t_token *lexeme, int size);
char				*width_oct(char *txt, t_token *lexeme, int size);
char				*precision_oct(char *txt, t_token *lexeme, int size);
char				*width_hex_u(char *text, t_token *lexeme, int size);
char				*precision_hex_u(char *text, t_token *lexeme, int size);
char				*width_hex(char *text, t_token *lexeme, int size);
char				*precision_hex(char *text, t_token *lexeme, int size);
char				*get_type(char *format, t_token *lexeme);
char				*get_prec(char *format, t_token *lexeme, va_list arg);
char				*get_flags(char *format, t_token *lexeme);
char				*get_width(char *format, t_token *lexeme, va_list arg);
char				*put_dot_0(const char *text, t_token *lexeme, double nbr);
char				*ft_before_dot_zero(t_token *lexeme, double nbr);
char				*ft_precision_zero(t_token *lexeme, int isize);
char				*ft_width_in_zero(t_token *lexeme, char *before_dot);
char				*put_dot(const char *text, t_token *lexeme, double nbr);
char				*ft_before_dot(t_token *lexeme, int isize, char *text);
char				*ft_precision(t_token *lexeme, int isize, char *text);
char				*check_after_dot(char *after_dot, int fsize);
char				*ft_w_p(char *before_dot, int p, t_token *lexeme, int nbr);
char				*print_colors(char conv);
const char			*ft_format(t_token *lexeme, va_list arguments);
const char			*get_decimals(t_token *lexeme, long double nbr);
const char			*check_round_up(char *text, long double nbr);
const char			*ft_format(t_token *lexeme, va_list arguments);
const char			*charac(t_token *lexeme, va_list arguments);
const char			*string(t_token *lexeme, va_list arguments);
const char			*pointer(t_token *lexeme, va_list arguments);
const char			*sig_dec_i(t_token *lexeme, va_list arguments);
const char			*uns_dec_i(t_token *lexeme, va_list arguments);
const char			*oct(t_token *lexeme, va_list arguments);
const char			*hex_low(t_token *lexeme, va_list arguments);
const char			*hex_up(t_token *lexeme, va_list arguments);
const char			*floating(t_token *lexeme, va_list arguments);
const char			*binary(t_token *lexeme, va_list arguments);

#endif
