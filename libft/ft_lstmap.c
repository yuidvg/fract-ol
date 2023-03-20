/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynishimu <ynishimu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 15:28:42 by ynishimu          #+#    #+#             */
/*   Updated: 2023/01/19 13:07:09 by ynishimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*node;

	if (!lst || !f || !del)
		return (NULL);
	new_lst = ft_lstnew(f(lst->content));
	if (!new_lst)
	{
		ft_lstclear(&new_lst, del);
		return (NULL);
	}
	node = new_lst;
	while (lst->next)
	{
		lst = lst->next;
		node->next = ft_lstnew(f(lst->content));
		if (!(node->next))
		{
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		node = node->next;
	}
	return (new_lst);
}
