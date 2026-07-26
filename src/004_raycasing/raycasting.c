#include "../../include/cub3d.h"

int compute_height(t_game *g, double distance)
{
    double projection_plane = 800 / tan(FOV / 2);
    int height = (int)((g->tile_size / distance) * projection_plane);

    if (height > 600)
        height = 600;

    return height;
}





t_hit launch_ray(t_game *g, double angle)
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