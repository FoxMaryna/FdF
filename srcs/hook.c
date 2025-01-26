#include "../fdf.h"

int key_hook(int keycode, t_fdf *fdf)
{
    if (keycode == 53) // ESC
    {
        mlx_destroy_window(fdf->mlx, fdf->win);
        exit(0);
    }
    else if (keycode == 126) // Up arrow
        fdf->shift_y -= 10;
    else if (keycode == 125) // Down arrow
        fdf->shift_y += 10;
    else if (keycode == 123) // Left arrow
        fdf->shift_x -= 10;
    else if (keycode == 124) // Right arrow
        fdf->shift_x += 10;
    else if (keycode == 69) // +
        fdf->zoom += 2;
    else if (keycode == 78) // -
        fdf->zoom -= 2;
    else if (keycode == 34) // I key
        fdf->is_isometric = !fdf->is_isometric;
    
    mlx_clear_window(fdf->mlx, fdf->win);
    draw_map(fdf);
    return (0);
}
