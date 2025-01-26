#include "../fdf.h"

void error_exit(char *message)
{
    ft_putendl_fd(message, 2);
    exit(1);
}

int ft_word_count(char const *str, char c)
{
    int count;
    int i;

    count = 0;
    i = 0;
    while (str[i])
    {
        while (str[i] == c)
            i++;
        if (str[i] != c && str[i] != '\0')
            count++;
        while (str[i] != c && str[i] != '\0')
            i++;
    }
    return (count);
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

void free_map(t_map *map)
{
    int i;

    i = 0;
    while (i < map->height)
    {
        free(map->points[i]);
        i++;
    }
    free(map->points);
    free(map);
}

