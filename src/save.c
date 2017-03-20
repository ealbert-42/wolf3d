/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 15:28:28 by ealbert           #+#    #+#             */
/*   Updated: 2017/03/20 18:13:11 by ealbert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void			free_map(t_env *v, int x)
{
	int		i;

	i = -1;
	if (v->pts)
	{
		while (++i <= x + 1)
		{
			if (v->pts[i])
				free(v->pts[i]);
		}
		free(v->pts);
		v->pts = NULL;
	}
}

void			clean_tab(char **t)
{
	int		i;

	i = -1;
	while (t[++i])
		free(t[i]);
	free(t);
}

static void		fill_line(t_env *v, int i, char **t)
{
	int		j;

	j = -1;
	if (i == 0 || i == v->y + 1)
	{
		while (++j <= v->x + 1)
			v->pts[i][j] = 1;
	}
	else
	{
		v->pts[i][++j] = 1;
		while (++j <= v->x)
			v->pts[i][j] = (t[j - 1][0] == 'X') ? 0 : ft_atoi(t[j - 1]);
		v->pts[i][j] = 1;
	}
}

static t_env	*get_line(t_env *v, int i)
{
	int		ret;
	char	*line;
	char	**tab;

	ret = get_next_line(v->fd, &line);
	if (ret == -1)
		error_handle("Could not read the file.", v);
	tab = ft_strsplit(line, ' ');
	fill_line(v, i, tab);
	free(line);
	clean_tab(tab);
	return (v);
}

t_env			*save_map(t_env *v, char *s)
{
	int		i;

	if ((v->fd = open(s, O_RDONLY)) == -1)
		error_handle("Could not open the file.", v);
	if (!(v->pts = (int **)malloc(sizeof(int *) * (v->y + 2))))
		error_handle("Malloc error.", v);
	i = -1;
	while (++i != (v->y + 2))
	{
		if (!(v->pts[i] = (int *)malloc(sizeof(int) * (v->x + 2))))
			error_handle("Malloc error.", v);
		if (i == 0 || i == (v->y + 1))
			fill_line(v, i, NULL);
		else
			v = get_line(v, i);
	}
	close(v->fd);
	return (v);
}
