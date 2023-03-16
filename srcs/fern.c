/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fern.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynishimu <ynishimu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 22:01:07 by ynishimu          #+#    #+#             */
/*   Updated: 2023/03/16 22:01:11 by ynishimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

static void	move(double *x, double *y, double random)
{
	if (random < 0.01)
	{
		*x = 0;
		*y = 0.16 * *y;
	}
	else if (random < 0.85)
	{
		*x = 0.85 * *x + 0.04 * *y;
		*y = -0.04 * *x + 0.85 * *y + 1.6;
	}
	else if (random < 0.93)
	{
		*x = 0.2 * *x - 0.26 * *y;
		*y = 0.23 * *x + 0.22 * *y + 1.6;
	}
	else
	{
		*x = -0.15 * *x + 0.28 * *y;
		*y = 0.26 * *x + 0.24 * *y + 0.44;
	}
}

uint32_t	xorshift(t_xorshift *seed)
{
	uint32_t		t;

	t = seed->x ^ (seed->x << 11);
	seed->x = seed->y;
	seed->y = seed->z;
	seed->z = seed->w;
	seed->w ^= t ^ (t >> 8) ^ (seed->w >> 19);
	return (seed->w);
}

static void	wipe_image(t_image *img, int color)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < WIN_W)
	{
		j = 0;
		while (j < WIN_H)
		{
			putpixel_to_image(img, i, j, color);
			j++;
		}
		i++;
	}
}

static void	set_color(t_color *color,
	double hue, double saturation, double value)
{
	color->hue = hue;
	color->saturation = saturation;
	color->value = value;
}

void	draw_fern_to_window(t_fractol *f)
{
	size_t		i;
	t_color		color;

	i = 0;
	wipe_image(&f->mlx.image, 0x000000);
	while (i < f->max_iters)
	{
		move(&f->viewport.x, &f->viewport.y,
			(double)xorshift(&f->seed) / (double)UINT32_MAX);
		if (f->viewport.x * f->viewport.scale + f->viewport.offset_x < WIN_W
			&& f->viewport.x * f->viewport.scale + f->viewport.offset_x > 0
			&& f->viewport.y * f->viewport.scale + f->viewport.offset_y < WIN_H
			&& f->viewport.y * f->viewport.scale + f->viewport.offset_y > 0)
		{
			set_color(&color, i * 360 / f->max_iters, 1, 1);
			putpixel_to_image(&f->mlx.image,
				f->viewport.x * f->viewport.scale + f->viewport.offset_x,
				f->viewport.y * f->viewport.scale + f->viewport.offset_y,
				hsv_to_rgb(&color));
		}
		i++;
	}
	mlx_put_image_to_window(f->mlx.ptr, f->mlx.window, f->mlx.image.ptr, 0, 0);
}
