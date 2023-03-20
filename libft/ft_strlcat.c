/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynishimu <ynishimu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 16:05:52 by ynishimu          #+#    #+#             */
/*   Updated: 2023/01/19 16:36:01 by ynishimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	dst_len;

	i = 0;
	if (!dst && dstsize == 0)
		return (ft_strlen(src));
	dst_len = ft_strlen(dst);
	if (dstsize == 0 || dstsize < ft_strlen(dst))
		return (dstsize + ft_strlen(src));
	while (dst[i] != '\0')
		i++;
	while (i < dstsize - 1 && src[i - dst_len] != '\0')
	{
		dst[i] = src[i - dst_len];
		i++;
	}
	dst[i] = '\0';
	return (dst_len + ft_strlen(src));
}
