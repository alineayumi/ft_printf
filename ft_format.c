/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afukuhar <afukuhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 11:42:42 by afukuhar          #+#    #+#             */
/*   Updated: 2020/09/07 15:25:11 by afukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		arg_print(t_format *arg, va_list *ap)
{
	if (arg->spec == 'c')
		pf_c(arg, va_arg(*ap, int));
	// if (arg->spec == 's')
	// 	new = pf_formats(arg, va_arg(*ap, char *));
	//if (arg->spec == 'p')
		//new = pf_formatp(arg, va_arg(*ap, void *);
}

void		pf_c(t_format *arg, int c)
{
	pf_analyse_c(arg);
	if (arg->left)
	{
		arg->len += ft_putchar((unsigned char)c);
		arg->len += ft_putnchar(arg->pad, arg->n_pad);
	}
	else
	{
		arg->len += ft_putnchar(arg->pad, arg->n_pad);
		arg->len += ft_putchar((unsigned char)c);
	}
}

// char		*pf_formats(t_format *arg, char *str)
// {
// 	char	*str_format;
// 	char	*str_prec;

// 	str_prec = pf_sprecision(str, arg);
// 	pf_width(&str_format, str_prec, arg);
// 	ft_strdel(&str_prec);
// 	return (str_format);
// }

void		pf_analyse_c(t_format *arg)
{
	if (arg->w > 1)
	{
		arg->pad = (arg->zero && !arg->left) ? '0' : ' ';
		arg->n_pad = arg->w - 1;
	}
}

// void		pf_print_c(t_format *arg, unsigned char c)
// {
// 	if (arg->null)
// 		ft_putstr("(null)");
// 	else
// 		ft_putchar(c);
// }

int		ft_putnchar(char pad, int n)
{
	int len;

	len = 0;
	while (n)
	{
		len += ft_putchar(pad);
		n--;
	}
	return (len);
}