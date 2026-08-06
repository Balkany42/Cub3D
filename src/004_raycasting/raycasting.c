#include "../../include/cub3d.h"

int compute_height(t_game *g, double distance)
{
    double projection_plane = 800 / tan(FOV / 2);
    int height = (int)((g->tile_size / distance) * projection_plane);

    if (height > 600)
        height = 600;

    return height;
}

t_hit launch_ray_dda(t_game *g, double angle)
{
    t_hit h;

    double rayDirX = cos(angle);
    double rayDirY = sin(angle);

    double deltaDistX = (rayDirX == 0) ? 1e30 : fabs(1.0 / rayDirX);
    double deltaDistY = (rayDirY == 0) ? 1e30 : fabs(1.0 / rayDirY);

    int mapX = (int)(g->player_x / g->tile_size);
    int mapY = (int)(g->player_y / g->tile_size);

    int stepX;
    int stepY;
    double sideDistX;
    double sideDistY;

    if (rayDirX < 0)
    {
        stepX = -1;
        sideDistX = (g->player_x / g->tile_size - mapX) * deltaDistX;
    }
    else
    {
        stepX = 1;
        sideDistX = (mapX + 1.0 - g->player_x / g->tile_size) * deltaDistX;
    }

    if (rayDirY < 0)
    {
        stepY = -1;
        sideDistY = (g->player_y / g->tile_size - mapY) * deltaDistY;
    }
    else
    {
        stepY = 1;
        sideDistY = (mapY + 1.0 - g->player_y / g->tile_size) * deltaDistY;
    }

    int hit = 0;
    int side = 0;

    while (!hit)
    {
        if (sideDistX < sideDistY)
        {
            sideDistX += deltaDistX;
            mapX += stepX;
            side = 0;
        }
        else
        {
            sideDistY += deltaDistY;
            mapY += stepY;
            side = 1;
        }

        if (g->map[mapY][mapX] == '1')
            hit = 1;
    }

    double perpWallDist;

    if (side == 0)
        perpWallDist = (mapX - g->player_x / g->tile_size + (1 - stepX) / 2) / rayDirX;
    else
        perpWallDist = (mapY - g->player_y / g->tile_size + (1 - stepY) / 2) / rayDirY;

    h.distance = perpWallDist * g->tile_size;

    h.hit_x = g->player_x + rayDirX * h.distance;
    h.hit_y = g->player_y + rayDirY * h.distance;

    if (side == 0)
    {
        if (rayDirX > 0)
            h.face = 3; // EA
        else
            h.face = 2; // WE
    }
    else
    {
        if (rayDirY > 0)
            h.face = 1; // SO
        else
            h.face = 0; // NO
    }

    return h;
}
