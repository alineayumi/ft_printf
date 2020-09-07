/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_aux.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afukuhar <afukuhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 12:14:46 by afukuhar          #+#    #+#             */
/*   Updated: 2020/09/07 15:15:48 by afukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		arg_init(t_format *arg)
{
	// arg->is_string = 0;
	// arg->is_integer = 0;
	// arg->is_char = 0;
	// arg->is_upper = 0;
	// arg->is_numeric = 0;
	// arg->is_negative = 0;
	// arg->is_signed = 0;
    // arg->is_zero = 0;
    // arg->is_normalized = 0;
    arg->is_null = 0;
    arg->is_nan = 0;
    arg->is_inf = 0;    
    arg->base = 0;
    arg->exponent = 0;
	arg->left = 0;
	arg->zero = 0;
	arg->w = -1;
	arg->p = -1;
	arg->spec = 0;
	arg->pad = 0;
	arg->n_pad = 0;
}

/*
** Read str until
** it reaches the end (conversion spec) of arg
** filling the structure with the specifications for the argument
** str points to first char after %
*/

void		get_arg(const char **str, va_list *ap, t_format *new)
{
	int		i;

	i = 0;
	pf_saveflag(*str, new, &i);
	pf_savew(*str, new, &i, ap);
	pf_savep(*str, new, &i, ap);
	pf_savespec(*str, new, &i);
	*str = *str + i;
}

// void		arg_print(va_list *ap, t_format *arg)
// {
// 	char	*print;

// 	print = pf_format(arg, ap);
// 	arg->len += ft_putstr(print);
// 	ft_strdel(&print);
// }

/*
** Print the string until it finds a "%" or "\0"
** The str to print starts where the pointer str is pointing at
** It returns the pointer to str at % or end of string
*/

void		str_print(const char **str, t_format *arg)
{
	char	*end;
	char	*print;

	end = ft_strchr(*str, '%') ? ft_strchr(*str, '%') : ft_strchr(*str, '\0');
	if (end > *str)
	{
		print = ft_substr(*str, 0, end - *str);
		arg->len += ft_putstr(print);
		if (arg->is_null)
			arg->len -= 1; 
		ft_strdel(&print);
	}
	*str = end;
}
