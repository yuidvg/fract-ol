/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynishimu <ynishimu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 13:33:05 by ynishimu          #+#    #+#             */
/*   Updated: 2023/01/26 19:56:59 by ynishimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	string[11];
	size_t	length;

	if (fd < 0)
		return ;
	length = 0;
	if (n < 0)
	{
		if (n == -2147483648)
		{
			write(fd, "-2147483648", 11);
			return ;
		}
		write(fd, "-", 1);
		n *= -1;
	}
	if (n == 0)
		write(fd, "0", 1);
	while (n)
	{
		string[10 - length] = "0123456789"[n % 10];
		n /= 10;
		length++;
	}
	write(fd, string + 11 - length, length);
}
