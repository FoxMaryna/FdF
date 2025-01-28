/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkrainyk <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 14:52:36 by mkrainyk          #+#    #+#             */
/*   Updated: 2024/10/02 15:10:51 by mkrainyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	len_dst;

	len_dst = ft_strlen(dst);
	i = 0;
	j = 0;
	while (dst[i] && i < dstsize)
		i++;
	if (i >= dstsize)
		return (dstsize + ft_strlen(src));
	while (src[j] && (i + 1 < dstsize))
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (len_dst + ft_strlen(src));
}
