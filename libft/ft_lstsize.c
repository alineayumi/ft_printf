/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afukuhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/15 19:49:45 by afukuhar          #+#    #+#             */
/*   Updated: 2020/04/15 19:49:47 by afukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int len;

	if (!lst)
		return (0);
	len = 1;
	while (lst->next)
	{
		lst = lst->next;
		len++;
	}
	return (len);
}
