/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afukuhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/17 15:34:35 by afukuhar          #+#    #+#             */
/*   Updated: 2020/04/20 14:32:24 by afukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *restrict s1, const char *restrict s2, size_t n)
{
	char	*ptr;
	size_t	l1;
	size_t	l2;

	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	ptr = s1 + l1;
	ft_strncpy(ptr, s2, n < l2 ? n : l2);
	ft_bzero(ptr + (n < l2 ? n : l2), 1);
	return (s1);
}
