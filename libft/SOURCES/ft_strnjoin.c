/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 20:02:31 by ealbert           #+#    #+#             */
/*   Updated: 2016/03/29 21:02:49 by ealbert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnjoin(char *s1, char *s2, int n)
{
	char	*new;

	if (!(new = malloc(ft_strlen(s1) + n + 1)))
		return (NULL);
	ft_strcpy(new, s1);
	ft_strncat(new, s1, n);
	return (new);
}
