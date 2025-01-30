/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkrainyk <mkrainyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:31:51 by mkrainyk          #+#    #+#             */
/*   Updated: 2025/01/30 16:14:56 by mkrainyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	error_exit(char *message)
{
	ft_putendl_fd(message, 2);
	exit(1);
}

int	key_hook(int keycode, t_fdf *fdf)
{
	if (keycode == ESCAPE)
		close_window(fdf);
	return (0);
}

int	close_window(t_fdf *fdf)
{
	mlx_destroy_window(fdf->mlx, fdf->win);
	exit(0);
}

int	ft_word_count(const char *str, char c)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*str)
	{
		if (*str != c && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if (*str == c)
			in_word = 0;
		str++;
	}
	return (count);
}

int	get_color(int z, t_map *map)
{
	double	percentage;

	percentage = (z - map->z_min) / (double)(map->z_max - map->z_min);
	if (percentage < 0.1)
		return (0x0000FF);
	else if (percentage < 0.2)
		return (0x0080FF);
	else if (percentage < 0.3)
		return (0x00FFFF);
	else if (percentage < 0.4)
		return (0x00FF80);
	else if (percentage < 0.5)
		return (0x00FF00);
	else if (percentage < 0.6)
		return (0x80FF00);
	else if (percentage < 0.7)
		return (0xFFFF00);
	else if (percentage < 0.8)
		return (0xFF8000);
	else if (percentage < 0.9)
		return (0xFF4000);
	else
		return (0xFF0000);
}
