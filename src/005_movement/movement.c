#include "../../include/cub3d.h"

#include "cub3d.h"

int key_press(int keycode, t_game *g)
{
    double move_speed = 5.0;
    double rot_speed = 0.05;

    // W → avancer
    if (keycode == 13) // W
    {
        double nx = g->player_x + cos(g->player_angle) * move_speed;
        double ny = g->player_y + sin(g->player_angle) * move_speed;

        int mx = (int)(nx / g->tile_size);
        int my = (int)(ny / g->tile_size);

        if (g->map[my][mx] != '1')
        {
            g->player_x = nx;
            g->player_y = ny;
        }
    }

    // S → reculer
    if (keycode == 1) // S
    {
        double nx = g->player_x - cos(g->player_angle) * move_speed;
        double ny = g->player_y - sin(g->player_angle) * move_speed;

        int mx = (int)(nx / g->tile_size);
        int my = (int)(ny / g->tile_size);

        if (g->map[my][mx] != '1')
        {
            g->player_x = nx;
            g->player_y = ny;
        }
    }

    // A → strafe gauche
    if (keycode == 0) // A
    {
        double nx = g->player_x - cos(g->player_angle + M_PI/2) * move_speed;
        double ny = g->player_y - sin(g->player_angle + M_PI/2) * move_speed;

        int mx = (int)(nx / g->tile_size);
        int my = (int)(ny / g->tile_size);

        if (g->map[my][mx] != '1')
        {
            g->player_x = nx;
            g->player_y = ny;
        }
    }

    // D → strafe droite
    if (keycode == 2) // D
    {
        double nx = g->player_x + cos(g->player_angle + M_PI/2) * move_speed;
        double ny = g->player_y + sin(g->player_angle + M_PI/2) * move_speed;

        int mx = (int)(nx / g->tile_size);
        int my = (int)(ny / g->tile_size);

        if (g->map[my][mx] != '1')
        {
            g->player_x = nx;
            g->player_y = ny;
        }
    }

    // ← → rotation
    if (keycode == 123) // left arrow
        g->player_angle -= rot_speed;

    if (keycode == 124) // right arrow
        g->player_angle += rot_speed;

    // Normalisation de l’angle
    if (g->player_angle < 0)
        g->player_angle += 2 * M_PI;
    if (g->player_angle > 2 * M_PI)
        g->player_angle -= 2 * M_PI;

    return (0);
}
