/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afukuhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 15:50:56 by afukuhar          #+#    #+#             */
/*   Updated: 2020/07/24 14:52:02 by afukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "./libft/libft.h"

/*
** --- STRUCT ARGUMENTS ---
** 
** Flag characters: # 0 - ' ' + 
** Field width: decimal digit string or *
** Precision: '.' followed by a decimal digit string or *
** Length modifier: hh h ll l
** Conversion specifiers: d i o u x X e E f F a A c s p n %
*/
typedef struct		s_format
{
	int				is_string;
	int				is_integer;
	int				is_float;
	int				left; // "-" -> default is to right align the output - 1 or 0
	int				sign; // "+" -> prepends a plus for positive signed-numeric types. pos = +, neg = - 
	int				invsign; // " " -> prepends a space for positive signed-numeric types, this is ignored if + exists
	int				zero; // "0" -> when width is specified, prepends zeros for numeric types. default is to prepend spaces
	int				hash; // "#" -> g - trailing zeroes are not removed; f, g, e - output always contain a decimal point; x, X - 									0x and 0X are preprended for non-zero numbers 
	int				w; // number or * - minimum number of characters to output
	int				p; // ".(number or *)" -> floats: max number of digits to the right of a dec point ; str: max number								 of characters to output, the string is trucated
	char			*l; // length : l, ll, h, hh
	char			spec;
	int				len;
}					t_format;

/*
** --- functions prototypes ---
*/
int					ft_printf(const char *str, ...);
void				arg_print(va_list *ap, t_format *arg);
void				str_print(const char **str, t_format *arg);
char				*nxt_conv_spec(char *str);
int					is_conv_spec(char c);
int					is_flag(char c);
int					is_valid(char *str);
void				pf_saveflag(const char *str, t_format *arg, int *i);
void				pf_savewidth(const char *str, t_format *arg, int *i, va_list *ap);
void				pf_saveprecision(const char *str, t_format *arg, int *i, va_list *ap);
void				pf_savelen(const char *str, t_format *arg, int *i);
void				pf_savespec(const char *str, t_format *arg, int *i);
void				get_arg(const char **str, va_list *ap, t_format *new);
char				*pf_format(t_format *arg, va_list *ap);
char				*pf_formatc(t_format *arg, int c);
char				*pf_formats(t_format *arg, char *str);
char				*pf_sprecision(char *str, t_format *arg);
void				pf_width(char **dst, char *src, t_format *arg);
void				arg_init(t_format *arg);
#endif
