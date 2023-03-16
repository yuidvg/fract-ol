/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynishimu <ynishimu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 22:04:17 by ynishimu          #+#    #+#             */
/*   Updated: 2023/03/16 21:53:40 by ynishimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
# define FRACT_OL_H

# ifndef WIN_W
#  define WIN_W 1200
# endif
# ifndef WIN_H
#  define WIN_H 800
# endif

//libs
# include <math.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include <errno.h>

//local_libs
# include "../mlx/mlx.h"
# include "../libft/libft.h"

# include "macos_keys.h"

typedef enum e_fractal_type
{
	MANDELBROT,
	JULIA,
	FERN,
}	t_fractal_type;

typedef struct s_image
{
	void	*ptr;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_image;

typedef struct s_viewport
{
	double	x;
	double	y;
	double	offset_x;
	double	offset_y;
	double	scale;
}	t_viewport;

typedef struct s_mlx
{
	void		*ptr;
	void		*window;
	t_image		image;
}	t_mlx;

typedef struct s_complex
{
	double	real;
	double	imaginary;
}	t_complex;

typedef struct s_color
{
	double	hue;
	double	saturation;
	double	value;
}	t_color;

typedef struct s_xorshift
{
	uint32_t	x;
	uint32_t	y;
	uint32_t	z;
	uint32_t	w;
}	t_xorshift;

typedef struct s_fractol
{
	t_mlx			mlx;
	t_viewport		viewport;
	t_fractal_type	type;
	t_complex		z;
	t_complex		c;
	size_t			max_iters;
	size_t			shift;
	t_xorshift		seed;
}	t_fractol;

//mlx
void	putpixel_to_image(t_image *img, int x, int y, int color);
int		key_hook(int key, t_fractol *mlx);
int		mouse_hook(int button, int x, int y, t_fractol *mlx);

//drow_fractals
void	draw_fractal_to_window(t_fractol *f);
void	draw_mandelbrot_to_window(t_fractol *f);
void	draw_julia_to_window(t_fractol *f);
void	draw_fern_to_window(t_fractol *f);

//utils
int		iters_to_color(size_t iters, t_fractol *f);
int		hsv_to_rgb(t_color *color);
size_t	iters_till_2(t_fractol *f);
int		set_atod(double *num, char *str);
int		print_help(int retval);
void	init_settings(t_fractol *f);
int		set_atod(double *num, char *str);

#endif