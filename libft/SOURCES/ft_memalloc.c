/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 16:01:27 by ealbert           #+#    #+#             */
/*   Updated: 2015/11/26 15:22:03 by ealbert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void			*new;
	int				i;
	unsigned char	*tmp;

	new = malloc(size);
	tmp = (unsigned char *)new;
	i = 0;
	if (!new)
		return (NULL);
	else
	{
		while (i < size)
		{
			tmp[i] = 0;
			i++;
		}
	}
	new = (void *)tmp;
	return (new);
}
