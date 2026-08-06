#include "../../include/cub3d.h"

// Ici c'est un main. Il y aura pas mal de choses à passer dans le main principale, mais la
// plupart sera à jeter. C'est pour que je puisse tester mon raycasting :)

int main(void)
{
    t_game g;

    printf("A\n");
    fflush(stdout);
    // MAP CODÉE EN DUR
    g.map = (char *[]){
        "111111",
        "100001",
        "100N01",
        "100001",
        "100001",
        "111111",
        NULL
    };
    printf("B\n");
    fflush(stdout);
    g.tile_size = 64;
    g.map_width = 6;
    g.map_height = 6;
    init_player(&g);

    printf("C\n");
    fflush(stdout);

    g.player_x = 3 * g.tile_size;
    g.player_y = 3 * g.tile_size;
    g.player_angle = 0;

    g.win_width = 800;
    g.win_height = 600;
    // FOV dynamique (pour zoom/dézoom)
    g.fov = 60 * (M_PI / 180);

    // INIT MLX
    g.mlx = mlx_init();
    g.win = mlx_new_window(g.mlx, 800, 600, "Cub3D test");

    g.img = mlx_new_image(g.mlx, 800, 600);
    g.addr = mlx_get_data_addr(g.img, &g.bpp, &g.line_len, &g.endian);

    // TEXTURES
    load_textures(&g);


    // HOOKS
    mlx_hook(g.win, 2, 1L<<0, key_press, &g);   // clavier
    mlx_hook(g.win, 17, 0, close_window, &g);  // croix rouge
    mlx_loop_hook(g.mlx, render_frame, &g);    // rendu

    mlx_loop(g.mlx);
    return (0);
}

