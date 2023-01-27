/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _model.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-silv <bda-silv@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 15:42:15 by bda-silv          #+#    #+#             */
/*   Updated: 2023/01/24 11:26:22 by bda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/* TODO
 *
 * */
int	mandelbrot(double x0, double y0)
{
	double	x;
	double	y;
	double	next_x;
	double	next_y;
	int		i;

	x = 0;
	y = 0;
	i = 0;
	next_x = 0;
	next_y = 0;
	while (x * x + y * y <= 2 * 2 && i < IMAX)
	{
		next_x = x * x - y * y + x0;
		next_y = 2 * x * y + y0;
		x = next_x;
		y = next_y;
		i++;
	}
	return (i);
}

double	julia(double cr, double ci, double zr, double zi)
{
	double	tempi;
	double	tempr;
	int		i;

	i = 0;
	while (zr * zr + zi * zi <= 2 * 2 && i < IMAX)
	{
		tempr = zr * zr - zi * zi + cr;
		tempi = 2 * zr * zi + ci;
		zr = tempr;
		zi = tempi;
		i++;
	}
	//i = i + 1 - log(log2(fabs(zi * zi + zr * zr)));
	return (i);
}
