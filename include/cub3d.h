#ifndef CUB3D_H
# define CUB3D_H

# include <stddef.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include "../mlx/mlx.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#ifndef M_PI // Peut être redondant à vérifier
#define M_PI 3.14159265358979323846
#endif // Peut être redondant à vérifier

#define FOV (60 * (M_PI / 180))

typedef struct s_game
{
    void    *mlx; // Contien la minilibx
    void    *win; // La fenêtre mlx
    void    *img; //Load l'image dans laquelle on dessine
    char    *addr; // Adresse de début de l'image
    int     bpp; // Bits par pixel
    int     line_len; // Nombre d'octet par ligne dans l'image
    int     endian; // A priori on va pas l'utiliser

    int     win_width; // La largeur en pixels de la fenètre
    int     win_height; // La hauteur en piwels de la fenètre

    void *tex_no; // Texture NO
    void *tex_so; // Texture SO
    void *tex_we; // Texture WE
    void *tex_ea; // Texture EA

    char *addr_no; // Adresse du buffer NO
    char *addr_so; // Adresse du buffer SO
    char *addr_we; // Adresse du buffer WE
    char *addr_ea; // Adresse du buffer ea

    int tex_w; // Largeur des textures
    int tex_h; // Hauteur des textures
    int tex_bpp; // Bits par pixel des textures
    int tex_line_len; // Octet par ligne dans les textures
    int tex_endian; // Pas utilisé ici non plus

    char    **map; // La map en tableau de chaînes
    int     map_width; // La largeur de la map en cases
    int     map_height; // La hauteur de la map en cases
    int     tile_size; // Taille d'un bloc

    double  player_x; // Position X du joueur en pixel
    double  player_y; // Position Y du joueur en pixel
    double  player_angle; // Angle du joueur (utilisé pour savoir dans quelle direction il regarde)

    double fov; // Pour le zoom et le dézoom
}   t_game;

typedef struct s_hit
{
    double distance;
    double hit_x;
    double hit_y;
    int face; // 0=NO, 1=SO, 2=WE, 3=EA
} t_hit;

void load_textures (t_game *g);
int compute_height(t_game *g, double distance);
void clear_image(t_game *g);
int render_frame(t_game *g);
void draw_column(t_game *g, int col, int height, t_hit hit);
void    put_pixel(t_game *g, int x, int y, int color);
int key_press(int keycode, t_game *g);
int close_window(t_game *g);
t_hit launch_ray_dda(t_game *g, double angle);
void init_player(t_game *g);

#endif