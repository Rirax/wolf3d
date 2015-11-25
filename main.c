/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlechapt <rlechapt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/11 01:03:32 by rlechapt          #+#    #+#             */
/*   Updated: 2015/11/01 20:27:57 by rlechapt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/wolf3d.h"

int		expose_hook(t_env *e)
{
	mlx_key_hook(e->win, key_hook, e);
	return (0);
}

int		main(void)
{
	t_env	e;

	e.set = 0;
	if (!(e.mlx = mlx_init()))
	{
		ft_putendl_fd("Error minilibx init", 2);
		return (0);
	}
	e.win = mlx_new_window(e.mlx, WIN_WIDTH, WIN_HEIGHT, "wolf3d");
	e.img = mlx_new_image(e.mlx, WIN_WIDTH, WIN_HEIGHT);
	e.data = mlx_get_data_addr(e.img, &e.bpp, &e.sizeline, &e.endian);
	mlx_string_put(e.mlx, e.win, WIN_WIDTH / 2 - 110, WIN_HEIGHT / 2.2,
			0xFFFFFF, "WELCOME IN WOLF3D BY RIROU !");
	mlx_string_put(e.mlx, e.win, WIN_WIDTH / 2 - 140, WIN_HEIGHT / 2,
			0xFFFFFF, "PRESS 1 TO 4 TO CHOOSE YOUR WORLD");
	mlx_string_put(e.mlx, e.win, WIN_WIDTH - 200, WIN_HEIGHT - 40,
			0xFFFFFF, "PRESS ESC TO QUIT");
	mlx_expose_hook(e.win, expose_hook, &e);
	mlx_hook(e.win, KEYPRESS, KEYPRESSMASK, key_hook, &e);
	mlx_loop(e.mlx);
	return (0);
}
