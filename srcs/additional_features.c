#include "../fdf.h"

void rotate_map(t_fdf *fdf, float angle)
{
    int x;
    int y;
    float old_x;
    float old_y;

    y = 0;
    while (y < fdf->map->height)
    {
        x = 0;
        while (x < fdf->map->width)
        {
            old_x = fdf->map->points[y][x].x;
            old_y = fdf->map->points[y][x].y;
            fdf->map->points[y][x].x = old_x * cos(angle) - old_y * sin(angle);
            fdf->map->points[y][x].y = old_x * sin(angle) + old_y * cos(angle);
            x++;
        }
        y++;
    }
}

void change_color(t_fdf *fdf)
{
    int x;
    int y;
    int color;

    color = rand() % 0xFFFFFF;
    y = 0;
    while (y < fdf->map->height)
    {
        x = 0;
        while (x < fdf->map->width)
        {
            fdf->map->points[y][x].color = color;
            x++;
        }
        y++;
    }
}
