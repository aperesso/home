/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperesso <aperesso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/03 18:09:44 by aperesso          #+#    #+#             */
/*   Updated: 2017/08/03 21:22:50 by aperesso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

float		map(float x, float fmin, float fmax, float tmin, float tmax)
{
	float map;

	map = tmax - tmin;
	map /= fmax - fmin;
	map *=  x - fmin;
	map += tmin;
	return (map);
}

t_complex		complex(float _re, float _im)
{
	t_complex	z;

	z.re = _re;
	z.im = _im;
	return (z);
}

t_coordinate	coordinate(float _x, float _y)
{
	t_coordinate c;

	c.x = _x;
	c.y = _y;
	return (c);
}

t_complex	multiply(t_complex a, t_complex b)
{
	t_complex	c;

	c.re = a.re * b.re;
	c.re += -1 * a.im * b.im;
	c.im = a.im * b.re;
	c.im += a.re * b.im;
	return (c);
}

t_complex	add(t_complex a, t_complex b)
{
	return (complex(a.re + b.re, a.im + b.im));
}