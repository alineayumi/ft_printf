/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afukuhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/12 21:50:20 by afukuhar          #+#    #+#             */
/*   Updated: 2020/04/28 13:03:44 by afukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char *str;

	if (!(str = malloc(sizeof(char) * (len + 1))) || !s)
		return (NULL);
	if (start >= ft_strlen(s))
		ft_bzero(str, len + 1);
	else
	{
		s += start;
		ft_strlcpy(str, s, len + 1);
	}
	return (str);
}
