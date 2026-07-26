#include "../../include/cub3d.h"

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
    mlx_hook(g.win, 2, 1L<<0, key_press, &g);
    mlx_loop_hook(g.mlx, render_frame, &g);
    mlx_loop(g.mlx);

    return (0);
}
