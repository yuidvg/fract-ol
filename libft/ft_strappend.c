/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strappend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynishimu <ynishimu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 17:33:54 by ynishimu          #+#    #+#             */
/*   Updated: 2023/02/26 17:17:19 by ynishimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strappend(char *save, const char *const buf)
{
	char	*apnd;
	size_t	i;
	size_t	save_len;
	size_t	buf_len;

	save_len = ft_strlen(save);
	buf_len = ft_strlen(buf);
	apnd = (char *)malloc(sizeof(char) * (save_len + buf_len + 1));
	if (!apnd)
		return (NULL);
	i = 0;
	while (i < save_len)
	{
		apnd[i] = save[i];
		i++;
	}
	while (i < (save_len + buf_len))
	{
		apnd[i] = buf[i - save_len];
		i++;
	}
	apnd[i] = '\0';
	free(save);
	return (apnd);
}
