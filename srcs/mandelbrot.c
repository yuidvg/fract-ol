/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynishimu <ynishimu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 20:06:14 by ynishimu          #+#    #+#             */
/*   Updated: 2023/03/13 22:37:10 by ynishimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	draw_mandelbrot_to_window(t_fractol *f)
{
	f->viewport.offset_x = 2 * WIN_W / 3;
	f->viewport.offset_y = WIN_H / 2;
	f->viewport.scale = 500;
	f->z.real = 0;
	f->z.imaginary = 0;
	f->viewport.y = 0;
	while (f->viewport.y < WIN_H)
	{
		f->viewport.x = 0;
		while (f->viewport.x < WIN_W)
		{
			f->c.real
				= (f->viewport.x - f->viewport.offset_x) / f->viewport.scale;
			f->c.imaginary
				= (f->viewport.y - f->viewport.offset_y) / f->viewport.scale;
			putpixel_to_image(&f->mlx.image, f->viewport.x, f->viewport.y,
				iters_to_color(iters_till_2(&f->z, &f->c)));
			f->viewport.x++;
		}
		f->viewport.y++;
	}
	mlx_put_image_to_window(f->mlx.ptr, f->mlx.window, f->mlx.image.ptr, 0, 0);
}
