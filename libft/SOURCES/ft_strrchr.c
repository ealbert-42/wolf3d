/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 11:46:49 by ealbert           #+#    #+#             */
/*   Updated: 2015/12/02 16:24:42 by ealbert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		len;
	char	*tmp;

	tmp = (char *)s;
	len = ft_strlen((char *)s);
	while (len != 0 && tmp[len] != (char)c)
		len--;
	if (tmp[len] == (char)c)
		return (&tmp[len]);
	return (NULL);
}
