/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maryna <maryna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:55:49 by mkrainyk          #+#    #+#             */
/*   Updated: 2025/02/01 22:36:51 by maryna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

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

int	get_height(char *filename)
{
	int		fd;
	int		height;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		error_exit("Error opening file for height calculation");
	height = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		height++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (height);
}

int	get_width(char *filename)
{
	int		fd;
	char	*line;
	int		width;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		error_exit("Error opening file for width calculation");
	line = get_next_line(fd);
	if (line)
	{
		width = ft_word_count(line, ' ');
		free(line);
	}
	else
		width = 0;
	close(fd);
	return (width);
}

void	fill_points(t_map *map, char *line, int y)
{
	char	**split;
	int		x;

	split = ft_split(line, ' ');
	if (!split)
		error_exit("Error splitting line");
	x = 0;
	while (split[x] && x < map->width)
	{
		map->points[y][x].x = x;
		map->points[y][x].y = y;
		map->points[y][x].z = ft_atoi(split[x]);
		if (map->points[y][x].z > map->z_max)
			map->z_max = map->points[y][x].z;
		if (map->points[y][x].z < map->z_min)
			map->z_min = map->points[y][x].z;
		x++;
	}
	ft_free_split(split);
}
