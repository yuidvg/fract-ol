/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynishimu <ynishimu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 13:03:44 by ynishimu          #+#    #+#             */
/*   Updated: 2023/03/10 00:09:53 by ynishimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int	mouse_hook(int button, int x, int y, t_graphics *view)
{
	(void)x;
	(void)y;
	if (button == MOUSE_SCROLL_UP)
	{
		view->port.scale *= 1.1;
		// view->port.offset_x += (x - WIN_W / 2) * view->port.scale;
		// view->port.offset_y += (y - WIN_H / 2) * view->port.scale;
	}
	else if (button == MOUSE_SCROLL_DOWN)
	{
		view->port.scale /= 1.1;
		// view->port.offset_x -= (x - WIN_W / 2) * view->port.scale;
		// view->port.offset_y -= (y - WIN_H / 2) * view->port.scale;
	}
	// mlx_clear_window(view->mlx, view->window);
	draw_mandelbrot_to_image(&view->image, &view->port);
	mlx_put_image_to_window(view->mlx, view->window, view->image.ptr, 0, 0);
	return (0);
}

int	key_hook(int key, t_graphics *view)
{
	if (key == KEY_ESC)
	{
		mlx_destroy_image(view->mlx, view->image.ptr);
		mlx_destroy_window(view->mlx, view->window);
		exit(0);
	}
	if (key == KEY_LEFT)
		view->port.offset_x += 10;
	if (key == KEY_RIGHT)
		view->port.offset_x -= 10;
	if (key == KEY_UP)
		view->port.offset_y += 10;
	if (key == KEY_DOWN)
		view->port.offset_y -= 10;
	if (key == KEY_LEFT || key == KEY_RIGHT || key == KEY_UP || key == KEY_DOWN)
	{
		draw_mandelbrot_to_image(&view->image, &view->port);
		mlx_put_image_to_window(view->mlx, view->window, view->image.ptr, 0, 0);
	}
	return (0);
}
