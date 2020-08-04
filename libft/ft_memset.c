/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afukuhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/15 19:52:23 by afukuhar          #+#    #+#             */
/*   Updated: 2020/04/15 19:52:24 by afukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*ptr_to_b;

	ptr_to_b = (unsigned char *)b;
	while (len > 0)
	{
		*ptr_to_b = (unsigned char)c;
		len--;
		ptr_to_b++;
	}
	return (b);
}
