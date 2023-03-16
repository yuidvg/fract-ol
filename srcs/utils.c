/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynishimu <ynishimu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 18:56:22 by ynishimu          #+#    #+#             */
/*   Updated: 2023/03/16 22:29:43 by ynishimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	putpixel_to_image(t_image *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

size_t	iters_till_2(t_fractol *f)
{
	size_t	i;
	double	tmp;

	i = 0;
	while (i < f->max_iters
		&& f->z.real * f->z.real + f->z.imaginary * f->z.imaginary < 4)
	{
		tmp = f->z.real * f->z.real
			- f->z.imaginary * f->z.imaginary + f->c.real;
		f->z.imaginary = 2 * f->z.real * f->z.imaginary + f->c.imaginary;
		f->z.real = tmp;
		i++;
	}
	return (i);
}

int	print_help(int retval)
{
	ft_printf("Invalid Parameters.\nFollow these formats:\n");
	ft_printf("Mandelbrot\n");
	ft_printf("Julia [(real part of the seed) (imaginary part of the seed)]\n");
	ft_printf("Fern\n");
	return (retval);
}
