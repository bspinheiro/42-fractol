/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _events.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-silv <bda-silv@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 15:42:15 by bda-silv          #+#    #+#             */
/*   Updated: 2023/02/13 08:19:29 by bda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	on_keypress_move(char c, int s, t_data *id)
{
	c = ft_tolower(c);
	if (c == 'x')
	{
		id->xmax = id->xmax + (s * (id->xmax - id->xmin) * KEY_SPEED);
		id->xmin = id->xmin + (s * (id->xmax - id->xmin) * KEY_SPEED);
	}
	else if (c == 'y')
	{
		id->ymax = id->ymax + (s *(id->ymax - id->ymin) * KEY_SPEED);
		id->ymin = id->ymin + (s *(id->ymax - id->ymin) * KEY_SPEED);
	}
}

int	key_events(int key, t_data *id)
{
	if (key == ESC)
		fractol_quit(id);
	if (key == LEFT)
		on_keypress_move('x', +1, id);
	if (key == RIGHT)
		on_keypress_move('x', -1, id);
	if (key == UP)
		on_keypress_move('y', +1, id);
	if (key == DOWN)
		on_keypress_move('y', -1, id);
	mlx_clear_window(id, id->win);
	render(id, 0, 0);
	return (0);
}

void	on_mouse_scroll(double zoom, int x, int y, t_data *id)
{
	double	x0;
	double	y0;

	y0 = id->ymin + y * (id->ymax - id->ymin) / HEIGHT;
	x0 = id->xmin + x * (id->xmax - id->xmin) / WIDTH;
	id->xmax = x0 + ((id->xmax - x0) * zoom);
	id->xmin = x0 + ((id->xmin - x0) * zoom);
	id->ymax = y0 + ((id->ymax - y0) * zoom);
	id->ymin = y0 + ((id->ymin - y0) * zoom);
}

void	on_mouse_click_reset(t_data *id)
{
	parse(id->argv, id);
}

int	mouse_events(int key, int x, int y, t_data *id)
{
	if (key == 1)
		change_palette(id);
	if (key == 2)
		on_mouse_click_reset(id);
	if (key == 4)
		on_mouse_scroll(ZOOM_OUT, x, y, id);
	if (key == 5)
		on_mouse_scroll(ZOOM_IN, x, y, id);
	mlx_clear_window(id, id->win);
	render(id, 0, 0);
	return (0);
}
