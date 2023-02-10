/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-silv <bda-silv@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 15:42:15 by bda-silv          #+#    #+#             */
/*   Updated: 2023/02/09 17:02:13 by bda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
		mlx_hook(id.win, BTN_CLOSE, 0, &fractol_quit, &id);
		mlx_key_hook(id.win, &key_events, &id);
		mlx_mouse_hook(id.win, &mouse_events, &id);
		mlx_loop(id.mlx);
	}
	else
		helper();
	return (0);
}
