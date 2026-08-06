NAME := cub3d
CC := cc
CFLAGS := -Wall -Werror -Wextra -g3

SRC := \
src/003_init/init_textures.c \
src/003_init/test.c \
src/004_raycasting/raycasting.c \
src/004_raycasting/render.c \
src/005_movement/movement.c \
src/utils/utils1.c

OBJ := $(SRC:.c=.o)

# === MLX ===
MLX_DIR := mlx
MLX := $(MLX_DIR)/libmlx_Linux.a

# === INCLUDES ===
INCLUDES := -Iinclude -I$(MLX_DIR)

# === LIBS ===
LIBS := $(MLX) -lXext -lX11 -lm -lz

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJ) $(LIBS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
