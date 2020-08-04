/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afukuhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/15 19:59:20 by afukuhar          #+#    #+#             */
/*   Updated: 2020/04/15 20:23:55 by afukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list *tmp;

	tmp = *lst;
	while (tmp)
	{
		del(tmp->content);
		tmp = tmp->next;
		free(*lst);
		*lst = tmp;
	}
	lst = NULL;
}
