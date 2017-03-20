/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 17:48:58 by ealbert           #+#    #+#             */
/*   Updated: 2017/03/14 17:21:27 by ealbert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H

# define WOLF3D_H
# define WIN_X 1200
# define WIN_Y 900
# define K_EXIT 53
# define RIGHT 124
# define LEFT 123
# define FWD 126
# define BWD 125
# define ROTM 78
# define ROTP 69
# define ROTMAX (25 * M_PI / 180)
# define ROTMIN (1 * M_PI / 180)

# include "libft.h"
# include "mlx.h"
# include <fcntl.h>
# include <math.h>

typedef struct		s_2d
{
	double			x;
	double			y;
}					t_2d;

typedef struct		s_2i
{
	int				x;
	int				y;
}					t_2i;

typedef struct		s_ray
{
	t_2d			cam;
	t_2d			plane;
	t_2d			pdir;
	t_2d			rdir;
	t_2d			sdist;
	t_2i			map;
	t_2i			inc; //step
	t_2d			rinc; //raystep
	t_2d			pos;
	int				xmap;
	int				ymap;
	double			dist;
	double			side;
}					t_ray;


typedef struct		s_env
{
	void			*mlx;
	void			*win;
	void			*img;
	unsigned char	*data;
	int				bpp;
	int				s_line;
	int				end;
	int				x;
	int				y;
	int				fd;
	double			xpos;
	double			ypos;
	int				**pts;
	double			acc;
	double			rot;
	t_ray			r;
}					t_env;

void				error_handle(char *s, t_env *v);
void				mlx_calls(t_env *v);
void				free_map(t_env *v, int x);
t_env				*save_map(t_env *v, char *s);
void				raycast(t_env *v);
void				draw_line(t_env *v, int x, double dist);
void				forward(t_env *v);
void				backward(t_env *v);
void				left(t_env *v);
void				right(t_env *v);
void				background(t_env *v);
void				parser(t_env *v, char *s);
void				clean_tab(char **t);

#endif
