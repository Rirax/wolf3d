/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlechapt <rlechapt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/01 16:13:11 by rlechapt          #+#    #+#             */
/*   Updated: 2015/11/01 18:19:20 by rlechapt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/wolf3d.h"

void	put_pixel_to_image(t_env *e, int *color, int x, int y)
{
	e->p = y * e->sizeline + (e->bpp / 8) * x;
	ft_memcpy(&e->data[e->p], color, (e->bpp / 8));
}

void	get_color(t_env *e, int y)
{
	if (y < e->drstart)
		e->color = mlx_get_color_value(e->mlx, 0xE1E6FA);
	else if (y >= e->drstart && y < e->drend)
	{
		if (e->side == 0)
			e->color = mlx_get_color_value(e->mlx, 0xE70739);
		else if (e->side == 1)
			e->color = mlx_get_color_value(e->mlx, 0x5EB6DD);
		else if (e->side == 2)
			e->color = mlx_get_color_value(e->mlx, 0xFFF168);
		else if (e->side == 3)
			e->color = mlx_get_color_value(e->mlx, 0x8FCF3C);
	}
	else if (y >= e->drend && y < WIN_HEIGHT)
		e->color = mlx_get_color_value(e->mlx, 0x795344);
}

void	draw_column(t_env *e, int x)
{
	int	y;

	y = 0;
	get_color(e, y);
	while (y < e->drstart)
	{
		put_pixel_to_image(e, &e->color, x, y);
		y++;
	}
	get_color(e, y);
	while (y < e->drend)
	{
		put_pixel_to_image(e, &e->color, x, y);
		y++;
	}
	get_color(e, y);
	while (y <= WIN_HEIGHT)
	{
		put_pixel_to_image(e, &e->color, x, y);
		y++;
	}
}
