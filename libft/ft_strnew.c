/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afukuhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/17 21:53:54 by afukuhar          #+#    #+#             */
/*   Updated: 2020/04/25 16:29:05 by afukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *new_str;

	if (!(new_str = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	ft_bzero(new_str, size + 1);
	return (new_str);
}
