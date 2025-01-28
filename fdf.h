#ifndef FDF_H
# define FDF_H

# include "minilibx-linux/mlx.h"
# include "libft.h"
# include "gnl/get_next_line.h"
# include <math.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define WIDTH 1200
# define HEIGHT 800

# define ARROW_LEFT 65361
# define ARROW_RIGHT 65363
# define ARROW_DOWN 65364
# define ARROW_UP 65362
# define MINUS 45
# define PLUS 61
# define ESCAPE 65307

typedef struct s_point
{
    float x;
    float y;
    float z;
    int color;
} t_point;

typedef struct s_map
{
    t_point **points;
    int width;
    int height;
    int z_max;
    int z_min;
} t_map;

typedef struct s_camera
{
    float zoom;
    float x_angle;
    float y_angle;
    float z_angle;
    int x_offset;
    int y_offset;
} t_camera;

typedef struct s_fdf
{
    void *mlx;
    void *win;
    void *img;
    char *data_addr;
    int bits_per_pixel;
    int size_line;
    int endian;
    t_map *map;
    t_camera *camera;
} t_fdf;

t_map *parse_map(char *filename);
void draw_map(t_fdf *fdf);
void draw_line(t_fdf *fdf, t_point start, t_point end);
int key_hook(int keycode, t_fdf *fdf);
void error_exit(char *message);
int get_color(int z, t_map *map);
void init_camera(t_fdf *fdf);
void apply_camera(t_fdf *fdf, t_point *p);
int ft_word_count(const char *str, char c);
void ft_free_split(char **split);

#endif
