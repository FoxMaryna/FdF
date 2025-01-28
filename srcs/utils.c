#include "../fdf.h"

void error_exit(char *message)
{
    ft_putendl_fd(message, 2);
    exit(1);
}

int key_hook(int keycode, t_fdf *fdf)
{
    if (keycode == ESCAPE)
    {
        mlx_destroy_window(fdf->mlx, fdf->win);
        exit(0);
    }
    // Добавьте здесь обработку других клавиш для управления камерой
    return (0);
}

void ft_free_split(char **split)
{
    int i;

    i = 0;
    while (split[i])
    {
        free(split[i]);
        i++;
    }
    free(split);
}

int ft_word_count(const char *str, char c)
{
    int count = 0;
    int in_word = 0;

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
    return count;
}
