/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afukuhar <afukuhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 10:22:56 by afukuhar          #+#    #+#             */
/*   Updated: 2020/09/11 12:15:58 by afukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** After analysing all attributes
** nbr is filled with the right format of the number to be printed
**
** Based on left flag
** it prints pad than nbr or vice-versa
**
** this function uses ft_puthexa, that is in ft_format_x.c
*/

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

/*
** Converting number (itoa):
**		- there is a special case that should print nothing when
**			p is NULL and precision is zero
**		- otherwise just a common itoa base
**
** Precision: when p > len, should pad on left with zeroes
**
** len: updated if pad_zero > 0;
**
** Width: After all updates inside number, we have new len
** 		based on that, if w > newlen + 2 we should pad
**		(+2 is the ox at beggining of number)
**		- pad: '0' or ' '
**		- n_pad: how many chars of pad
*/

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
