/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afukuhar <afukuhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 15:47:30 by afukuhar          #+#    #+#             */
/*   Updated: 2020/09/11 11:32:09 by afukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Main flow of printf
**
** initialize va_list and structure
** walk through string
**
** 		%...<spec> :	initialize struct
**						get arguments and save it
**                      print accordinly
**						update len (number of chars printed)
**
**		common string:	print string until it finds a '%' or '\0'
**						update len (number of chars printed)
*/

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
