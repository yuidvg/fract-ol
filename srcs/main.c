/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynishimu <ynishimu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 14:27:28 by ynishimu          #+#    #+#             */
/*   Updated: 2023/03/11 20:11:18 by ynishimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int	main(int argc, char *argv[])
{
	t_mlx		mlx;
	t_viewport	viewport;

	(void)argc;
	(void)argv;
	mlx.ptr = mlx_init();
	mlx.window = mlx_new_window(mlx.ptr, WIN_W, WIN_H, "fract_ol");
	mlx.image.img = mlx_new_image(mlx.ptr, WIN_W, WIN_H);
	mlx.image.addr = mlx_get_data_addr(mlx.image.img, &mlx.image.bpp,
			&mlx.image.line_len, &mlx.image.endian);
	draw_mandelbrot_to_image(&mlx.image, &viewport);
	mlx_put_image_to_window(mlx.ptr, mlx.window, mlx.image.img, 0, 0);
	// mlx_mouse_hook(mlx.window, mouse_hook, &vars);
	// mlx_key_hook(mlx.ptr, key_hook, &mlx);
	mlx_loop(mlx.ptr);
}
