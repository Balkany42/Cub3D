#define _USE_MATH_DEFINES
#include <math.h>
#include "mlx/mlx.h"
#include <stdlib.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

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
    int     map_height; // La heuteur de la map en cases
    int     tile_size; // Taille d'un bloc

    double  player_x; // Position X du joueur en pixel
    double  player_y; // Position Y du joueur en pixel
    double  player_angle; // Angle du joueur (utilisé pour savoir dans quelle direction il regarde)

}   t_game;

void clear_image(t_game *g)
{
    int x, y;

    for (y = 0; y < 600; y++)
        for (x = 0; x < 800; x++)
            put_pixel(g, x, y, 0x00000000);
}
int render_frame(t_game *g)
{
    clear_image(g);

    for (int col = 0; col < 800; col++)
    {
        double ray_angle = g->player_angle + (col - 400) * FOV / 800;

        double distance = lancer_rayon(g, ray_angle);

        int wall_height = calculer_hauteur(distance);

        dessiner_colonne(g, col, wall_height);
    }

    mlx_put_image_to_window(g->mlx, g->win, g->img, 0, 0);
    return (0);
}

double lancer_rayon(t_game *g, double angle)
{
    // temporaire : renvoie une distance fixe
    return 200;
}
int calculer_hauteur(double distance)
{
    return 300; // temporaire
}
void dessiner_colonne(t_game *g, int col, int height)
{
    int start = 300 - height / 2;
    int end = 300 + height / 2;

    for (int y = start; y < end; y++)
        put_pixel(g, col, y, 0x00AAAAAA);
}


void    put_pixel(t_game *g, int x, int y, int color)
{
    char    *dst;

    dst = g->addr + (y * g->line_len + x * (g->bpp / 8));
    *(unsigned int *)dst = color;
}


int main(void)
{
    t_game g;

    // MAP CODÉE EN DUR
    g.map = (char *[]){
        "111111",
        "100001",
        "100001",
        "100001",
        "100001",
        "111111",
        NULL
    };

    g.tile_size = 64;
    g.map_width = 6;
    g.map_height = 6;

    g.player_x = 3 * g.tile_size;
    g.player_y = 3 * g.tile_size;
    g.player_angle = 0;

    // INIT MLX
    g.mlx = mlx_init();
    g.win = mlx_new_window(g.mlx, 800, 600, "Cub3D test");

    g.img = mlx_new_image(g.mlx, 800, 600);
    g.addr = mlx_get_data_addr(g.img, &g.bpp, &g.line_len, &g.endian);

    // BOUCLE
    mlx_loop_hook(g.mlx, render_frame, &g);
    mlx_loop(g.mlx);

    return (0);
}
void load_textures (t_game g)
{
    g.tex_no = mlx_xpm_file_to_image(g.mlx, "NO.xpm", &g.tex_w, &g.tex_h);
    g.addr_no = mlx_get_data_addr(g.tex_no, &g.tex_bpp, &g.tex_line_len, &g.tex_endian);
    g.tex_so = mlx_xpm_file_to_image(g.mlx, "SO.xpm", &g.tex_w, &g.tex_h);
    g.addr_so = mlx_get_data_addr(g.tex_so, &g.tex_bpp, &g.tex_line_len, &g.tex_endian);
    g.tex_we = mlx_xpm_file_to_image(g.mlx, "WE.xpm", &g.tex_w, &g.tex_h);
    g.addr_we = mlx_get_data_addr(g.tex_we, &g.tex_bpp, &g.tex_line_len, &g.tex_endian);
    g.tex_ea = mlx_xpm_file_to_image(g.mlx, "EA.xpm", &g.tex_w, &g.tex_h);
    g.addr_ea = mlx_get_data_addr(g.tex_ea, &g.tex_bpp, &g.tex_line_len, &g.tex_endian);
}