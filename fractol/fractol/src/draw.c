/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperesso <aperesso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/02 23:00:21 by aperesso          #+#    #+#             */
/*   Updated: 2017/08/05 03:58:38 by aperesso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	fill_pixel(t_mlx *env, int x, int y, int color)
{
	env->data[y * W + x] = color;
}

void	background(int color, t_mlx *data)
{
	int		i;
	int		j;

	i = 0;
	while (i < W)
	{
		j = 0;
		while (j < H)
		{
			fill_pixel(data, i, j, color);
			j++;
		}
		i++;
	}
}

void	line(int color, t_mlx *data, t_coordinate a, t_coordinate b)
{
	t_coordinate d;
	t_coordinate s;
	int			err;
	int			e2;

	d = coordinate(fabs(b.x-a.x),fabs(b.y - a.y));
	s.x = a.x < b.x ? 1 : -1;
	s.y = a.y < b.y ? 1 : -1;
	err = (int) round((d.x > d.y) ? d.x : -d.y) / 2 ;
	while (1)
	{
		fill_pixel(data, a.x, a.y, color);
		if (a.x == b.x && a.y == b.y)
			break;
		e2 = err;
		if (e2 > -d.x)
		{
			err -= d.y,
			a.x += s.x;
		}
		if (e2 < d.y)
		{
			err += d.x;
			a.y += s.y;
		}
	}
}
