/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynishimu <ynishimu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 14:32:49 by ynishimu          #+#    #+#             */
/*   Updated: 2023/01/17 23:50:14 by ynishimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;
	t_list	*tmp_next;

	if (!lst || !del)
		return ;
	tmp = *lst;
	tmp_next = *lst;
	while (tmp)
	{
		tmp_next = tmp->next;
		if (tmp->content)
			del(tmp->content);
		if (tmp)
			free(tmp);
		tmp = tmp_next;
	}
	*lst = NULL;
}
