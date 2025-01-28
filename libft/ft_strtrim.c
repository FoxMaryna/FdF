/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkrainyk <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 12:27:00 by mkrainyk          #+#    #+#             */
/*   Updated: 2024/10/10 12:27:01 by mkrainyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_is_set(char c, const char *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	char	*s2;

	i = 0;
	j = ft_strlen(s1);
	if (!s1 || !set)
		return (0);
	while (s1[i] && ft_is_set(s1[i], set))
		i++;
	while (j > i && ft_is_set(s1[j - 1], set))
		j--;
	s2 = malloc((j - i + 1) * sizeof(char));
	if (!s2)
		return (0);
	ft_strlcpy(s2, &s1[i], j - i + 1);
	return (s2);
}
