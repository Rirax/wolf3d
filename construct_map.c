/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   construct_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlechapt <rlechapt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/31 19:24:30 by rlechapt          #+#    #+#             */
/*   Updated: 2015/11/01 20:23:05 by rlechapt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	get_nbcol(t_env *e)
{
	int		i;

	i = 0;
	while (e->str[i] != '\n')
		i++;
	e->nbcol = i;
}

void	get_nblin(t_env *e)
{
	int		i;

	i = 0;
	e->nblin = 0;
	while (e->str[i] != '\0')
	{
		if (e->str[i] == '\n')
			e->nblin++;
		i++;
	}
}

int		create_tab(t_env *e)
{
	int		i;

	if ((e->wmap = (int **)malloc(sizeof(int*) * e->nblin)) == NULL)
		return (-1);
	if ((e->map = (int *)malloc(sizeof(int) * e->nbcol * e->nblin)) == NULL)
		return (-1);
	i = 0;
	while (i < e->nblin)
	{
		e->wmap[i] = &e->map[i * e->nbcol];
		i++;
	}
	return (0);
}

int		ft_atoi_mod(char c)
{
	int		val;

	val = 0;
	if (c >= '0' && c <= '9' && c != '\0')
		val = c - 48;
	return (val);
}

int		world_map(t_env *e)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	while (e->str[k] != '\0')
	{
		j = 0;
		while (e->str[k] != '\n')
		{
			e->wmap[i][j] = ft_atoi_mod(e->str[k]);
			k++;
			j++;
		}
		i++;
		k++;
	}
	free(e->str);
	return (0);
}
