/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afukuhar <afukuhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 10:22:56 by afukuhar          #+#    #+#             */
/*   Updated: 2020/09/09 14:15:33 by afukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pf_p(t_format *arg, unsigned long long int p)
{
	char *nbr;

	nbr = pf_analyse_p(arg, p);
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

char	*pf_analyse_p(t_format *arg, long long int p)
{
	char	*nbr;
	int		len;

	if (arg->p == 0 && !p)
		nbr = ft_strnew(0);
	else
		nbr = ft_itoa_base(p, 16, 0);
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
