/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 18:04:28 by ealbert           #+#    #+#             */
/*   Updated: 2017/03/19 22:55:53 by ealbert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static double	hit_perform(t_env *v, int hit)
{
	while (hit == 0)
	{
		if (v->r.sdist.x < v->r.sdist.y)
		{
			v->r.sdist.x += v->r.rinc.x;
			v->r.map.x += v->r.inc.x;
			v->r.side = 0;
		}
		else
		{
			v->r.sdist.y += v->r.rinc.y;
			v->r.map.y += v->r.inc.y;
			v->r.side = 1;
		}
		hit = (v->pts[v->r.map.x][v->r.map.y] > 0) ? 1 : 0;
	}
	if (v->r.side == 0)
		return (fabs((v->r.map.x - v->r.pos.x + (1 - v->r.inc.x) / 2)
			/ v->r.rdir.x));
	else
		return (fabs((v->r.map.y - v->r.pos.y + (1 - v->r.inc.y) / 2)
			/ v->r.rdir.y));
}

static int		init_ray(t_env *v, int x)
{
	v->r.map.x = (int)(v->r.pos.x);
	v->r.map.y = (int)(v->r.pos.y);
	v->r.cam.x = (2 * (double)x / (double)WIN_Y) - 1;
	v->r.rdir.x = v->r.pdir.x + v->r.plane.x * v->r.cam.x;
	v->r.rdir.y = v->r.pdir.y + v->r.plane.y * v->r.cam.x;
	v->r.rinc.x = sqrt(1 + (v->r.rdir.y * v->r.rdir.y)
			/ (v->r.rdir.x * v->r.rdir.x));
	v->r.rinc.y = sqrt(1 + (v->r.rdir.x * v->r.rdir.x)
			/ (v->r.rdir.y * v->r.rdir.y));
	v->r.inc.x = (v->r.rdir.x < 0) ? -1 : 1;
	v->r.inc.y = (v->r.rdir.y < 0) ? -1 : 1;
	v->r.sdist.x = (v->r.rdir.x < 0) ? (v->r.pos.x - v->r.map.x) * v->r.rinc.x :
		(v->r.map.x + 1.0 - v->r.pos.x) * v->r.rinc.x;
	v->r.sdist.y = (v->r.rdir.y < 0) ? (v->r.pos.y - v->r.map.y) * v->r.rinc.y :
		(v->r.map.y + 1.0 - v->r.pos.y) * v->r.rinc.y;
	return (0);
}

void			raycast(t_env *v)
{
	int		x;
	int		hit;
	double	dist;

	x = 0;
	background(v);
	while (++x != WIN_X)
	{
		hit = init_ray(v, x);
		dist = hit_perform(v, hit);
		draw_line(v, x, dist);
	}
}
