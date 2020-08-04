/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afukuhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/15 19:51:22 by afukuhar          #+#    #+#             */
/*   Updated: 2020/04/22 14:25:50 by afukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	char		*d;
	const char	*s;

	if (!dst && !src)
		return (NULL);
	d = dst;
	s = src;
	while (n--)
		*d++ = *s++;
	return (dst);
}
