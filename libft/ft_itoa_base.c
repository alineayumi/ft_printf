/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afukuhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/15 19:47:43 by afukuhar          #+#    #+#             */
/*   Updated: 2020/04/17 11:11:59 by afukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_convert(char *nbr, int n, int base, size_t len)
{
	int	dig;

	if (n < 0 && base == 10)
		nbr[0] = '-';
	if (n == 0)
		nbr[0] = '0';
	nbr[len] = '\0';
	while (n != 0)
	{
		dig = (n % base) * ((n < 0) ? -1 : 1);
		n = n / base;
		if (dig < 10)
			nbr[--len] = '0' + dig;
		else
			nbr[--len] = 'A' + dig - 10;
	}
}

char		*ft_itoa_base(int n, int base)
{
	char	*nbr;
	int		len;

	len = ft_numdig(n, base) + ((n < 0 && base != 10) ? -1 : 0);
	if (!(nbr = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	ft_convert(nbr, n, base, len);
	return (nbr);
}
