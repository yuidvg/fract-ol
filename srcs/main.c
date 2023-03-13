/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynishimu <ynishimu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 14:27:28 by ynishimu          #+#    #+#             */
/*   Updated: 2023/03/13 12:40:34 by ynishimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int	main(int argc, char *argv[])
{
	t_graphics		view;

	(void)argc;
	(void)argv;
	view.mlx = mlx_init();
	view.window
		= mlx_new_window(view.mlx, WIN_W, WIN_H, "fract_ol");
	view.image.ptr = mlx_new_image(view.mlx, WIN_W, WIN_H);
	view.image.addr = mlx_get_data_addr(view.image.ptr, &view.image.bpp,
			&view.image.line_len, &view.image.endian);
	view.port.offset_x = 2 * WIN_W / 3;
	view.port.offset_y = WIN_H / 2;
	view.port.scale = 500;
	draw_mandelbrot_to_image(&view.image, &view.port);
	mlx_put_image_to_window(view.mlx, view.window, view.image.ptr, 0, 0);
	mlx_mouse_hook(view.window, mouse_hook, &view);
	mlx_key_hook(view.window, key_hook, &view);
	mlx_loop(view.mlx);
}
