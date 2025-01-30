/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkrainyk <mkrainyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:30:39 by mkrainyk          #+#    #+#             */
/*   Updated: 2025/01/30 16:10:01 by mkrainyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "minilibx-linux/mlx.h"
# include "libft.h"
# include "gnl/get_next_line.h"
# include <math.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define WIDTH 3600
# define HEIGHT 2000

# define ESCAPE 65307

typedef struct s_point
{
	float	x;
	float	y;
	float	z;
	int		color;
}			t_point;

typedef struct s_line
{
	float	dx;
	float	dy;
	float	max;
	float	x;
	float	y;
}			t_line;

typedef struct s_map
{
	t_point	**points;
	int		width;
	int		height;
	int		z_max;
	int		z_min;
}			t_map;

typedef struct s_fdf
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*data_addr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	t_map	*map;
}			t_fdf;

t_map	*parse_map(char *filename);
void	draw_map(t_fdf *fdf);
void	draw_line(t_fdf *fdf, t_point start, t_point end);
int		key_hook(int keycode, t_fdf *fdf);
int		close_window(t_fdf *fdf);
void	error_exit(char *message);
int		get_color(int z, t_map *map);
void	isometric(float *x, float *y, int z);
int		ft_word_count(const char *str, char c);
void	ft_free_split(char **split);
int		get_height(char *filename);
int		get_width(char *filename);
void	fill_points(t_map *map, char *line, int y);

#endif