/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_save_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afukuhar <afukuhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 11:36:38 by afukuhar          #+#    #+#             */
/*   Updated: 2020/08/27 12:17:33 by afukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		pf_saveflag(const char *str, t_format *arg, int *i)
{
	while (is_flag(str[*i]))
	{
		if (str[*i] == '#')
			arg->hash = 1;
		else if (str[*i] == ' ')
			arg->invsign = 1;
		else if (str[*i] == '0')
			arg->zero = 1;
		else if (str[*i] == '+')
			arg->sign = 1;
		else if (str[*i] == '-')
			arg->left = 1;
		*i = *i + 1;
	}
}

void		pf_savew(const char *str, t_format *arg, int *i, va_list *ap)
{
	int	w;

	if (ft_isdigit(str[*i]))
	{
		w = 0;
		while (ft_isdigit(str[*i]))
		{
			w = 10 * w + (str[*i] - '0');
			*i = *i + 1;
		}
		arg->w = w;
	}
	else if (str[*i] == '*')
	{
		arg->w = va_arg(*ap, int);
		*i = *i + 1;
	}
}

void		pf_savep(const char *str, t_format *arg, int *i, va_list *ap)
{
	int p;

	if (str[*i] == '.')
	{
		*i = *i + 1;
		p = 0;
		if (ft_isdigit(str[*i]))
		{
			while (ft_isdigit(str[*i]))
			{
				p = 10 * p + (str[*i] - '0');
				*i = *i + 1;
			}
		}
		else if (str[*i] == '*')
		{
			p = va_arg(*ap, int);
			*i = *i + 1;
		}
		arg->p = p;
	}
}

void		pf_savelen(const char *str, t_format *arg, int *i)
{
	if (str[*i] == 'l')
	{
		*i = *i + 1;
		if (str[*i] == 'l')
		{
			arg->l = "ll";
			*i = *i + 1;
		}
		else
			arg->l = "l";
	}
	else if (str[*i] == 'h')
	{
		*i = *i + 1;
		if (str[*i] == 'h')
		{
			arg->l = "hh";
			*i = *i + 1;
		}
		else
			arg->l = "h";
	}
}

void		pf_savespec(const char *str, t_format *arg, int *i)
{
	if (is_conv_spec(str[*i]))
	{
		arg->spec = str[*i];
		*i = *i + 1;
	}
}