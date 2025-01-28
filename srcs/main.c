#include "../fdf.h"

int main(int argc, char **argv)
{
    t_fdf *fdf;

    if (argc != 2)
        error_exit("Usage: ./fdf <filename.fdf>");

    fdf = (t_fdf *)ft_calloc(1, sizeof(t_fdf));
    if (!fdf)
        error_exit("Memory allocation failed");

    fdf->mlx = mlx_init();
    if (!fdf->mlx)
        error_exit("MLX initialization failed");

    fdf->win = mlx_new_window(fdf->mlx, WIDTH, HEIGHT, "FdF");
    if (!fdf->win)
        error_exit("Window creation failed");

    fdf->map = parse_map(argv[1]);
    fdf->img = mlx_new_image(fdf->mlx, WIDTH, HEIGHT);
    if (!fdf->img)
        error_exit("Image creation failed");
    fdf->data_addr = mlx_get_data_addr(fdf->img, &fdf->bits_per_pixel, &fdf->size_line, &fdf->endian);

    draw_map(fdf);
    mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img, 0, 0);

    mlx_key_hook(fdf->win, key_hook, fdf);
    mlx_hook(fdf->win, 17, 0, close_window, fdf);

    mlx_loop(fdf->mlx);

    return (0);
}