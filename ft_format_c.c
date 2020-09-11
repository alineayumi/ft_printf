/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afukuhar <afukuhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 11:43:26 by afukuhar          #+#    #+#             */
/*   Updated: 2020/09/11 12:15:08 by afukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** After analysing all attributes
** Based on left flag
** it prints pad than char or vice-versa
*/

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

/*
** Analyses if it has a width and if it has, update:
** 		- pad: '0' or ' '
**		- n_pad: how many chars of pad
*/

void		pf_analyse_c(t_format *arg)
{
	if (arg->w > 1)
	{
		arg->pad = (arg->zero && !arg->left) ? '0' : ' ';
		arg->n_pad = arg->w - 1;
	}
}
