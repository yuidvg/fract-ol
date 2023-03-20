/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynishimu <ynishimu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 15:21:07 by ynishimu          #+#    #+#             */
/*   Updated: 2023/03/20 13:51:51 by ynishimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol_bonus.h"

static int	get_rgb(double r, double g, double b, double m)
{
	int	rgb;

	rgb = 0x00000000;
	rgb += (int)((r + m) * 255);
	rgb <<= sizeof(int) * 8 / 4;
	rgb += (int)((g + m) * 255);
	rgb <<= sizeof(int) * 8 / 4;
	rgb += (int)((b + m) * 255);
	return (rgb);
}

int	hsv_to_rgb(t_color *color)
{
	double	c;
	double	x;
	double	m;

	c = color->value * color->saturation;
	x = c * (1 - fabs(fmod(color->hue / 60, 2) - 1));
	m = color->value - c;
	if (color->hue < 60)
		return (get_rgb(c, x, 0, m));
	else if (color->hue < 120)
		return (get_rgb(x, c, 0, m));
	else if (color->hue < 180)
		return (get_rgb(0, c, x, m));
	else if (color->hue < 240)
		return (get_rgb(0, x, c, m));
	else if (color->hue < 300)
		return (get_rgb(x, 0, c, m));
	else
		return (get_rgb(c, 0, x, m));
}

int	iters_to_color(size_t iters, t_fractol *f)
{
	t_color	color;

	if (iters == f->max_iters)
		return (0x00000000);
	else
	{
		color.hue = (iters * 5) + f->shift % 360;
		color.saturation = 1;
		color.value = 1;
	}
	return (hsv_to_rgb(&color));
}
