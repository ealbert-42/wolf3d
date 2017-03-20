/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 17:34:06 by ealbert           #+#    #+#             */
/*   Updated: 2017/03/20 18:30:31 by ealbert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		error_handle(char *s, t_env *v)
{
	ft_putendl(s);
	mlx_destroy_image(v->mlx, v->img);
	mlx_destroy_window(v->mlx, v->win);
	if (v->pts)
		free_map(v, v->y);
	if (v)
		free(v);
	exit(0);
}

t_env		*var_init(t_env *v)
{
	v->r.pdir.x = -1;
	v->r.pdir.y = 0;
	v->r.plane.x = 0;
	v->r.plane.y = 0.66;
	v->rot = 10.0 * M_PI / 180.0;
	v->acc = 0.35;
	v->r.pos.x = v->xpos;
	v->r.pos.y = v->ypos;
	return (v);
}

int			main(int ac, char **av)
{
	t_env	*v;

	if (!(v = (t_env *)malloc(sizeof(t_env))))
		error_handle("Malloc error.", v);
	if (ac != 2)
		error_handle("Usage: ./wolf3d [MAP_FILE]", v);
	v->xpos = -1;
	v->ypos = -1;
	v->x = -1;
	v->y = 0;
	parser(v, av[1]);
	v = save_map(v, av[1]);
	v = var_init(v);
	mlx_calls(v);
	return (0);
}
