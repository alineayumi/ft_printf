/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afukuhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/15 19:50:42 by afukuhar          #+#    #+#             */
/*   Updated: 2020/04/15 19:50:45 by afukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char *src;

	src = s;
	while (n--)
	{
		if (*src == (unsigned char)c)
			return ((void *)src);
		src++;
	}
	return (NULL);
}
