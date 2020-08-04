/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afukuhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/11 17:12:10 by afukuhar          #+#    #+#             */
/*   Updated: 2020/04/11 17:50:29 by afukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *restrict dst, const char *restrict src, size_t dstsize)
{
	size_t src_len;
	size_t dst_len;

	src_len = ft_strlen(src);
	dst_len = ft_strlen(dst);
	if (dstsize < dst_len)
		return (src_len + dstsize);
	dst += dst_len;
	ft_strlcpy(dst, src, dstsize - dst_len);
	return (src_len + dst_len);
}
