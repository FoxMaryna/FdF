#include "../fdf.h"

int main(int, char **argv)
{
    t_fdf *fdf;

    fdf = (t_fdf *)malloc(sizeof(t_fdf));
    if (!fdf)
        return (1);

    fdf->mlx = mlx_init();
    fdf->win = mlx_new_window(fdf->mlx, WIDTH, HEIGHT, "FDF");
    fdf->map = parse_map(argv[1]);
    fdf->zoom = 20;
    fdf->angle = 0.8;
    fdf->shift_x = WIDTH / 2;
    fdf->shift_y = HEIGHT / 3;
    fdf->is_isometric = 1;

    draw_map(fdf);

    mlx_key_hook(fdf->win, key_hook, fdf);
    mlx_loop(fdf->mlx);

    return (0);
}
