/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 12:04:28 by ealbert           #+#    #+#             */
/*   Updated: 2015/12/03 17:13:43 by ealbert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s)
{
	size_t	bfr;
	size_t	keep;
	size_t	i;

	i = 0;
	bfr = 0;
	keep = 0;
	while (s[bfr] == ' ' || s[bfr] == '\t' || s[bfr] == '\n')
		bfr++;
	while (s[i] != '\0')
	{
		if (s[i] != ' ' && s[i] != '\t' && s[i] != '\n')
		{
			i++;
			keep = i;
		}
		else
			i++;
	}
	if (keep == 0)
		return (ft_strdup(""));
	return (ft_strsub(s, bfr, (keep - bfr)));
}
