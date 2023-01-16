/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-silv <bda-silv@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 07:48:08 by bda-silv          #+#    #+#             */
/*   Updated: 2023/01/16 16:03:13 by bda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define WIDTH  (1920)
# define HEIGHT (1080)
# define IMAX   (30)

# include "../lib/libft/inc/libft.h"
# include "../lib/mlx/mlx.h"

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
}			t_data;

/* MODEL */
unsigned int	mandelbrot(double x0, double y0);

/* VIEW */
double			screen_to_x(t_data *id, unsigned int x);
double			screen_to_y(t_data *id, unsigned int y);
void			draw(t_data *img, int x, int y, int color);
void			render(t_data *id, int color);

/* CONTROLLER */
void			fractol_init(t_data *id);
void			set(t_data *i, char *t, double xmin, double xmax, double ymin, double ymax);

/* ROUTER */
void			helper(void);
void			normalize(char **argv);
void			parse(char **argv, t_data *id);


#endif
