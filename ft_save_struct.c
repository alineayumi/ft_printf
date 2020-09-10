/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_save_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afukuhar <afukuhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 11:36:38 by afukuhar          #+#    #+#             */
/*   Updated: 2020/09/10 12:47:08 by afukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

const char	*pf_saveflag(const char *str, t_format *arg)
{
	while (*str && is_flag(*str))
	{
		if (*str == '0')
			arg->zero = 1;
		else if (*str == '-')
			arg->left = 1;
		str++;
	}
	return (str);
}

const char	*pf_savew(const char *str, t_format *arg, va_list *ap)
{
	int		w;

	if (ft_isdigit(*str))
	{
		w = 0;
		while (ft_isdigit(*str))
		{
			w = 10 * w + (*str - '0');
			str++;
		}
		arg->w = w;
	}
	else if (*str == '*')
	{
		arg->w = va_arg(*ap, int);
		if (arg->w < 0)
		{
			arg->w *= -1;
			arg->left = 1;
		}
		str++;
	}
	return (str);
}

const char	*pf_savep(const char *str, t_format *arg, va_list *ap)
{
	int p;

	if (*str == '.')
	{
		str++;
		p = 0;
		if (ft_isdigit(*str))
		{
			while (ft_isdigit(*str))
			{
				p = 10 * p + (*str - '0');
				str++;
			}
		}
		else if (*str == '*')
		{
			p = va_arg(*ap, int);
			str++;
		}
		arg->p = p;
	}
	return (str);
}

const char	*pf_savespec(const char *str, t_format *arg)
{
	if (*str && is_conv_spec(*str))
	{
		arg->spec = *str;
		str++;
	}
	return (str);
}
