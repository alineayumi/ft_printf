/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afukuhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/10 21:55:46 by afukuhar          #+#    #+#             */
/*   Updated: 2020/04/23 17:05:58 by afukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		n_len;
	const char	*end_haystack;

	n_len = ft_strlen(needle);
	end_haystack = haystack + len - 1;
	if (!n_len)
		return ((char *)haystack);
	while (*haystack)
	{
		if ((end_haystack - haystack + 1) < (int)n_len)
			return (NULL);
		if (ft_strncmp(needle, haystack, n_len) == 0)
			return ((char *)haystack);
		haystack++;
	}
	return (NULL);
}
