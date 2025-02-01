/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maryna <maryna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 22:25:53 by maryna            #+#    #+#             */
/*   Updated: 2025/02/01 22:59:37 by maryna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	ft_free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	free_map(t_map *map)
{
	int	i;

	if (!map)
		return ;
	if (map->points)
	{
		i = 0;
		while (i < map->height)
		{
			free(map->points[i]);
			i++;
		}
		free(map->points);
	}
	free(map);
}

void	free_fdf(t_fdf *fdf)
{
	int	i;

	if (!fdf)
		return ;
	if (fdf->map)
	{
		i = 0;
		while (i < fdf->map->height)
		{
			free(fdf->map->points[i]);
			i++;
		}
		free(fdf->map->points);
		free(fdf->map);
	}
	if (fdf->img)
		mlx_destroy_image(fdf->mlx, fdf->img);
	if (fdf->win)
		mlx_destroy_window(fdf->mlx, fdf->win);
	if (fdf->mlx)
	{
		mlx_destroy_display(fdf->mlx);
		free(fdf->mlx);
	}
	free(fdf);
}
