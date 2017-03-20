/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 11:26:42 by ealbert           #+#    #+#             */
/*   Updated: 2016/01/18 11:34:53 by ealbert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_strlcat(char *dst, const char *src, size_t size)
{
	int		i;
	int		j;

	i = 0;
	while (src[i])
		i++;
	j = i;
	i = 0;
	while (dst[i] && i < size)
		i++;
	if (i < size)
		j = j + i;
	else
		j = j + size;
	if ((int)(size - ft_strlen(dst) - 1) > 0)
		ft_strncat(dst, src, size - ft_strlen(dst) - 1);
	return (j);
}
