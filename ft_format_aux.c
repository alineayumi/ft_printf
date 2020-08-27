/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_aux.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afukuhar <afukuhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 11:43:26 by afukuhar          #+#    #+#             */
/*   Updated: 2020/08/27 11:45:50 by afukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*pf_sprecision(char *str, t_format *arg)
{
	char	*str_prec;
	int		len;

	len = (int)ft_strlen(str) > arg->p ? arg->p : ft_strlen(str);
	if (len < arg->p)
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
