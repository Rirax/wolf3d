/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlechapt <rlechapt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/30 18:59:32 by rlechapt          #+#    #+#             */
/*   Updated: 2015/11/01 20:23:20 by rlechapt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/wolf3d.h"

void	left(t_env *e)
{
	if (e->wmap[(int)(e->pos_x - e->plan_x *
			e->mv_speed)][(int)(e->pos_y)] == 0)
		e->pos_x -= e->plan_x * e->mv_speed;
	if (e->wmap[(int)(e->pos_x)][(int)(e->pos_y - e->plan_y *
			e->mv_speed)] == 0)
		e->pos_y -= e->plan_y * e->mv_speed;
}

void	up(t_env *e)
{
	if (e->wmap[(int)(e->pos_x + e->dir_x *
			e->mv_speed)][(int)(e->pos_y)] == 0)
		e->pos_x += e->dir_x * e->mv_speed;
	if (e->wmap[(int)(e->pos_x)][(int)(e->pos_y + e->dir_y *
			e->mv_speed)] == 0)
		e->pos_y += e->dir_y * e->mv_speed;
}

void	down(t_env *e)
{
	if (e->wmap[(int)(e->pos_x - e->dir_x *
			e->mv_speed)][(int)(e->pos_y)] == 0)
		e->pos_x -= e->dir_x * e->mv_speed;
	if (e->wmap[(int)(e->pos_x)][(int)(e->pos_y - e->dir_y *
				e->mv_speed)] == 0)
		e->pos_y -= e->dir_y * e->mv_speed;
}

void	right(t_env *e)
{
	if (e->wmap[(int)(e->pos_x + e->plan_x *
			e->mv_speed)][(int)(e->pos_y)] == 0)
		e->pos_x += e->plan_x * e->mv_speed;
	if (e->wmap[(int)(e->pos_x)][(int)(e->pos_y + e->plan_y *
			e->mv_speed)] == 0)
		e->pos_y += e->plan_y * e->mv_speed;
}
