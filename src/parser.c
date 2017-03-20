/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 22:49:37 by ealbert           #+#    #+#             */
/*   Updated: 2017/03/20 18:10:21 by ealbert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static int	line_parse(char *line, t_env *v, int i)
{
	char	**tab;
	int		j;

	tab = ft_strsplit(line, ' ');
	j = -1;
	while (tab[++j])
	{
		if (ft_strlen(tab[j]) != 1 || (tab[j][0] != '1' && tab[j][0] != '0'
			&& tab[j][0] != 'X'))
			return (-1);
		if (tab[j][0] == 'X')
		{
			if (v->xpos != -1 && v->ypos != -1)
				return (-1);
			v->xpos = i + 1.4999;
			v->ypos = j + 1.4999;
		}
	}
	clean_tab(tab);
	v->x = (v->x == -1) ? j : v->x;
	return ((j != v->x) ? -1 : 1);
}

void		parser(t_env *v, char *s)
{
	char	*line;
	int		ret;

	if ((v->fd = open(s, O_RDONLY)) == -1)
		error_handle("Could not open the file.", v);
	while ((ret = get_next_line(v->fd, &line)))
	{
		if (ret == -1)
			error_handle("Could not read the file.", v);
		if (line_parse(line, v, v->y) == -1)
			error_handle("Invalid file.", v);
		v->y++;
		free(line);
	}
	if (v->xpos == -1 || v->ypos == -1)
		error_handle("Invalid file.", v);
	close(v->fd);
}
