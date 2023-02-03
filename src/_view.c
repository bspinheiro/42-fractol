/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _view.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-silv <bda-silv@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 15:42:15 by bda-silv          #+#    #+#             */
/*   Updated: 2023/02/03 16:11:53 by bda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/* TODO
 ** Excluir color de render
 ** Trabalhar Paleta de cores
*/
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

int	color(int iteration, int precision, int color)
{
	if (iteration >= precision)
		return (trgb(0, 0, 0, 0));
	else if (color == 0)
		return (trgb(0, 30 * iteration, 30 * iteration,
				30 * iteration));
	else if (color == 1)
		return (trgb(0, 255, 20.5 * iteration, 0));
	else if (color == 2)
		return (trgb(0, 0, 20.5 * iteration, 0));
	else if (color == 3)
		return (trgb(0, 0, 0, 20.5 * iteration));
	return (trgb(0, 40.5 * iteration, 20.5 * iteration, 255));
}

double	trigger(t_data *id, double x, double y)
{
	if (ft_strcmp(id->type, "mandelbrot") == 0)
		return (mandelbrot(x, y, 0, 0));
	if (ft_strcmp(id->type, "julia") == 0)
		return (julia(x, y, -0.8, +0.156));
	else
		return (0);
}

void	render(t_data *id, int color)
{
	unsigned int	x;
	unsigned int	y;
	double			x0;
	double			y0;
	double			i;

	x = 0;
	y = 0;
	while (y != HEIGHT)
	{
		y0 = id -> ymin + y * (id-> ymax - id->ymin) / HEIGHT;
		while (x != WIDTH)
		{
			x0 = id -> xmin + x * (id->xmax - id->xmin) / WIDTH;
			i = trigger(id, x0, y0);
			if (i == IMAX)
				color = 0x00FFFFFF;
				//color = 0x00AABBCC - 30 * i;
			else
				color = 0x00F0F8FF * i;
				//color = get_color(i, IMAX, 0);
				//color = i * 255 / IMAX;
				//color = 0x00F0F8FF * i;
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
