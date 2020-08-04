/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afukuhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/19 00:20:28 by afukuhar          #+#    #+#             */
/*   Updated: 2020/04/25 16:43:18 by afukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t len_n;
	size_t len_h;

	if (!*needle)
		return ((char *)haystack);
	len_n = ft_strlen(needle);
	len_h = ft_strlen(haystack);
	if (len_h < len_n)
		return (NULL);
	while (*haystack)
	{
		if (ft_strncmp(haystack, needle, len_n) == 0)
			return ((char *)haystack);
		haystack++;
	}
	return (NULL);
}
