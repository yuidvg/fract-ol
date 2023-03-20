/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynishimu <ynishimu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 18:02:49 by ynishimu          #+#    #+#             */
/*   Updated: 2023/02/26 17:36:03 by ynishimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t	putfmtd(char exp, va_list ap)
{
	if (exp == 'c')
		return (ft_putchr((char)va_arg(ap, int)));
	if (exp == 's')
		return (ft_putstr(va_arg(ap, char *)));
	if (exp == 'p')
		return (ft_putptr((uintptr_t)va_arg(ap, void *)));
	if (exp == 'd' || exp == 'i')
		return (ft_putnbr(va_arg(ap, int)));
	if (exp == 'u')
		return (ft_putunbr(va_arg(ap, unsigned int)));
	if (exp == 'x')
		return (ft_puthex_l(va_arg(ap, unsigned int)));
	if (exp == 'X')
		return (ft_puthex_u(va_arg(ap, unsigned int)));
	if (exp == '%')
		return (ft_putchr('%'));
	return (0);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	size_t	i;
	ssize_t	ptd;

	i = 0;
	ptd = 0;
	va_start(ap, fmt);
	while (fmt[i])
	{
		if (fmt[i] != '%')
			ptd += ft_putchr(fmt[i]);
		else
		{
			i++;
			ptd += putfmtd(fmt[i], ap);
		}
		i++;
	}
	va_end(ap);
	return (ptd);
}
