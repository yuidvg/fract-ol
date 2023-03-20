/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynishimu <ynishimu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 16:16:36 by ynishimu          #+#    #+#             */
/*   Updated: 2023/01/26 19:09:11 by ynishimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strmatch(const char *haystack, const char *needle)
{
	size_t	i;

	i = 0;
	while (needle[i] != '\0')
	{
		if (haystack[i] != needle[i])
			return (0);
		i++;
	}
	return (1);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;

	i = 0;
	if (*needle == '\0')
		return ((char *)haystack);
	if (len == 0 && !haystack)
		return (NULL);
	while (i < len && haystack[i] != '\0')
	{
		if (ft_strmatch((char *)haystack + i, needle)
			&& i + ft_strlen(needle) <= len)
			return ((char *)haystack + i);
		i++;
	}
	return (NULL);
}
