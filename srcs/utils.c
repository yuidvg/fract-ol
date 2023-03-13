/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynishimu <ynishimu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 18:56:22 by ynishimu          #+#    #+#             */
/*   Updated: 2023/03/13 21:31:22 by ynishimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	putpixel_to_image(t_image *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

size_t	iters_till_2(t_complex *z, t_complex *c)
{
	size_t	i;
	double	tmp;

	i = 0;
	while (i < MAX_ITERS && z->real * z->real + z->imaginary * z->imaginary < 4)
	{
		tmp = z->real * z->real - z->imaginary * z->imaginary + c->real;
		z->imaginary = 2 * z->real * z->imaginary + c->imaginary;
		z->real = tmp;
		i++;
	}
	return (i);
}
