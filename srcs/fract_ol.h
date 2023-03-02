/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynishimu <ynishimu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 22:04:17 by ynishimu          #+#    #+#             */
/*   Updated: 2023/03/02 15:55:12 by ynishimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
# define FRACT_OL_H


# define WIN_W 1920
# define WIN_H 1080
# define TITLE "fract_ol"
# define MAX_ITER 100

//libs
# include <math.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>

//local_libs
# include "mlx.h"
# include "../libft/libft.h"

# include "macos_keys.h"

typedef struct s_image
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_image;

typedef struct s_mlx
{
	void	*ptr;
	void	*window;
	t_image	*image;
}	t_mlx;

typedef struct s_complex
{
	double	real;
	double	imaginary;
}	t_complex;


//mlx
void	putpixel_to_image(t_image *img, int x, int y, int color);
int		key_hook(int key, t_mlx *mlx);

//drow_fractals
void	draw_mandelbrot_to_image(t_image *image);

#endif