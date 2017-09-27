/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperesso <aperesso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/02 01:10:57 by aperesso          #+#    #+#             */
/*   Updated: 2017/08/07 22:04:46 by aperesso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static	int		init_mlx(t_mlx	*mlx)
{
	int		bpp;
	int		s_l;
	int		endian;

	if (!(mlx->ptr = mlx_init()))
		return (0);
	if (!(mlx->win = mlx_new_window(mlx->ptr, W, H, "Fract'ol by minouche")))
		return (0);
	if (!(mlx->img = mlx_new_image(mlx->ptr, W, H)))
		return (0);
	mlx->data = (int *)mlx_get_data_addr(mlx->img, &(bpp), &(s_l), &(endian));
	mlx->pos = coordinate(0,0);
	mlx->start = 1;
	return (1);
}

int				main(int ac, char **av)
{
	t_mlx		mlx;
	(void)av;

	if (ac != 2)
		ft_putstr("liste des fractales"); // à faire
	if (ac == 2)
	{
		init_mlx(&mlx);
		if (!ft_strcmp("-mandelbrot", av[1]))
			mandelbrot(&mlx);
		mlx_put_image_to_window(mlx.ptr, mlx.win, mlx.img, 0, 0);
		mlx_key_hook(mlx.win, global_key, &mlx);
		mlx_mouse_hook(mlx.win, global_mouse, &mlx);
		mlx_loop(mlx.ptr);
	}

	return (1);
}