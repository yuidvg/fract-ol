/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynishimu <ynishimu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 20:06:14 by ynishimu          #+#    #+#             */
/*   Updated: 2023/03/05 20:50:27 by ynishimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

static size_t	iters_till_2(t_complex *c)
{
	size_t		i;
	t_complex	z;
	double_t	tmp;

	z.real = 0;
	z.imaginary = 0;
	i = 0;
	while (i < MAX_ITER && pow(z.real, 2.0) + pow(z.imaginary, 2.0) < 4)
	{
		tmp = pow(z.real, 2.0) - pow(z.imaginary, 2.0) + c->real;
		z.imaginary = 2 * z.real * z.imaginary + c->imaginary;
		z.real = tmp;
		i++;
	}
	return (i * (i < MAX_ITER));
}

static int	color_of_pixel(t_viewport *viewport)
{
	int			color_rgb;
	t_complex	c;
	t_hsv		color_hsv;

	// color_rgb = 0x00000000;
	c.real = (viewport->x - viewport->offset_x) / viewport->zoom;
	c.imaginary = (viewport->y - viewport->offset_y) / viewport->zoom;

	if (iters_till_2(&c))
		color_rgb = 0x00ffffff;
	return (color_rgb);
}

void	draw_mandelbrot_to_image(t_image *image, t_viewport *viewport)
{
	viewport->offset_x = 2 * WIN_W / 3;
	viewport->offset_y = WIN_H / 2;
	viewport->zoom = 500;
	viewport->y = 0;
	while (viewport->y < WIN_H)
	{
		viewport->x = 0;
		while (viewport->x < WIN_W)
		{
			putpixel_to_image(image, viewport->x, viewport->y,
				color_of_pixel(viewport));
			viewport->x++;
		}
		viewport->y++;
	}
}
