/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afukuhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/16 10:56:15 by afukuhar          #+#    #+#             */
/*   Updated: 2020/04/16 18:53:59 by afukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*tmp;

	if (!lst || !(tmp = ft_lstnew(f(lst->content))))
		return (NULL);
	new_lst = tmp;
	while (lst->next)
	{
		lst = lst->next;
		if (!(tmp = ft_lstnew(f(lst->content))))
			return (NULL);
		ft_lstadd_back(&new_lst, tmp);
		tmp = tmp->next;
		if (tmp)
			ft_lstdelone(tmp, del);
	}
	return (new_lst);
}
