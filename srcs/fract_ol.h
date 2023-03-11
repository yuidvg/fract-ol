/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynishimu <ynishimu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 22:04:17 by ynishimu          #+#    #+#             */
/*   Updated: 2023/03/09 14:40:10 by ynishimu         ###   ########.fr       */
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

# define TITLE "fract_ol"
# define MAX_ITERS 50

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
	double_t	x;
	double_t	y;
	double_t	offset_x;
	double_t	offset_y;
	double_t	scale;
}	t_viewport;

typedef struct s_graphics
{
	void		*mlx;
	void		*window;
	t_image		image;
	t_viewport	port;
}	t_graphics;

typedef struct s_complex
{
	double_t	real;
	double_t	imaginary;
}	t_complex;

typedef struct s_color
{
	double_t	h;
	double_t	s;
	double_t	v;
	int			rgb;
}	t_color;

//mlx
void	putpixel_to_image(t_image *img, int x, int y, int color);
int		key_hook(int key, t_graphics *mlx);
int		mouse_hook(int button, int x, int y, t_graphics *mlx);

//drow_fractals
void	draw_mandelbrot_to_image(t_image *image, t_viewport *viewport);
int		iters_to_color(size_t iters);

#endif