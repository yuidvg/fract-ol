/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynishimu <ynishimu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 13:03:44 by ynishimu          #+#    #+#             */
/*   Updated: 2023/03/14 12:19:53 by ynishimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int	mouse_hook(int button, int x, int y, t_fractol *f)
{
	(void)x;
	(void)y;
	if (button == MOUSE_SCROLL_UP)
	{
		f->viewport.scale *= 1.1;
		// view->port.offset_x += (x - WIN_W / 2) * view->port.scale;
		// view->port.offset_y += (y - WIN_H / 2) * view->port.scale;
	}
	else if (button == MOUSE_SCROLL_DOWN)
	{
		f->viewport.scale /= 1.1;
		// view->port.offset_x -= (x - WIN_W / 2) * view->port.scale;
		// view->port.offset_y -= (y - WIN_H / 2) * view->port.scale;
	}
	if (button == MOUSE_SCROLL_UP || button == MOUSE_SCROLL_DOWN)
	{
		if (f->type == MANDELBROT)
			draw_mandelbrot_to_window(f);
		if (f->type == JULIA)
			draw_julia_to_window(f);
	}
	return (0);
}

int	key_hook(int key, t_fractol *f)
{
	if (key == KEY_ESC)
	{
		mlx_destroy_image(f->mlx.ptr, f->mlx.image.ptr);
		mlx_destroy_window(f->mlx.ptr, f->mlx.window);
		exit(0);
	}
	if (key == KEY_LEFT)
		f->viewport.offset_x += 10;
	if (key == KEY_RIGHT)
		f->viewport.offset_x -= 10;
	if (key == KEY_UP)
		f->viewport.offset_y += 10;
	if (key == KEY_DOWN)
		f->viewport.offset_y -= 10;
	if (key == KEY_LEFT || key == KEY_RIGHT || key == KEY_UP || key == KEY_DOWN)
	{
		if (f->type == MANDELBROT)
			draw_mandelbrot_to_window(f);
		if (f->type == JULIA)
			draw_julia_to_window(f);
	}
	return (0);
}
