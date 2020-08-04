/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afukuhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/17 13:23:01 by afukuhar          #+#    #+#             */
/*   Updated: 2020/04/17 13:58:38 by afukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *restrict s1, const char *restrict s2)
{
	char *ptr;

	ptr = s1;
	ptr += ft_strlen(s1);
	ft_strcpy(ptr, s2);
	return (s1);
}
