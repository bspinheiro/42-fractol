/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-silv <bda-silv@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 07:48:08 by bda-silv          #+#    #+#             */
/*   Updated: 2023/02/06 20:56:47 by bda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define WIDTH  (1080)
# define HEIGHT (1080)
# define IMAX   (100)

# define FAILURE (1)
# define SUCCESS (0)

# include "../lib/libft/inc/libft.h"
# include "../lib/mlx/mlx.h"
# include "colors.h"
# include "ansi.h"
# include <math.h>

typedef struct s_data {
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
	int		hue;
}			t_data;

/* MODEL */
double	mandelbrot(double cr, double ci, double zr, double zi);
double	julia(double zr, double zi, double cr, double ci);
double	tricorn(double zr, double zi, double cr, double ci);

/* VIEW */
int		palette(int hue);
int		background(int hue);
void	draw(t_data *img, int x, int y, int color);
void	render(t_data *id, int x, int y);

/* CONTROLLER */
void	fractol_init(t_data *id);
int		fractol_quit(t_data *id);
int		key_events(int keycode, t_data *id);
int		mouse_events(int key, int x, int y, t_data *id);
void	set_model(t_data *id, char *t, double x, double y);
void	axis_x(t_data *id, double xmin, double xmax);
void	axis_y(t_data *id, double ymin, double ymax);

/* ROUTER */
void	helper(void);
void	normalize(char **argv);
void	parse(char **argv, t_data *id);
double	trigger(t_data *id, double x, double y);

#endif
