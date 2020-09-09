/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afukuhar <afukuhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 11:42:42 by afukuhar          #+#    #+#             */
/*   Updated: 2020/09/09 01:33:20 by afukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		arg_print(t_format *arg, va_list *ap)
{
	if (arg->spec == 'c' || arg->spec == '%')
		pf_c(arg, arg->spec == 'c' ? va_arg(*ap, int) : '%');
	if (arg->spec == 's')
		pf_s(arg, va_arg(*ap, char *));
	if (arg->spec == 'p')
		pf_p(arg, (unsigned long long int) va_arg(*ap, void *));
	if (arg->spec == 'd' || arg->spec == 'i')
		pf_di(arg, va_arg(*ap, int));
	if (arg->spec == 'u')
		pf_di(arg, va_arg(*ap, unsigned int));
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

void		pf_p(t_format *arg, unsigned long long int p)
{
	char *nbr;

	nbr = pf_analyse_p(arg, p);
	if (arg->left)
	{
		arg->len += ft_puthexa(nbr, arg->pad_zero);
		arg->len += ft_putnchar(arg->pad, arg->n_pad);
	}
	else
	{
		arg->len += ft_putnchar(arg->pad, arg->n_pad);
		arg->len += ft_puthexa(nbr, arg->pad_zero);
	}
	ft_strdel(&nbr);
}

void		pf_di(t_format *arg, long long int n)
{
	char *nbr;

	nbr = pf_analyse_di(arg, n);
	if (arg->left)
	{
		arg->len += ft_putint(nbr, arg->pad_zero, arg->is_neg);
		arg->len += ft_putnchar(arg->pad, arg->n_pad);
	}
	else
	{
		arg->len += ft_putnchar(arg->pad, arg->n_pad);
		arg->len += ft_putint(nbr, arg->pad_zero, arg->is_neg);
	}
	ft_strdel(&nbr);
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

char		*pf_analyse_p(t_format *arg, long long int p)
{
	char *nbr;
	int len;

	nbr = ft_itoa_base(p, 16);
	len = ft_strlen(nbr);
	arg->pad_zero = (arg->p > len) ? arg->p - len : 0;
	len += arg->pad_zero;
	if (arg->w > len + 2)
	{
		arg->pad = (arg->zero && !arg->left) ? '0' : ' ';
		arg->n_pad = arg->w - len - 2;
	}
	return (nbr);
}

char		*pf_analyse_di(t_format *arg, long long int n)
{
	char *nbr;
	int len;

	if (n < 0)
	{
		arg->is_neg = 1;
		n *= -1;
	}
	nbr = (!n && !arg->p) ? ft_strnew(0) : ft_itoa_base(n, 10);
	len = ft_strlen(nbr);
	arg->pad_zero = (arg->p > len) ? arg->p - len : 0;
	len += arg->pad_zero + (arg->is_neg ? 1 : 0);
	if (arg->w > len)
	{
		if (arg->zero && !arg->left && arg->p < 0)
			arg->pad_zero += arg->w - len;
		else
		{
			arg->pad = ' ';
			arg->n_pad = arg->w - len;
		}
	}
	return (nbr);
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

int		ft_puthexa(char *nbr, int pad_zero)
{
	int len;

	len = 0;
	len += ft_putstr("0x");
	len += ft_putnchar('0', pad_zero);
	len += ft_putstr(nbr);

	return (len);
}

int		ft_putint(char *nbr, int pad_zero, int is_neg)
{
	int len;

	len = 0;
	if (is_neg)
		len += ft_putstr("-");
	len += ft_putnchar('0', pad_zero);
	len += ft_putstr(nbr);

	return (len);
}