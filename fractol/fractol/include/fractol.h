/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperesso <aperesso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/02 01:07:56 by aperesso          #+#    #+#             */
/*   Updated: 2017/08/11 12:27:39 by aperesso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H

# define FRACTOL_H
# define W  500
# define H  500
# define PI 3.141593

# include <mlx.h>
# include <math.h>
# include <stdio.h> // à retirer
# include <stdlib.h>
# include "../libft/libft.h"

typedef struct 	s_coordinate
{
	float		x;
	float		y;
}				t_coordinate;

typedef struct 	s_mlx
{
	void				*ptr;
	void				*win;
	void				*img;
	int					*data;
	int					fractale;
	int					start;
	t_coordinate		scale;
	t_coordinate		pos;
}				t_mlx;

typedef struct  s_complex
{
	float		re;
	float		im;
}				t_complex;

typedef struct 	s_rule
{
	char 			a;
	char			*b;
	struct s_rule	*next;
}				t_rule;

typedef	struct 	s_turtle
{
	t_coordinate	pos;
	double			angle;
	int				len;
}				t_turtle;

int				global_key(int keycode, t_mlx *mlx);
int				mandelbrot(t_mlx *mlx);

void			fill_pixel(t_mlx *mlx, int x, int y, int color);
void			background(int color, t_mlx *data);
void			line(int color, t_mlx *data, t_coordinate a, t_coordinate b);


float			map(float x, float fmin, float fmax, float tmin, float tmax);
t_complex		complex(float _re, float _im);
t_complex		multiply(t_complex a, t_complex b);
t_complex		add(t_complex a, t_complex b);
t_coordinate	coordinate(float _x, float _y);

int				createRGB(int r, int g, int b);


int				global_mouse(int button, int x, int y, t_mlx *param);
#endif 