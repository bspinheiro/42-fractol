/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _view.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-silv <bda-silv@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 15:42:15 by bda-silv          #+#    #+#             */
/*   Updated: 2023/02/02 17:40:55 by bda-silv         ###   ########.fr       */
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
			if (ft_strcmp(id->type, "mandelbrot") == 0)
				i = mandelbrot(delta_x(id, x), delta_y(id, y), 0, 0);
			else if (ft_strcmp(id->type, "julia") == 0)
				i = julia(delta_x(id, x), delta_y(id, y), -0.8, +0.156);
			else
				i = IMAX;
			if (i == IMAX)
				color = 0x00000000;
				//color = 0x00AABBCC - 30 * i;
			else
				color = i * 255 / IMAX;
				//paleta = color(0x00AABBCC) * i * correcao (if int > pot 2;
				//corr = 1)
			draw(id, x, y, color);
			x++;
		}
		x = 0;
		y++;
	}
	mlx_put_image_to_window(id->mlx, id->win, id->ptr, 0, 0);
}
