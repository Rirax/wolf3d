/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_0.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlechapt <rlechapt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/30 18:55:28 by rlechapt          #+#    #+#             */
/*   Updated: 2015/11/01 20:20:51 by rlechapt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/wolf3d.h"

void	left_rot(t_env *e)
{
	e->oldir_x = e->dir_x;
	e->dir_x = e->dir_x * cos(-e->rot_speed) - e->dir_y * sin(e->rot_speed);
	e->dir_y = e->oldir_x * sin(e->rot_speed) + e->dir_y * cos(e->rot_speed);
	e->oldplan_x = e->plan_x;
	e->plan_x = e->plan_x * cos(e->rot_speed) - e->plan_y * sin(e->rot_speed);
	e->plan_y = e->oldplan_x * sin(e->rot_speed) + e->plan_y *
		cos(e->rot_speed);
}

void	right_rot(t_env *e)
{
	e->oldir_x = e->dir_x;
	e->dir_x = e->dir_x * cos(-e->rot_speed) - e->dir_y * sin(-e->rot_speed);
	e->dir_y = e->oldir_x * sin(-e->rot_speed) + e->dir_y * cos(-e->rot_speed);
	e->oldplan_x = e->plan_x;
	e->plan_x = e->plan_x * cos(-e->rot_speed) - e->plan_y *
		sin(-e->rot_speed);
	e->plan_y = e->oldplan_x * sin(-e->rot_speed) +
		e->plan_y * cos(-e->rot_speed);
}

void	control(int keycode, t_env *e)
{
	if (keycode == LEFT)
		left(e);
	else if (keycode == UP)
		up(e);
	else if (keycode == RIGHT)
		right(e);
	else if (keycode == DOWN)
		down(e);
	else if (keycode == LEFT_ROT)
		left_rot(e);
	else if (keycode == RIGHT_ROT)
		right_rot(e);
}

int		key_hook(int keycode, t_env *e)
{
	if (keycode == 53)
	{
		mlx_destroy_image(e->mlx, e->img);
		free(e->map);
		free(e->wmap);
		exit(0);
	}
	if (keycode == 83 || keycode == 18 || keycode == 84 || keycode == 19 ||
			keycode == 20 || keycode == 21 || keycode == 85 || keycode == 86)
	{
		free(e->map);
		free(e->wmap);
		get_map(keycode, e);
		e->set = 1;
		raycasting(e);
	}
	if (e->set == 1)
	{
		control(keycode, e);
		raycasting(e);
	}
	return (0);
}
