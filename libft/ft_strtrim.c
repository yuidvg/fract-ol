/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynishimu <ynishimu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 18:18:36 by ynishimu          #+#    #+#             */
/*   Updated: 2023/01/17 23:56:01 by ynishimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	i;
	size_t	j;
	size_t	k;

	if (!s1 || !set)
		return (NULL);
	if (*set == '\0' || *s1 == '\0')
		return (ft_strdup(s1));
	i = 0;
	j = ft_strlen(s1) - 1;
	while (s1[i] != '\0' && ft_strchr(set, s1[i]))
		i++;
	while (j > i && ft_strchr(set, s1[j]))
		j--;
	str = (char *)malloc(j - i + 2);
	if (!str)
		return (NULL);
	k = 0;
	while (i <= j)
		str[k++] = s1[i++];
	str[k] = '\0';
	return (str);
}
