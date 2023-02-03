/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _model.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-silv <bda-silv@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 15:42:15 by bda-silv          #+#    #+#             */
/*   Updated: 2023/02/03 16:16:25 by bda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/* TODO
 ** Usar função
 ** Implemntar Tricorn
 ** Tricorn? tempi = -2 * zr ...
*/

double	julia(double zr, double zi, double cr, double ci)
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
	i = i + 1 - log(log2(fabs(zi * zi + zr * zr)));
	return (i);
}

double	mandelbrot(double cr, double ci, double zr, double zi)
{
	zr = 0;
	zi = 0;
	return (julia(zr, zi, cr, ci));
}

double	tricorn(double zr, double zi, double cr, double ci)
{
	double	tempi;
	double	tempr;
	int		i;

	i = 0;
	while (zr * zr + zi * zi <= 2 * 2 && i < IMAX)
	{
		tempr = zr * zr - zi * zi + cr;
		tempi = -2 * zr * zi + ci;
		zr = tempr;
		zi = tempi;
		i++;
	}
	i = i + 1 - log(log2(fabs(zi * zi + zr * zr)));
	return (i);
}
