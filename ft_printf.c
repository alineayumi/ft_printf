/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afukuhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 15:47:30 by afukuhar          #+#    #+#             */
/*   Updated: 2020/07/27 16:44:17 by afukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int			ft_printf(const char *str, ...)
{
	va_list		ap;
	t_format	arg;

	va_start(ap, str);
	arg.len = 0;
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			arg_init(&arg);
			get_arg(&str, &ap, &arg);
			arg_print(&ap, &arg);
		}
		else
			str_print(&str, &arg);
	}
	va_end(ap);
	return (arg.len);
}

void		arg_init(t_format *arg)
{
	arg->is_string = 0;
	arg->is_integer = 0;
	arg->is_float = 0;
	arg->left = 0;
	arg->sign = 0;
	arg->invsign = 0;
	arg->zero = 0;
	arg->hash = 0;
	arg->w = 0;
	arg->p = 0;
	arg->l = "";
	arg->spec = '\0';
}

void		arg_print(va_list *ap, t_format *arg)
{
	char	*print;

	print = pf_format(arg, ap);
	arg->len += ft_putstr(print);
	ft_strdel(&print);
}

/*
** Print the string until it finds a "%" or "\0"
** The str to print starts where the pointer str is pointing at
** It returns the pointer to str at % or end of string
*/

void		str_print(const char **str, t_format *arg)
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
** Walk through string and return the position of first
** occurence of conversion specifier
** the str pointer must be the char right after the %
** int  			d i
** unsigned int 	o u x X
** double			e E
** double			f F
** double			g G
** double			a A
** int				c
** const char *		s
** void *			p
** int *			n
** char				%
*/

char		*nxt_conv_spec(char *str)
{
	char	*types;

	types = "cspdiuxXnfge%";
	while (*str && !ft_strchr(types, *str))
		str++;
	return (str);
}

int			is_conv_spec(char c)
{
	char	*conv_specs;

	conv_specs = "cspdiuxXnfge%";
	if (ft_strchr(conv_specs, c))
		return (1);
	return (0);
}

/*
** Checks if the current character is a flag
*/

int			is_flag(char c)
{
	char	*flags;

	flags = "#0- +";
	if (ft_strchr(flags, c))
		return (1);
	return (0);
}

/*
** checks if all strings between % and conversion specifier are valid
** !! Need to think if it is necessaire and how to implement
*/

int			is_valid(char *str)
{
	(void)str;
	return (0);
}

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
		while (ft_isdigit(str[*i]))
		{
			p = 10 * p + (str[*i] - '0');
			*i = *i + 1;
		}
		if (str[*i] == '*')
		{
			p = va_arg(*ap, int);
			*i = *i + 1;
		}
		arg->p = p;
	}
}

void	pf_savelen(const char *str, t_format *arg, int *i)
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

/*
** Allocate memory to struct t_arg and read str until
** it reaches the end (conversion spec) of arg
** filling the structure with the specifications for the argument
** str points to first char after %
*/

void		get_arg(const char **str, va_list *ap, t_format *new)
{
	int		i;

	i = 0;
	pf_saveflag(*str, new, &i);
	pf_savew(*str, new, &i, ap);
	pf_savep(*str, new, &i, ap);
	pf_savelen(*str, new, &i);
	pf_savespec(*str, new, &i);
	*str = *str + i;
}

char		*pf_format(t_format *arg, va_list *ap)
{
	char	*new;

	if (arg->spec == 'c')
		new = pf_formatc(arg, va_arg(*ap, int));
	if (arg->spec == 's')
		new = pf_formats(arg, va_arg(*ap, char *));
	//if (arg->spec == 'p')
		//new = pf_formatp(arg, va_arg(*ap, void *);
	return (new);
}

char		*pf_formatc(t_format *arg, int c)
{
	char	*new;
	char	*str_c;

	str_c = ft_strnew(2);
	str_c[0] = (unsigned char)c;
	pf_width(&new, str_c, arg);
	ft_strdel(&str_c);
	return (new);
}

char		*pf_formats(t_format *arg, char *str)
{
	char	*str_format;
	char	*str_prec;

	str_prec = pf_sprecision(str, arg);
	pf_width(&str_format, str_prec, arg);
	ft_strdel(&str_prec);
	return (str_format);
}

/*char		*pf_formatp(t_format *arg, void *str)
{
	return (0);
}*/

char		*pf_formatn(t_format *arg, int nb)
{
	char	*str_n;

	str_n = ft_itoa_base(nb, 10);
}

char		*pf_dprecision(char *str_i, t_format *arg)
{
	char	*int_prec;
	int		len;

	len = (int)ft_strlen(str_i);
	if (arg->p > len)
	{
		int_prec = ft_strnew(arg->p);
		ft_memset(int_prec, '0', arg->p - len);
		//ft_strlcpy(int_prec + arg-> - len, str_i, len + 1);
	}
}

char		*pf_sprecision(char *str, t_format *arg)
{
	char	*str_prec;
	int		len;

	len = (int)ft_strlen(str) > arg->p ? arg->p : ft_strlen(str);
	if (len <= arg->p)
		return (str);
	str_prec = ft_strnew(len + 1);
	ft_strlcpy(str_prec, str, len + 1);
	return (str_prec);
}

/*
** Fill the w - len characters of dst with zeroes, depends on arg->left
*/

void		pf_width(char **dst, char *src, t_format *arg)
{
	char	*str;
	char	*num;
	char	pad;
	int		start;
	int		len;

	str = "csp%";
	num = "diuxXefg";
	pad = (arg->zero && !(arg->left)) ? '0' : ' ';
	len = ft_strlen(src);
	if (arg->w <= len)
	{
		*dst = ft_strnew(len + 1);
		ft_strlcpy(*dst, src, len + 1);
		return ;
	}
	start = arg->left ? 0 : arg->w - len;
	*dst = ft_strnew(arg->w + 1);
	ft_strlcpy(*dst + start, src, len + 1);
	if (arg->left && (ft_strchr(str, arg->spec) || ft_strchr(num, arg->spec)))
		ft_memset(*dst + len, pad, arg->w - len);
	else if (ft_strchr(str, arg->spec) || (ft_strchr(num, arg->spec) &&
		!arg->p))
		ft_memset(*dst, pad, arg->w - len);
}
