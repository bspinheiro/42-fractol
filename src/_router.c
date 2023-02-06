/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _router.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-silv <bda-silv@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 15:42:15 by bda-silv          #+#    #+#             */
/*   Updated: 2023/02/05 12:24:06 by bda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
 ** TODO
 ** - Incluir ft_normalize() na libft
 ** - ft_strcmp com strlen(s2)
 ** - saída com errorlevel para helper();
*/
void	helper(void)
{
	ft_printf("Error! incorrect parameter -- must specify fractol name.\n");
	ft_printf("Usage: ./fractol [mandelbrot | julia(1..6) | tricorn]\n");
	exit(FAILURE);
}

void	normalize(char **argv)
{
	int	i;
	int	p;

	p = 0;
	while (argv[++p])
		;
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

void	parse(char **argv, t_data *id)
{
	if (ft_strcmp(argv[1], "mandelbrot") == 0)
	{
		set_model(id, "mandelbrot");
		axis_x(id, -2.00, +0.47);
		axis_y(id, -1.12, +1.12);
	}
	if (ft_strcmp(argv[1], "julia") == 0)
	{
		set_model(id, "julia");
		axis_x(id, -2.1, +1.90);
		axis_y(id, -2.1, +1.90);
	}
	if (ft_strcmp(argv[1], "tricorn") == 0)
	{
		set_model(id, "tricorn");
		axis_x(id, -2.10, 1.50);
		axis_y(id, -2, 2);
	}
	else
	{
		helper();
		exit(FAILURE);
	}
}

double	trigger(t_data *id, double x, double y)
{
	if (ft_strcmp(id->type, "mandelbrot") == 0)
		return (mandelbrot(x, y, 0, 0));
	if (ft_strcmp(id->type, "julia") == 0)
		return (julia(x, y, -0.8, +0.156)); //-0.8 +0.156; -0.4 +0.6;
	if (ft_strcmp(id->type, "tricorn") == 0)
		return (tricorn(x, y, 0, 0));
	else
		return (0);
}
