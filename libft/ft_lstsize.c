/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynishimu <ynishimu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 22:10:51 by ynishimu          #+#    #+#             */
/*   Updated: 2023/01/17 23:51:57 by ynishimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*node;
	size_t	size;

	if (!lst)
		return (0);
	size = 0;
	node = lst;
	while (node)
	{
		node = node->next;
		size++;
	}
	return (size);
}
