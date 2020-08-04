/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy_rev.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afukuhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/15 19:51:41 by afukuhar          #+#    #+#             */
/*   Updated: 2020/04/15 19:51:43 by afukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy_rev(void *restrict dst, const void *restrict src, size_t n)
{
	char		*d;
	const char	*s;

	if (!dst && !src)
		return (NULL);
	d = dst + n - 1;
	s = src + n - 1;
	while (n-- > 0)
		*d-- = *s--;
	return (d);
}
