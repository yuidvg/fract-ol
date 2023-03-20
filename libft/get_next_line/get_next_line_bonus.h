/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynishimu <ynishimu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 14:34:27 by ynishimu          #+#    #+#             */
/*   Updated: 2023/02/27 12:04:26 by ynishimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

char	*get_next_line(int fd);
char	*ft_strappend(char *save, const char *const buf);
size_t	strlen_nullable(const char *const str);
size_t	ft_strlen_c(const char *const str, int c);
char	*get_line(const char *const save);
char	*get_save(char *save);

#endif