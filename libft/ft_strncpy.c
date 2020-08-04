/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afukuhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/17 14:15:12 by afukuhar          #+#    #+#             */
/*   Updated: 2020/04/24 13:04:27 by afukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	char *ptr;

	ptr = dst;
	while (len && *src)
	{
		*ptr++ = *src++;
		len--;
	}
	ft_bzero(ptr, len);
	return (dst);
}
