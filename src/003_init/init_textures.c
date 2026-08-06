#include "../../include/cub3d.h"

void load_textures (t_game *g)
{
    g->tex_no = mlx_xpm_file_to_image(g->mlx, "textures/NO.xpm", &g->tex_w, &g->tex_h);
    g->addr_no = mlx_get_data_addr(g->tex_no, &g->tex_bpp, &g->tex_line_len, &g->tex_endian);
    g->tex_so = mlx_xpm_file_to_image(g->mlx, "textures/SO.xpm", &g->tex_w, &g->tex_h);
    g->addr_so = mlx_get_data_addr(g->tex_so, &g->tex_bpp, &g->tex_line_len, &g->tex_endian);
    g->tex_we = mlx_xpm_file_to_image(g->mlx, "textures/WE.xpm", &g->tex_w, &g->tex_h);
    g->addr_we = mlx_get_data_addr(g->tex_we, &g->tex_bpp, &g->tex_line_len, &g->tex_endian);
    g->tex_ea = mlx_xpm_file_to_image(g->mlx, "textures/EA.xpm", &g->tex_w, &g->tex_h);
    g->addr_ea = mlx_get_data_addr(g->tex_ea, &g->tex_bpp, &g->tex_line_len, &g->tex_endian);
}

void init_player(t_game *g)
{
    printf("0\n");
    fflush(stdout);
    for (int y = 0; g->map[y]; y++)
    {
        printf("1\n");
        fflush(stdout);
        for (int x = 0; g->map[y][x]; x++)
        {
            printf("2\n");
            fflush(stdout);
            char c = g->map[y][x];

            if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
            {
                // Position au centre de la case
                g->player_x = x * g->tile_size + g->tile_size / 2;
                g->player_y = y * g->tile_size + g->tile_size / 2;

                // Angle selon la lettre
                if (c == 'N')
                    g->player_angle = 3 * M_PI / 2;  // vers le haut
                if (c == 'S')
                    g->player_angle = M_PI / 2;      // vers le bas
                if (c == 'E')
                    g->player_angle = 0;             // vers la droite
                if (c == 'W')
                    g->player_angle = M_PI;          // vers la gauche

                // On remplace la lettre par du sol
                g->map[y][x] = '0';
                return;
            }
            printf("3\n");
            fflush(stdout);
        }
        printf("4\n");
        fflush(stdout);
    }
    printf("5\n");
    fflush(stdout);
}
