/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/06 15:14:36 by ealbert           #+#    #+#             */
/*   Updated: 2017/03/14 15:43:38 by ealbert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		find_nl(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

static int		last_line(char **array, char **line)
{
	if (!(*line = ft_strdup(*array)))
		return (-1);
	free(*array);
	*array = ft_strnew(0);
	return (1);
}

static int		cut_line(char **array, char **line, int len)
{
	char	*tmp;

	if (!(*line = ft_strsub(*array, 0, len)))
		return (-1);
	tmp = *array;
	if (!(*array = ft_strdup(ft_strchr(*array, '\n') + 1)))
		return (-1);
	ft_strdel(&tmp);
	return (1);
}

static int		read_file(int fd, char **array, char **line)
{
	char	buf[BUFF_SIZE + 1];
	int		ret;
	int		len;
	char	*tmp;

	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		if (ret == -1)
			return (-1);
		buf[ret] = '\0';
		tmp = *array;
		*array = ft_strjoin(*array, buf);
		ft_strdel(&tmp);
		if ((len = find_nl(*array)) > -1)
			return (cut_line(array, line, len));
	}
	return (-2);
}

int				get_next_line(int fd, char **line)
{
	static char		*array[MAX_FD];
	int				len;
	int				ret;

	if (fd < 0 || fd == 1 || fd == 2 || fd >= MAX_FD \
			|| BUFF_SIZE <= 0 || line == NULL)
		return (-1);
	if (array[fd] == NULL)
		array[fd] = ft_strnew(0);
	if (ft_strlen(array[fd]) && (len = find_nl(array[fd])) != -1)
		return (cut_line(&array[fd], line, len));
	if ((ret = read_file(fd, &array[fd], line)) && ret != -2)
		return (ret);
	if (array[fd] && find_nl(array[fd]) == -1 && ft_strlen(array[fd]))
		return (last_line(&array[fd], line));
	*line = ft_strdup("");
	ft_strclr(array[fd]);
	return (0);
}
