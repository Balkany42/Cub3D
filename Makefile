NAME := cub3D
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
src/init/bonus.c \
src/init/ghosts.c \
src/init/load.c \
src/init/matrix.c \
src/init/textures.c \
src/movement/key_press.c \
src/movement/key_release.c \
src/movement/movement.c \
src/movement/update.c \
src/parsing/check_closed.c \
src/parsing/check_matrix.c \
src/parsing/check_monument.c \
src/parsing/check_player.c \
src/parsing/door.c \
src/parsing/free_bonus.c \
src/parsing/free_ghosts.c \
src/parsing/free.c \
src/parsing/parsing_args.c \
src/parsing/parsing_config_color.c \
src/parsing/parsing_config_utils.c \
src/parsing/parsing_config.c \
src/parsing/parsing_map.c \
src/parsing/parsing.c \
src/parsing/read_file.c \
src/render/controls.c \
src/render/draw.c \
src/render/matrix_blit.c \
src/render/matrix_dispatch.c \
src/render/matrix_glyph_pick.c \
src/render/matrix_tick.c \
src/render/matrix_wall.c \
src/render/minimap_draw.c \
src/render/minimap_frame.c \
src/render/raycast_dda.c \
src/render/raycast_dispatch.c \
src/render/raycast_draw.c \
src/render/raycast_ghost_textures.c \
src/render/raycast_loop.c \
src/render/raycast_monument.c \
src/render/raycast_present_texture.c \
src/render/raycast_ray_setup.c \
src/render/star_wars.c \
src/render/crawl_state.c \
src/render/tutorial_flow.c \
src/render/tutorial_render.c \
src/render/tutorial_timers.c \
src/utils/utils.c

OBJ := $(SRC:.c=.o)
BONUS_FLAG := .bonus_flag

# === INCLUDES ===
INCLUDES := -Iinclude -I$(MLX_PATH) -I$(LIBFT_PATH)
HEADERS := include/cub3d.h

# === LIBS ===
LIBS := $(MLX) $(LIBFT) -lXext -lX11 -lm -lz

# === RULES ===
all: $(MLX) $(LIBFT) check_bonus $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBS) -o $(NAME)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

check_bonus:
	@if [ ! -f $(BONUS_FLAG) ] || [ "$$(cat $(BONUS_FLAG))" != "$(BONUS)" ]; then \
		rm -f $(OBJ); \
		echo $(BONUS) > $(BONUS_FLAG); \
	fi

# === LIBFT BUILD ===
$(LIBFT):
	make -C $(LIBFT_PATH)

# === MLX BUILD ===
$(MLX):
	@if [ -f "$(MLX_PATH)configure" ]; then chmod +x $(MLX_PATH)configure; fi
	make -C $(MLX_PATH)

bonus:
	make BONUS=1

clean:
	rm -f $(OBJ) $(BONUS_FLAG)
	@if [ -f "$(MLX_PATH)configure" ]; then chmod +x $(MLX_PATH)configure; fi
	make -C $(LIBFT_PATH) clean
	make -C $(MLX_PATH) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_PATH) fclean

re: fclean all

.PHONY: all clean fclean re bonus check_bonus
