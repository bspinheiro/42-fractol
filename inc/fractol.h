/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-silv <bda-silv@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 07:48:08 by bda-silv          #+#    #+#             */
/*   Updated: 2023/01/30 15:56:59 by bda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define WIDTH  (1920)
# define HEIGHT (1080)
# define IMAX   (100)

# include "../lib/libft/inc/libft.h"
# include "../lib/mlx/mlx.h"
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
	double	r;
	double	g;
	double	b;
	double	color;
	int		palet;
}			t_data;


/* MODEL */
double	mandelbrot(double cr, double ci, double zr, double zi);
double	julia(double cr, double ci, double zr, double zi);

/* VIEW */
double	delta_x(t_data *id, unsigned int x);
double	delta_y(t_data *id, unsigned int y);
void	draw(t_data *img, int x, int y, int color);
void	render(t_data *id, int color);

/* CONTROLLER */
void	fractol_init(t_data *id);
void	set_model(t_data *id, char *t);
void	axis_x(t_data *id, double xmin, double xmax);
void	axis_y(t_data *id, double ymin, double ymax);

/* ROUTER */
void	helper(void);
void	normalize(char **argv);
void	parse(char **argv, t_data *id);

#endif
