/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynishimu <ynishimu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 14:34:30 by ynishimu          #+#    #+#             */
/*   Updated: 2023/02/10 13:56:28 by ynishimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	*saves[OPEN_MAX + 1];
	char		*ret;
	char		buf[BUFFER_SIZE + 1];
	ssize_t		read_size;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	read_size = 1;
	while (read_size != 0 && ft_strlen_c(saves[fd], '\n') == 0)
	{
		read_size = read(fd, buf, BUFFER_SIZE);
		if (read_size < 0)
		{
			free(saves[fd]);
			return (NULL);
		}
		buf[read_size] = '\0';
		saves[fd] = ft_strappend(saves[fd], buf);
	}
	ret = get_line(saves[fd]);
	saves[fd] = get_save(saves[fd]);
	return (ret);
}
