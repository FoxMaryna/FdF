/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkrainyk <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 12:20:34 by mkrainyk          #+#    #+#             */
/*   Updated: 2024/10/10 12:20:35 by mkrainyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_numlen(long int nb);
static char	*ft_nullnb(void);

char	*ft_itoa(int n)
{
	long int	nb;
	int			len;
	char		*s;

	nb = n;
	len = ft_numlen(nb);
	if (nb == 0)
		return (ft_nullnb());
	s = malloc((len + 1) * sizeof(char));
	if (!s)
		return (NULL);
	s[len] = '\0';
	if (nb < 0)
	{
		s[0] = '-';
		nb = -nb;
	}
	while (nb > 0)
	{
		s[--len] = (nb % 10) + '0';
		nb /= 10;
	}
	return (s);
}

static int	ft_numlen(long int nb)
{
	int	len;

	len = 0;
	if (nb < 0)
		len++;
	while (nb)
	{
		nb /= 10;
		len++;
	}
	return (len);
}

static char	*ft_nullnb(void)
{
	char	*s;

	s = malloc(2 * sizeof(char));
	if (!s)
		return (NULL);
	s[0] = '0';
	s[1] = '\0';
	return (s);
}
