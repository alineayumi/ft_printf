/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afukuhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/17 13:31:06 by afukuhar          #+#    #+#             */
/*   Updated: 2020/04/17 13:57:34 by afukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dst, const char *src)
{
	char *ptr;

	ptr = dst;
	while (*src)
		*ptr++ = *src++;
	*ptr = *src;
	return (dst);
}
