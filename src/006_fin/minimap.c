#include "../../include/cub3d.h"

static void	fill_cell(t_img *img, int px, int py, int color)
{
	int	dx;
	int	dy;

	dy = 0;
	while (dy < MM_TILE - 1)
	{
		dx = 0;
		while (dx < MM_TILE - 1)
		{
			put_pixel(img, px + dx, py + dy, color);
			dx++;
		}
		dy++;
	}
}

void	draw_minimap(t_game *game)
{
	t_map	*map;
	int		x;
	int		y;
	int		px;
	int		py;

	map = &game->map;
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			px = MM_PAD + x * MM_TILE;
			py = MM_PAD + y * MM_TILE;
			if (map->grid[y][x] == '1')
				fill_cell(&game->screen, px, py, 0x888888);
			else if (map->grid[y][x] == '0')
				fill_cell(&game->screen, px, py, 0x222222);
			x++;
		}
		y++;
	}
	px = MM_PAD + (int)(game->player.x * MM_TILE);
	py = MM_PAD + (int)(game->player.y * MM_TILE);
	fill_cell(&game->screen, px - 2, py - 2, 0xFF0000);
	x = 0;
	while (x < 6)
	{
		put_pixel(&game->screen, px + (int)(game->player.dir_x * x),
			py + (int)(game->player.dir_y * x), 0xFFFF00);
		x++;
	}
}
