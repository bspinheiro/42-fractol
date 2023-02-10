/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _view.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-silv <bda-silv@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 15:42:15 by bda-silv          #+#    #+#             */
/*   Updated: 2023/02/09 16:27:52 by bda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw(t_data *img, int x, int y, int color)
{
	char	*pixel;

	pixel = (*img).adr + (y * (*img).len + x * ((*img).bpp / 8));
	*(unsigned int *)pixel = color;
}

int	palette(int hue)
{
	if (hue == 0)
		return (COLOR_0);
	if (hue == 1)
		return (COLOR_1);
	if (hue == 2)
		return (COLOR_2);
	if (hue == 3)
		return (COLOR_3);
	if (hue == 4)
		return (COLOR_4);
	if (hue == 5)
		return (COLOR_5);
	if (hue == 6)
		return (COLOR_6);
	if (hue == 7)
		return (COLOR_7);
	else
		return (COLOR_8);
}

int	background(int hue)
{
	if (hue == 0)
		return (BG_0);
	if (hue == 1)
		return (BG_1);
	if (hue == 2)
		return (BG_2);
	if (hue == 3)
		return (BG_3);
	if (hue == 4)
		return (BG_4);
	if (hue == 5)
		return (BG_5);
	if (hue == 6)
		return (BG_6);
	if (hue == 7)
		return (BG_7);
	else
		return (BG_8);
}

void	render(t_data *id, int x, int y)
{
	double	x0;
	double	y0;
	double	i;
	int		color;

	y0 = 0;
	x0 = 0;
	while (y != HEIGHT)
	{
		y0 = id->ymin + y * (id->ymax - id->ymin) / HEIGHT;
		while (x != WIDTH)
		{
			x0 = id->xmin + x * (id->xmax - id->xmin) / WIDTH;
			i = trigger(id, x0, y0);
			if (i == IMAX)
				color = background(id->hue);
			else
				color = palette(id->hue) * i;
			draw(id, x, y, color);
			x++;
		}
		x = 0;
		y++;
	}
	mlx_put_image_to_window(id->mlx, id->win, id->ptr, 0, 0);
}
