/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrager <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 23:29:23 by mgrager           #+#    #+#             */
/*   Updated: 2026/08/30 23:38:40 by mgrager          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../minilibx-linux/mlx.h"
# include "libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include <sys/time.h>

# define WIN_WIDTH  1024
# define WIN_HEIGHT 768
# define TILE_SIZE  64
# define MOVE_SPEED 3.0
# define ROT_SPEED  2.2
# define FOV_FACTOR 0.66
# define SCROLL_ZOOM_STEP 0.1

# define ZOOM_SPEED 1.0
# define FOV_MIN    0.20
# define FOV_MAX    1.20

# define MINIMAP_TILE 8
# define MINIMAP_OFFSET 12
# define MINIMAP_WIDTH 15
# define MINIMAP_HEIGHT 8

# define CONTROL_WIDTH_PX 480
# define CONTROL_HEIGHT_PX 200
# define CONTROL_OFFSET_PX 15
# define CONTROL_LINE_HEIGHT 16
# define CONTROL_COL_GAP 240

# define TUTORIAL_OFFSET_PX 200
# define TUTORIAL_HEIGHT_OFFSET_PX 15
# define TUTORIAL_HEIGHT_PX 120
# define MESSAGE_LINE 8
# define MESSAGE_REVEAL_INTERVAL 0.0000000000000001
# define RANDOM_MESSAGE_INTERVAL 45
# define MESSAGE_AUTO_DISMISS_TIME 5

# define WALL_MARGIN 0.2

# define ANIMATION_TIME_GHOSTS 0.40
# define TIME_SCARED 7

# define MONUMENT_SIZE 3
# define MATRIX_SIZE 7
# define MONUMENT_AROUND 2
# define MATRIX_AROUND 3
# define GLYPH_SIZE 8
# define SCROLL_INTERVAL 0.05

# define CRAWL_VANISH_Y 160
# define CRAWL_FOCAL 200.0
# define CRAWL_Y_SCALE 5.0
# define CRAWL_X_SCALE 2.5
# define CRAWL_SCROLL_SPEED 140.0
# define CRAWL_DURATION 148.0
# define CRAWL_MIN_WIDTH_RATIO 0.35

# define MAX_PATH_LEN 1024
# define MAX_CUB_FILE_SIZE 50000000

# ifndef BONUS
#  define BONUS 0
# endif

# define RED	"\e[31m"
# define RESET	"\e[0m"

# define KEY_SPACE  32
# define KEY_A      97
# define KEY_D      100
# define KEY_S      115
# define KEY_W      119
# define KEY_ESC    65307
# define KEY_LEFT   65361
# define KEY_UP     65362
# define KEY_RIGHT  65363
# define KEY_DOWN   65364
# define MOUSE_SENSITIVITY 0.005
# define KEY_P 112
# define KEY_O 111
# define KEY_I 105
# define KEY_T 116
# define KEY_Y 121
# define KEY_M 109
# define KEY_Q 113
# define KEY_R 114

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		width;
	int		height;
}	t_img;

typedef struct s_imgbonus
{
	t_img	blue_braille[7];
	t_img	red_braille[7];
	t_img	blue_fr[7];
	t_img	red_fr[7];
	t_img	blue_eng[7];
	t_img	red_eng[7];
	t_img	blue_ru[7];
	t_img	red_ru[7];
	t_img	creator[3];
	t_img	rand_latin[52];
	t_img	rand_braille[51];
	t_img	rand_ru[77];
	t_img	rand_sign[24];
	t_img	rand_digit[10];
	t_img	ghost_noframe_blue[2];
	t_img	ghost_noframe_eyes[4];
	t_img	ghost_noframe_orange[8];
	t_img	ghost_noframe_pink[8];
	t_img	ghost_noframe_red[8];
	t_img	ghost_noframe_cyan[8];
	t_img	ghost_noframe_white[2];
	t_img	ghost_frame_blue[2];
	t_img	ghost_frame_eyes[4];
	t_img	ghost_frame_orange[8];
	t_img	ghost_frame_pink[8];
	t_img	ghost_frame_red[8];
	t_img	ghost_frame_cyan[8];
	t_img	ghost_frame_white[2];
	t_img	basics[3];
}	t_imgbonus;

typedef struct s_keys
{
	int	w;
	int	a;
	int	s;
	int	d;
	int	space;
	int	up;
	int	down;
	int	left;
	int	right;
	int	esc;
	int	p;
	int	o;
	int	i;
	int	t;
	int	y;
	int	m;
	int	q;
	int	r;
}	t_keys;

typedef struct s_player
{
	double	x;
	double	y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
}	t_player;

typedef struct s_map
{
	char	**grid;
	int		width;
	int		height;
	char	*no_path;
	char	*so_path;
	char	*we_path;
	char	*ea_path;
	int		f_set;
	int		c_set;
	int		f[3];
	int		c[3];
	int		floor_color;
	int		ceil_color;
}	t_map;

typedef struct s_ray
{
	double	ray_dir_x;
	double	ray_dir_y;
	int		map_x;
	int		map_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	int		step_x;
	int		step_y;
	int		side;
	double	perp_wall_dist;
	char	character_hit;
}	t_ray;

typedef struct s_col_draw
{
	int		line_h;
	int		draw_start;
	int		draw_end;
	int		tex_x;
	t_img	*tex;
	double	step;
	double	tex_pos;
}	t_col_draw;

typedef struct s_matrix_pos
{
	int	face;
	int	cell;
	int	subcol;
}	t_matrix_pos;

typedef struct s_glyph_pos
{
	int	x;
	int	row;
	int	offset_x;
	int	offset_y;
}	t_glyph_pos;

typedef struct s_zone
{
	int	size;
	int	around;
}	t_zone;

typedef struct s_flood_grid
{
	char	**grid;
	int		height;
	int		width;
}	t_flood_grid;

typedef struct s_matrix_col
{
	t_img	*current_glyph;
	int		progress;
	double	next_tick;
	int		glyphs_done;
	int		is_message_glyph;
	double	delta_start;
}	t_matrix_col;

typedef enum e_matrix_state
{
	MATRIX_OFF,
	MATRIX_WORKING,
	MATRIX_BLUE_PILL,
	MATRIX_RED_PILL
}	t_matrix_state;

typedef struct s_line_box
{
	int	top;
	int	bottom;
	int	left;
	int	right;
}	t_line_box;

typedef struct s_msg_layout
{
	int			line_count;
	t_line_box	line[MESSAGE_LINE];
}	t_msg_layout;

typedef enum e_msg_state
{
	MSG_INACTIVE,
	MSG_REVEALING,
	MSG_HOLDING
}	t_msg_state;

typedef struct s_message
{
	t_msg_state		msg_state;
	t_img			*current_message;
	t_msg_layout	msg_layout;
	int				msg_current_line;
	int				msg_revealed_x;
	double			msg_hold_start;
	int				tutorial_index;
	int				tutorial_done;
	t_img			tutorial_messages[6];
	double			last_random_msg_time;
	t_img			random_messages[8];
	double			msg_next_tick;
	int				dismiss_key;
}	t_message;

typedef struct s_game
{
	void			*mlx;
	void			*win;
	char			**lines;
	t_img			screen;
	t_img			tex[4];
	t_imgbonus		img_bonus;
	t_map			map;
	t_player		player;
	t_keys			keys;
	int				light;
	double			last_time;
	double			last_time_ghosts;
	int				animation_ghosts;
	int				ghost_state;
	double			time_scared;
	int				monument_count;
	int				matrix_count;
	t_img			matrix_tex[4][MATRIX_SIZE];
	unsigned int	rand_seed;
	t_matrix_col	matrix_col[4][MATRIX_SIZE][8];
	t_matrix_state	matrix_state;
	int				control;
	t_message		message;
	int				light_used;
	t_img			crawl_tex;
	int				crawl_active;
	double			crawl_start;
	int				mouse_ref;
}	t_game;

enum e_tex
{
	TEX_NO = 0,
	TEX_SO = 1,
	TEX_WE = 2,
	TEX_EA = 3
};

enum e_phantom_state
{
	ABSENT = 0,
	HIDDEN = 1,
	PRESENT = 2,
	SCARED = 3,
};

t_ray	setup_ray(t_game *game, int x);
void	cast_column(t_game *game, int x);
void	draw_column(t_game *game, t_ray *r, int x);
t_img	*pick_texture(t_game *game, t_ray *r);
t_img	*pick_texture_wall(t_game *game, t_ray *r);
t_img	*pick_texture_present(t_game *game, t_ray *r);
t_img	*pick_texture_monument_light(t_game *game, t_ray *r);
int		get_monument_local_x(t_game *game, t_ray *r);
int		get_monument_local_y(t_game *game, t_ray *r);
void	render_frame(t_game *game);
int		render_loop(t_game *game);

void	put_pixel(t_img *img, int x, int y, int color);
int		get_tex_pixel(t_img *tex, int x, int y);
void	render_floor_ceiling(t_game *game);

void	inject_new_row(t_img *img, t_img *glyph, t_glyph_pos *gp);
void	shift_column_up(t_img *img, int x);
void	update_animation_matrix(t_game *game, double now);
t_img	*pick_glyph(t_game *game, int family, t_matrix_pos *pos, double now);
t_img	*pick_texture_matrix_light(t_game *game, t_ray *r);
int		get_matrix_local_x(t_game *game, t_ray *r);
int		get_matrix_local_y(t_game *game, t_ray *r);
int		matrix_face_family(int face);
void	start_message(t_game *game, double now);
t_img	*pick_texture_matrix(t_game *game, t_ray *r);

int		cell_colour(char c);
void	render_cell(t_game *game, int colour, int y, int x);
void	render_grid_cell(t_game *game, int colour, int y, int x);
void	render_cursor(t_game *game, int center_x, int center_y);
void	render_minimap_frame(t_game *game);
void	draw_minimap(t_game *game);

void	render_control_panel(t_game *game);
void	render_control_text(t_game *game);

void	start_message_display(t_game *game, t_img *img, int dismiss_key);
void	start_tutorial(t_game *game);
void	try_advance_message(t_game *game, int keycode);
void	handle_skip_key(t_game *game);
void	check_random_message_timer(t_game *game);
void	check_message_auto_dismiss(t_game *game);
void	update_message_reveal(t_game *game);
void	detect_message_lines(t_img *img, t_msg_layout *layout);
int		row_has_text(t_img *img, int y);
void	find_line_x_bounds(t_img *img, t_line_box *box);
void	render_tutorial_text(t_game *game);
void	render_tutorial_frame(t_game *game);

void	render_crawl(t_game *game);
void	start_crawl(t_game *game);
void	update_crawl(t_game *game);

void	load_textures_bonus(t_game *game);
void	load_ghosts_noframes(t_game *game);
void	load_ghosts_frames(t_game *game);
void	load_randoms(t_game *game);
void	new_img(t_game *game, t_img *img, int width, int height);
int		init_game(t_game *game);
double	now_seconds(void);
void	load_one(t_game *game, t_img *tex, char *path);
void	load_numbered_family(t_game *game, t_img *dst, char *dir, int count);
void	init_matrix_textures(t_game *game);
void	init_state_texture(t_game *game);
void	load_textures(t_game *game);
void	load_crawl(t_game *game);
void	load_basics(t_game *game);

int		key_press(int keycode, t_game *game);
int		key_release(int keycode, t_game *game);
int		is_wall(t_map *map, double x, double y);
void	rotate_player(t_game *game, double angle);
void	move_player(t_game *game, double dt);
void	update_phantom_state(t_game *game, int i);
void	toggle_door(t_game *game);
void	update_matrix_pill_state(t_game *game, t_matrix_state target);
void	zoom_player(t_game *game, double factor);
int		mouse_hook(int x, int y, t_game *game);
int		scroll_hook(int button, int x, int y, t_game *game);

char	**read_file(char *path);
int		check_top_corner(t_game *game, int y, int x, char c);
int		check_matrix(t_game *game, int size, int around);
int		check_monuments(t_game *game, int size, int around);
int		iwn(t_game *game, int y, int x);
int		check_doors(t_game *game);
int		parse_error(t_game *game, char *msg);
void	free_all(t_game *game);
void	delete_randoms(t_game *game);
void	delete_messages(t_game *game);
void	free_img_bonus(t_game *game);
void	delete_image_group(t_img *img, int n, void *mlx);
void	delete_ghosts_noframe(t_game *game);
void	delete_ghosts_frame(t_game *game);
int		parse(char **lines, t_game *game);
int		has_valid_extension(char *filename);
int		check_file(char *filename);
int		is_blank(char *line);
int		is_map_line(char *line);
int		match_token(char *line, char *token);
int		parse_config_line(t_game *game, char *line);
int		parse_config(t_game *game, char **lines, int *i);
int		try_color_token(t_game *game, char *line, int *handled);
int		config_is_complete(t_map *map);
char	*get_value(char *line, char *token);
int		try_texture_token(t_game *game, char *line, int *handled);
int		parse_component(char *str, int *out);
int		parse_map(t_game *game, char **lines, int start);
int		check_player(t_game *game);
int		check_map(t_game *game);
int		is_safe_file(char *path);
char	*skip_ws(char *line);

#endif
