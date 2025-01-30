NAME = fdf

CC = gcc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I./includes -I./libft -I./minilibx-linux -I./gnl
LIBS = -L./libft -lft -L./minilibx-linux -lmlx -lXext -lX11 -lm

SRCS = srcs/main.c \
		srcs/draw.c \
		srcs/parse_map.c \
		srcs/parse_map_utils.c \
		srcs/utils.c \
		gnl/get_next_line.c \
		gnl/get_next_line_utils.c

OBJS = $(SRCS:.c=.o)

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

MLX_DIR = ./minilibx-linux
MLX = $(MLX_DIR)/libmlx.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(MLX)	
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT):
	make -C $(LIBFT_DIR)

$(MLX):
	make -C $(MLX_DIR)

clean:
	rm -f $(OBJS)
	make -C $(LIBFT_DIR) clean
	make -C $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
