NAME = so_long
NAME_B = so_long_b

CC = cc -fsanitize=address
FLAGS = -Wall -Wextra -Werror -I$(MLX_DIR) 

# MiniLibX Paths
MLX_DIR = minilibx-linux
MLX_LIB = $(MLX_DIR)/libmlx.a
MLX_INC = -I$(MLX_DIR)
MLX_FLAGS = -L$(MLX_DIR) -lmlx -L/usr/lib -lXext -lX11 -lm

SRC = ft_split.c \
		parssing.c \
		gnl.c \
		gnl_utils.c \
		ft_putstr_fd.c \
		floodfill.c \
		drawing.c \
		putimage.c \
		len.c \
		ft_putnbr.c \
		move_player.c \
		exit.c \
		so_long.c 

SRC_B = gnl.c \
			gnl_utils.c \
			ft_split.c \
			ft_putnbr.c \
			ft_itoa.c \
			len.c \
			ft_putstr_fd.c \
			exit.c \
			monster.c \
			animation.c \
			monster_move.c \
			parssing_bonus.c \
			floodfill_bonus.c \
			drawing_bonus.c \
			putimage_bonus.c \
			move_player_bonus.c \
			so_long_bonus.c

OBJ = $(SRC:.c=.o)
OBJ_B = $(SRC_B:.c=.o)

INCLUDE = so_long.h

all: $(NAME)

bonus: $(NAME_B)

%.o: %.c $(INCLUDE)
	$(CC) $(FLAGS) $(MLX_INC) -c $< -o $@

$(MLX_LIB):
	make -C $(MLX_DIR)

$(NAME): $(MLX_LIB) $(OBJ)
	$(CC) $(OBJ) $(MLX_FLAGS) -o $(NAME)

$(NAME_B): $(MLX_LIB) $(OBJ_B)
	$(CC) $(OBJ_B) $(MLX_FLAGS) -o $(NAME_B)

clean:
	rm -rf $(OBJ) $(OBJ_B)

fclean: clean
	rm -rf $(NAME) $(NAME_B)

re: fclean all

.PHONY: clean fclean re all bonus