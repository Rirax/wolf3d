/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlechapt <rlechapt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/31 19:23:41 by rlechapt          #+#    #+#             */
/*   Updated: 2015/11/01 20:20:25 by rlechapt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/wolf3d.h"

void	var_init(t_env *e, double x, double y)
{
	e->pos_x = x;
	e->pos_y = y;
	e->dir_x = -1;
	e->dir_y = 0;
	e->plan_x = 0;
	e->plan_y = 0.66;
	e->mv_speed = 0.10;
	e->rot_speed = 0.05;
}

int		choice_map(int key, t_env *e)
{
	int	fd;

	fd = 0;
	if (key == 83 || key == 18)
	{
		fd = open("./map/map1", O_RDONLY);
		var_init(e, 5, 1.5);
	}
	else if (key == 84 || key == 19)
	{
		fd = open("./map/map2", O_RDONLY);
		var_init(e, 8.5, 7.5);
	}
	else if (key == 85 || key == 20)
	{
		fd = open("./map/map3", O_RDONLY);
		var_init(e, 8, 1.5);
	}
	else if (key == 86 || key == 21)
	{
		fd = open("./map/map4", O_RDONLY);
		var_init(e, 17.5, 2.5);
	}
	return (fd);
}

char	*ft_strjoin_mod(char const *s1, char const *s2)
{
	char	*s3;

	if ((s3 = ft_strnew(ft_strlen(s1) + ft_strlen(s2))) == NULL)
		return (NULL);
	ft_strcpy(s3, s1);
	ft_strcat(s3, s2);
	free((void*)s1);
	return (s3);
}

int		o_read(int key, t_env *e)
{
	int		fd;
	int		ret;
	char	buf[BUFF_SIZE + 1];

	fd = choice_map(key, e);
	e->str = NULL;
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (!e->str)
			e->str = ft_strdup(buf);
		else
			e->str = ft_strjoin_mod(e->str, buf);
	}
	close(fd);
	return (0);
}

void	get_map(int key, t_env *e)
{
	o_read(key, e);
	get_nbcol(e);
	get_nblin(e);
	create_tab(e);
	world_map(e);
}
