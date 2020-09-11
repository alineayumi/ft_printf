/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_aux.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afukuhar <afukuhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 12:14:46 by afukuhar          #+#    #+#             */
/*   Updated: 2020/09/11 11:36:07 by afukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Initialize structure for saving new flags, specs and attributes
** w and p are -1 because we can have 0 width and precision
*/

void	arg_init(t_format *arg)
{
	arg->is_neg = 0;
	arg->left = 0;
	arg->zero = 0;
	arg->w = -1;
	arg->p = -1;
	arg->spec = 0;
	arg->pad = 0;
	arg->n_pad = 0;
	arg->n_str = 0;
	arg->pad_zero = 0;
	arg->spec = 0;
}

/*
** Read str until
** it reaches the end (conversion spec) of arg
** filling the structure with the specifications for the argument
** and updating the pointer to str
*/

void	get_arg(const char **str, va_list *ap, t_format *new)
{
	*str = pf_saveflag(*str, new);
	*str = pf_savew(*str, new, ap);
	*str = pf_savep(*str, new, ap);
	*str = pf_savespec(*str, new);
}

/*
** Based on specifier, call the correnponding function
** for printing it
*/

void	arg_print(t_format *arg, va_list *ap)
{
	if (arg->spec == 'c' || arg->spec == '%')
		pf_c(arg, arg->spec == 'c' ? va_arg(*ap, int) : '%');
	if (arg->spec == 's')
		pf_s(arg, va_arg(*ap, char *));
	if (arg->spec == 'p')
		pf_p(arg, (unsigned long long int)va_arg(*ap, void *));
	if (arg->spec == 'd' || arg->spec == 'i')
		pf_di(arg, va_arg(*ap, int));
	if (arg->spec == 'u')
		pf_di(arg, va_arg(*ap, unsigned int));
	if (arg->spec == 'x' || arg->spec == 'X')
		pf_x(arg, va_arg(*ap, unsigned int));
}

void	str_print(const char **str, t_format *arg)
{
	char	*end;
	char	*print;

	end = ft_strchr(*str, '%') ? ft_strchr(*str, '%') : ft_strchr(*str, '\0');
	if (end > *str)
	{
		print = ft_substr(*str, 0, end - *str);
		arg->len += ft_putstr(print);
		ft_strdel(&print);
	}
	*str = end;
}

/*
** Auxiliar function used for printing '0' or ' '
*/

int		ft_putnchar(char pad, int n)
{
	int len;

	len = 0;
	while (n)
	{
		len += ft_putchar(pad);
		n--;
	}
	return (len);
}
