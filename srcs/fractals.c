/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynishimu <ynishimu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 19:54:37 by ynishimu          #+#    #+#             */
/*   Updated: 2023/03/13 22:36:39 by ynishimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	draw_fractal_to_window(t_fractol *f)
{
	if (f->type == MANDELBROT)
		draw_mandelbrot_to_window(f);
	if (f->type == JULIA)
		draw_julia_to_window(f);
}
