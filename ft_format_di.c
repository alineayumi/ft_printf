/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_di.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afukuhar <afukuhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 10:24:13 by afukuhar          #+#    #+#             */
/*   Updated: 2020/09/09 11:40:24 by afukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pf_di(t_format *arg, long long int n)
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

char	*pf_analyse_di(t_format *arg, long long int n)
{
	char	*nbr;
	int		len;

	if (n < 0)
	{
		arg->is_neg = 1;
		n *= -1;
	}
	nbr = (!n && !arg->p) ? ft_strnew(0) : ft_itoa_base(n, 10, 0);
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
