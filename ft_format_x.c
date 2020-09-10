/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afukuhar <afukuhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 11:42:42 by afukuhar          #+#    #+#             */
/*   Updated: 2020/09/09 11:57:07 by afukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pf_x(t_format *arg, unsigned int x)
{
	char *nbr;

	nbr = pf_analyse_x(arg, x);
	if (arg->left)
	{
		arg->len += ft_puthexa(nbr, arg->pad_zero, arg->spec == 'p');
		arg->len += ft_putnchar(arg->pad, arg->n_pad);
	}
	else
	{
		arg->len += ft_putnchar(arg->pad, arg->n_pad);
		arg->len += ft_puthexa(nbr, arg->pad_zero, arg->spec == 'p');
	}
	ft_strdel(&nbr);
}

char	*pf_analyse_x(t_format *arg, long long int x)
{
	char	*nbr;
	int		len;

	if (x == 0 && arg->p == 0)
		nbr = ft_strnew(0);
	else
		nbr = ft_itoa_base(x, 16, (arg->spec == 'x' ? 0 : 1));
	len = ft_strlen(nbr);
	arg->pad_zero = (arg->p > len) ? arg->p - len : 0;
	len += arg->pad_zero;
	if (arg->w > len)
	{
		arg->pad = (arg->zero && !arg->left && arg->p < 0) ? '0' : ' ';
		arg->n_pad = arg->w - len;
	}
	return (nbr);
}

int		ft_puthexa(char *nbr, int pad_zero, int is_p)
{
	int len;

	len = 0;
	if (is_p)
		len += ft_putstr("0x");
	len += ft_putnchar('0', pad_zero);
	len += ft_putstr(nbr);
	return (len);
}
