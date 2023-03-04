/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynishimu <ynishimu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 13:03:44 by ynishimu          #+#    #+#             */
/*   Updated: 2023/03/04 12:41:20 by ynishimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int	key_hook(int key, t_mlx *mlx)
{
	if (key == KEY_ESC)
	{
		mlx_destroy_image(mlx->ptr, &mlx->image);
		ft_exit(0, NULL, NULL, NULL);
	}
	return (0);
}
