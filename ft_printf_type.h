/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_type.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afukuhar <afukuhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 12:40:50 by afukuhar          #+#    #+#             */
/*   Updated: 2020/09/09 11:17:21 by afukuhar         ###   ########.fr       */
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
** "-" -> default is to right align the output - 1 or 0
** "0" -> when width is specified, prepends zeros for numeric types.
** 		default is to prepend spaces
** ".(number or *)" -> floats: max number of digits to the right of a dec point
** 		str: max number of characters to output, the string is trucated
** "pad" -> char to pad
** "n_pad" -> number of chars to pad
** "n_str" -> number of chars to print from str
** "pad_zero" -> number of zeroes to pad on left of a number
** "ken" -> total chars printed
*/
typedef struct		s_format
{
	int		is_neg;
	int		left;
	int		zero;
	int		w;
	int		p;
	char	pad;
	int		n_pad;
	int		n_str;
	int		pad_zero;
	char	spec;
	int		len;
}					t_format;
#endif
