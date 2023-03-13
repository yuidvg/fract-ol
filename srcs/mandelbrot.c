/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynishimu <ynishimu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 20:06:14 by ynishimu          #+#    #+#             */
/*   Updated: 2023/03/10 00:12:28 by ynishimu         ###   ########.fr       */
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
	while (i < MAX_ITERS && z.real * z.real + z.imaginary * z.imaginary < 4)
	{
		tmp = z.real * z.real - z.imaginary * z.imaginary + c->real;
		z.imaginary = 2 * z.real * z.imaginary + c->imaginary;
		z.real = tmp;
		i++;
	}
	return (i);
}

static int	color_of_pixel(t_viewport *viewport)
{
	t_complex	c;

	c.real = (viewport->x - viewport->offset_x) / viewport->scale;
	c.imaginary = (viewport->y - viewport->offset_y) / viewport->scale;

	return (iters_to_color(iters_till_2(&c)));
}

void	draw_mandelbrot_to_image(t_image *image, t_viewport *viewport)
{
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
