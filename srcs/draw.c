/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maryna <maryna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:31:56 by mkrainyk          #+#    #+#             */
/*   Updated: 2025/02/01 22:38:27 by maryna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	isometric(float *x, float *y, int z)
{
	float	previous_x;
	float	previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = (previous_x - previous_y) * cos(0.523599);
	*y = -z + (previous_x + previous_y) * sin(0.523599);
}

void	draw_line(t_fdf *fdf, t_point start, t_point end)
{
	t_line	line;
	int		color;
	int		index;
	int		i;

	line.dx = end.x - start.x;
	line.dy = end.y - start.y;
	line.max = fmax(fabs(line.dx), fabs(line.dy));
	line.x = start.x;
	line.y = start.y;
	i = 0;
	while (i < line.max)
	{
		if (line.x >= 0 && line.x < WIDTH && line.y >= 0 && line.y < HEIGHT)
		{
			color = get_color(start.z, fdf->map);
			index = ((int)line.y * fdf->size_line)
				+ ((int)line.x * (fdf->bits_per_pixel / 8));
			*(unsigned int *)(fdf->data_addr + index)
				= mlx_get_color_value(fdf->mlx, color);
		}
		line.x += line.dx / line.max;
		line.y += line.dy / line.max;
		i++;
	}
}

static void	draw_horizontal_line(t_fdf *fdf, int x, int y, float scale)
{
	t_point	start;
	t_point	end;

	if (x < fdf->map->width - 1)
	{
		start = fdf->map->points[y][x];
		end = fdf->map->points[y][x + 1];
		start.x = x * scale;
		start.y = y * scale;
		end.x = (x + 1) * scale;
		end.y = y * scale;
		isometric(&start.x, &start.y, start.z * scale / 10);
		isometric(&end.x, &end.y, end.z * scale / 10);
		start.x += WIDTH / 2;
		start.y += HEIGHT / 3;
		end.x += WIDTH / 2;
		end.y += HEIGHT / 3;
		draw_line(fdf, start, end);
	}
}

static void	draw_vertical_line(t_fdf *fdf, int x, int y, float scale)
{
	t_point	start;
	t_point	end;

	if (y < fdf->map->height - 1)
	{
		start = fdf->map->points[y][x];
		end = fdf->map->points[y + 1][x];
		start.x = x * scale;
		start.y = y * scale;
		end.x = x * scale;
		end.y = (y + 1) * scale;
		isometric(&start.x, &start.y, start.z * scale / 10);
		isometric(&end.x, &end.y, end.z * scale / 10);
		start.x += WIDTH / 2;
		start.y += HEIGHT / 3;
		end.x += WIDTH / 2;
		end.y += HEIGHT / 3;
		draw_line(fdf, start, end);
	}
}

void	draw_map(t_fdf *fdf)
{
	int		x;
	int		y;
	float	scale;

	scale = fmin(WIDTH / fdf->map->width / 2.5,
			HEIGHT / fdf->map->height / 2.5);
	y = 0;
	while (y < fdf->map->height)
	{
		x = 0;
		while (x < fdf->map->width)
		{
			draw_horizontal_line(fdf, x, y, scale);
			draw_vertical_line(fdf, x, y, scale);
			x++;
		}
		y++;
	}
}
