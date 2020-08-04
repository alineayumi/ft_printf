/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afukuhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/11 12:32:46 by afukuhar          #+#    #+#             */
/*   Updated: 2020/04/11 16:57:51 by afukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *restrict dst, const char *restrict src,
	size_t dstsize)
{
	size_t src_len;

	if (!dst || !src)
		return (0);
	src_len = ft_strlen(src);
	if (dstsize == 0)
		return (src_len);
	while (*src && dstsize-- > 1)
		*dst++ = *src++;
	*dst = '\0';
	return (src_len);
}
