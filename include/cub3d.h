#ifndef CUB3D_H
# define CUB3D_H

# include "../minilibx-linux/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include <sys/time.h>

# define WIN_WIDTH  1024
# define WIN_HEIGHT 768
# define TILE_SIZE  64      /* taille d'une case de map, en "unités monde" */
# define MOVE_SPEED 3.0     /* cases par seconde */
# define ROT_SPEED  2.2     /* radians par seconde */
# define FOV_FACTOR 0.66    /* longueur du plan caméra -> ~66° de FOV */

# define MM_TILE 8    /* taille d'une case sur la minimap, en pixels */
# define MM_PAD  12   /* marge depuis le bord de l'écran */
# define WALL_MARGIN 0.2

# define RED	"\e[31m"
# define GREEN	"\e[32m"

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

typedef struct s_img
{
	void	*img;        // Le mlx l'utilise pour savoir quelle image manipuler
	char	*addr;       // Adresse du premier pixel dans la mémoire de l'image
	int		bpp;         /* bits per pixel */
	int		line_len;    /* octets par ligne */
	int		endian;      // On ne l'utilise pas dans Cub3d, mais la mlx le donne
	int		width;       // Largeur de l'image en pixels
	int		height;      // Hauteur de l'image en pixels
}	t_img;

typedef struct s_player
{
	double	x;
	double	y;
	double	dir_x;      /* vecteur direction (où regarde le joueur) */
	double	dir_y;
	double	plane_x;    /* vecteur "plan caméra", perpendiculaire à dir */
	double	plane_y;    /* sa longueur fixe le champ de vision (FOV)   */
}	t_player;

typedef struct s_map
{
	char	**grid;
	int		width;      /* largeur max (en cases) */
	int		height;     /* nombre de lignes */
	char	*no_path;
	char	*so_path;
	char	*we_path;
	char	*ea_path;
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
}	t_ray;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_img		screen;     /* buffer dans lequel on dessine chaque frame */
	t_img		tex[4];     /* index : 0=NO 1=SO 2=WE 3=EA (cf. enum ci-dessous) */
	t_map		map;
	t_player	player;

	int			keys[65536]; /* état courant des touches (pressed = 1) */

	double		last_time;   /* pour calculer le delta-time du mouvement */
}	t_game;

enum e_tex
{
	TEX_NO = 0,
	TEX_SO = 1,
	TEX_WE = 2,
	TEX_EA = 3
};

int	render_loop(t_game *game);
int	key_press(int keycode, t_game *game);
int	key_release(int keycode, t_game *game);

#endif