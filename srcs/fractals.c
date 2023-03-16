/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynishimu <ynishimu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 19:54:37 by ynishimu          #+#    #+#             */
/*   Updated: 2023/03/16 22:07:47 by ynishimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

static void	set_seed(t_xorshift *seed)
{
	seed->x = 123456789;
	seed->y = 362436069;
	seed->z = 521288629;
	seed->w = 88675123;
}

void	init_settings(t_fractol *f)
{
	f->shift = 0;
	if (f->type == MANDELBROT)
	{
		f->max_iters = 50;
		f->viewport.offset_x = 2 * WIN_W / 3;
		f->viewport.offset_y = WIN_H / 2;
		f->viewport.scale = 500;
	}
	else if (f->type == JULIA)
	{
		f->max_iters = 50;
		f->viewport.offset_x = WIN_W / 2;
		f->viewport.offset_y = WIN_H / 2;
		f->viewport.scale = 400;
	}
	else if (f->type == FERN)
	{
		f->max_iters = 100000;
		f->viewport.offset_x = WIN_W / 2;
		f->viewport.offset_y = 0;
		f->viewport.x = 0;
		f->viewport.y = 0;
		f->viewport.scale = 100;
		set_seed(&f->seed);
	}
}

void	draw_fractal_to_window(t_fractol *f)
{
	if (f->type == MANDELBROT)
		draw_mandelbrot_to_window(f);
	if (f->type == JULIA)
		draw_julia_to_window(f);
	if (f->type == FERN)
		draw_fern_to_window(f);
}
