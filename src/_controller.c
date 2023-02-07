/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _controller.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-silv <bda-silv@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 15:42:15 by bda-silv          #+#    #+#             */
/*   Updated: 2023/02/06 21:10:00 by bda-silv         ###   ########.fr       */
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
		id->xmax += mid_x * 0.15;
		id->xmin += mid_x * 0.15;
	}
	if (key == RIGHT)
	{
		id->xmax -= mid_x * 0.15;
		id->xmin -= mid_x * 0.15;
	}
	if (key == UP)
	{
		id->ymax += mid_y * 0.15;
		id->ymin += mid_y * 0.15;
	}
	if (key == DOWN)
	{
		id->ymax -= mid_y * 0.15;
		id->ymin -= mid_y * 0.15;
	}
	mlx_clear_window(id, id->win);
	render(id, 0, 0);
	return (0);
}

int	mouse_events(int key, int x, int y, t_data *id)
{
	if (key == 4)
	{
		id->xmax *= 1.1;
		id->xmin *= 1.1;
		id->ymax *= 1.1;
		id->ymin *= 1.1;
	}
	if (key == 5)
	{
		id->xmax *= 0.9;
		id->xmin *= 0.9;
		id->ymax *= 0.9;
		id->ymin *= 0.9;
	}
	mlx_clear_window(id, id->win);
	render(id, 0, 0);
	return (0);
}

