/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afukuhar <afukuhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 11:42:42 by afukuhar          #+#    #+#             */
/*   Updated: 2020/08/27 11:44:47 by afukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*pf_format(t_format *arg, va_list *ap)
{
	char	*new;

	if (arg->spec == 'c')
		new = pf_formatc(arg, va_arg(*ap, int));
	if (arg->spec == 's')
		new = pf_formats(arg, va_arg(*ap, char *));
	//if (arg->spec == 'p')
		//new = pf_formatp(arg, va_arg(*ap, void *);
	return (new);
}

char		*pf_formatc(t_format *arg, int c)
{
	char	*new;
	char	*str_c;

	if (c == '\0')
	{
		arg->is_null = 1;
		str_c = "(null)";
		arg->w += 6;
	}
	else
	{
		str_c = ft_strnew(2);
		str_c[0] = (unsigned char)c;
	}
	pf_width(&new, str_c, arg);
	ft_strdel(&str_c);
	return (new);
}

char		*pf_formats(t_format *arg, char *str)
{
	char	*str_format;
	char	*str_prec;

	str_prec = pf_sprecision(str, arg);
	pf_width(&str_format, str_prec, arg);
	ft_strdel(&str_prec);
	return (str_format);
}

/*char		*pf_formatp(t_format *arg, void *str)
{
	return (0);
}*/

// char		*pf_formatn(t_format *arg, int nb)
// {
// 	char	*str_n;

// 	str_n = ft_itoa_base(nb, 10);
// }

// char		*pf_dprecision(char *str_i, t_format *arg)
// {
// 	char	*int_prec;
// 	int		len;

// 	len = (int)ft_strlen(str_i);
// 	if (arg->p > len)
// 	{
// 		int_prec = ft_strnew(arg->p);
// 		ft_memset(int_prec, '0', arg->p - len);
// 		//ft_strlcpy(int_prec + arg-> - len, str_i, len + 1);
// 	}
// }
