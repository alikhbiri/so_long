NAME = so_long
NAME_B = so_long_b

CC = cc
FLAGS = -Wall -Wextra -Werror -Imlx

# MiniLibX Path
MLX_DIR = minilibx-linux
MLX_FLAGS = -L$(MLX_DIR) -lmlx -L/usr/lib -lXext -lX11 -lm

SRC = outils/ft_split.c \
		parssing/parssing.c \
		outils/gnl.c \
		outils/gnl_utils.c \
		outils/ft_putstr_fd.c \
		map_manipulation/floodfill.c \
		map_manipulation/drawing.c \
		map_manipulation/putimage.c \
		outils/len.c \
		outils/ft_putnbr.c \
		move_player.c \
		map_manipulation/exit.c \
		so_long.c

SRC_B = outils/gnl.c \
			outils/gnl_utils.c \
			outils/ft_split.c \
			outils/ft_putnbr.c \
			outils/ft_itoa.c \
			outils/len.c \
			outils/ft_putstr_fd.c \
			map_manipulation/exit.c \
			player_monster/monster.c \
			parssing/animation.c \
			player_monster/monster_move.c \
			parssing/parssing_bonus.c \
			map_manipulation/floodfill_bonus.c \
			map_manipulation/drawing_bonus.c \
			map_manipulation/putimage_bonus.c \
			player_monster/move_player_bonus.c \
			so_long_bonus.c

OBJ = $(SRC:.c=.o)
OBJ_B = $(SRC_B:.c=.o)

INCLUDE = so_long.h

all: $(NAME)

bonus: $(NAME_B)

%.o: %.c $(INCLUDE)
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJ) $(INCLUDE)
	make -C $(MLX_DIR)  # Compile MiniLibX
	$(CC) $(OBJ) $(MLX_FLAGS) -o $(NAME)

$(NAME_B): $(OBJ_B) $(INCLUDE)
	make -C $(MLX_DIR)  # Compile MiniLibX
	$(CC) $(OBJ_B) $(MLX_FLAGS) -o $(NAME_B)

clean:
	rm -rf $(OBJ) $(OBJ_B)

fclean: clean
	rm -rf $(NAME) $(NAME_B)

re: fclean all

.PHONY: clean fclean re all bonus
