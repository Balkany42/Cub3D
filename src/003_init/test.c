#include "../../include/cub3d.h"

int calculer_hauteur(t_game *g, double distance)
{
    double projection_plane = 800 / tan(FOV / 2);
    int height = (int)((g->tile_size / distance) * projection_plane);

    if (height > 600)
        height = 600;

    return height;
}



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
        // Angle du rayon pour cette colonne
        double ray_angle = g->player_angle + (col - 400) * FOV / 800;

        // Lancer le rayon → distance + face + hit_x + hit_y
        t_hit hit = lancer_rayon(g, ray_angle);

        // Calculer la hauteur du mur
        int wall_height = calculer_hauteur(g, hit.distance);

        // Dessiner la colonne texturée
        dessiner_colonne(g, col, wall_height, hit);
    }

    // Afficher l'image dans la fenêtre
    mlx_put_image_to_window(g->mlx, g->win, g->img, 0, 0);

    return (0);
}

t_hit lancer_rayon(t_game *g, double angle)
{
    t_hit h;

    double ray_x = g->player_x;
    double ray_y = g->player_y;

    double dx = cos(angle);
    double dy = sin(angle);

    while (1)
    {
        ray_x += dx;
        ray_y += dy;

        int mx = (int)(ray_x / g->tile_size);
        int my = (int)(ray_y / g->tile_size);

        if (g->map[my][mx] == '1')
        {
            h.distance = sqrt(
                (ray_x - g->player_x) * (ray_x - g->player_x) +
                (ray_y - g->player_y) * (ray_y - g->player_y)
            );

            h.hit_x = ray_x;
            h.hit_y = ray_y;

            double local_x = fmod(ray_x, g->tile_size);
            double local_y = fmod(ray_y, g->tile_size);

            if (local_x < 1)
                h.face = 2; // WE
            else if (local_x > g->tile_size - 1)
                h.face = 3; // EA
            else if (local_y < 1)
                h.face = 0; // NO
            else
                h.face = 1; // SO

            return h;
        }
    }
}


void dessiner_colonne(t_game *g, int col, int height, t_hit hit)
{
    int top = (600 - height) / 2;
    int bottom = top + height;

    // plafond
    for (int y = 0; y < top; y++)
        put_pixel(g, col, y, 0x00333333);

    // calcul texture_x
    int texture_x;
    if (hit.face == 0 || hit.face == 1) // NO / SO
        texture_x = (int)(fmod(hit.hit_x, g->tile_size) * g->tex_w / g->tile_size);
    else // WE / EA
        texture_x = (int)(fmod(hit.hit_y, g->tile_size) * g->tex_w / g->tile_size);

    // mur texturé
    for (int y = top; y < bottom; y++)
    {
        double tex_y_ratio = (double)(y - top) / height;
        int texture_y = (int)(tex_y_ratio * g->tex_h);

        char *tex_addr;
        if (hit.face == 0) tex_addr = g->addr_no;
        else if (hit.face == 1) tex_addr = g->addr_so;
        else if (hit.face == 2) tex_addr = g->addr_we;
        else tex_addr = g->addr_ea;

        int color = *(unsigned int *)(tex_addr +
            texture_y * g->tex_line_len +
            texture_x * (g->tex_bpp / 8));

        put_pixel(g, col, y, color);
    }

    // sol
    for (int y = bottom; y < 600; y++)
        put_pixel(g, col, y, 0x00555555);
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
    load_textures(&g);
    mlx_loop_hook(g.mlx, render_frame, &g);
    mlx_loop(g.mlx);

    return (0);
}
void load_textures (t_game *g)
{
    g.tex_no = mlx_xpm_file_to_image(g->mlx, "NO.xpm", &g->tex_w, &g->tex_h);
    g.addr_no = mlx_get_data_addr(g->tex_no, &g->tex_bpp, &g->tex_line_len, &g->tex_endian);
    g.tex_so = mlx_xpm_file_to_image(g->mlx, "SO.xpm", &g->tex_w, &g->tex_h);
    g.addr_so = mlx_get_data_addr(g->tex_so, &g->tex_bpp, &g->tex_line_len, &g->tex_endian);
    g.tex_we = mlx_xpm_file_to_image(g->mlx, "WE.xpm", &g->tex_w, &g->tex_h);
    g.addr_we = mlx_get_data_addr(g->tex_we, &g->tex_bpp, &g->tex_line_len, &g->tex_endian);
    g.tex_ea = mlx_xpm_file_to_image(g->mlx, "EA.xpm", &g->tex_w, &g->tex_h);
    g.addr_ea = mlx_get_data_addr(g->tex_ea, &g->tex_bpp, &g->tex_line_len, &g->tex_endian);
}