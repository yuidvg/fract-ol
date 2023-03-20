/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynishimu <ynishimu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 14:34:32 by ynishimu          #+#    #+#             */
/*   Updated: 2023/02/27 11:51:23 by ynishimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	strlen_nullable(const char *const str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strappend(char *save, const char *const buf)
{
	char	*apnd;
	size_t	i;
	size_t	save_len;
	size_t	buf_len;

	save_len = strlen_nullable(save);
	buf_len = strlen_nullable(buf);
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

size_t	ft_strlen_c(const char *const str, int c)
{
	size_t	i;
	size_t	len;

	if (!str)
		return (0);
	i = 0;
	len = strlen_nullable(str);
	while (i < len)
	{
		if (str[i] == (char)c)
			return (i + 1);
		i++;
	}
	return (0);
}

char	*get_line(const char *const save)
{
	char	*line;
	size_t	i;
	size_t	line_len;

	i = 0;
	line_len = ft_strlen_c(save, '\n');
	if (line_len == 0)
		line_len = strlen_nullable(save);
	if (line_len == 0)
		return (NULL);
	line = (char *)malloc(sizeof(char) * (line_len + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (i < line_len)
	{
		line[i] = save[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*get_save(char *old_save)
{
	char	*new_save;
	size_t	i;
	size_t	j;

	i = 0;
	if (!old_save)
		return (NULL);
	while (old_save[i] != '\n' && old_save[i] != '\0')
		i++;
	if (old_save[i] == '\0')
	{
		free(old_save);
		return (NULL);
	}
	new_save = (char *)malloc((strlen_nullable(old_save) - i + 1));
	if (!new_save)
		return (NULL);
	i++;
	j = 0;
	while (old_save[i])
		new_save[j++] = old_save[i++];
	new_save[j] = '\0';
	free(old_save);
	return (new_save);
}
