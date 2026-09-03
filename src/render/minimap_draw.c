/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_draw.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrager <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 23:20:00 by mgrager           #+#    #+#             */
/*   Updated: 2026/08/31 23:20:00 by mgrager          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	minimap_cell_color(t_game *game, int px, int py)
{
	int	colour;

	if (px >= 0 && py >= 0 && px < game->map.width && py < game->map.height)
		colour = cell_colour(game->map.grid[py][px]);
	else
		colour = -1;
	if (colour == -1)
		colour = 0x888888;
	return (colour);
}

static void	draw_minimap_row(t_game *game, int row, int off_x, int off_y)
{
	int	col;
	int	px;
	int	py;
	int	colour;

	col = 0;
	while (col <= MINIMAP_WIDTH)
	{
		px = (int)game->player.x - MINIMAP_WIDTH / 2 + col;
		py = (int)game->player.y - MINIMAP_HEIGHT / 2 + row;
		colour = minimap_cell_color(game, px, py);
		render_grid_cell(game, colour,
			MINIMAP_OFFSET + MINIMAP_TILE * row - off_y,
			MINIMAP_OFFSET + MINIMAP_TILE * col - off_x);
		col++;
	}
}

static void	draw_minimap_grid(t_game *game, int off_x, int off_y)
{
	int	row;

	row = 0;
	while (row <= MINIMAP_HEIGHT)
	{
		draw_minimap_row(game, row, off_x, off_y);
		row++;
	}
}

void	draw_minimap(t_game *game)
{
	int	off_x;
	int	off_y;

	render_minimap_frame(game);
	off_x = (int)((game->player.x - (int)game->player.x) * MINIMAP_TILE);
	off_y = (int)((game->player.y - (int)game->player.y) * MINIMAP_TILE);
	draw_minimap_grid(game, off_x, off_y);
	render_cell(game, 0x3399FF,
		MINIMAP_OFFSET + MINIMAP_TILE * (MINIMAP_HEIGHT / 2),
		MINIMAP_OFFSET + MINIMAP_TILE * (MINIMAP_WIDTH / 2));
	render_cursor(game,
		MINIMAP_OFFSET + MINIMAP_TILE * (MINIMAP_WIDTH / 2) + MINIMAP_TILE / 2,
		MINIMAP_OFFSET + MINIMAP_TILE
		* (MINIMAP_HEIGHT / 2) + MINIMAP_TILE / 2);
}
