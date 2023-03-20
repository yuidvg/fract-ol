/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynishimu <ynishimu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 20:41:52 by ynishimu          #+#    #+#             */
/*   Updated: 2023/02/26 17:35:15 by ynishimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stddef.h>
# include <limits.h>

int		ft_printf(const char *fmt, ...);
ssize_t	putfmtd(char c, va_list ap);
ssize_t	ft_putchr(char c);
ssize_t	ft_putstr(char *str);
ssize_t	ft_putnbr(int n);
ssize_t	ft_putunbr(unsigned int n);
ssize_t	ft_puthex_l(unsigned int n);
ssize_t	ft_puthex_u(unsigned int n);
ssize_t	ft_putptr(uintptr_t ptr);

#endif
