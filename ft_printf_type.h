/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_type.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afukuhar <afukuhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 12:40:50 by afukuhar          #+#    #+#             */
/*   Updated: 2020/09/11 11:26:34 by afukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_TYPE_H
# define FT_PRINTF_TYPE_H

/*
** --- STRUCT ARGUMENTS ---
**
** Flag characters: 0 (zero), - (left)
** Field width (w): decimal digit string or *
** Precision (p): '.' followed by a decimal digit string or * (p)
** Conversion specifiers (spec): d i u x X c s p %
** "-" -> default is to right align the output - 1 or 0
** "0" -> when width is specified, prepends zeros for numeric types.
** 		default is to prepend spaces
** ".(number or *)" -> floats: max number of digits to the right of a dec point
** 					str: max number of chars to output, the string is truncated
**					integers: min number of digits to appear (leading zeroes)
** "pad" -> char to pad
** "n_pad" -> number of chars to pad
** "n_str" -> number of chars to print from str
** "pad_zero" -> number of zeroes to pad on left of a number
** "is_neg" -> if number is negative this flag is turned on
** "len" -> total chars printed (only one that is not initialized on arg_init)
*/
typedef struct		s_format
{
	int		zero;
	int		left;
	int		w;
	int		p;
	char	spec;
	char	pad;
	int		n_pad;
	int		n_str;
	int		pad_zero;
	int		is_neg;
	int		len;
}					t_format;
#endif
