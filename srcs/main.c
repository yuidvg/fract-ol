/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynishimu <ynishimu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 14:27:28 by ynishimu          #+#    #+#             */
/*   Updated: 2023/03/16 21:53:39 by ynishimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

static int	set_type(t_fractal_type *type, char *arg)
{
	if (ft_strncmp("Mandelbrot", arg, ft_strlen(arg)) == 0)
	{
		*type = MANDELBROT;
		return (0);
	}
	else if (ft_strncmp("Julia", arg, ft_strlen(arg)) == 0)
	{
		*type = JULIA;
		return (0);
	}
	else if (ft_strncmp("Fern", arg, ft_strlen(arg)) == 0)
	{
		*type = FERN;
		return (0);
	}
	return (-1);
}

static int	set_complex(t_complex *c, char *real, char *imaginary)
{
	if (set_atod(&c->real, real))
		return (-1);
	if (set_atod(&c->imaginary, imaginary))
		return (-1);
	return (0);
}

static int	init_mlx(t_fractol *f, char *type)
{
	f->mlx.ptr = mlx_init();
	f->mlx.window
		= mlx_new_window(f->mlx.ptr, WIN_W, WIN_H, type);
	f->mlx.image.ptr = mlx_new_image(f->mlx.ptr, WIN_W, WIN_H);
	f->mlx.image.addr = mlx_get_data_addr(f->mlx.image.ptr, &f->mlx.image.bpp,
			&f->mlx.image.line_len, &f->mlx.image.endian);
	mlx_hook(f->mlx.window, 2, 0, key_hook, f);
	mlx_hook(f->mlx.window, 4, 0, mouse_hook, f);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_fractol	f;

	if (!(argc == 2 || argc == 4))
		return (print_help(0));
	else if (set_type(&f.type, argv[1]))
		return (print_help(0));
	else if ((f.type == MANDELBROT || f.type == FERN) && argc != 2)
		return (print_help(0));
	else if (f.type == JULIA && !(argc == 2 || argc == 4))
		return (print_help(0));
	if (f.type == JULIA && argc == 4)
	{
		if (set_complex(&f.c, argv[2], argv[3]))
			return (print_help(0));
	}
	else if (f.type == JULIA && argc == 2)
	{
		f.c.real = -0.7;
		f.c.imaginary = 0.27015;
	}
	init_mlx(&f, argv[1]);
	init_settings(&f);
	draw_fractal_to_window(&f);
	mlx_loop(f.mlx.ptr);
}
