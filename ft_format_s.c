/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afukuhar <afukuhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 10:20:39 by afukuhar          #+#    #+#             */
/*   Updated: 2020/09/11 12:16:28 by afukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** After analysing all attributes
** Based on left flag
** it prints pad than str or vice-versa
**
** when string is null, should print "(null)"
*/

void	pf_s(t_format *arg, char *str)
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

/*
** First check if string is null and update length accordinly
**
** Precision: should print at most p chars, if p < len,
**				n_str that is the number of chars to print should
**				be len - p or len (this prints whole string)
** Width: if w > n_str, should pad:
** 		- pad: '0' or ' '
**		- n_pad: how many chars of pad
*/

void	pf_analyse_s(t_format *arg, char *str)
{
	int len;

	len = !str ? 6 : ft_strlen(str);
	if (arg->p >= 0 && arg->p < len)
		arg->n_str = arg->p;
	else
		arg->n_str = len;
	if (arg->w > arg->n_str)
	{
		arg->pad = (arg->zero && !arg->left) ? '0' : ' ';
		arg->n_pad = arg->w - arg->n_str;
	}
}

/*
** According to n, will print until n chars of string
*/

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
