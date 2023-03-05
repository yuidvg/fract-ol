/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynishimu <ynishimu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 15:21:07 by ynishimu          #+#    #+#             */
/*   Updated: 2023/03/04 15:27:19 by ynishimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

static void	hsv_to_rgb(t_color color)
{
	int	rgb;


}

int	iters_to_color(size_t iters)
{
	t_color	color;

	color.h = iters_to_hue(iters);
	color.s = 100;
	color.v = 50;
	return ();
}
