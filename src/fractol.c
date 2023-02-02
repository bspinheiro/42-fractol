/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-silv <bda-silv@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 15:42:15 by bda-silv          #+#    #+#             */
/*   Updated: 2023/02/02 18:37:35 by bda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/* TODO
 ** Implementar fechamentos
 ** Implementar Msgs de Erro com códigos de saída
 ** Implementar Eventos
 ** Makefile
*/

int	main(int argc, char **argv)
{
	t_data	img;

	if (argc == 2)
	{
		normalize(argv);
		parse(argv, &img);
		fractol_init(&img);
		render(&img, 0x00FF00FF);
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
