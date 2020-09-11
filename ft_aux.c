/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aux.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afukuhar <afukuhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 11:40:30 by afukuhar          #+#    #+#             */
/*   Updated: 2020/09/11 11:42:43 by afukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

/*
** Checks if the current character is a specifier
*/

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
