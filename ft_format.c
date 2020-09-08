/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afukuhar <afukuhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 11:42:42 by afukuhar          #+#    #+#             */
/*   Updated: 2020/09/08 00:10:23 by afukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		arg_print(t_format *arg, va_list *ap)
{
	if (arg->spec == 'c' || arg->spec == '%')
		pf_c(arg, arg->spec == 'c' ? va_arg(*ap, int) : '%');
	if (arg->spec == 's')
		pf_s(arg, va_arg(*ap, char *));
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

void		pf_s(t_format *arg, char *str)
{
	pf_analyse_s(arg, str);
	if (arg->left)
	{
		arg->len += ft_putnstr(str ? str : "(null)", arg->n_str);
		arg->len += ft_putnchar(arg->pad, arg->n_pad);
	}
	else
	{
		arg->len += ft_putnchar(arg->pad, arg->n_pad);
		arg->len += ft_putnstr(str ? str : "(null)", arg->n_str);
	}

}

void		pf_analyse_c(t_format *arg)
{
	if (arg->w > 1)
	{
		arg->pad = (arg->zero && !arg->left) ? '0' : ' ';
		arg->n_pad = arg->w - 1;
	}
}

void		pf_analyse_s(t_format *arg, char *str)
{
	int len;

	len = !str ? 6 : ft_strlen(str);
	if (arg->p >=0 && arg->p < len)
		arg->n_str = arg->p;
	else
		arg->n_str = len;
	if (arg->w > arg->n_str)
	{
		arg->pad = (arg->zero && !arg->left) ? '0' : ' ';
		arg->n_pad = arg->w - arg->n_str;
	}
}

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

int		ft_putnstr(char *str, int n)
{
	int len;

	len = 0;
	if (!str)
	{
		len = ft_putstr("(null)");
	}
	else
	{
		while (n)
		{
			len += ft_putchar(*str);
			str++;
			n--;
		}
	}
	return (len);
}