/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _events.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-silv <bda-silv@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 15:42:15 by bda-silv          #+#    #+#             */
/*   Updated: 2023/02/10 08:46:40 by bda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	on_key_press_move_add(double max, double min)
{
	double	mid;

	mid = 0;
	mid = max - min;
	max += mid * KEY_SPEED;
	min += mid * KEY_SPEED;
}

int	key_events(int key, t_data *id)
{
	double	mid_x;
	double	mid_y;

	mid_x = id->xmax - id->xmin;
	mid_y = id->ymax - id->ymin;
	if (key == ESC)
		fractol_quit(id);
	if (key == LEFT)
	{
		id->xmax += mid_x * KEY_SPEED;
		id->xmin += mid_x * KEY_SPEED;
	}
	if (key == RIGHT)
	{
		id->xmax -= mid_x * KEY_SPEED;
		id->xmin -= mid_x * KEY_SPEED;
	}
	if (key == UP)
	{
		id->ymax += mid_y * KEY_SPEED;
		id->ymin += mid_y * KEY_SPEED;
	}
	if (key == DOWN)
	{
		id->ymax -= mid_y * KEY_SPEED;
		id->ymin -= mid_y * KEY_SPEED;
	}
	mlx_clear_window(id, id->win);
	render(id, 0, 0);
	return (0);
}

int	mouse_events(int key, int x, int y, t_data *id)
{
	double	x0;
	double	y0;

	y0 = id->ymin + y * (id->ymax - id->ymin) / HEIGHT;
	x0 = id->xmin + x * (id->xmax - id->xmin) / WIDTH;
	if (key == 1)
	{
		id->hue += 1;
		if (id->hue == 9)
			id->hue = 0;
	}
	if (key == 2)
		render(id, 0, 0);
	if (key == 4)
	{
		id->xmax = x0 + ((id->xmax - x0) * ZOOM_OUT);
		id->xmin = x0 + ((id->xmin - x0) * ZOOM_OUT);
		id->ymax = y0 + ((id->ymax - y0) * ZOOM_OUT);
		id->ymin = y0 + ((id->ymin - y0) * ZOOM_OUT);
	}
	if (key == 5)
	{
		id->xmax = x0 + ((id->xmax - x0) * ZOOM_IN);
		id->xmin = x0 + ((id->xmin - x0) * ZOOM_IN);
		id->ymax = y0 + ((id->ymax - y0) * ZOOM_IN);
		id->ymin = y0 + ((id->ymin - y0) * ZOOM_IN);
	}
	mlx_clear_window(id, id->win);
	render(id, 0, 0);
	return (0);
}
