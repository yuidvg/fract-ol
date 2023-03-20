/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchrs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynishimu <ynishimu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 12:38:42 by ynishimu          #+#    #+#             */
/*   Updated: 2023/02/13 13:13:38 by ynishimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t	ft_putchr(char c)
{
	return (write(STDOUT_FILENO, &c, 1));
}

ssize_t	ft_putstr(char *str)
{
	ssize_t	i;

	if (!str)
		return (ft_putstr("(null)"));
	i = 0;
	while (str[i])
	{
		ft_putchr(str[i]);
		i++;
	}
	return (i);
}
