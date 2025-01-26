#ifndef FDF_H
# define FDF_H

# include "../minilibx-linux/mlx.h"
# include <math.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "../gnl/get_next_line.h"

# define WIDTH 1200
# define HEIGHT 800

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

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
} t_map;

typedef struct s_fdf
{
    void *mlx;
    void *win;
    t_map *map;
    float zoom;
    float angle;
    int shift_x;
    int shift_y;
    int is_isometric;
} t_fdf;

// Функции для работы с картой
t_map *parse_map(char *filename);
void free_map(t_map *map);

// Функции для рисования
void draw_map(t_fdf *fdf);
void draw_line(t_fdf *fdf, t_point start, t_point end);

// Функции для обработки событий
int key_hook(int keycode, t_fdf *fdf);

// Вспомогательные функции
void error_exit(char *message);
int ft_word_count(char const *str, char c);
void ft_free_split(char **split);
void rotate_map(t_fdf *fdf, float angle);
void change_color(t_fdf *fdf);

// Строковые функции
size_t ft_strlen(const char *s);
char *ft_strdup(const char *s1);
char *ft_strchr(const char *s, int c);
char *ft_substr(char const *s, unsigned int start, size_t len);
char *ft_strjoin(char *s1, char const *s);
char *ft_strncpy(char *dest, const char *src, size_t n);

// Функции для работы со строками и числами
char **ft_split(char *str, char c);
int ft_atoi(const char *str);

#endif
