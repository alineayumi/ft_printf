/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_type.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afukuhar <afukuhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 12:40:50 by afukuhar          #+#    #+#             */
/*   Updated: 2020/09/03 13:39:17 by afukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_TYPE_H
# define FT_PRINTF_TYPE_H
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
	int		is_string;
	int		is_integer;
    int		is_char;
    int		is_upper;
    int		is_numeric;
    int		is_negative;
    int		is_signed;
    int		is_zero;
    int		is_normalized;
    int		is_null;
    int		is_nan;
    int		is_inf; 
    int		base;
    int		exponent;
	int		left; // "-" -> default is to right align the output - 1 or 0
	int		zero; // "0" -> when width is specified, prepends zeros for numeric types. default is to prepend spaces
	int		w; // number or * - minimum number of characters to output
	int		p; // ".(number or *)" -> floats: max number of digits to the right of a dec point ; str: max number								 of characters to output, the string is trucated
	char	pad;
	int		n_pad;
	char	spec;
	int		len; //total chars printed
}					t_format;
#endif