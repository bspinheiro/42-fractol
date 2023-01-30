/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _router.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-silv <bda-silv@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 15:42:15 by bda-silv          #+#    #+#             */
/*   Updated: 2023/01/30 11:10:05 by bda-silv         ###   ########.fr       */
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
	ft_printf("Usage: ./fractol [mandelbrot | julia]\n");
	exit(1);
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
		set(id, "mandelbrot", -2.00, 0.47, -1.12, 1.12);
		ft_printf("Mandelbrot selected!");
	}
	else if (ft_strcmp(argv[1], "julia") == 0)
	{
		set(id, "julia", -2.1, 1.9, -2.1, 1.9);
		ft_printf("Julia selected!");
	}
	else
		helper();
}
