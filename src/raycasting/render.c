#include "../../include/cub3d.h"

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

    for (int col = 0; col < g->win_width; col++)
    {
        // Angle du rayon pour cette colonne (FOV dynamique)
        double ray_angle = g->player_angle
            + (col - g->win_width / 2) * g->fov / g->win_width;

        // Lancer le rayon → distance + face + hit_x + hit_y
        t_hit hit = launch_ray_dda(g, ray_angle);

        // Calculer la hauteur du mur
        int wall_height = compute_height(g, hit.distance);

        // Dessiner la colonne texturée
        draw_column(g, col, wall_height, hit);
    }

    // Afficher l'image dans la fenêtre
    mlx_put_image_to_window(g->mlx, g->win, g->img, 0, 0);

    return (0);
}



void draw_column(t_game *g, int col, int height, t_hit hit)
{
    int top = (g->win_height - height) / 2;
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
    for (int y = bottom; y < g->win_height; y++)
        put_pixel(g, col, y, 0x00555555);
}


void    put_pixel(t_game *g, int x, int y, int color)
{
    char    *dst;

    dst = g->addr + (y * g->line_len + x * (g->bpp / 8));
    *(unsigned int *)dst = color;
}