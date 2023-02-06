/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _controller.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-silv <bda-silv@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 15:42:15 by bda-silv          #+#    #+#             */
/*   Updated: 2023/02/06 18:12:10 by bda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/* TODO
 *
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
