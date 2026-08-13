#include "../../include/cub3d.h"
#define COLLISION_PAD 10.0

int key_press(int keycode, t_game *g)
{
    double move_speed = 5.0;
    double rot_speed = 0.05;

    printf("KEY = %d\n", keycode);
    fflush(stdout);
    // W → avancer
    if (keycode == 119) // W
    {
        double nx = g->player_x + cos(g->player_angle) * move_speed;
        double ny = g->player_y + sin(g->player_angle) * move_speed;

        int nx_case = (int)(nx / g->tile_size);
        int ny_case = (int)(ny / g->tile_size);

// Vérification avec padding
        if (g->map[ny_case][nx_case] != '1' &&
            g->map[(int)((ny + COLLISION_PAD) / g->tile_size)][nx_case] != '1' &&
            g->map[(int)((ny - COLLISION_PAD) / g->tile_size)][nx_case] != '1' &&
            g->map[ny_case][(int)((nx + COLLISION_PAD) / g->tile_size)] != '1' &&
            g->map[ny_case][(int)((nx - COLLISION_PAD) / g->tile_size)] != '1')
        {
            g->player_x = nx;
            g->player_y = ny;
        }
    }

    // S → reculer
    if (keycode == 115) // S
    {
        double nx = g->player_x - cos(g->player_angle) * move_speed;
        double ny = g->player_y - sin(g->player_angle) * move_speed;

        int nx_case = (int)(nx / g->tile_size);
        int ny_case = (int)(ny / g->tile_size);

        if (g->map[ny_case][nx_case] != '1' &&
            g->map[(int)((ny + COLLISION_PAD) / g->tile_size)][nx_case] != '1' &&
            g->map[(int)((ny - COLLISION_PAD) / g->tile_size)][nx_case] != '1' &&
            g->map[ny_case][(int)((nx + COLLISION_PAD) / g->tile_size)] != '1' &&
            g->map[ny_case][(int)((nx - COLLISION_PAD) / g->tile_size)] != '1')
        {
            g->player_x = nx;
            g->player_y = ny;
        }
    }

    // A → strafe gauche
    if (keycode == 97) // A
    {
        double nx = g->player_x - cos(g->player_angle + M_PI/2) * move_speed;
        double ny = g->player_y - sin(g->player_angle + M_PI/2) * move_speed;

        int nx_case = (int)(nx / g->tile_size);
        int ny_case = (int)(ny / g->tile_size);

        if (g->map[ny_case][nx_case] != '1' &&
            g->map[(int)((ny + COLLISION_PAD) / g->tile_size)][nx_case] != '1' &&
            g->map[(int)((ny - COLLISION_PAD) / g->tile_size)][nx_case] != '1' &&
            g->map[ny_case][(int)((nx + COLLISION_PAD) / g->tile_size)] != '1' &&
            g->map[ny_case][(int)((nx - COLLISION_PAD) / g->tile_size)] != '1')
        {
            g->player_x = nx;
            g->player_y = ny;
        }
    }

    // D → strafe droite
    if (keycode == 100) // D
    {
        double nx = g->player_x + cos(g->player_angle + M_PI/2) * move_speed;
        double ny = g->player_y + sin(g->player_angle + M_PI/2) * move_speed;

        int nx_case = (int)(nx / g->tile_size);
        int ny_case = (int)(ny / g->tile_size);

        if (g->map[ny_case][nx_case] != '1' &&
            g->map[(int)((ny + COLLISION_PAD) / g->tile_size)][nx_case] != '1' &&
            g->map[(int)((ny - COLLISION_PAD) / g->tile_size)][nx_case] != '1' &&
            g->map[ny_case][(int)((nx + COLLISION_PAD) / g->tile_size)] != '1' &&
            g->map[ny_case][(int)((nx - COLLISION_PAD) / g->tile_size)] != '1')
        {
            g->player_x = nx;
            g->player_y = ny;
        }
    }

    // ← → rotation
    if (keycode == 65361) // left arrow
        g->player_angle -= rot_speed;

    if (keycode == 65363) // right arrow
        g->player_angle += rot_speed;
    if (keycode == 65307) // ESC
        close_window(g);
// Flèche HAUT → zoom
    if (keycode == 65362) // Up arrow
    {
        g->fov -= 0.02;
        if (g->fov < 0.2)
            g->fov = 0.2;
    }

// Flèche BAS → dézoom
    if (keycode == 65364) // Down arrow
    {
        g->fov += 0.02;
        if (g->fov > 1.5)
            g->fov = 1.5;
    }


    // Normalisation de l’angle
    if (g->player_angle < 0)
        g->player_angle += 2 * M_PI;
    if (g->player_angle > 2 * M_PI)
        g->player_angle -= 2 * M_PI;

    return (0);
}
int close_window(t_game *g)
{
    mlx_destroy_window(g->mlx, g->win);
    exit(0);
    return (0);
}
