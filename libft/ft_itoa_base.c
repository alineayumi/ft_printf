/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afukuhar <afukuhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/15 19:47:43 by afukuhar          #+#    #+#             */
/*   Updated: 2020/09/09 11:39:07 by afukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_convert(long long int n, int base, size_t len, int is_upper)
{
	int		dig;
	char	*nbr;

	if (!(nbr = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
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
		else if (!is_upper)
			nbr[--len] = 'a' + dig - 10;
		else
			nbr[--len] = 'A' + dig - 10;
	}
	return (nbr);
}

char		*ft_itoa_base(long long int n, int base, int is_upper)
{
	char	*nbr;
	int		len;

	len = ft_numdig(n, base) + ((n < 0 && base != 10) ? -1 : 0);
	nbr = ft_convert(n, base, len, is_upper);
	return (nbr);
}
