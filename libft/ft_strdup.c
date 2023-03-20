/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynishimu <ynishimu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 17:55:44 by ynishimu          #+#    #+#             */
/*   Updated: 2023/02/26 21:02:52 by ynishimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	dstsize;
	char	*dst;

	dstsize = ft_strlen(s1)+ 1;
	dst = malloc(dstsize);
	if (!dst)
		return (NULL);
	if (ft_strlcpy(dst, s1, dstsize) >= dstsize)
		return (NULL);
	return (dst);
}
