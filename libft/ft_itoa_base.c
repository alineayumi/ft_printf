/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afukuhar <afukuhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/15 19:47:43 by afukuhar          #+#    #+#             */
/*   Updated: 2020/09/08 13:33:12 by afukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_convert(char *nbr, long long int n, int base, size_t len)
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
			nbr[--len] = 'a' + dig - 10;
	}
}

char		*ft_itoa_base(long long int n, int base)
{
	char	*nbr;
	int		len;

	len = ft_numdig(n, base) + ((n < 0 && base != 10) ? -1 : 0);
	if (!(nbr = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	ft_convert(nbr, n, base, len);
	return (nbr);
}
