NAME = fdf

CC = gcc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I./includes -I./libft -I./minilibx-linux -I./gnl
LIBS = -L./libft -lft -L./minilibx-linux -lmlx -lXext -lX11 -lm

SRCS = srcs/main.c \
       srcs/draw.c \
       srcs/map.c \
       srcs/utils.c

OBJS = $(SRCS:.c=.o)

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

MLX_DIR = ./minilibx-linux
MLX = $(MLX_DIR)/libmlx.a

GNL_DIR = ./gnl
GNL_SRCS = $(GNL_DIR)/get_next_line.c $(GNL_DIR)/get_next_line_utils.c
GNL_OBJS = $(GNL_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(GNL_OBJS) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) $(OBJS) $(GNL_OBJS) $(LIBS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT):
	make -C $(LIBFT_DIR)

$(MLX):
	make -C $(MLX_DIR)

clean:
	rm -f $(OBJS) $(GNL_OBJS)
	make -C $(LIBFT_DIR) clean
	make -C $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
