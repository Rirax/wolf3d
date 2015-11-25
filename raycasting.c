/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlechapt <rlechapt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/01 16:28:39 by rlechapt          #+#    #+#             */
/*   Updated: 2015/11/01 20:19:57 by rlechapt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/wolf3d.h"

void	hit(t_env *e)
{
	while (e->hit == 0)
	{
		if (e->sdist_x < e->sdist_y)
		{
			e->sdist_x += e->ddist_x;
			e->map_x += e->step_x;
			e->side = 0;
		}
		else
		{
			e->sdist_y += e->ddist_y;
			e->map_y += e->step_y;
			e->side = 1;
		}
		if (e->wmap[e->map_x][e->map_y] > 0)
			e->hit = 1;
	}
}

void	digital_differential_analizer(t_env *e)
{
	if (e->rdir_x < 0)
	{
		e->step_x = -1;
		e->sdist_x = (e->rpos_x - e->map_x) * e->ddist_x;
	}
	else
	{
		e->step_x = 1;
		e->sdist_x = (e->map_x + 1.0 - e->rpos_x) * e->ddist_x;
	}
	if (e->rdir_y < 0)
	{
		e->step_y = -1;
		e->sdist_y = (e->rpos_y - e->map_y) * e->ddist_y;
	}
	else
	{
		e->step_y = 1;
		e->sdist_y = (e->map_y + 1.0 - e->rpos_y) * e->ddist_y;
	}
	hit(e);
}

void	optic_correction(t_env *e)
{
	if (e->side == 0)
	{
		e->ppwdist = fabs((e->map_x - e->rpos_x +
					(1 - e->step_x) / 2) / e->rdir_x);
		e->side = (e->step_x < 0) ? 0 : 1;
	}
	else
	{
		e->ppwdist = fabs((e->map_y - e->rpos_y +
					(1 - e->step_y) / 2) / e->rdir_y);
		e->side = (e->step_y < 0) ? 2 : 3;
	}
}

void	get_height_column(t_env *e)
{
	e->hlin = abs((int)(WIN_HEIGHT / e->ppwdist));
	e->drstart = -e->hlin / 2 + WIN_HEIGHT / 2;
	e->drend = e->hlin / 2 + WIN_HEIGHT / 2;
	if (e->drstart < 0)
		e->drstart = 0;
	if (e->drend >= WIN_HEIGHT)
		e->drend = WIN_HEIGHT - 1;
}

void	raycasting(t_env *e)
{
	int	x;

	x = 0;
	while (x < WIN_WIDTH)
	{
		e->cam_x = (2.0 * x / (double)(WIN_WIDTH)) - 1.0;
		e->rpos_x = e->pos_x;
		e->rpos_y = e->pos_y;
		e->rdir_x = e->dir_x + e->plan_x * e->cam_x;
		e->rdir_y = e->dir_y + e->plan_y * e->cam_x;
		e->map_x = (int)(e->rpos_x);
		e->map_y = (int)(e->rpos_y);
		e->ddist_x = sqrt(1 + (e->rdir_y * e->rdir_y) / (e->rdir_x *
				e->rdir_x));
		e->ddist_y = sqrt(1 + (e->rdir_x * e->rdir_x) / (e->rdir_y *
				e->rdir_y));
		e->hit = 0;
		digital_differential_analizer(e);
		optic_correction(e);
		get_height_column(e);
		draw_column(e, x);
		x++;
	}
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
}
