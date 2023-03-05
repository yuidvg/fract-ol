/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynishimu <ynishimu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 20:06:14 by ynishimu          #+#    #+#             */
/*   Updated: 2023/03/03 20:21:20 by ynishimu         ###   ########.fr       */
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
	int			color;
	t_complex	c;

	color = 0x00000000;
	c.real = ((double_t)viewport->x - viewport->offset_x) / viewport->zoom;
	c.imaginary = ((double_t)viewport->y - viewport->offset_y) / viewport->zoom;
	if (iters_till_2(&c))
		color = 0x00ffffff;
	return (color);
}

void	draw_mandelbrot_to_image(t_image *image)
{
	t_viewport	viewport;

	viewport.y = 0;
	viewport.zoom = 400;
	viewport.offset_x = 3 * WIN_W / 4;
	viewport.offset_y = WIN_H / 2;
	while (viewport.y < WIN_H)
	{
		viewport.x = 0;
		while (viewport.x < WIN_W)
		{
			putpixel_to_image(image, viewport.x, viewport.y,
				color_of_pixel(&viewport));
			viewport.x++;
		}
		viewport.y++;
	}
}
