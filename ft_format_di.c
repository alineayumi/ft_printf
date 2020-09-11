/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_di.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afukuhar <afukuhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 10:24:13 by afukuhar          #+#    #+#             */
/*   Updated: 2020/09/11 12:15:33 by afukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** After analysing all attributes
** nbr is filled with the right format of the number to be printed
**
** Based on left flag
** it prints pad than nbr or vice-versa
*/

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

/*
** Checks if n is neg - change to pos and update is_neg flag if so
**
** Converting number (itoa):
**		- there is a special case that should print nothing when
**			n is NULL and we have precisio
**		- otherwise just a common itoa base
**
** Precision: when p > len, should pad on left with zeroes
**
** len: updated if is_neg (+1) and pad_zero > 0;
**
** Width: After all updates inside number, we have new len
** 		based on that, if w > newlen we should pad
**		- there is a special case when pad is '0' and we don't have
**			precision .. zero should go in the number part
**		- otherwise will be a ' ' pad and we update n_pad and pad
*/

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

/*
** Printing the number part
**	- if is_neg, should print a '-' at beggining
**	- print the '0's inside number part
** 	- print the number string
*/

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
