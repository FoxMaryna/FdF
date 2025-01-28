/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkrainyk <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 12:26:43 by mkrainyk          #+#    #+#             */
/*   Updated: 2024/10/10 12:26:44 by mkrainyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*i;

	i = 0;
	while (*s)
	{
		if (*s == (char)c)
			i = s;
		s++;
	}
	if (!(char)c)
		return ((char *)s);
	return ((char *)i);
}
