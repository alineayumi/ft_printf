/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afukuhar <afukuhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 10:20:39 by afukuhar          #+#    #+#             */
/*   Updated: 2020/09/09 10:32:08 by afukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
