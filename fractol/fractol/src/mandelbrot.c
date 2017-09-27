/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperesso <aperesso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/02 01:20:21 by aperesso          #+#    #+#             */
/*   Updated: 2017/08/03 23:56:44 by aperesso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int		is_mandel(t_complex c)
{
	t_complex	z;
	int			i;
	float		absolute;

	z = c;
	i = -1;
	while (++i < 1000)
	{
		absolute = (z.re * z.re) + (z.im * z.im);
		if (absolute > 4)
			return (i);
		z = add(multiply(z,z), c);
	}
	return (-1);
}

int		mandelbrot(t_mlx *mlx)
{
	int			x;
	int			y;
	t_complex	z;
	int			i;

	mlx->fractale = 0;
	if (mlx->start == 1)
	{
		mlx->scale = coordinate(2, 1.5);
		mlx->start = 0;
	}
	x = -1;
	while (++x < W)
	{
		y = -1;
		z.re = map(x, 0, W, mlx->pos.x - mlx->scale.x, mlx->pos.x + mlx->scale.x);
		while (++y < H)
		{
			z.im = map(y, 0, H, mlx->pos.y - mlx->scale.y, mlx->pos.y + mlx->scale.y);
			if ((i = is_mandel(z)) != -1)
				fill_pixel(mlx, x, y, createRGB((255 - i * 10)% 255, 255 - i % 255, 255 - i % 255));
			else
				fill_pixel(mlx, x, y, 0xF0F8FF);
		}
	}
	return (1);
}