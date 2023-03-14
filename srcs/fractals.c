/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynishimu <ynishimu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 19:54:37 by ynishimu          #+#    #+#             */
/*   Updated: 2023/03/14 12:16:22 by ynishimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	draw_fractal_to_window(t_fractol *f)
{
	if (f->type == MANDELBROT)
	{
		f->viewport.offset_x = 2 * WIN_W / 3;
		f->viewport.offset_y = WIN_H / 2;
		f->viewport.scale = 500;
		draw_mandelbrot_to_window(f);
	}
	if (f->type == JULIA)
	{
		f->viewport.offset_x = WIN_W / 2;
		f->viewport.offset_y = WIN_H / 2;
		f->viewport.scale = 400;
		draw_julia_to_window(f);
	}
}
