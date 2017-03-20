/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbert <ealbert@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 11:19:11 by ealbert           #+#    #+#             */
/*   Updated: 2016/01/18 11:38:00 by ealbert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	char	*s;

	s = dst;
	while (n > 0 && *src != '\0')
	{
		*s = *src;
		s++;
		src++;
		n--;
	}
	while (n > 0)
	{
		*s = '\0';
		s++;
		n--;
	}
	return (dst);
}
