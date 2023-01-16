/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-silv <bda-silv@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 15:42:15 by bda-silv          #+#    #+#             */
/*   Updated: 2023/01/07 19:22:39 by bda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

/* TODO
 * - Enviar para router
 * * Controller
 * * TRGB
 * * Julia
 * * Refactor
 *
 * */

typedef struct	s_data {										// fractol.h
	char	*type;
	double	xmin;
	double	xmax;
	double	ymin;
	double	ymax;
	void	*mlx;
	void	*win;
	void	*ptr;
	char	*adr;
	int		bpp;
	int		len;
	int		edn;
}			t_data;

unsigned int	mandelbrot(double x0, double y0)
{
	double	x; 												//z=(x+iy)
	double	y;
	int	i;

	x = 0;
	y = 0;
	i = 0;
	// |z|<=2, zˆ2<= 4
	while(x*x + y*y <= 2*2 && i < IMAX)
	{
		double proxZX;
		double proxZY;
		// proxZ = Zˆ2 + C
		proxZX = x*x - y*y + x0;
		proxZY = 2*x*y + y0;
		x = proxZX;
		y = proxZY;
		i++;
	}
	return (i);
}

double screenToX(t_data *id, unsigned int x)
{
	return id->xmin + x*(id->xmax - id->xmin)/WIDTH;
}

double screenToY(t_data *id, unsigned int y)
{
	return id->ymin + y*(id->ymax - id->ymin)/HEIGHT;
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
			int it = mandelbrot(screenToX(id, x), screenToY(id, y));
			color = it%255;
			draw(id, x, y, color);
			x++;
		}
		x = 0;
		y++;
	}
	mlx_put_image_to_window(id->mlx, id->win, id->ptr, 0, 0);
}

void fractol_init(t_data *id)//													Controller and events
{
	(*id).mlx = mlx_init();
	(*id).win = mlx_new_window(id->mlx, WIDTH, HEIGHT, "Fractol");
	(*id).ptr = mlx_new_image(id->mlx, WIDTH, HEIGHT);
	(*id).adr = mlx_get_data_addr(id->ptr, &id->bpp, &id->len, &id->edn);
}

void helper(void)
{
	ft_printf("Error! incorrect parameter -- must specify fractol name.\n");
	ft_printf("Usage: ./fractol [mandelbrot | julia]\n");
}

void normalize(char **argv)
{
	int i;
	int p;

	p = 0;
	while(argv[++p]);
	p = p - 1;
	while (p != 0)
	{
		i = 0;
		while (argv[p][i])
		{
			argv[p][i] = ft_tolower(argv[p][i]);
			i++;
		}
		p--;
	}
}

void set(t_data *i, char *t, double xmin, double xmax, double ymin, double ymax)
{
	(*i).type = t;
	(*i).xmin = xmin;
	(*i).xmax = xmax;
	(*i).ymin = ymin;
	(*i).ymax = ymax;
}

void parse(char **argv, t_data *id)
{
	if (ft_strcmp(argv[1], "mandelbrot") == 0)
		set(id, "mandelbrot", -2.00, 0.47, -1.12, 1.12);
	else if (ft_strcmp(argv[1], "julia") == 0)
		(*id).type = "julia";
	else
		helper();
}

int	main(int argc, char **argv)//												Router
{
	t_data	img;

	if (argc == 2)
	{
		normalize(argv);
		parse(argv, &img);
		fractol_init(&img);
		render(&img, 0x000000AA);
		mlx_loop(img.mlx);
	}
	else
		helper();
	return (0);
}

/*
	mlx_put_image_to_window(img.mlx, img.win, img.ptr, 0, 0);
	mlx_string_put(img.mlx, img.window, 200, 200, 0x00FF0000, "Hello you!");

	mlx_destroy_window(img.mlx, img.window);
	mlx_destroy_display(&img.mlx);
	free(img.mlx);
*/
