/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperesso <aperesso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/02 01:44:27 by aperesso          #+#    #+#             */
/*   Updated: 2017/08/05 17:18:34 by aperesso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int		global_key(int keycode, t_mlx *mlx)
{
	(void) mlx;
	printf("key : %d\n", keycode);
	if (keycode == 53)
		exit(0);
	return (1);
}

int		global_mouse(int button, int x, int y, t_mlx *mlx)
{
	if (button == 1)
	{
		mlx->pos.x = map(x, 0, W, mlx->pos.x - mlx->scale.x, mlx->pos.x + mlx->scale.x);
		mlx->pos.y = map(y, 0, H, mlx->pos.y - mlx->scale.y, mlx->pos.y + mlx->scale.y);
		mlx->scale.x *= 0.7;
		mlx->scale.y *= 0.7;
		if (mlx->fractale == 0)
			mandelbrot(mlx);
		mlx_clear_window(mlx->ptr, mlx->win);
		mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img, 0, 0);
	}
	return (1);
}