/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-silv <bda-silv@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 15:42:15 by bda-silv          #+#    #+#             */
/*   Updated: 2023/02/07 19:33:23 by bda-silv         ###   ########.fr       */
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
	t_data	id;

	if (argc == 2)
	{
		argc = argc * 1;
		normalize(argv);
		parse(argv, &id);
		fractol_init(&id);
		render(&id, 0, 0);
		mlx_hook(id.win, WIN_CLOSE, 0, &fractol_quit, &id);
		mlx_key_hook(id.win, &key_events, &id);
		mlx_mouse_hook(id.win, &mouse_events, &id);
		mlx_loop(id.mlx);
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
