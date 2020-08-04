/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countword.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afukuhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/15 19:46:06 by afukuhar          #+#    #+#             */
/*   Updated: 2020/04/15 19:46:10 by afukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_countword(char const *s, char c)
{
	size_t	count;

	if (!*s)
		return (0);
	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			count++;
		while (*s != c && *s)
			s++;
	}
	return (count);
}
