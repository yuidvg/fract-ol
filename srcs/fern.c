/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fern.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynishimu <ynishimu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 23:02:45 by ynishimu          #+#    #+#             */
/*   Updated: 2023/03/14 23:56:41 by ynishimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

// this function draws Barnsley fern to the window

void	draw_fern_to_window(t_fractol *f)
{
	int		i;
	int		x;
	int		y;
	double	x1;
	double	y1;
	double	x2;
	double	y2;
	double	r;

	i = 0;
	x = 0;
	y = 0;
	x1 = 0;
	y1 = 0;
	x2 = 0;
	y2 = 0;
	r = 0;
	while (i < 100000)
	{
		r = ft_random() % 100;
		if (r < 1)
		{
			x2 = 0;
			y2 = 0.16 * y1;
		}
		else if (r < 86)
		{
			x2 = 0.85 * x1 + 0.04 * y1;
			y2 = -0.04 * x1 + 0.85 * y1 + 1.6;
		}
		else if (r < 93)
		{
			x2 = 0.2 * x1 - 0.26 * y1;
			y2 = 0.23 * x1 + 0.22 * y1 + 1.6;
		}
		else
		{
			x2 = -0.15 * x1 + 0.28 * y1;
			y2 = 0.26 * x1 + 0.24 * y1 + 0.44;
		}
		x = (int)(x2 * 100 + 400);
		y = (int)(y2 * 100 + 400);
		putpixel_to_image(&f->mlx.image, x, y, 0x00FFFFFF);
		x1 = x2;
		y1 = y2;
		i++;
	}
	mlx_put_image_to_window(f->mlx.ptr, f->mlx.window, f->mlx.image.ptr, 0, 0);
}
