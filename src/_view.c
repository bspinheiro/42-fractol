/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _view.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-silv <bda-silv@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 15:42:15 by bda-silv          #+#    #+#             */
/*   Updated: 2023/01/30 11:33:49 by bda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/* TODO
 ** Seletor de funcao automatico
 ** Excluir color de render
 ** Trabalhar Paleta de cores
*/
double	screen_to_x(t_data *id, unsigned int x)
{
	return (id -> xmin + x * (id -> xmax - id-> xmin) / WIDTH);
}

double	screen_to_y(t_data *id, unsigned int y)
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

void	render(t_data *id, int color)
{
	unsigned int	x;
	unsigned int	y;
	double			i;

	x = 0;
	y = 0;
	while (y != HEIGHT)
	{
		while (x != WIDTH)
		{
			i = mandelbrot(screen_to_x(id, x), screen_to_y(id, y), 0, 0);
			//i = julia(-0.8, +0.156, screen_to_x(id, x), screen_to_y(id, y));
			//i = julia(screen_to_x(id, x), screen_to_y(id, y), 0, 0);
			if (i == IMAX)
				color = 0x00000000;
				//color = 0x00AABBCC - 30 * i;
			else
				color = i * 255 / IMAX;
			draw(id, x, y, color);
			x++;
		}
		x = 0;
		y++;
	}
	mlx_put_image_to_window(id->mlx, id->win, id->ptr, 0, 0);
}
