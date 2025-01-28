#include "../fdf.h"

static int get_height(char *filename)
{
    int fd;
    int height;
    char *line;

    fd = open(filename, O_RDONLY);
    if (fd < 0)
        error_exit("Error opening file for height calculation");

    height = 0;
    while ((line = get_next_line(fd)) != NULL)
    {
        height++;
        free(line);
    }
    close(fd);
    return (height);
}

static int get_width(char *filename)
{
    int fd;
    char *line;
    int width;

    fd = open(filename, O_RDONLY);
    if (fd < 0)
        error_exit("Error opening file for width calculation");

    line = get_next_line(fd);
    if (line)
    {
        width = ft_word_count(line, ' ');
        free(line);
    }
    else
        width = 0;

    close(fd);
    return (width);
}

static void fill_points(t_map *map, char *line, int y)
{
    char **split;
    int x;

    split = ft_split(line, ' ');
    if (!split)
        error_exit("Error splitting line");

    x = 0;
    while (split[x] && x < map->width)
    {
        map->points[y][x].x = x;
        map->points[y][x].y = y;
        map->points[y][x].z = ft_atoi(split[x]);
        if (map->points[y][x].z > map->z_max)
            map->z_max = map->points[y][x].z;
        if (map->points[y][x].z < map->z_min)
            map->z_min = map->points[y][x].z;
        x++;
    }

    ft_free_split(split);
}

t_map *parse_map(char *filename)
{
    t_map *map;
    int fd;
    char *line;
    int y;

    map = (t_map *)ft_calloc(1, sizeof(t_map));
    if (!map)
        error_exit("Memory allocation failed for map");

    map->height = get_height(filename);
    map->width = get_width(filename);
    map->z_min = INT_MAX;
    map->z_max = INT_MIN;

    map->points = (t_point **)ft_calloc(map->height, sizeof(t_point *));
    if (!map->points)
        error_exit("Memory allocation failed for map->points");

    for (int i = 0; i < map->height; i++)
    {
        map->points[i] = (t_point *)ft_calloc(map->width, sizeof(t_point));
        if (!map->points[i])
            error_exit("Memory allocation failed for map->points[i]");
    }

    fd = open(filename, O_RDONLY);
    if (fd < 0)
        error_exit("Error opening file for map parsing");

    y = 0;
    while ((line = get_next_line(fd)) != NULL && y < map->height)
    {
        fill_points(map, line, y);
        free(line);
        y++;
    }

    close(fd);
    return (map);
}
