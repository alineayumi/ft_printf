/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afukuhar <afukuhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 15:47:30 by afukuhar          #+#    #+#             */
/*   Updated: 2020/09/09 12:49:52 by afukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_printf(const char *str, ...)
{
	va_list		ap;
	t_format	arg;

	va_start(ap, str);
	arg.len = 0;
	ft_pf_internal(str, &ap, &arg);
	va_end(ap);
	return (arg.len);
}

void		ft_pf_internal(const char *str, va_list *ap, t_format *arg)
{
	while (*str)
	{
		if (*str && *str == '%')
		{
			str++;
			arg_init(arg);
			get_arg(&str, ap, arg);
			arg_print(arg, ap);
		}
		else
			str_print(&str, arg);
	}
}
