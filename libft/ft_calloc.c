/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynishimu <ynishimu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 17:10:00 by ynishimu          #+#    #+#             */
/*   Updated: 2023/01/19 13:40:23 by ynishimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*alcd_ptr;

	if (size != 0 && count > SIZE_MAX / size)
		return (NULL);
	alcd_ptr = malloc(count * size);
	if (!alcd_ptr)
		return (NULL);
	ft_bzero(alcd_ptr, count * size);
	return (alcd_ptr);
}
