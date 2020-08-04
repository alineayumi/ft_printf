/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afukuhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/15 19:51:58 by afukuhar          #+#    #+#             */
/*   Updated: 2020/04/15 19:51:59 by afukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t count)
{
	if (!dst && !src)
		return (NULL);
	if (dst < src)
		ft_memcpy(dst, src, count);
	else
		ft_memcpy_rev(dst, src, count);
	return (dst);
}
