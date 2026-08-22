NAME := cub3d
CC := cc
BONUS = 0
CFLAGS := -Wall -Wextra -Werror -g3 -DBONUS=$(BONUS)

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
BONUS_FLAG := .bonus_flag

# === INCLUDES ===
INCLUDES := -Iinclude -I$(MLX_PATH) -I$(LIBFT_PATH)

# === LIBS ===
LIBS := $(MLX) $(LIBFT) -lXext -lX11 -lm -lz

# === RULES ===
all: $(MLX) $(LIBFT) check_bonus $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

check_bonus:
	@if [ ! -f $(BONUS_FLAG) ] || [ "$$(cat $(BONUS_FLAG))" != "$(BONUS)" ]; then \
		rm -f $(OBJ); \
		echo $(BONUS) > $(BONUS_FLAG); \
	fi

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
	rm -f $(OBJ) $(BONUS_FLAG)
	make -C $(LIBFT_PATH) clean
	make -C $(MLX_PATH) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_PATH) fclean

re: fclean all

.PHONY: all clean fclean re bonus check_bonus
