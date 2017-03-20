/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 14:40:04 by ealbert           #+#    #+#             */
/*   Updated: 2015/11/30 19:16:14 by ealbert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*dest;
	char	*srcs;

	if (n == 0 || dst == src)
		return (dst);
	dest = (char *)dst;
	srcs = (char *)src;
	while (--n)
		*dest++ = *srcs++;
	*dest = *srcs;
	return (dst);
}
