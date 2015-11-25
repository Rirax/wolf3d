/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlechapt <rlechapt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/11 01:00:21 by rlechapt          #+#    #+#             */
/*   Updated: 2015/11/01 19:53:13 by rlechapt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# define WIN_WIDTH 1200
# define WIN_HEIGHT 800
# define BUFF_SIZE 1
# define LEFT 0
# define UP 13
# define RIGHT 2
# define DOWN 1
# define LEFT_ROT 123
# define RIGHT_ROT 124
# define KEYPRESS 2
# define KEYPRESSMASK (1L<<0)
# include "../libft/libft.h"
# include <mlx.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>

typedef struct	s_env
{
	int		set;
	void	*mlx;
	void	*win;
	void	*img;
	char	*str;
	char	*data;
	int		p;
	int		sizeline;
	int		endian;
	int		bpp;
	int		color;
	int		nblin;
	int		nbcol;
	int		**wmap;
	int		*map;
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plan_x;
	double	plan_y;
	double	cam_x;
	double	rpos_x;
	double	rpos_y;
	double	rdir_x;
	double	rdir_y;
	int		map_x;
	int		map_y;
	double	ddist_x;
	double	ddist_y;
	int		hit;
	int		step_x;
	int		step_y;
	double	sdist_x;
	double	sdist_y;
	int		side;
	double	ppwdist;
	int		hlin;
	int		drstart;
	int		drend;
	float	mv_speed;
	float	rot_speed;
	double	oldir_x;
	double	oldplan_x;
}				t_env;

int				choice_map(int key, t_env *e);
void			get_map(int key, t_env *e);
int				o_read(int key, t_env *e);
char			*ft_strjoin_mod(char const *s1, char const *s2);
void			get_nbcol(t_env *e);
void			get_nblin(t_env *e);
int				world_map(t_env *e);
int				create_tab(t_env *e);
int				ft_atoi_mod(char c);
int				key_hook(int keycode, t_env *e);
void			put_pixel_to_image(t_env *e, int *color, int x, int y);
void			var_init(t_env *e, double x, double y);
void			raycasting(t_env *e);
void			digital_differential_analizer(t_env *e);
void			optic_correction(t_env *e);
void			get_height_column(t_env *e);
void			get_color(t_env *e, int y);
void			draw_column(t_env *e, int x);
void			control(int keycode, t_env *e);
void			up(t_env *e);
void			left(t_env *e);
void			down(t_env *e);
void			right(t_env *e);
void			left_rot(t_env *e);
void			right_rot(t_env *e);
#endif
