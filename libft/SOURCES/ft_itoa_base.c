/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/08 18:29:27 by ealbert           #+#    #+#             */
/*   Updated: 2016/04/08 19:40:19 by ealbert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nblen(int nb, int len)
{
	int		i;

	i = 0;
	if (nb <= 0 && len == 10)
		i++;
	while (nb)
	{
		nb /= len;
		i++;
	}
	return (i + 1);
}

static int	matching(char *base)
{
	int		i;
	int		j;

	i = 0;
	if (!base[i])
		return (-1);
	while (base[++i])
	{
		j = i;
		while (base[++j])
		{
			if (base[j] == base[i])
				return (-1);
		}
	}
	return (i);
}

char		*ft_itoa_base(int nb, char *base)
{
	char	*new;
	int		len;
	int		len2;
	int		nbr;

	if ((len = matching(base)) <= 1)
		return (NULL);
	len2 = nblen(nb, len);
	if (!(new = malloc(sizeof(char) * len2)))
		return (NULL);
	new[--len2] = '\0';
	nbr = (unsigned int)((nb < 0) ? -nb : nb);
	while (nbr)
	{
		new[--len2] = base[nbr % len];
		nbr /= len;
	}
	if (nb < 0 && len == 10)
		new[0] = '-';
	return (new);
}
