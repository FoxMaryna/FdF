/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maryna <maryna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:32:36 by mkrainyk          #+#    #+#             */
/*   Updated: 2025/02/01 22:54:04 by maryna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static t_map	*initialize_map(char *filename)
{
	t_map	*map;

	map = (t_map *)ft_calloc(1, sizeof(t_map));
	if (!map)
		error_exit("Memory allocation failed for map");
	map->height = get_height(filename);
	map->width = get_width(filename);
	if (map->height <= 0 || map->width <= 0)
		error_exit("Invalid map dimensions");
	map->z_min = INT_MAX;
	map->z_max = INT_MIN;
	return (map);
}

static void	allocate_points(t_map *map)
{
	int	i;
	int	j;

	map->points = (t_point **)ft_calloc(map->height, sizeof(t_point *));
	if (!map->points)
		error_exit("Memory allocation failed for map->points");
	i = 0;
	while (i < map->height)
	{
		map->points[i] = (t_point *)ft_calloc(map->width, sizeof(t_point));
		j = 0;
		if (!map->points[i])
		{
			while (j < i)
			{
				free(map->points[j]);
				j++;
			}
			free(map->points);
			free(map);
			error_exit("Memory allocation failed for map->points[i]");
		}
		i++;
	}
}

static void	read_and_fill_map(t_map *map, char *filename)
{
	int		fd;
	char	*line;
	int		y;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		error_exit("Error opening file for map parsing");
	y = 0;
	line = get_next_line(fd);
	while (line)
	{
		if (y >= map->height)
		{
			free(line);
			break ;
		}
		fill_points(map, line, y);
		free(line);
		y++;
		line = get_next_line(fd);
	}
	close(fd);
}

t_map	*parse_map(char *filename)
{
	t_map	*map;

	map = initialize_map(filename);
	allocate_points(map);
	read_and_fill_map(map, filename);
	return (map);
}
