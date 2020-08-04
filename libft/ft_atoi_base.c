/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afukuhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/11 23:22:46 by afukuhar          #+#    #+#             */
/*   Updated: 2020/04/17 11:12:25 by afukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isvalid(char c, int base)
{
	if (base <= 10)
		return (c >= '0' && c <= '0' + base - 1);
	return (ft_isdigit(c) || (c >= 'a' && c <= 'a' + base - 11) ||
		(c >= 'A' && c <= 'A' + base - 11));
}

int			ft_atoi_base(const char *str, int base)
{
	int			signal;
	long int	nbr;

	nbr = 0;
	signal = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '-')
		signal = -1;
	if (*str == '+' || *str == '-')
		str++;
	while (ft_isvalid(*str, base))
	{
		if (ft_isdigit(*str))
			nbr = nbr * base + (*str - '0');
		else if (ft_isupper(*str))
			nbr = nbr * base + (*str - 'A' + 10);
		else if (ft_islower(*str))
			nbr = nbr * base + (*str - 'a' + 10);
		str++;
		if (nbr < 0)
			return (signal == -1 ? 0 : -1);
	}
	return (nbr * signal);
}
