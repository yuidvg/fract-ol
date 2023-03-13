/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynishimu <ynishimu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 13:30:03 by ynishimu          #+#    #+#             */
/*   Updated: 2023/03/13 22:35:40 by ynishimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	draw_julia_to_window(t_fractol *f)
{
	f->viewport.offset_x = WIN_W / 2;
	f->viewport.offset_y = WIN_H / 2;
	f->viewport.scale = 2;
	f->viewport.y = 0;
	while (f->viewport.y < WIN_H)
	{
		f->viewport.x = 0;
		while (f->viewport.x < WIN_W)
		{
			f->z.real
				= (f->viewport.x - f->viewport.offset_x) / f->viewport.scale;
			f->z.imaginary
				= (f->viewport.y - f->viewport.offset_y) / f->viewport.scale;
			putpixel_to_image(&f->mlx.image, f->viewport.x, f->viewport.y,
				iters_to_color(iters_till_2(&f->z, &f->c)));
			f->viewport.x++;
		}
		f->viewport.y++;
	}
	mlx_put_image_to_window(f->mlx.ptr, f->mlx.window, f->mlx.image.ptr, 0, 0);
}
