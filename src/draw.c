/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 18:52:58 by ealbert           #+#    #+#             */
/*   Updated: 2017/03/20 17:40:35 by ealbert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static unsigned int	color_define(t_env *v)
{
	if (v->r.side == 0)
	{
		if (v->r.inc.x == 1)
			return (0x00AA00);
		else
			return (0x007000);
	}
	else
	{
		if (v->r.inc.y == 1)
			return (0x008800);
		else
			return (0x008800);
	}
	return (0xFFFFFF);
}

void				ft_pixel_put(t_env *v, int x, int y, int color)
{
	if (x > 0 && x < WIN_X && y > 0 && y < WIN_Y)
	{
		v->data[y * v->s_line + x * v->bpp / 8] = (unsigned int)color % 256;
		v->data[y * v->s_line + x * v->bpp / 8 + 1] =
			(unsigned int)color >> 8 % 256;
		v->data[y * v->s_line + x * v->bpp / 8 + 2] =
			(unsigned int)color >> 16 % 256;
	}
}

void				background(t_env *v)
{
	int		i;
	int		j;

	i = -1;
	while (++i != WIN_Y / 2)
	{
		j = -1;
		while (++j < WIN_X)
			ft_pixel_put(v, j, i, 0x88bef0);
	}
	i = WIN_Y / 2 - 1;
	while (++i != WIN_Y)
	{
		j = -1;
		while (++j < WIN_X)
			ft_pixel_put(v, j, i, 0x947d47);
	}
}

void				draw_line(t_env *v, int x, double dist)
{
	int				height;
	unsigned int	color;
	int				y;

	height = (int)(fabs(WIN_X / dist) / 2);
	color = color_define(v);
	y = (int)(-height / 2 + (WIN_Y / 2));
	if (y < 0)
		y = 0;
	while (y <= (height / 2) + (WIN_Y / 2) && y != WIN_Y)
	{
		ft_pixel_put(v, x, y, color);
		y++;
	}
}
