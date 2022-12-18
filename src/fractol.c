/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-silv <bda-silv@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 15:42:15 by bda-silv          #+#    #+#             */
/*   Updated: 2022/12/18 04:28:20 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

typedef struct s_data {
	void	*mlx;
	void	*win;
	void	*ptr;
	char	*adr;
	int		bpp;
	int		len;
	int		edn;
}			t_data;

void	pixel(t_data *img, int x, int y, int color)
{
	char	*pixel;

	pixel = (*img).adr + (y * (*img).len + x * ((*img).bpp / 8));
	*(unsigned int *)pixel = color;
}

void render(t_data *id, int color)
{
	unsigned int x;
	unsigned int y;

	x = 0;
	y = 0;
	while (y != HEIGHT)
	{
		while(x != WIDTH)
		{
			pixel(id, x, y, color);
			x++;
		}
		x = 0;
		y++;
	}
	mlx_put_image_to_window(id->mlx, id->win, id->ptr, 0, 0);
}


void fractol_init(t_data *id)
{
	(*id).mlx = mlx_init();
	(*id).win = mlx_new_window(id->mlx, WIDTH, HEIGHT, "Fractol");
	(*id).ptr = mlx_new_image(id->mlx, WIDTH, HEIGHT);
	(*id).adr = mlx_get_data_addr(id->ptr, &id->bpp, &id->len, &id->edn);
}

int	main(void)
{
	t_data	img;

	fractol_init(&img);
	render(&img, 0x0000FFFF);
	mlx_put_image_to_window(img.mlx, img.win, img.ptr, 0, 0);
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
