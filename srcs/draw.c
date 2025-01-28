#include "../fdf.h"

void apply_camera(t_fdf *fdf, t_point *p)
{
    float x = p->x;
    float y = p->y;
    float z = p->z;

    // Применение поворотов
    float y1 = y * cos(fdf->camera->x_angle) + z * sin(fdf->camera->x_angle);
    float z1 = -y * sin(fdf->camera->x_angle) + z * cos(fdf->camera->x_angle);

    float x2 = x * cos(fdf->camera->y_angle) + z1 * sin(fdf->camera->y_angle);
    z = -x * sin(fdf->camera->y_angle) + z1 * cos(fdf->camera->y_angle);

    x = x2 * cos(fdf->camera->z_angle) - y1 * sin(fdf->camera->z_angle);
    y = x2 * sin(fdf->camera->z_angle) + y1 * cos(fdf->camera->z_angle);

    // Применение зума и смещения
    x *= fdf->camera->zoom;
    y *= fdf->camera->zoom;

    x += fdf->camera->x_offset;
    y += fdf->camera->y_offset;

    p->x = x;
    p->y = y;
}

void draw_line(t_fdf *fdf, t_point start, t_point end)
{
    float dx = end.x - start.x;
    float dy = end.y - start.y;
    float step = fmax(fabs(dx), fabs(dy));

    dx /= step;
    dy /= step;

    float x = start.x;
    float y = start.y;

    while ((int)(x - end.x) || (int)(y - end.y))
    {
        if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
        {
            int color = get_color(start.z, fdf->map);
            mlx_pixel_put(fdf->mlx, fdf->win, x, y, color);
        }
        x += dx;
        y += dy;
    }
}

void draw_map(t_fdf *fdf)
{
    int x, y;

    y = 0;
    while (y < fdf->map->height)
    {
        x = 0;
        while (x < fdf->map->width)
        {
            if (x < fdf->map->width - 1)
            {
                t_point start = fdf->map->points[y][x];
                t_point end = fdf->map->points[y][x + 1];
                apply_camera(fdf, &start);
                apply_camera(fdf, &end);
                draw_line(fdf, start, end);
            }
            if (y < fdf->map->height - 1)
            {
                t_point start = fdf->map->points[y][x];
                t_point end = fdf->map->points[y + 1][x];
                apply_camera(fdf, &start);
                apply_camera(fdf, &end);
                draw_line(fdf, start, end);
            }
            x++;
        }
        y++;
    }
}

int get_color(int z, t_map *map)
{
    double percentage = (z - map->z_min) / (double)(map->z_max - map->z_min);
    if (percentage < 0.2)
        return (0x0000FF); // Blue for low values
    else if (percentage < 0.4)
        return (0x00FFFF); // Cyan
    else if (percentage < 0.6)
        return (0x00FF00); // Green
    else if (percentage < 0.8)
        return (0xFFFF00); // Yellow
    else
        return (0xFF0000); // Red for high values
}
