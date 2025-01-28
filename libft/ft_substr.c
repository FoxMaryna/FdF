/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkrainyk <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 12:27:19 by mkrainyk          #+#    #+#             */
/*   Updated: 2024/10/10 12:27:20 by mkrainyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	slen;
	size_t	sublen;

	slen = 0;
	sublen = 0;
	if (!s)
		return (0);
	slen = ft_strlen(s);
	if (start >= slen)
		return (ft_strdup(""));
	sublen = slen - start;
	if (sublen > len)
		sublen = len;
	sub = malloc((sublen + 1) * sizeof(char));
	if (!sub)
		return (0);
	ft_strlcpy(sub, s + start, sublen + 1);
	return (sub);
}
