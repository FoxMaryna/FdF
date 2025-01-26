NAME = fdf

CC = gcc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I. -I./minilibx-linux -I./gnl

LIBS = -L./minilibx-linux -lmlx -lm -lX11 -lXext

SRCS = srcs/main.c \
		srcs/map.c \
		srcs/draw.c \
		srcs/hook.c \
		srcs/utils.c \
		srcs/utils2.c \
		srcs/additional_features.c \
		srcs/ft_split.c \
		gnl/get_next_line.c \
		gnl/get_next_line_utils.c

OBJS = $(SRCS:.c=.o)

HEADER = fdf.h

all: $(NAME)

$(NAME): $(OBJS)
	@make -C minilibx-linux
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) $(LIBS) -o $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)
	$(MAKE) -C minilibx-linux clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C minilibx-linux fclean

re: fclean all

.PHONY: all clean fclean re
