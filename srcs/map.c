#include "../fdf.h"

static int get_height(char *filename)
{
    int fd;
    int height;
    char *line;

    fd = open(filename, O_RDONLY);
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

t_map *parse_map(char *filename)
{
    t_map *map;
    int fd;
    char *line;
    int i;
    int j;

    map = (t_map *)malloc(sizeof(t_map));
    map->height = get_height(filename);
    map->width = get_width(filename);
    map->points = (t_point **)malloc(sizeof(t_point *) * (map->height + 1));
    fd = open(filename, O_RDONLY);
    i = 0;
    while ((line = get_next_line(fd)) != NULL)
    {
        map->points[i] = (t_point *)malloc(sizeof(t_point) * (map->width + 1));
        char **split = ft_split(line, ' ');
        j = 0;
        while (split[j])
        {
            map->points[i][j].x = j;
            map->points[i][j].y = i;
            map->points[i][j].z = ft_atoi(split[j]);
            map->points[i][j].color = 0xFFFFFF; // Default color
            j++;
        }
        ft_free_split(split);
        free(line);
        i++;
    }
    map->points[i] = NULL;
    close(fd);
    return (map);
}
