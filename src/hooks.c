/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 20:35:44 by ealbert           #+#    #+#             */
/*   Updated: 2017/03/20 18:26:27 by ealbert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <stdio.h>

static void	commands(t_env *v)
{
	mlx_string_put(v->mlx, v->win, 3, 0, 0, "Esc        = Quit");
	mlx_string_put(v->mlx, v->win, 3, 15, 0, "Up/Down    = Move");
	mlx_string_put(v->mlx, v->win, 3, 30, 0, "Left/Right = Rotate");
	mlx_string_put(v->mlx, v->win, 3, 45, 0, "Numpad +/- = Change rot. speed");
	mlx_string_put(v->mlx, v->win, 510, 0, 0, "Wolf3D by ealbert");
}

static int	refresher(t_env *v)
{
	mlx_clear_window(v->mlx, v->win);
	raycast(v);
	mlx_put_image_to_window(v->mlx, v->win, v->img, 0, 0);
	commands(v);
	return (1);
}

static int	on_crossclick(t_env *v)
{
	error_handle("The program stopped successfully.", v);
	return (0);
}

static int	on_keydown(int keycode, t_env *v)
{
	if (keycode == K_EXIT)
		error_handle("The program stopped successfully.", v);
	else if (keycode == FWD)
		forward(v);
	else if (keycode == BWD)
		backward(v);
	else if (keycode == RIGHT)
		right(v);
	else if (keycode == LEFT)
		left(v);
	else if (keycode == ROTM)
		v->rot = (v->rot - ROTMIN >= 0.05) ? v->rot - ROTMIN : ROTMIN;
	else if (keycode == ROTP)
		v->rot = (v->rot <= ROTMAX) ? v->rot + ROTMIN : ROTMAX;
	refresher(v);
	return (0);
}

void		mlx_calls(t_env *v)
{
	v->mlx = mlx_init();
	v->win = mlx_new_window(v->mlx, WIN_X, WIN_Y, "");
	v->img = mlx_new_image(v->mlx, WIN_X, WIN_Y);
	v->data = (unsigned char *)mlx_get_data_addr(v->img, &(v->bpp),
		&(v->s_line), &(v->end));
	mlx_hook(v->win, 2, 2, on_keydown, v);
	mlx_hook(v->win, 17, 2, on_crossclick, v);
	mlx_expose_hook(v->win, refresher, v);
	mlx_loop(v->mlx);
}
