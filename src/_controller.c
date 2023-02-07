/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _controller.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-silv <bda-silv@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 15:42:15 by bda-silv          #+#    #+#             */
/*   Updated: 2023/02/07 19:31:50 by bda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>
/* TODO
 ** recode set_axis_to(x)...
 ** events
 * */

void	fractol_init(t_data *id)
{
	(*id).mlx = mlx_init();
	(*id).win = mlx_new_window(id->mlx, WIDTH, HEIGHT, "Fractol");
	(*id).ptr = mlx_new_image(id->mlx, WIDTH, HEIGHT);
	(*id).adr = mlx_get_data_addr(id->ptr, &id->bpp, &id->len, &id->edn);
}

void	set_model(t_data *id, char *t, double x, double y)
{
	(*id).type = t;
	(*id).hue = 0;
	axis_x(id, -x, x);
	axis_y(id, -y, y);
}

void	axis_x(t_data *id, double xmin, double xmax)
{
	(*id).xmin = xmin;
	(*id).xmax = xmax;
}

void	axis_y(t_data *id, double ymin, double ymax)
{
	(*id).ymin = ymin;
	(*id).ymax = ymax;
}

int	fractol_quit(t_data *id)
{
	mlx_destroy_window(id->mlx, id->win);
	exit(SUCCESS);
	return (0);
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
