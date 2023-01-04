/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-silv <bda-silv@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 15:42:15 by bda-silv          #+#    #+#             */
/*   Updated: 2023/01/03 18:55:52 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

double xMin = -2.00;
double xMax =  0.47;
double yMin = -1.12;
double yMax = +1.12;

typedef struct s_data {															// fractol.h
	void	*mlx;
	void	*win;
	void	*ptr;
	char	*adr;
	int		bpp;
	int		len;
	int		edn;
}			t_data;

unsigned int  mandelbrot(double x0, double y0)
{
	double x = 0; 																//z=(x+iy)
	double y = 0;
	int i = 0;

	// |z|<=2, zˆ2<= 4
	while(x*x + y*y <= 2*2 && i < IMAX)
	{
		double proxZX, proxZY;
		// proxZ = Zˆ2 + C
		proxZX = x*x - y*y + x0;
		proxZY = 2*x*y + y0;
		x = proxZX;
		y = proxZY;
		i++;
	}
	return (i);
}

double screenToX(unsigned int x)
{
	return xMin + x*(xMax - xMin)/WIDTH;
}

double screenToY(unsigned int y)
{
	return yMin + y*(yMax - yMin)/HEIGHT;
}


void	draw(t_data *img, int x, int y, int color)								// view model
{
	char	*pixel;

	pixel = (*img).adr + (y * (*img).len + x * ((*img).bpp / 8));
	*(unsigned int *)pixel = color;
}

void render(t_data *id, int color)												// view model
{
	unsigned int x;
	unsigned int y;

	x = 0;
	y = 0;
	while (y != HEIGHT)
	{
		while(x != WIDTH)
		{
			int it = mandelbrot(screenToX(x), screenToY(y));
			color = it%255;
			draw(id, x, y, color);
			x++;
		}
		x = 0;
		y++;
	}
	mlx_put_image_to_window(id->mlx, id->win, id->ptr, 0, 0);
}

void fractol_init(t_data *id)													// controller and events
{
	(*id).mlx = mlx_init();
	(*id).win = mlx_new_window(id->mlx, WIDTH, HEIGHT, "Fractol");
	(*id).ptr = mlx_new_image(id->mlx, WIDTH, HEIGHT);
	(*id).adr = mlx_get_data_addr(id->ptr, &id->bpp, &id->len, &id->edn);
}

int	main(void)																	// router
{
	t_data	img;

	fractol_init(&img);
	render(&img, 0x0000FFFF);
	mlx_loop(img.mlx);
	return (0);
}

/*
	mlx_put_image_to_window(img.mlx, img.win, img.ptr, 0, 0);
	mlx_string_put(img.mlx, img.window, 200, 200, 0x00FF0000, "Hello you!");

	mlx_destroy_window(img.mlx, img.window);
	mlx_destroy_display(&img.mlx);
	free(img.mlx);
*/
