/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynishimu <ynishimu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 20:06:14 by ynishimu          #+#    #+#             */
/*   Updated: 2023/03/02 15:54:42 by ynishimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

static size_t	iters_till_2(t_complex *c)
{
	size_t		i;
	t_complex	z;
	double		tmp;

	z.real = 0;
	z.imaginary = 0;
	while (i < MAX_ITER && z.real ^ 2 + z.imaginary ^ 2 < 4)
	{
		tmp = pow(z.real, 2.0) - pow(z.imaginary, 2.0) + c->real;
		z.imaginary = 2 * z.real * z.imaginary + c->imaginary;
		z.real = tmp;
		i++;
	}
	return (i * (i < MAX_ITER));
}

static int	color_of_pixel(size_t window_x, size_t window_y)
{
	int			color;
	t_complex	c;

	c.real = window_x;
	c.imaginary = window_y;
	if (iters_till_2(&c))
		color = 0x00ffffff;
	return (color);
}

void	draw_mandelbrot_to_image(t_image *image)
{
	size_t	window_x;
	size_t	window_y;

	window_x = 0;
	window_y = 0;
	while (window_y < WIN_H)
	{
		while (window_x < WIN_W)
		{
			putpixel_to_image(image, window_x, window_y,
				color_of_pixel(window_x, window_y));
		}
	}
}
