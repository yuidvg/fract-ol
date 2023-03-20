/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynishimu <ynishimu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 21:09:42 by ynishimu          #+#    #+#             */
/*   Updated: 2023/02/25 21:51:14 by ynishimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_malloc(size_t size, void *asnd_0, void *asnd_1, void *asnd_2)
{
	void	*allocated;

	allocated = malloc(size);
	if (!allocated)
		ft_exit(-1, asnd_0, asnd_1, asnd_2);
	return (allocated);
}
