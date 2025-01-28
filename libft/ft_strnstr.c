/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkrainyk <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 12:26:30 by mkrainyk          #+#    #+#             */
/*   Updated: 2024/10/10 12:26:31 by mkrainyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *b, const char *l, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!b && !l)
		return (0);
	if (!*l)
		return ((char *)&b[i]);
	while (b[i] && i < len)
	{
		j = 0;
		while (b[i + j] == l[j] && i + j < len)
		{
			if (!l[j + 1])
				return ((char *)&b[i]);
			j++;
		}
		i++;
	}
	return (0);
}
