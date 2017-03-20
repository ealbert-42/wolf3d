/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 18:59:15 by ealbert           #+#    #+#             */
/*   Updated: 2017/03/19 22:56:08 by ealbert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		right(t_env *v)
{
	double x;

	x = v->r.pdir.x;
	v->r.pdir.x = v->r.pdir.x * cos(-v->rot) - v->r.pdir.y * sin(-v->rot);
	v->r.pdir.y = x * sin(-v->rot) + v->r.pdir.y * cos(-v->rot);
	x = v->r.plane.x;
	v->r.plane.x = v->r.plane.x * cos(-v->rot) - v->r.plane.y * sin(-v->rot);
	v->r.plane.y = x * sin(-v->rot) + v->r.plane.y * cos(-v->rot);
}

void		left(t_env *v)
{
	double x;

	x = v->r.pdir.x;
	v->r.pdir.x = v->r.pdir.x * cos(v->rot) - v->r.pdir.y * sin(v->rot);
	v->r.pdir.y = x * sin(v->rot) + v->r.pdir.y * cos(v->rot);
	x = v->r.plane.x;
	v->r.plane.x = v->r.plane.x * cos(v->rot) - v->r.plane.y * sin(v->rot);
	v->r.plane.y = x * sin(v->rot) + v->r.plane.y * cos(v->rot);
}

void		forward(t_env *v)
{
	if (!v->pts[(int)(v->r.pos.x + v->r.pdir.x * v->acc)][(int)(v->r.pos.y)])
		v->r.pos.x += v->r.pdir.x * v->acc;
	if (!v->pts[(int)(v->r.pos.x)][(int)(v->r.pos.y + v->r.pdir.y * v->acc)])
		v->r.pos.y += v->r.pdir.y * v->acc;
}

void		backward(t_env *v)
{
	if (!v->pts[(int)(v->r.pos.x - v->r.pdir.x * v->acc)][(int)(v->r.pos.y)])
		v->r.pos.x -= v->r.pdir.x * v->acc;
	if (!v->pts[(int)(v->r.pos.x)][(int)(v->r.pos.y - v->r.pdir.y * v->acc)])
		v->r.pos.y -= v->r.pdir.y * v->acc;
}
