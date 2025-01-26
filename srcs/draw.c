#include "../fdf.h"

static void isometric(float *x, float *y, int z, float angle)
{
    *x = (*x - *y) * cos(angle);
    *y = (*x + *y) * sin(angle) - z;
}

static void project_point(t_fdf *fdf, t_point *p, float *x, float *y)
{
    *x = p->x * fdf->zoom;
    *y = p->y * fdf->zoom;
    if (fdf->is_isometric)
        isometric(x, y, p->z, fdf->angle);
    *x += fdf->shift_x;
    *y += fdf->shift_y;
}

void draw_line(t_fdf *fdf, t_point start, t_point end)
{
    float x1, y1, x2, y2;
    float dx, dy, step;
    int i;

    project_point(fdf, &start, &x1, &y1);
    project_point(fdf, &end, &x2, &y2);

    dx = x2 - x1;
    dy = y2 - y1;
    step = fabs(dx) > fabs(dy) ? fabs(dx) : fabs(dy);
    dx /= step;
    dy /= step;
    i = 0;
    while (i <= step)
    {
        mlx_pixel_put(fdf->mlx, fdf->win, x1, y1, 0xFFFFFF);
        x1 += dx;
        y1 += dy;
        i++;
    }
}

void draw_map(t_fdf *fdf)
{
    int x;
    int y;

    y = 0;
    while (y < fdf->map->height)
    {
        x = 0;
        while (x < fdf->map->width)
        {
            if (x < fdf->map->width - 1)
                draw_line(fdf, fdf->map->points[y][x], fdf->map->points[y][x + 1]);
            if (y < fdf->map->height - 1)
                draw_line(fdf, fdf->map->points[y][x], fdf->map->points[y + 1][x]);
            x++;
        }
        y++;
    }
}
