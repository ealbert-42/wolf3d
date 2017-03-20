/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrealloc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 16:32:57 by ealbert           #+#    #+#             */
/*   Updated: 2016/03/11 16:48:57 by ealbert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrealloc(char *str, int size)
{
	char		*new;
	int			i;

	size += ft_strlen(str) + 1;
	if ((new = (char *)malloc(size)))
		return (NULL);
	i = -1;
	while (str[++i])
		new[i] = str[i];
	free(str);
	new[i] = '\0';
	return (new);
}
