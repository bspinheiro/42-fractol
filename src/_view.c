/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _view.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-silv <bda-silv@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 15:42:15 by bda-silv          #+#    #+#             */
/*   Updated: 2023/02/05 10:24:25 by bda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/* TODO
 ** Consertar Julia para ficar na tela toda
 ** Codar outros Julia
 ** Implementar Eventos
 ** Rotacionar paleta (id.hue++)
 ** 
*/
void	draw(t_data *img, int x, int y, int color)
{
	char	*pixel;

	pixel = (*img).adr + (y * (*img).len + x * ((*img).bpp / 8));
	*(unsigned int *)pixel = color;
}

int	palette(int hue)
{
	if (hue == 0)
		return (0x00F0F8FF);
	if (hue == 1)
		return (0x00E8C3E2);
	if (hue == 2)
		return (0x00E8DAC3);
	if (hue == 3)
		return (0x00D5E8CF);
	if (hue == 4)
		return (0x00E8C3F8);
	if (hue == 5)
		return (0x00E8E3DA);
	if (hue == 6)
		return (1);
	if (hue == 7)
		return (256);
	else
		return (0x00FFFFFF);
}

double	trigger(t_data *id, double x, double y)
{
	if (ft_strcmp(id->type, "mandelbrot") == 0)
		return (mandelbrot(x, y, 0, 0));
	if (ft_strcmp(id->type, "julia") == 0)
		return (julia(x, y, -0.8, +0.156)); //-0.8 +0.156; -0.4 +0.6;
	if (ft_strcmp(id->type, "tricorn") == 0)
		return (tricorn(x, y, 0, 0));
	else
		return (0);
}

void	render(t_data *id, int x, int y)
{
	double	x0;
	double	y0;
	double	i;
	int		color;

	while (y != HEIGHT)
	{
		y0 = id -> ymin + y * (id-> ymax - id->ymin) / HEIGHT;
		while (x != WIDTH)
		{
			x0 = id -> xmin + x * (id->xmax - id->xmin) / WIDTH;
			i = trigger(id, x0, y0);
			if (i == IMAX)
				color = 0x00FFFFFF;
			else
				color = i * palette(id->hue);
			draw(id, x, y, color);
			x++;
		}
		x = 0;
		y++;
	}
	mlx_put_image_to_window(id->mlx, id->win, id->ptr, 0, 0);
}
