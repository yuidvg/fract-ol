/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynishimu <ynishimu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 15:11:53 by ynishimu          #+#    #+#             */
/*   Updated: 2023/03/14 23:02:24 by ynishimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int	mouse_hook(int button, int x, int y, t_fractol *f)
{
	if (button == MOUSE_SCROLL_UP)
	{
		f->viewport.scale *= 1.1;
		f->viewport.offset_x
			+= 0.1 * (f->viewport.offset_x - x);
		f->viewport.offset_y
			+= 0.1 * (f->viewport.offset_y - y);
	}
	else if (button == MOUSE_SCROLL_DOWN)
	{
		f->viewport.scale /= 1.1;
		f->viewport.offset_x
			-= 0.1 / 1.1 * (f->viewport.offset_x - x);
		f->viewport.offset_y
			-= 0.1 / 1.1 * (f->viewport.offset_y - y);
	}
	else
		return (0);
	draw_fractal_to_window(f);
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
	else if (key == KEY_PLUS && f->max_iters < 1000)
		f->max_iters += 10;
	else if (key == KEY_MINUS && f->max_iters > 10)
		f->max_iters -= 10;
	else if (key == KEY_LEFT || key == KEY_A)
		f->viewport.offset_x += 10;
	else if (key == KEY_RIGHT || key == KEY_D)
		f->viewport.offset_x -= 10;
	else if (key == KEY_UP || key == KEY_W)
		f->viewport.offset_y += 10;
	else if (key == KEY_DOWN || key == KEY_S)
		f->viewport.offset_y -= 10;
	else if (key == KEY_COMMA && f->shift > 0)
		f->shift = (f->shift - 10) % 360;
	else if (key == KEY_PERIOD)
		f->shift = (f->shift + 10) % 360;
	else
		return (0);
	draw_fractal_to_window(f);
	return (0);
}
