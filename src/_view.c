/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _view.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-silv <bda-silv@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 15:42:15 by bda-silv          #+#    #+#             */
/*   Updated: 2023/02/02 19:24:11 by bda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/* TODO
 ** Seletor de funcao automatico
 ** Excluir color de render
 ** Trabalhar Paleta de cores
*/
double	delta_x(t_data *id, unsigned int x)
{
	return (id -> xmin + x * (id -> xmax - id-> xmin) / WIDTH);
}

double	delta_y(t_data *id, unsigned int y)
{
	return (id -> ymin + y * (id -> ymax - id -> ymin) / HEIGHT);
}

void	draw(t_data *img, int x, int y, int color)
{
	char	*pixel;

	pixel = (*img).adr + (y * (*img).len + x * ((*img).bpp / 8));
	*(unsigned int *)pixel = color;
}

int	trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}


double	trigger(t_data *id, double x0, double y0)
{
		//return (&mandelbrot(delta_x(id, x), delta_y(id, y), 0, 0));
		//return (&julia(delta_x(id, x), delta_y(id, y), -0.8, +0.156));
	if (ft_strcmp(id->type, "mandelbrot") == 0)
		return (mandelbrot(x0, y0, 0, 0));
	else if (ft_strcmp(id->type, "julia") == 0)
		return (julia(x0, y0, -0.8, +0.156));
	else
		return (0);
}

void	render(t_data *id, int clr)
{
	unsigned int	x;
	unsigned int	y;
	double	x0;
	double	y0;
	double			i;

	x = 0;
	y = 0;
	while (y != HEIGHT)
	{
		y0 = id -> ymin + y * (id-> ymax - id->ymin) / HEIGHT;
		while (x != WIDTH)
		{
			x0 = id -> xmin + x * (id->xmax - id->xmin) / WIDTH;
			/* 
			if (ft_strcmp(id->type, "mandelbrot") == 0)
				i = mandelbrot(x0, y0, 0, 0);
			else if (ft_strcmp(id->type, "julia") == 0)
				i = julia(x0, y0, -0.8, +0.156);
				*/
			i = trigger(id, x0, y0);
			if (i == IMAX)
				clr = 0x00000000;
				//color = 0x00AABBCC - 30 * i;
			else
				clr = i * 255 / IMAX;
				//paleta = color(0x00AABBCC) * i * correcao (if int > pot 2;
				//corr = 1)
			draw(id, x, y, clr);
			x++;
		}
		x = 0;
		y++;
	}
	mlx_put_image_to_window(id->mlx, id->win, id->ptr, 0, 0);
}
