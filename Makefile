NAME := cub3d
CC := cc
CFLAGS := -Wall -Wextra -Werror -g3 -DBONUS=$(BONUS)

BONUS = 0

# === MLX ===
MLX_PATH = minilibx-linux/
MLX = $(MLX_PATH)libmlx.a

# === LIBFT ===
LIBFT_PATH = libft/
LIBFT = $(LIBFT_PATH)libft.a

# === SOURCES ===
SRC := \
src/main.c \
src/init/init.c \
src/movement/keyboard.c \
src/movement/movement.c \
src/parsing/parsing_args.c \
src/parsing/parsing_config_color.c \
src/parsing/parsing_config_utils.c \
src/parsing/parsing_config.c \
src/parsing/parsing_errors.c \
src/parsing/parsing_map_check.c \
src/parsing/parsing_map.c \
src/parsing/parsing.c \
src/parsing/read_file.c \
src/raycasting/draw.c \
src/raycasting/minimap.c \
src/raycasting/raycast.c

OBJ := $(SRC:.c=.o)

# === INCLUDES ===
INCLUDES := -Iinclude -I$(MLX_PATH) -I$(LIBFT_PATH)

# === LIBS ===
LIBS := $(MLX) $(LIBFT) -lXext -lX11 -lm -lz

# === RULES ===
all: $(MLX) $(LIBFT) $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# === LIBFT BUILD ===
$(LIBFT):
	@if [ -f "$(LIBFT_PATH)configure" ]; then chmod +x $(LIBFT_PATH)configure; fi
	make -C $(LIBFT_PATH)

# === MLX BUILD ===
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
