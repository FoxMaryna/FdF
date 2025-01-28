#include "../fdf.h"

void isometric(float *x, float *y, int z)
{
    float previous_x = *x;
    float previous_y = *y;
    *x = (previous_x - previous_y) * cos(0.523599);
    *y = -z + (previous_x + previous_y) * sin(0.523599);
}

void draw_line(t_fdf *fdf, t_point start, t_point end)
{
    float dx = end.x - start.x;
    float dy = end.y - start.y;
    float max = fmax(fabs(dx), fabs(dy));
    float x = start.x;
    float y = start.y;

    int i = 0;
    while (i < max)
    {
        if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
        {
            int color = get_color(start.z, fdf->map);
            int index = ((int)y * fdf->size_line) + ((int)x * (fdf->bits_per_pixel / 8));
            *(unsigned int*)(fdf->data_addr + index) = mlx_get_color_value(fdf->mlx, color);
        }
        x += dx / max;
        y += dy / max;
        i++;
    }
}

void draw_map(t_fdf *fdf)
{
    int x, y;
    float scale = fmin(WIDTH / fdf->map->width / 2, HEIGHT / fdf->map->height / 2);

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
            if (y < fdf->map->height - 1)
            {
                t_point start = fdf->map->points[y][x];
                t_point end = fdf->map->points[y + 1][x];
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
            x++;
        }
        y++;
    }
}
