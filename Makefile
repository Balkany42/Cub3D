NAME := cub3d
CC := cc
CFLAGS := -Wall -Werror -Wextra -g3

BONUS = 0

# MLX
MLX_PATH = minilibx-linux/
MLX = $(MLX_PATH)libmlx.a

# Libft
LIBFT_PATH = libft/
LIBFT = $(LIBFT_PATH)libft.a

# Sources (à compléter !)
SRC := \
src/main.c \
src/003_init/init_textures.c \
src/004_raycasting/raycasting.c \
src/004_raycasting/render.c \
src/005_movement/movement.c \
src/utils/utils1.c

OBJ := $(SRC:.c=.o)

# Includes
INCLUDES := -Iinclude -I$(MLX_PATH) -I$(LIBFT_PATH)

# Libs
LIBS := $(MLX) $(LIBFT) -lXext -lX11 -lm -lz

all: $(MLX) $(LIBFT) $(NAME)

$(NAME): $(OBJ)
    $(CC) $(CFLAGS) -DBONUS=$(BONUS) $(OBJ) $(LIBS) -o $(NAME)

%.o: %.c
    $(CC) $(CFLAGS) -DBONUS=$(BONUS) -c $< -o $@ $(INCLUDES)

# Build libft
$(LIBFT):
    make -C $(LIBFT_PATH)

# Build mlx
$(MLX):
    make -C $(MLX_PATH)

bonus:
    make BONUS=1

clean:
    rm -f $(OBJ)
    make -C $(LIBFT_PATH) clean
    make -C $(MLX_PATH) clean

fclean: clean
    rm -f $(NAME)
    make -C $(LIBFT_PATH) fclean

re: fclean all

.PHONY: all clean fclean re bonus
