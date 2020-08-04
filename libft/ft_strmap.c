/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afukuhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/15 19:56:29 by afukuhar          #+#    #+#             */
/*   Updated: 2020/04/25 16:42:19 by afukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	unsigned int	i;
	unsigned int	len;
	char			*str;

	i = 0;
	if (!s || !f)
		return (NULL);
	len = ft_strlen((char *)s);
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (s[i])
	{
		str[i] = f((char)s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
