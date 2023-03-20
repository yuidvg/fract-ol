/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnums.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynishimu <ynishimu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 13:50:58 by ynishimu          #+#    #+#             */
/*   Updated: 2023/02/26 17:40:42 by ynishimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t	ft_putnbr(int n)
{
	ssize_t	i;

	i = 0;
	if (n == -2147483648)
	{
		ft_putstr("-2147483648");
		return (11);
	}
	if (n < 0)
	{
		ft_putchr('-');
		n = -n;
		i++;
	}
	if (n >= 10)
	{
		i += ft_putnbr(n / 10);
		i += ft_putnbr(n % 10);
	}
	else
	{
		ft_putchr(n + '0');
		i++;
	}
	return (i);
}

ssize_t	ft_putunbr(unsigned int n)
{
	ssize_t	ptd;

	ptd = 0;
	if (n >= 10)
		ptd += ft_putunbr(n / 10);
	ptd += ft_putchr("0123456789"[n % 10]);
	return (ptd);
}

ssize_t	ft_puthex_l(unsigned int n)
{
	ssize_t	ptd;

	ptd = 0;
	if (n >= 16)
		ptd += ft_puthex_l(n / 16);
	ptd += ft_putchr("0123456789abcdef"[n % 16]);
	return (ptd);
}

ssize_t	ft_puthex_u(unsigned int n)
{
	ssize_t	ptd;

	ptd = 0;
	if (n >= 16)
		ptd += ft_puthex_l(n / 16);
	ptd += ft_putchr("0123456789ABCDEF"[n % 16]);
	return (ptd);
}

ssize_t	ft_putptr(uintptr_t ptr)
{
	ssize_t	ptd;

	ptd = 0;
	if (ptr >= 16)
		ptd += ft_putptr(ptr / 16);
	else
		ptd += ft_putstr("0x");
	ptd += ft_putchr("0123456789abcdef"[ptr % 16]);
	return (ptd);
}
